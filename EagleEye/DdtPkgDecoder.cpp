#include "DdtPkgDecoder.h"
#include "StrucDDTLUT.h"
#include "StrucTree.h"
#include "StrucTreeManager.h"
#include "LteRrcDecoder.h"


DdtPkgDecoder::DdtPkgDecoder(unsigned pkgId) :
PkgDecoder(pkgId)
{
}

void DdtPkgDecoder::decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter)
{
	PkgDecoder::decode(b, pkgLoc, is4Filter);

	StrucTree* rst = EE_GET_ST(DDT_ID_DDT);//<< DDT_t
	strucTree = rst->clone();
	quint16 blockId = STRUC_N(pkgId);
	strucTree->insertKV("blockId", blockId);	
	if (pkgLoc != Q_NULLPTR)
	{
		//idx 2 for blockId, make sure idx is consitent w/ 
		// SLUT_INSERT_FK in StrucDDTLUT::initStrucLut()		
		pkgLoc->fk[2] = blockId;
	}
}

DdtDlPkgDecoderComm::DdtDlPkgDecoderComm(unsigned pkgId) :
DdtPkgDecoder(pkgId)
{
}

void DdtDlPkgDecoderComm::decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter)
{
	DdtPkgDecoder::decode(b, pkgLoc, is4Filter);

	if (is4Filter)
	{
		return;
	}

	StrucTree* nst = is4Filter ? Q_NULLPTR : strucTree;

	StrucTree* rst = Q_NULLPTR;
	if ('N' == b.at(b.size() - 1))
	{
		rst = EE_GET_ST(DDT_ID_UDPHEADER);//<< DDTUdpHeader_t
	}
	else if ('C' == b.at(b.size() - 1))
	{
		rst = EE_GET_ST(DDT_ID_UDPHEADERCA);//<< DDTUdpHeaderCA_t
	}
	else
	{
		quint8 ver = STRUC_V(pkgId);
		if (ver >= DDT_VER_DLT_BCEM_FDD_TDD_V13)
		{
			rst = EE_GET_ST(DDT_ID_UDPHEADERCATM_LR171);//<< DDTUdpHeaderCATM_171_t

		}
		else
		{
			rst = EE_GET_ST(DDT_ID_UDPHEADERCATM_LR162);;//<< DDTUdpHeaderCATM_162_t
		}
	}

	StrucTree* header = rst->clone();
	header->decode(QByteArray(b.data(), rst->getSizeInByte()), nst, pkgLoc);
	header->setParent(strucTree);
	strucTree->appendChild(header);
	strucTree->shiftSizeInByte(header->getSizeInByte());
}

DdtDlPkgDecoder::DdtDlPkgDecoder(unsigned pkgId) :
DdtDlPkgDecoderComm(pkgId)
{
}

void DdtDlPkgDecoder::decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter)
{
	DdtDlPkgDecoderComm::decode(b, pkgLoc, is4Filter);

	StrucTree* nst = is4Filter ? Q_NULLPTR : strucTree;

	StrucTree* rst = EE_GET_ST(pkgId);
	if (rst->getSizeInByte() != 0)
	{
		StrucTree* payload = rst->clone();
		quint16 payloadOffset = strucTree->getSizeInByte();
		payload->decode(QByteArray(b.data() + payloadOffset, payload->getSizeInByte()), nst, pkgLoc);
		payload->shiftOffsetInByte(payloadOffset);
		payload->setParent(strucTree);
		strucTree->appendChild(payload);
		strucTree->shiftSizeInByte(payload->getSizeInByte());
	}
}

DdtPkgDecoderB0010::DdtPkgDecoderB0010(unsigned pkgId) :
DdtDlPkgDecoder(pkgId)
{
}

void DdtPkgDecoderB0010::decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter)
{
	DdtDlPkgDecoder::decode(b, pkgLoc, is4Filter);	
	EeStrucId id(pkgId);
	if (strucTree)
	{
		quint16 payloadOffset = strucTree->getSizeInByte();

		id.id = DDT_ID_BLOCK0001;//addBearerHdr
		StrucTree* rst = EE_GET_ST(id.getSID());		
		StrucTree* cloneAddBearerHdr = rst->clone();
		quint16 sizeOfAddBearerHdr = cloneAddBearerHdr->getSizeInByte();
		cloneAddBearerHdr->decode(QByteArray(b.data() + payloadOffset, sizeOfAddBearerHdr), 
			strucTree, 
			pkgLoc);
		quint8 bearerNumber = strucTree->getFieldValue("bearerNumber");
		quint8 setupFlag = strucTree->getFieldValue("setupFlag");
		cloneAddBearerHdr->shiftOffsetInByte(payloadOffset);
		strucTree->shiftSizeInByte(cloneAddBearerHdr->getSizeInByte());
		cloneAddBearerHdr->setParent(strucTree);
		strucTree->appendChild(cloneAddBearerHdr);
		payloadOffset = strucTree->getSizeInByte();

		switch (setupFlag)
		{
			case DDT_UE_SETUP_TYPE_0:
			case DDT_UE_SETUP_TYPE_1:
			case DDT_UE_SETUP_TYPE_3:
			{
				id.id = DDT_ID_BLOCK0002; //ueCfgInfo
				rst = EE_GET_ST(id.getSID());
				StrucTree* cloneUeCfgInfo = rst->clone();
				quint16 sizeOfUeCfgInfo = cloneUeCfgInfo->getSizeInByte();
				cloneUeCfgInfo->decode(QByteArray(b.data() + payloadOffset, sizeOfUeCfgInfo), 
					strucTree, 
					pkgLoc);
				cloneUeCfgInfo->shiftOffsetInByte(payloadOffset);
				strucTree->shiftSizeInByte(cloneUeCfgInfo->getSizeInByte());
				cloneUeCfgInfo->setParent(strucTree);
				strucTree->appendChild(cloneUeCfgInfo);
				payloadOffset = strucTree->getSizeInByte();
			}
			break;

			case DDT_UE_SETUP_TYPE_2:
			{
				id.id = DDT_ID_BLOCK0003; //ueModif
				rst = EE_GET_ST(id.getSID());
				StrucTree* cloneUeModif = rst->clone();
				quint16 sizeOfUeModif = cloneUeModif->getSizeInByte();
				cloneUeModif->decode(QByteArray(b.data() + payloadOffset, sizeOfUeModif), 
					strucTree, 
					pkgLoc);
				cloneUeModif->shiftOffsetInByte(payloadOffset);
				strucTree->shiftSizeInByte(cloneUeModif->getSizeInByte());
				cloneUeModif->setParent(strucTree);
				strucTree->appendChild(cloneUeModif);
				payloadOffset = strucTree->getSizeInByte();
			}
			break;

			default:
			break;
		}

		if (DDT_UE_SETUP_TYPE_1 == setupFlag)
		{
			id.id = DDT_ID_BLOCK000B;//srInfo
			rst = EE_GET_ST(id.getSID());
			StrucTree* cloneUeSetupHdr = rst->clone();
			quint16 sizeOfUeSetupHdr = cloneUeSetupHdr->getSizeInByte();
			cloneUeSetupHdr->decode(QByteArray(b.data() + payloadOffset, sizeOfUeSetupHdr), cloneUeSetupHdr);
			quint8 isCatm = cloneUeSetupHdr->getFieldValue("reserved");
			delete cloneUeSetupHdr;

			id.id = DDT_ID_BLOCK0004; //ueSetup legacy;
			rst = EE_GET_ST(id.getSID());
			quint16 sizeOfUeSetup = rst->getSizeInByte();
			if (isCatm)
			{
				id.id = DDT_ID_BLOCK000A; //ueSetup catm;
				rst = EE_GET_ST(id.getSID());
			}
			StrucTree* cloneUeSetup = rst->clone();
			cloneUeSetup->decode(QByteArray(b.data() + payloadOffset, sizeOfUeSetup), 
				strucTree,
				pkgLoc);
			cloneUeSetup->shiftOffsetInByte(payloadOffset);
			strucTree->shiftSizeInByte(cloneUeSetup->getSizeInByte());
			cloneUeSetup->setParent(strucTree);
			strucTree->appendChild(cloneUeSetup);
			payloadOffset = strucTree->getSizeInByte();
		}

		id.id = DDT_ID_BLOCK0005;//bearerInfo;
		rst = EE_GET_ST(id.getSID());
		quint16 sizeOfBearerInfo = rst->getSizeInByte();

		quint8 rbIdx;
		for (rbIdx = 0; rbIdx < bearerNumber; ++rbIdx)
		{
			StrucTree* cloneBearerInfo = rst->clone();
			cloneBearerInfo->decode(QByteArray(b.data() + payloadOffset, sizeOfBearerInfo), 
				strucTree,
				pkgLoc);
			cloneBearerInfo->shiftOffsetInByte(payloadOffset);
			strucTree->shiftSizeInByte(cloneBearerInfo->getSizeInByte());
			cloneBearerInfo->setParent(strucTree);
			strucTree->appendChild(cloneBearerInfo);
			payloadOffset = strucTree->getSizeInByte();
		}
	}

}

DdtPkgDecoderB0011::DdtPkgDecoderB0011(unsigned pkgId) :
DdtDlPkgDecoder(pkgId)
{
}

void DdtPkgDecoderB0011::decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter)
{
	DdtDlPkgDecoder::decode(b, pkgLoc, is4Filter);
	EeStrucId id(pkgId);
	if (strucTree)
	{
		quint16 payloadOffset = strucTree->getSizeInByte();
		id.id = DDT_ID_BLOCK0006;//delBearerHdr
		StrucTree* rst = EE_GET_ST(id.getSID());
		StrucTree* cloneDelBearerHdr = rst->clone();
		quint16 sizeOfDelBearerHdr = cloneDelBearerHdr->getSizeInByte();
		cloneDelBearerHdr->decode(QByteArray(b.data() + payloadOffset, sizeOfDelBearerHdr), 
			cloneDelBearerHdr);
		quint8 bearerNumber = cloneDelBearerHdr->getFieldValue("bearerNumber");
		quint8 type = cloneDelBearerHdr->getFieldValue("type");
		delete cloneDelBearerHdr;

		if (DDT_RB_DEL_TYPE_0 == type)
		{
			StrucTree* cloneDelBearerHdr = rst->clone();
			quint16 sizeOfDelBearerHdr = cloneDelBearerHdr->getSizeInByte();
			cloneDelBearerHdr->decode(QByteArray(b.data() + payloadOffset, sizeOfDelBearerHdr), 
				strucTree,
				pkgLoc);
			cloneDelBearerHdr->shiftOffsetInByte(payloadOffset);
			strucTree->shiftSizeInByte(cloneDelBearerHdr->getSizeInByte());
			cloneDelBearerHdr->setParent(strucTree);
			strucTree->appendChild(cloneDelBearerHdr);
			payloadOffset = strucTree->getSizeInByte();


			id.id = DDT_ID_BLOCK0007; //<< v10_b0_7_t delBearerInfo
			rst = EE_GET_ST(id.getSID());
			quint16 sizeOfDelBearerInfo = rst->getSizeInByte();

			quint8 rbIdx;
			for (rbIdx = 0; rbIdx < bearerNumber; ++rbIdx)
			{
				StrucTree* cloneDelBearerInfo = rst->clone();
				cloneDelBearerInfo->decode(QByteArray(b.data() + payloadOffset, sizeOfDelBearerInfo), 
					strucTree,
					pkgLoc);
				cloneDelBearerInfo->shiftOffsetInByte(payloadOffset);
				strucTree->shiftSizeInByte(cloneDelBearerInfo->getSizeInByte());
				cloneDelBearerInfo->setParent(strucTree);
				strucTree->appendChild(cloneDelBearerInfo);
				payloadOffset = strucTree->getSizeInByte();
			}
		}
		else if (DDT_RB_DEL_TYPE_1 == type)
		{
			id.id = DDT_ID_BLOCK0009; //rLCFailure
			rst = EE_GET_ST(id.getSID());
			quint16 sizeOfRLCFailure = rst->getSizeInByte();
			StrucTree* cloneRLCFailure = rst->clone();
			cloneRLCFailure->decode(QByteArray(b.data() + payloadOffset, sizeOfRLCFailure), 
				strucTree,
				pkgLoc);
			cloneRLCFailure->shiftOffsetInByte(payloadOffset);
			strucTree->shiftSizeInByte(cloneRLCFailure->getSizeInByte());
			cloneRLCFailure->setParent(strucTree);
			strucTree->appendChild(cloneRLCFailure);
			payloadOffset = strucTree->getSizeInByte();
		}
		else if (DDT_RB_DEL_TYPE_2 == type)
		{
			id.id = DDT_ID_BLOCK0008; //ulL1OoS
			rst = EE_GET_ST(id.getSID());
			quint16 sizeOfUlL1OoS = rst->getSizeInByte();
			StrucTree* cloneUlL1OoS = rst->clone();
			cloneUlL1OoS->decode(QByteArray(b.data() + payloadOffset, sizeOfUlL1OoS), 
				strucTree,
				pkgLoc);
			cloneUlL1OoS->shiftOffsetInByte(payloadOffset);
			strucTree->shiftSizeInByte(cloneUlL1OoS->getSizeInByte());
			cloneUlL1OoS->setParent(strucTree);
			strucTree->appendChild(cloneUlL1OoS);
			payloadOffset = strucTree->getSizeInByte();
		}
	}
}

DdtPkgDecoderB0501::DdtPkgDecoderB0501(unsigned pkgId) :
DdtDlPkgDecoder(pkgId)
{
}

void DdtPkgDecoderB0501::decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter)
{
	DdtDlPkgDecoder::decode(b, pkgLoc, is4Filter);
	EeStrucId id(pkgId);
	StrucTree* rlcHdrClone = Q_NULLPTR;

	if (is4Filter)
	{
		return;
	}

	StrucTree* rlcHeader = EE_GET_ST(pkgId); //<< rlcHeader		
	quint16 length = strucTree->getFieldValue("Length") - 
		(rlcHeader->getSizeInByte() - 1);
	quint8 pos = strucTree->getSizeInByte() - 1;
	quint8 rlcMode = strucTree->getFieldValue("RlcMode");	
	StrucTree* data = strucTree->getChild("Data");
	if (DDT_LTE_RRC_CT_RLC_MODE_UM_5B == rlcMode)
	{
		id.id = DDT_ID_BLOCK0510; //<< DDT_rlcUM5bHdr_t
		StrucTree* rUM5bHdr = EE_GET_ST(id.getSID());
		if (length >= rUM5bHdr->getSizeInByte())
		{
			rlcHdrClone = rUM5bHdr->clone();
			rlcHdrClone->decode(QByteArray(b.data() + pos, length),
				strucTree,
				pkgLoc);
		}
		else
		{
			EELOG_WARN("DdtPkgDecoderB0501::decode|DDT_rlcUM5bHdr_t too short");
		}
	}
	else if (DDT_LTE_RRC_CT_RLC_MODE_UM_10B == rlcMode)
	{
		id.id = DDT_ID_BLOCK0511;//<< DDT_rlcUM10bHdr_t		
		StrucTree* rUM10bHdr = EE_GET_ST(id.getSID());
		if (length >= rUM10bHdr->getSizeInByte())
		{
			rlcHdrClone = rUM10bHdr->clone();
			rlcHdrClone->decode(QByteArray(b.data() + pos, length),
				strucTree,
				pkgLoc);
			quint16 SN =
				strucTree->getFieldValue("SN_2B") << 8 | 
				strucTree->getFieldValue("SN_8B");
			strucTree->insertKV("SN", SN);
		}
		else
		{
			EELOG_WARN("DdtPkgDecoderB0501::decode|DDT_rlcUM10bHdr_t too short");			
		}
	}
	else if (DDT_LTE_RRC_CT_RLC_MODE_AM == rlcMode)
	{
		if (length >= 1)
		{
			quint8 byte0 = *(const uchar*)(b.data() + pos);
			quint8 am_DC = (byte0 & 0x80) >> 7;
			quint8 am_RF = (byte0 & 0x40) >> 6;

			if (DDT_LTE_RLC_AM_PDU_DC_DATA == am_DC)
			{
				if (DDT_LTE_RLC_AM_PDU == am_RF)
				{
					id.id = DDT_ID_BLOCK0512;//DDT_rlcAMDataHdr_t					
					StrucTree* rAMDataHdr = EE_GET_ST(id.getSID());
					if (length >= rAMDataHdr->getSizeInByte())
					{
						rlcHdrClone = rAMDataHdr->clone();
						rlcHdrClone->decode(QByteArray(b.data() + pos, length),
							strucTree,
							pkgLoc);
						quint16 SN =
							strucTree->getFieldValue("SN_2B") << 8 | 
							strucTree->getFieldValue("SN_8B");
						strucTree->insertKV("SN", SN);
					}
					else
					{
						EELOG_WARN("DdtPkgDecoderB0501::decode|DDT_rlcAMDataHdr_t too short");						
					}
				}
				else
				{
					id.id = DDT_ID_BLOCK0513;//DDT_rlcAMDataRFHdr_t					
					StrucTree* rAMDataRFHdr = EE_GET_ST(id.getSID());
					if (length >= rAMDataRFHdr->getSizeInByte())
					{
						rlcHdrClone = rAMDataRFHdr->clone();
						rlcHdrClone->decode(QByteArray(b.data() + pos, length), 
							strucTree,
							pkgLoc);
						quint16 SN =
							strucTree->getFieldValue("SN_2B") << 8 | 
							strucTree->getFieldValue("SN_8B");
						strucTree->insertKV("SN", SN);
						quint16 SO =
							strucTree->getFieldValue("SO_7B") << 8 | 
							strucTree->getFieldValue("SO_8B");
						strucTree->insertKV("SO", SO);

					}
					else
					{
						EELOG_WARN("DdtPkgDecoderB0501::decode|DDT_rlcAMDataRFHdr_t too short");						
					}
				}
			}
			else if (DDT_LTE_RLC_AM_PDU_DC_CONTROL == am_DC)
			{
				id.id = DDT_ID_BLOCK0514; //<< DDT_rlcAMCtrlHdr_t
				StrucTree* rAMCtrlHdr = EE_GET_ST(id.getSID());
				id.id = DDT_ID_BLOCK0515; //<< DDT_rlcAMCtrlEHdr_t
				StrucTree* rAMCtrlEHdr = EE_GET_ST(id.getSID());
				if (length >= rAMCtrlEHdr->getSizeInByte())
				{
					rlcHdrClone = rAMCtrlEHdr->clone();
					rlcHdrClone->decode(QByteArray(b.data() + pos, length), 
						strucTree,
						pkgLoc);
					quint16 ACK_SN =
						strucTree->getFieldValue("ACK_SN_4B") << 6 | 
						strucTree->getFieldValue("ACK_SN_6B");
					strucTree->insertKV("ACK_SN", ACK_SN);
					quint16 NACK_SN =
						strucTree->getFieldValue("NACK_SN_1B_1") << 9 |
						strucTree->getFieldValue("NACK_SN_8B") << 1 |
						strucTree->getFieldValue("NACK_SN_1B_2");
					strucTree->insertKV("NACK_SN", NACK_SN);
				}
				else if (length >= rAMCtrlHdr->getSizeInByte())
				{
					rlcHdrClone = rAMCtrlHdr->clone();
					rlcHdrClone->decode(QByteArray(b.data() + pos, length), 
						strucTree,
						pkgLoc);
					quint16 ACK_SN =
						strucTree->getFieldValue("ACK_SN_4B") << 6 | 
						strucTree->getFieldValue("ACK_SN_6B");
					strucTree->insertKV("ACK_SN", ACK_SN);
				}
				else
				{
					EELOG_WARN("DdtPkgDecoderB0501::decode|DDT_rlcAMCtrlHdr_t too short");					
				}
			}
			else
			{
				Q_ASSERT(false);//bad RLC header
			}
		}
	}
	else
	{
		//UM MODE OR other ???
	}

	if (Q_NULLPTR != rlcHdrClone)
	{
		rlcHdrClone->setParent(data);
		rlcHdrClone->shiftOffsetInByte(pos);
		data->appendChild(rlcHdrClone);
	}

}

DdtPkgDecoderB0701::DdtPkgDecoderB0701(unsigned pkgId) :
DdtDlPkgDecoder(pkgId)
{
}

void DdtPkgDecoderB0701::decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter)
{
	DdtDlPkgDecoder::decode(b, pkgLoc, false);
	EeStrucId id(pkgId);

	if (is4Filter)
	{
		return;
	}

	StrucTree* rst = EE_GET_ST(pkgId); //<< rrc header	
	if (Q_NULLPTR != rst)
	{
		quint8 pos = strucTree->getSizeInByte();
		quint16 signalingInfoLength = strucTree->getFieldValue("signalingInfoLength");
		quint8 channelType = strucTree->getFieldValue("channelType");
		quint8 signalingInfoDirection = strucTree->getFieldValue("signalingInfoDirection");	
		LteRrcDecoder rrcDecoder(signalingInfoDirection,
			channelType, 
			QByteArray(b.data() + pos, signalingInfoLength));
		StrucTree *rrcCxt = rrcDecoder.getStrucTree(strucTree);
		if (rrcCxt != Q_NULLPTR)
		{
			StrucTree *rrcHdr = strucTree->getChild("dcchCcchInfo");
			rrcCxt->setParent(rrcHdr);
			rrcHdr->appendChild(rrcCxt);
		}
	}
}

DdtPkgDecoderB0301::DdtPkgDecoderB0301(unsigned pkgId) :
DdtDlPkgDecoderComm(pkgId)
{
}

void DdtPkgDecoderB0301::decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter)
{
	DdtDlPkgDecoderComm::decode(b, pkgLoc, is4Filter);
	EeStrucId id(pkgId);

	StrucTree* rst = EE_GET_ST(pkgId); //<< multiUe01msHdr	
	if (Q_NULLPTR != rst)
	{
		quint16 payloadOffset = strucTree->getSizeInByte();
		quint8 ueNumIdx = pkgLoc->headerLen >> 8;
		quint8 ueNum = ueNumIdx >> 4;
		quint8 ueIdx = ueNumIdx & 0x0F;
		QByteArray payloadBuf = QByteArray(b.data() + payloadOffset + ueIdx * 2, 2) +
			QByteArray(b.data() + payloadOffset + ueNum * 2 + (ueIdx >> 1), 1);

		StrucTree* payload = rst->clone();			
		payload->decode(payloadBuf, strucTree, pkgLoc);
		payload->shiftOffsetInByte(payloadOffset);
		payload->setParent(strucTree);
		strucTree->appendChild(payload);
		strucTree->shiftSizeInByte(payload->getSizeInByte());
	}
}

DdtPkgDecoderB2501::DdtPkgDecoderB2501(unsigned pkgId) :
DdtDlPkgDecoderComm(pkgId)
{
}

void DdtPkgDecoderB2501::decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter)
{
	DdtDlPkgDecoderComm::decode(b, pkgLoc, is4Filter);
	EeStrucId id(pkgId);

	StrucTree* rst = EE_GET_ST(pkgId); //<< mtc_unicast_scd_in	
	if (Q_NULLPTR != rst)
	{
		quint16 payloadOffset = strucTree->getSizeInByte();		
		quint8 ueIdx = pkgLoc->headerLen >> 8;
		QByteArray payloadBuf;
		quint8 ver = STRUC_V(pkgId);
		if (DDT_VER_ULT_BCEM_FDD_V19 == ver)
		{
			payloadBuf = QByteArray(b.data() + payloadOffset + ueIdx * 2, 2) +
				QByteArray(b.data() + payloadOffset + 3 * 2 + ueIdx * 2, 2);
		}
		else
		{
			payloadBuf = QByteArray(b.data() + payloadOffset + ueIdx * 2, 2) +
				QByteArray(b.data() + payloadOffset + 4 * 2 + ueIdx, 1);
		}		

		StrucTree* payload = rst->clone();
		payload->decode(payloadBuf, strucTree, pkgLoc);
		payload->shiftOffsetInByte(payloadOffset);
		payload->setParent(strucTree);
		strucTree->appendChild(payload);
		strucTree->shiftSizeInByte(payload->getSizeInByte());
	}
}

DdtPkgDecoderB1801::DdtPkgDecoderB1801(unsigned pkgId) :
DdtDlPkgDecoder(pkgId)
{
}

void DdtPkgDecoderB1801::decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter)
{
	DdtDlPkgDecoder::decode(b, pkgLoc, is4Filter);

	if (is4Filter)
	{
		return;
	}
	
	quint16 rnti = strucTree->getKvMap()->value("rnti").toUInt();
	quint32 msg2info = strucTree->getKvMap()->value("msg2info").toUInt();
	switch (rnti)
	{
	//case T_CRNTI_UL_PRACH_CONFIG_CATM:
	case T_CRNTI_UL_PRACH_POWER_FIRST:
	case T_CRNTI_UL_PRACH_POWER_SECOND:
	{
		strucTree->insertKV("peak_power", msg2info);
	}
	break;

	case T_CRNTI_PREAMBLE_ID:
	{
		quint8 pid_first = (msg2info & 0xFFFF) >> 8;
		quint8 pid_second = (msg2info & 0x00FF);
		strucTree->insertKV("PID1", pid_first);
		strucTree->insertKV("PID2", pid_second);
	}
	break;
	//case T_CRNTI_UL_PRACH_POWER_CATM:
	//case T_CRNTI_PREAMBLE_ID_CATM:
	default:
		break;
	}		
}


DdtUlPkgDecoder::DdtUlPkgDecoder(unsigned pkgId) :
DdtPkgDecoder(pkgId)
{
}

void DdtUlPkgDecoder::decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter)
{
	DdtPkgDecoder::decode(b, pkgLoc, is4Filter);

	StrucTree* nst = is4Filter ? Q_NULLPTR : strucTree;
	StrucTree* rst = EE_GET_ST(DDT_ID_ult_ct_hdr);

	if (!is4Filter)
	{
		StrucTree* header = rst->clone();
		header->decode(QByteArray(b.data(), rst->getSizeInByte()), nst, pkgLoc);
		header->setParent(strucTree);
		strucTree->appendChild(header);
		strucTree->shiftSizeInByte(header->getSizeInByte());

		if (DDT_IS_DCI_BLOCK(pkgId))
		{
			strucTree->insertKV("dciFormat", DDT_GET_DCI_FORMAT(pkgId));
		}
	}

	quint16 payloadOffset = strucTree->getSizeInByte();
	rst = EE_GET_ST(pkgId);
	if (rst->getSizeInByte() != 0)
	{
		StrucTree* payload = rst->clone();
		payload->decode(QByteArray(b.data() + payloadOffset, payload->getSizeInByte()), nst, pkgLoc);
		payload->shiftOffsetInByte(payloadOffset);
		payload->setParent(strucTree);
		strucTree->appendChild(payload);
		strucTree->shiftSizeInByte(payload->getSizeInByte());
	}
}

PkgDecoder* DdtPkgDecoderMng::getDecoder(unsigned pkgId)
{
	auto i = pkgDecoders.constFind(pkgId);
	if (i != pkgDecoders.constEnd())
	{
		return i.value();
	}

	PkgDecoder* decoder = Q_NULLPTR;
	quint16 id = STRUC_N(pkgId);
	switch (id)
	{
	case DDT_ID_BLOCK0010://cplace ue info(dummy)
		decoder = new DdtPkgDecoderB0010(pkgId);
		break;

	case DDT_ID_BLOCK0011://cplace rb info(dummy)
		decoder = new DdtPkgDecoderB0011(pkgId);
		break;
	
	case DDT_ID_BLOCK0301://multiUe01msHdr
		decoder = new DdtPkgDecoderB0301(pkgId);
		break;

	case DDT_ID_BLOCK0501://rlcHeader
		decoder = new DdtPkgDecoderB0501(pkgId);
		break;

	case DDT_ID_BLOCK0701://rrc
		decoder = new DdtPkgDecoderB0701(pkgId);
		break;

	case DDT_ID_BLOCK1801://MSG2 
		decoder = new DdtPkgDecoderB1801(pkgId);
		break;

	case DDT_ID_BLOCK2501://mtc_unicast_scd
		decoder = new DdtPkgDecoderB2501(pkgId);
		break;

	case DDT_ID_BLOCK0101://cqiUe
	case DDT_ID_BLOCK0200://common01ms
	case DDT_ID_BLOCK0201://common01ms MSG3
	case DDT_ID_BLOCK0202://common01ms MSG4
	case DDT_ID_BLOCK0300://multiUe01msHdr
	case DDT_ID_BLOCK0402://sch01ms
	case DDT_ID_BLOCK0403://timeFreqResBlockOcc
	case DDT_ID_BLOCK0800://usersSpeedHdr
	case DDT_ID_BLOCK0901://ueMimoStoreInfo
	case DDT_ID_BLOCK0A00://acqiListHdr
	case DDT_ID_BLOCK0B01://mG
	case DDT_ID_BLOCK0C01://hardInfo
	case DDT_ID_BLOCK0F01://ueCAmonitor
	case DDT_ID_BLOCK0F02://ueCAactivation
		decoder = new DdtDlPkgDecoder(pkgId);
		break;

	case DDT_ID_BLOCK1800://rach_msg2	
	case DDT_ID_BLOCK180A://catm_rach_cfg
	case DDT_ID_BLOCK180B://catm_rach_msg2
	case DDT_ID_BLOCK1900://PHICH
	case DDT_ID_BLOCK1A00://sps
	case DDT_ID_BLOCK1B00://rfns
	case DDT_ID_BLOCK1C00://meas
	case DDT_ID_BLOCK1D00://counter
	case DDT_ID_pdcch_pkt_hdr_t://unkonw dci
	case DDT_ID_mpdcch_pkt_hdr_t://unkonw mtc dci
	case DDT_ID_BLOCK280A://dci start
	case DDT_ID_BLOCK280B:
	case DDT_ID_BLOCK280C:
	case DDT_ID_BLOCK280D:
	case DDT_ID_BLOCK280E:
	case DDT_ID_BLOCK280F:
	case DDT_ID_BLOCK2810:
	case DDT_ID_BLOCK2811:
	case DDT_ID_BLOCK2812:
	case DDT_ID_BLOCK2813:
	case DDT_ID_BLOCK2814:
	case DDT_ID_BLOCK2815:
	case DDT_ID_BLOCK2816:
	case DDT_ID_BLOCK2817:
	case DDT_ID_BLOCK2818:
	case DDT_ID_BLOCK2819:
	case DDT_ID_BLOCK281A:
	case DDT_ID_BLOCK281B:
	case DDT_ID_BLOCK281C:
	case DDT_ID_BLOCK281D:
	case DDT_ID_BLOCK281E:
	case DDT_ID_BLOCK281F:
	case DDT_ID_BLOCK2820:
	case DDT_ID_BLOCK2821:
	case DDT_ID_BLOCK2822:
	case DDT_ID_BLOCK2823:
	case DDT_ID_BLOCK2824:
	case DDT_ID_BLOCK2825:
	case DDT_ID_BLOCK2826:
	case DDT_ID_BLOCK2827:
	case DDT_ID_BLOCK2840:
	case DDT_ID_BLOCK2841:
	case DDT_ID_BLOCK2842:
	case DDT_ID_BLOCK2843://dci end
		decoder = new DdtUlPkgDecoder(pkgId);
		break;

	default:
		EELOG_WARN("DdtPkgDecoderMng::getDecoder|failed to create PkgDecoder with Id (" << id << ")");
		break;
	}

	if (decoder)
	{
		pkgDecoders.insert(pkgId, decoder);
	}
	return decoder;
}
