#include "DdtPkgParser.h"
#include "StrucDDTLUT.h"
#include "DataManager.h"
#include "StrucTree.h"
#include "StrucTreeManager.h"
#include "EeProfile.h"

QDataStream& operator>>(QDataStream& dataStream, DDTUdpHeader_t& ddtUdpHeader)
{
	quint16 u16_value;
	dataStream 
		>> ddtUdpHeader.traceType
		>> ddtUdpHeader.cemCellId
		>> ddtUdpHeader.traceVersion
		>> ddtUdpHeader.lteCellIndex
		>> u16_value
		>> ddtUdpHeader.cpuOccupancy;
	ddtUdpHeader.sfn = (u16_value & 0xFFF0) >> 4;
	ddtUdpHeader.subFrameNumber = (u16_value & 0x0F);

	return dataStream;
}

QDataStream& operator>>(QDataStream& dataStream, DDTUdpHeaderCA_t& ddtUdpHeaderCA)
{
	dataStream 
		>> ddtUdpHeaderCA.ddtUdpHeader;
	dataStream 
		>> ddtUdpHeaderCA.cellEngineId
		>> ddtUdpHeaderCA.associatedCellEngineId[0]
		>> ddtUdpHeaderCA.associatedCellEngineId[1]
		>> ddtUdpHeaderCA.associatedCellEngineId[2]
		>> ddtUdpHeaderCA.associatedCellEngineId[3]
		>> ddtUdpHeaderCA.associatedCellEngineId[4]
		>> ddtUdpHeaderCA.associatedCellEngineId[5]
		>> ddtUdpHeaderCA.associatedCellEngineId[6]
		>> ddtUdpHeaderCA.associatedLteCellIdList[0]
		>> ddtUdpHeaderCA.associatedLteCellIdList[1]
		>> ddtUdpHeaderCA.associatedLteCellIdList[2]
		>> ddtUdpHeaderCA.associatedLteCellIdList[3]
		>> ddtUdpHeaderCA.associatedLteCellIdList[4]
		>> ddtUdpHeaderCA.associatedLteCellIdList[5]
		>> ddtUdpHeaderCA.associatedLteCellIdList[6]
		>> ddtUdpHeaderCA.associatedLteCellIdList[7];

	return dataStream;
}

QDataStream& operator>>(QDataStream& dataStream, ult_ct_hdr_t& ddtUlHeader)
{
	quint16 u16_value1;
	quint16 u16_value2;
	quint32 u32_value;

	dataStream 
		>> u32_value
		>> u16_value1
		>> u16_value2;

	ddtUlHeader.traceType = u32_value >> 24;
	ddtUlHeader.traceVersion = (u32_value >> 8) & 0xFFFF;
	ddtUlHeader.lteCellIndex = u32_value & 0xFF;
	ddtUlHeader.sfn = (u16_value1 & 0xFFF0) >> 4;
	ddtUlHeader.subFrameNumber = (u16_value1 & 0x0F);
	ddtUlHeader.header_filler1 = (u16_value2 & 0xFF00) >> 8;
	ddtUlHeader.p_dbg = (u16_value2 & 0x00C0) >> 6;
	ddtUlHeader.pu1 = (u16_value2 & (1 << 5)) >> 5;
	ddtUlHeader.pu2 = (u16_value2 & (1 << 4)) >> 4;
	ddtUlHeader.pd = (u16_value2 & (1 << 3)) >> 3;
	ddtUlHeader.ps = (u16_value2 & (1 << 2)) >> 2;
	ddtUlHeader.mode = u16_value2 & 0x03;

	return dataStream;
}


DdtPkgParser::DdtPkgParser(DataManager *dm):
PcapPkgParser(dm)
{
}

DdtPkgParser::~DdtPkgParser()
{	
}

void DdtPkgParser::checkFileSanity(void)
{
	EELOG_TRACE("Enter DdtPkgParser::checkFileSanity");
	
	PcapPkgParser::checkFileSanity();

	QString exeInfo;

	QDataStream inDs(&qFile);
	inDs.device()->seek(0);

	QByteArray data;
	data.reserve(EE_MAX_SIZE_IN_BYTE_PER_PAGE);
	int readSize = inDs.readRawData(data.data(), EE_MAX_SIZE_IN_BYTE_PER_PAGE);
	if (-1 == readSize)
	{
		exeInfo = 
			QObject::tr("DdtPkgParser::checkFileSanity|failed to readRawData(%1)").
			arg(readSize);
		throw EeException(exeInfo);
	}

	quint8 ddtType = EE_BE_GetQINT8(data.data() + getDdtTypePos());
	if (!isValidDdtPkg(ddtType))
	{
		exeInfo = 
			QObject::tr("DdtPkgParser::checkFileSanity|invalid DDT type(%1) at pos(%2)").
			arg(ddtType).arg(getDdtTypePos());

		QByteArray dataBuf(data.data(), 300);
		QVariant dataV(dataBuf.toHex());
		EELOG_ERROR("DdtPkgParser::checkFileSanity|=====> Data Stream <=====\n"
			<< QSTR2CSTR(dataV.toString()));

		throw EeException(exeInfo);
	}

	quint32 curByteLoc = EE_SIZE_PCAP_FILE_HEADER;
    while(curByteLoc < readSize)
    {
		quint32 pcapLen = 
			EE_LE_GetCapLenFromPcapPktHdr(data.data() + curByteLoc);

        //pcap packet headerSIZE_PCAP_PKT_HEADER
        curByteLoc += EE_SIZE_PCAP_PKT_HEADER;

        ////pcap packet payload
        ////skip ip/upd header if necessary
		quint8 ddtType = EE_BE_GetQINT8(data.data() + curByteLoc + getSizeOfEthIPUDPHdr());
		if (DDT_TYPE_ULT_SOC_TDD == ddtType || 
			DDT_TYPE_ULT_BCEM_TDD == ddtType)
        {
            techType = TECH_TYPE_TDD;
            break;
        }
		else if (DDT_TYPE_ULT_SOC_FDD == ddtType || 
			DDT_TYPE_ULT_BCEM_FDD == ddtType)
        {
			techType = TECH_TYPE_FDD;
            break;
        }
		else
		{
			EELOG_WARN("DdtPkgParser::checkFileSanity|ddt type (" 
				<< ddtType 
				<< ") pos (" 
				<< curByteLoc 
				<< ") pcap len (" 
				<< pcapLen 
				<< ")");
		}

		curByteLoc += pcapLen;
    }

	if (TECH_TYPE_NA == techType)
	{
		exeInfo = 
			QObject::tr("DdtPkgParser::checkFileSanity|failed to identify Tech type(%1)").
			arg(techType);
		throw EeException(exeInfo);
	}

	EeProfile::ddtProfile.tech = techType;
	StrucDDTLUT::setCurDciLut();

	EELOG_TRACE("Leave DdtPkgParser::checkFileSanity");
}

bool DdtPkgParser::parsePayload(CompLoc &headerLoc, CompLoc &payloadLoc)
{
	quint8 ddtType = 
		EE_BE_GetQINT8(dm->pkgPageRawData->data() + payloadLoc.pos);
	if (DDT_TYPE_DLT_BCEM_FDD_TDD == ddtType)
	{
		return parseDLT(headerLoc, payloadLoc);
	}
	else if (DDT_TYPE_ULT_BCEM_FDD == ddtType ||
		DDT_TYPE_ULT_BCEM_TDD == ddtType)
	{
		return parseULT(headerLoc, payloadLoc);
	}
	else
	{
		return true;
	}

	return true;
}

bool DdtPkgParser::isValidDdtPkg(quint8 ddtType)
{
	return ddtType == DDT_TYPE_DSP_SOC_FDD ||
		ddtType == DDT_TYPE_DSP_SOC_TDD ||
		ddtType == DDT_TYPE_DSP_SOC_TDD ||
		ddtType == DDT_TYPE_DSP_METRO_FDD ||
		ddtType == DDT_TYPE_DSP_BCEM_FDD ||
		ddtType == DDT_TYPE_DSP_BCEM_TDD ||
		ddtType == DDT_TYPE_ULT_SOC_FDD ||
		ddtType == DDT_TYPE_ULT_SOC_TDD ||
		ddtType == DDT_TYPE_ULT_METRO_FDD ||
		ddtType == DDT_TYPE_ULT_BCEM_FDD ||
		ddtType == DDT_TYPE_ULT_BCEM_TDD ||
		ddtType == DDT_TYPE_DLT_BCEM_FDD_TDD ||
		ddtType == DDT_TYPE_DLT_ECEM ||
		ddtType == DDT_TYPE_PDCP;	
}

quint16 DdtPkgParser::getDdtTypePos()
{
	switch (ethIPUDPHdrVer)
	{		
	case EE_VAL_ETH_IP_VER_V4:	
		return EE_POS_PCAP_DATA_W_ETHIPUDP_HDR_V4;

	case EE_VAL_ETH_IP_VER_V6:	
		return EE_POS_PCAP_DATA_W_ETHIPUDP_HDR_V6;

	case EE_VAL_ETH_IP_VER_NULL:
		return EE_POS_PCAP_DATA_WO_ETHIPUDP_HDR;

	default:
		Q_ASSERT(false);
		return 0xFF;
	}
}

bool DdtPkgParser::parseULT(CompLoc &headerLoc, CompLoc &payloadLoc)
{	
	QBuffer buffer;
	buffer.setData(GET_PDATA() + payloadLoc.pos, sizeof(DDTUdpHeader_t));
	buffer.open(QIODevice::ReadOnly);
	QDataStream ds(&buffer);

	ult_ct_hdr_t ult_call_trace_hdr;
	ds >> ult_call_trace_hdr;
	bool isGELR162 = ((isFdd() && (ult_call_trace_hdr.traceVersion >= DDT_VER_ULT_BCEM_FDD_V18)) || 
					  (!isFdd() && (ult_call_trace_hdr.traceVersion >= DDT_VER_ULT_BCEM_TDD_V6)));

	if (!isValidULTPacket(ult_call_trace_hdr))
	{
		EELOG_WARN("DdtPkgParser::parseULT|invalid ULT pkg ("
			<< parsedPkgNum
			<< ") traceType (" << ult_call_trace_hdr.traceType
			<< ") traceVersion (" << ult_call_trace_hdr.traceVersion
			<< ") lteCellIndex (" << ult_call_trace_hdr.lteCellIndex
			<< ") sfn (" << ult_call_trace_hdr.sfn
			<< ") subFrameNumber (" << ult_call_trace_hdr.subFrameNumber
			<< ") p_dbg (" << ult_call_trace_hdr.p_dbg
			<< ") pu1 (" << ult_call_trace_hdr.pu1
			<< ") pu2 (" << ult_call_trace_hdr.pu2
			<< ") pd (" << ult_call_trace_hdr.pd
			<< ") ps (" << ult_call_trace_hdr.ps
			<< ") mode (" << ult_call_trace_hdr.mode
			<< ")");

		return true; //just ignore
	}

	EeStrucId id;
	id.type = ult_call_trace_hdr.traceType;
	id.ver = ult_call_trace_hdr.traceVersion;

	PkgLoc pkgLocCom;
	pkgLocCom.timePos = headerLoc.pos;	
	pkgLocCom.headerPos = payloadLoc.pos;
	pkgLocCom.headerLen = sizeof(ult_ct_hdr_t);
	Q_ASSERT(pkgLocCom.headerLen <= 0xFF);

	id.id = DDT_ID_BLOCK3000;//ult_call_trace
	StrucTree *rst = EE_GET_ST(id.getSID());
	if (rst->getSizeInByte() != payloadLoc.len)
	{
		EELOG_ERROR("DdtPkgParser::parseULT|invalid size ("
			<< payloadLoc.len
			<< ") expected size ("
			<< rst->getSizeInByte()
			<< ")");

		return false;
	}

	quint16 pos_misc =
		rst->getOffsetInByte("misc");
	id.id = DDT_ID_BLOCK1E00; //misc
	StrucTree* miscRst = EE_GET_ST(id.getSID());
	quint16 sizeOfMisc = miscRst->getSizeInByte();
	StrucTree* miscRstClone = miscRst->clone();
	miscRstClone->decode(QByteArray(GET_PDATA() + payloadLoc.pos + pos_misc, sizeOfMisc), 
		miscRstClone);
	quint16 value_pdcch_dump_size = miscRstClone->getFieldValue("pdcch_dump_size") * 4;
	quint16 value_mpdcch_dump_size = 0;
	quint16 pos_a_ltx_mpdcch_buf = 0;
	quint16 pos_mtc_unicast_scd_in = 0;
	if (isGELR162)
	{
		value_mpdcch_dump_size =
			miscRstClone->getFieldValue("mpdcch_dump_size") * 4;

		pos_a_ltx_mpdcch_buf =
			rst->getOffsetInByte("a_ltx_mpdcch_buf[0]");

		pos_mtc_unicast_scd_in =
			rst->getOffsetInByte("mtc_unicast_scd_in");
	}
	delete miscRstClone;

	quint16 pos_call_trace_rach_msg2 =
		rst->getOffsetInByte("call_trace_rach_msg2");
	quint16 pos_call_trace_phich_rf =
		rst->getOffsetInByte("call_trace_phich_rf[0]");
	quint16 pos_a_ltx_pdcch_buf =
		rst->getOffsetInByte("a_ltx_pdcch_buf[0]");
	quint16 pos_call_trace_sps_infos =
		rst->getOffsetInByte("call_trace_sps_infos");
	quint16 pos_srs_snr_ue =
		rst->getOffsetInByte("srs_snr_ue[0]");
	quint16 pos_call_trace_reason_for_not_scheduled =
		rst->getOffsetInByte("call_trace_reason_for_not_scheduled");
	quint16 pos_call_trace_long_term_ue_observation =
		rst->getOffsetInByte("call_trace_long_term_ue_observation[0]");
	quint16 pos_call_trace_counters =
		rst->getOffsetInByte("call_trace_counters");

	id.id = DDT_ID_BLOCK1801; //rach_msg2_misc
	rst = EE_GET_ST(id.getSID());
	quint16 sizeOfMsg2 = rst->getSizeInByte();
	StrucTree* msg2stClone = rst->clone();
	msg2stClone->decode(QByteArray(GET_PDATA() + payloadLoc.pos + pos_call_trace_rach_msg2, 
		sizeOfMsg2), 
		msg2stClone);
	quint16 msg2_rnti = msg2stClone->getFieldValue("rnti");
	delete msg2stClone;
	msg2stClone = Q_NULLPTR;
	if (msg2_rnti != T_CRNTI_MSG2_INVALID)
	{
		if (T_CRNTI_UL_PRACH_CONFIG_CATM == msg2_rnti)
		{
			id.id = DDT_ID_BLOCK180A; //catm_rach_cfg
		}
		else if (msg2_rnti > T_CRNTI_PREAMBLE_ID_CATM)
		{
			id.id = DDT_ID_BLOCK1800; //rach_msg2
			if (isGELR162)
			{
				rst = EE_GET_ST(id.getSID());					
				msg2stClone = rst->clone();
				msg2stClone->decode(QByteArray(GET_PDATA() + payloadLoc.pos + pos_call_trace_rach_msg2, 
					sizeOfMsg2), 
					msg2stClone);
				quint8 r_flag = msg2stClone->getFieldValue("r_flag");
				delete msg2stClone;
				if (r_flag)
				{
					id.id = DDT_ID_BLOCK180B;//catm_rach_msg2					
				}
			}
		}
		else
		{
			//keep rach_msg2_misc
		}

		pkgLocCom.payloadPos = payloadLoc.pos + pos_call_trace_rach_msg2;
		pkgLocCom.payloadLen = rst->getSizeInByte();	
		pkgLocCom.misc = id.getSID();
		dm->insertPkgLoc(pkgLocCom);
	}

	id.id = DDT_ID_BLOCK1900; //phich
	rst = EE_GET_ST(id.getSID());
	quint8 phich_dem = 13;
	for(quint8 idx = 0; idx < phich_dem; ++idx)
	{
		pkgLocCom.payloadPos = payloadLoc.pos + pos_call_trace_phich_rf +
			idx * rst->getSizeInByte();
		pkgLocCom.payloadLen = rst->getSizeInByte();
		pkgLocCom.misc = id.getSID();
		dm->insertPkgLoc(pkgLocCom);
	}

	//////pdcch dump/
	if (value_pdcch_dump_size > 0)
	{
		rst = EE_GET_ST(DDT_ID_pdcch_pkt_hdr_dummy);//pdcch_pkt_hdr_dummy_t		
		StrucTree* st = Q_NULLPTR;
		quint16 next_dci_pos = pos_a_ltx_pdcch_buf;
		quint16 trbk_size = 0;
		quint16 trbk_size_in_byte = 0;
		quint8 flag_format_0_1A = 0;		
		do
		{
			st = rst->clone();
			QByteArray dci(GET_PDATA() + payloadLoc.pos + next_dci_pos, 
				rst->getSizeInByte());			
			st->decode(dci, st);
			trbk_size = st->getFieldValue("trbk_size");
			trbk_size_in_byte = ((trbk_size + 31) >> 5) << 2;
			flag_format_0_1A = st->getFieldValue("flag_format_0_1A");
			flag_format_0_1A = flag_format_0_1A ? DDT_DCI_FORMAT1A : DDT_DCI_FORMAT0;
			delete st;

			quint16 dciId = DDT_GET_DCI_ID(trbk_size, flag_format_0_1A);
			if (DDT_ID_BLOCKINVALID == dciId)
			{
				EELOG_WARN("DdtPkgParser::parseULT|no dci for trbk_size (" 
					<< trbk_size 
					<< ") flag_format_0_1A (" 
					<< flag_format_0_1A 
					<< ")");

				pkgLocCom.payloadPos = payloadLoc.pos + next_dci_pos;
				pkgLocCom.payloadLen = trbk_size_in_byte + 8;			
				pkgLocCom.misc = DDT_ID_pdcch_pkt_hdr;
				dm->insertPkgLoc(pkgLocCom);				
			}
			else
			{
				id.id = dciId;

				pkgLocCom.payloadPos = payloadLoc.pos + next_dci_pos;
				pkgLocCom.payloadLen = trbk_size_in_byte + 8;				
				pkgLocCom.misc = id.getSID();
				dm->insertPkgLoc(pkgLocCom);
			}
		
			next_dci_pos += pkgLocCom.payloadLen;
			value_pdcch_dump_size -= pkgLocCom.payloadLen;
		} while (value_pdcch_dump_size > 0);
	}

	//////mpdcch dump
	if (value_mpdcch_dump_size > 0)
	{
		rst = EE_GET_ST(DDT_ID_mpdcch_pkt_hdr_dummy);//mpdcch_pkt_hdr_dummy_t
		StrucTree* st = Q_NULLPTR;
		quint16 next_dci_pos = pos_a_ltx_mpdcch_buf;
		quint16 trbk_size = 0;
		quint16 trbk_size_in_byte = 0;
		quint8 flag_dci_format = 0;
		do
		{
			st = rst->clone();
			QByteArray dci(GET_PDATA() + payloadLoc.pos + next_dci_pos, 
				rst->getSizeInByte());			
			st->decode(dci, st);
			trbk_size = st->getFieldValue("trbk_size");
			trbk_size_in_byte = ((trbk_size + 31) >> 5) << 2;
			flag_dci_format = st->getFieldValue("flag_dci_format");
			delete st;

			if (RES_MPDCCH_N_BITS_DCI_FORMAT6_0A_10MHZ_FDD == trbk_size)
			{
				id.id = RES_MPDCCH_DCI_FORMAT_FLAG_FORMAT6_1A_DIFF == flag_dci_format ?
				DDT_ID_BLOCK2841 : DDT_ID_BLOCK2840; //pdcch_pkt_format6_1A_fdd_t : pdcch_pkt_format6_0A_fdd_t

				pkgLocCom.payloadPos = payloadLoc.pos + next_dci_pos;
				pkgLocCom.payloadLen = trbk_size_in_byte + 16;			
				pkgLocCom.misc = id.getSID();
				dm->insertPkgLoc(pkgLocCom);
			}
			else if (RES_MPDCCH_N_BITS_DCI_FORMAT6_2_10MHZ_FDD == trbk_size)
			{
				id.id = RES_MPDCCH_DCI_FORMAT_FLAG_FORMAT6_2_PAGING_DIFF == flag_dci_format ?
				DDT_ID_BLOCK2842 : DDT_ID_BLOCK2843; //pdcch_pkt_format6_2_P_10MHZ_fdd_t : pdcch_pkt_format6_2_10MHZ_fdd_t

				pkgLocCom.payloadPos = payloadLoc.pos + next_dci_pos;
				pkgLocCom.payloadLen = trbk_size_in_byte + 16;				
				pkgLocCom.misc = id.getSID();
				dm->insertPkgLoc(pkgLocCom);
			}
			else
			{
				pkgLocCom.payloadPos = payloadLoc.pos + next_dci_pos;
				pkgLocCom.payloadLen = trbk_size_in_byte + 16;				
				pkgLocCom.misc = DDT_ID_mpdcch_pkt_hdr;
				dm->insertPkgLoc(pkgLocCom);
			}

			next_dci_pos += pkgLocCom.payloadLen;
			value_mpdcch_dump_size -= pkgLocCom.payloadLen;
		} while (value_mpdcch_dump_size > 0);
	}

	id.id = DDT_ID_BLOCK1A00;//call_trace_sps_infos
	rst = EE_GET_ST(id.getSID());
	quint8 sps_dem = 3;
	for(quint8 idx = 0; idx < sps_dem; ++idx)
	{
		pkgLocCom.payloadPos = payloadLoc.pos + pos_call_trace_sps_infos + 
			idx * rst->getSizeInByte();
		pkgLocCom.payloadLen = rst->getSizeInByte();		
		pkgLocCom.misc = id.getSID();
		dm->insertPkgLoc(pkgLocCom);
	}

	////srs_snr_ue

	////RFNS
	id.id = DDT_ID_BLOCK1B00; //<< call_trace_reason_for_not_scheduled
	rst = EE_GET_ST(id.getSID());

	pkgLocCom.payloadPos = payloadLoc.pos + pos_call_trace_reason_for_not_scheduled;
	pkgLocCom.payloadLen = rst->getSizeInByte();
	pkgLocCom.misc = id.getSID();
	dm->insertPkgLoc(pkgLocCom);

	//meas
	id.id = DDT_ID_BLOCK1C00; //<< call_trace_long_term_ue_observation
	rst = EE_GET_ST(id.getSID());
	quint8 meas_dem = 4;
	for (quint8 idx = 0; idx < meas_dem; ++idx)
	{
		pkgLocCom.payloadPos = payloadLoc.pos + pos_call_trace_long_term_ue_observation + 
			idx * rst->getSizeInByte();
		pkgLocCom.payloadLen = rst->getSizeInByte();
		pkgLocCom.misc = id.getSID();		
		quint16 rnti =
			qFromBigEndian<quint16>((const uchar*)((char*)(GET_PDATA()) + pkgLocCom.payloadPos));
		if (rnti > 0)
		{
			dm->insertPkgLoc(pkgLocCom);
		}
	}

	////counter
	id.id = DDT_ID_BLOCK1D00; //<< call_trace_counters
	rst = EE_GET_ST(id.getSID());

	pkgLocCom.payloadPos = payloadLoc.pos + pos_call_trace_counters;
	pkgLocCom.payloadLen = rst->getSizeInByte();
	pkgLocCom.misc = id.getSID();
	dm->insertPkgLoc(pkgLocCom);

	///mtc_unicast_scd_in
	if (isGELR162)
	{
		id.id = DDT_ID_BLOCK2500;//mtc_unicast_scd_in
		rst = EE_GET_ST(id.getSID());
		quint16 sizeOfMtc_unicast_scd_in = rst->getSizeInByte();
		StrucTree* st = rst->clone();
		QByteArray schin(GET_PDATA() + payloadLoc.pos + pos_mtc_unicast_scd_in, 
			sizeOfMtc_unicast_scd_in);
		st->decode(schin, st);

		quint8 schNum = 0;
		quint8 idx;
		quint16 rnti;
		QString fieldName;
		for (idx = 0; idx < 4; ++idx)
		{
			fieldName = QString("rnti[%1]").arg(idx);
			rnti = st->getFieldValue(fieldName);
			if (rnti != 0) schNum++;
		}
		delete st;

		id.id = DDT_ID_BLOCK2501;//mtc_unicast_scd_in
		for (idx = 0; idx < schNum; ++idx)
		{
			pkgLocCom.headerLen |= idx << 8;
			pkgLocCom.payloadPos = payloadLoc.pos + pos_mtc_unicast_scd_in;
			pkgLocCom.payloadLen = sizeOfMtc_unicast_scd_in;
			pkgLocCom.misc = id.getSID();
			dm->insertPkgLoc(pkgLocCom);

			pkgLocCom.headerLen = EE_PKG_HDR_LEN(pkgLocCom.headerLen);
		}
	}

	return true;
}

bool DdtPkgParser::parseDLT(CompLoc &headerLoc, CompLoc &payloadLoc)
{	
	QBuffer buffer;
	buffer.setData(dm->pkgPageRawData->data() + payloadLoc.pos, sizeof(DDTUdpHeader_t));
	buffer.open(QIODevice::ReadOnly);
	QDataStream ds(&buffer);
	DDTUdpHeader_t ddtUdpHeader;
	ds >> ddtUdpHeader;

	if (!isValidDLTPacket(ddtUdpHeader))
	{
		EELOG_WARN("DdtPkgParser::parseDLT|ignore invalid DLT PKG (" 
			<< parsedPkgNum
			<< ") - traceType (" 
			<< ddtUdpHeader.traceType
			<< ") cemCellId (" 
			<< ddtUdpHeader.cemCellId
			<< ") traceVersion (" 
			<< ddtUdpHeader.traceVersion
			<< ") lteCellIndex (" 
			<< ddtUdpHeader.lteCellIndex
			<< ") sfn (" 
			<< ddtUdpHeader.sfn
			<< ") subFrameNumber (" 
			<< ddtUdpHeader.subFrameNumber
			<< ")");

		return true; //just ignore
	}

	quint32 blockIdOffset = sizeof(DDTUdpHeader_t);
	if (0 == ddtUdpHeader.sfn && 
		0 == ddtUdpHeader.subFrameNumber)
	{
		blockIdOffset = sizeof(DDTUdpHeaderCA_t);
	}
	else if (1 == (ddtUdpHeader.sfn & 0x3FF) && 
		    (0 == ddtUdpHeader.subFrameNumber))
	{
		if ((isFdd() && 
			 ddtUdpHeader.traceVersion >= DDT_VER_DLT_BCEM_FDD_TDD_V12) ||
			(!isFdd() && 
			 ddtUdpHeader.traceVersion >= DDT_VER_ULT_BCEM_TDD_V6))
		{
			if (isFdd() && 
				ddtUdpHeader.traceVersion >= DDT_VER_DLT_BCEM_FDD_TDD_V13)
			{
				blockIdOffset = sizeof(DDTUdpHeaderCATM_171_t);
			}
			else
			{
				blockIdOffset = sizeof(DDTUdpHeaderCATM_162_t);
			}
		}
	}

	EeStrucId id;
	id.type = 
		isFdd() ? ddtUdpHeader.traceType : DDT_TYPE_DLT_BCEM_TDD_INTERNAL;
	id.ver = ddtUdpHeader.traceVersion;	

	PkgLoc pkgLocComm;
	pkgLocComm.timePos = headerLoc.pos;
	pkgLocComm.headerPos = payloadLoc.pos;
	pkgLocComm.headerLen = blockIdOffset;

	CompLoc blockLoc;
	blockLoc.pos = payloadLoc.pos + blockIdOffset;
	blockLoc.len = 0;

	quint32 payloadLoclastPos = payloadLoc.pos + payloadLoc.len;
	quint32 blockPosIn;
	quint32 blockPosOut;
	quint8 blockId;
	int rc = false;

	do
	{
		blockPosIn = blockLoc.pos;
		blockId = EE_BE_GetQINT8(dm->pkgPageRawData->data() + blockLoc.pos);
		if (blockId > DDT_DLT_BLOCK_MAX)
		{
			errorStr = QObject::tr("DdtPkgParser::parseDLT|invalid block (%1) at pos (%2)")
				.arg(blockId)
				.arg(blockLoc.pos);

			QVariant v(QByteArray(dm->pkgPageRawData->data() + blockPosIn, 30).toHex());
			EELOG_ERROR("DdtPkgParser::parseDLT|ERROR block ("
				<< blockId
				<< ") blockPosIn ("
				<< blockPosIn
				<< ") blockPosOut ("
				<< blockPosOut
				<< ") payloadLen ("
				<< payloadLoc.len
				<< ") payloadLoclastPos ("
				<< payloadLoclastPos
				<< ") parsedPkgNum ("
				<< parsedPkgNum
				<< ") BLOCK data stream (" << QSTR2CSTR(v.toString())
				<< ")");

			EELOG_ERROR("DdtPkgParser::parseDLT|traceType ("
				<< ddtUdpHeader.traceType
				<< ") cemCellId ("
				<< ddtUdpHeader.cemCellId
				<< ") traceVersion ("
				<< ddtUdpHeader.traceVersion
				<< ") sfn ("
				<< ddtUdpHeader.sfn
				<< ") subFrameNumber ("
				<< ddtUdpHeader.subFrameNumber
				<< ") blockIdOffset ("
				<< blockIdOffset
				<< ")");

			QVariant pcapV(QByteArray(dm->pkgPageRawData->data() + pkgLocComm.headerPos, payloadLoc.len).toHex()) ;
			EELOG_ERROR("DdtPkgParser::parseDLT|=====> PCAP Data Stream <=====\n" 
				<< QSTR2CSTR(pcapV.toString()));

			return false;
		}
		//else
		//{
		//	if (parsedPkgNum == 91449)
		//	{
		//		EELOG_DEBUG("DdtPkgParser::parseDLT|blockId (" << blockId << ") blockPosIn (" << blockPosIn << ")");
		//	}
		//}
		
		switch (blockId)
		{
		case 0:
			rc = parseDLTblock00(id, pkgLocComm, blockLoc);
			break;

		case 1:
			rc = parseDLTblock01(id, pkgLocComm, blockLoc);
			break;

		case 2:
			rc = parseDLTblock02(id, pkgLocComm, blockLoc);
			break;

		case 3:
			rc = parseDLTblock03(id, pkgLocComm, blockLoc);
			break;

		case 4:
			rc = parseDLTblock04(id, pkgLocComm, blockLoc);
			break;

		case 5:
			rc = parseDLTblock05(id, pkgLocComm, blockLoc);
			break;

		case 6:
			rc = parseDLTblock06(id, pkgLocComm, blockLoc);
			break;

		case 7:
			rc = parseDLTblock07(id, pkgLocComm, blockLoc);
			break;
		case 8:
			rc = parseDLTblock08(id, pkgLocComm, blockLoc);
			break;
		case 9:

			rc = parseDLTblock09(id, pkgLocComm, blockLoc);
			break;

		case 10:
			rc = parseDLTblock10(id, pkgLocComm, blockLoc);
			break;

		case 11:
			rc = parseDLTblock11(id, pkgLocComm, blockLoc);
			break;

		case 12:
			rc = parseDLTblock12(id, pkgLocComm, blockLoc);
			break;

		case 13:
			rc = parseDLTblock13(id, pkgLocComm, blockLoc);
			break;

		case 14:
			rc = parseDLTblock14(id, pkgLocComm, blockLoc);
			break;

		case 15:
			rc = parseDLTblock15(id, pkgLocComm, blockLoc);
			break;

		default:
			Q_ASSERT(0);
			break;
		}

		if (false == rc)
		{
			errorStr = QObject::tr("DdtPkgParser::parseDLT|failed to decode block (%1) at pos (%2:%3:%4 - %5:%6)")
				.arg(blockId)
				.arg(blockPosIn)
				.arg(blockPosOut)
				.arg(blockPosOut - blockPosIn)
				.arg(payloadLoc.len)
				.arg(payloadLoclastPos);

			EELOG_ERROR(QSTR2CSTR(errorStr));

			return false;
		}

		blockPosOut = blockLoc.pos;

	} while (blockLoc.pos < payloadLoclastPos);

	return true;
}

bool DdtPkgParser::parseDLTblock00(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc)
{	
	CompLoc blockLocOrig = blockLoc;
	quint16 whileBlockSize = 0;
	id.id = DDT_ID_BLOCK0000;//cplaneHdr
	StrucTree* rst = EE_GET_ST(id.getSID());		
	StrucTree* st = rst->clone();
	quint16 sizeOfCplaneHdr = st->getSizeInByte();
	st->decode(QByteArray(GET_PDATA() + blockLoc.pos, sizeOfCplaneHdr), st);
	quint8 nbOfAddUe = st->getFieldValue("nbOfAddUe");
	quint8 nbOfDelUeorReportUe = st->getFieldValue("nbOfDelUeorReportUe");
	quint8 TAG_ForNewLen = st->getFieldValue("TAG_ForNewLen");	
	quint16 length = st->getFieldValue("length");
	length = TAG_ForNewLen ? TAG_ForNewLen : length;
	delete st;

	blockLoc.pos += sizeOfCplaneHdr;
	whileBlockSize += sizeOfCplaneHdr;
	if (nbOfAddUe > 0)
	{
		int number = 0;
		for (number = 0; number < nbOfAddUe; ++number)
		{
			id.id = DDT_ID_BLOCK0001;//addBearerHdr
			rst = EE_GET_ST(id.getSID());
			st = rst->clone();
			quint16 sizeOfAddBearerHdr = st->getSizeInByte();
			st->decode(QByteArray(GET_PDATA() + blockLoc.pos, sizeOfAddBearerHdr), st);
			quint8 bearerNumber = st->getFieldValue("bearerNumber");
			quint8 setupFlag = st->getFieldValue("setupFlag");
			delete st;
			st = Q_NULLPTR;

			id.id = DDT_ID_BLOCK0002; //ueCfgInfo
			rst = EE_GET_ST(id.getSID());
			quint16 sizeOfUeCfgInfo = rst->getSizeInByte();
			id.id = DDT_ID_BLOCK0003; //ueModif
			rst = EE_GET_ST(id.getSID());
			quint16 sizeOfUeModif = rst->getSizeInByte();
			id.id = DDT_ID_BLOCK0004; //ueSetup;
			rst = EE_GET_ST(id.getSID());
			quint16 sizeOfUeSetup = rst->getSizeInByte();
			id.id = DDT_ID_BLOCK0005; //bearerInfo;
			rst = EE_GET_ST(id.getSID());
			quint16 sizeOfBearerInfo = rst->getSizeInByte();

			bool isUeSetup = 0;
			quint16 size = 0;
			switch (setupFlag)
			{
			case DDT_UE_SETUP_TYPE_0:
				size = sizeOfUeCfgInfo;
				break;

			case DDT_UE_SETUP_TYPE_1:
				{
					size = sizeOfUeCfgInfo;
					isUeSetup = 1;

					id.id = DDT_ID_BLOCK000B;//srInfo
					rst = EE_GET_ST(id.getSID());
					StrucTree* cloneUeSetupHdr = rst->clone();
					quint16 sizeOfUeSetupHdr = cloneUeSetupHdr->getSizeInByte();
					cloneUeSetupHdr->decode(QByteArray(GET_PDATA() + 
						blockLoc.pos + 
						sizeOfAddBearerHdr + 
						sizeOfUeCfgInfo, 
						sizeOfUeSetupHdr), cloneUeSetupHdr);
					quint8 isCatm = cloneUeSetupHdr->getFieldValue("reserved");
					delete cloneUeSetupHdr;

					if (isCatm)
					{
						id.id = DDT_ID_BLOCK000A; //catm ueSetup;
						rst = EE_GET_ST(id.getSID());
						sizeOfUeSetup = rst->getSizeInByte();
					}
				}

				break;

			case DDT_UE_SETUP_TYPE_2:
				size = sizeOfUeModif;
				break;

			case DDT_UE_SETUP_TYPE_3:
				size = sizeOfUeCfgInfo;
				break;

			default:
				size = 0;
				break;
			}

			size = size +
				isUeSetup * sizeOfUeSetup +
				bearerNumber * sizeOfBearerInfo +
				sizeOfAddBearerHdr;

			id.id = DDT_ID_BLOCK0010;
			pkgLocCom.payloadPos = blockLoc.pos;
			pkgLocCom.payloadLen = size;
			pkgLocCom.misc = id.getSID();			
			dm->insertPkgLoc(pkgLocCom);

			blockLoc.pos += size;
			whileBlockSize += size;
		}
	}

	if (nbOfDelUeorReportUe > 0)
	{
		int number = 0;
		for (number = 0; number < nbOfDelUeorReportUe; ++number)
		{
			id.id = DDT_ID_BLOCK0006;//delBearerHdr
			rst = EE_GET_ST(id.getSID());
			st = rst->clone();
			quint16 sizeOfDelBearerHdr = st->getSizeInByte();
			st->decode(QByteArray(GET_PDATA() + blockLoc.pos, sizeOfDelBearerHdr), st);
			quint8 bearerNumber = st->getFieldValue("bearerNumber");
			quint8 type = st->getFieldValue("type");
			delete st;
			st = Q_NULLPTR;

			/* 0 del bearer,
			* 1:Modem report,
			* 2:report uls l1 oos,
			* other reserved */
			if (DDT_RB_DEL_TYPE_0 == type)
			{
				id.id = DDT_ID_BLOCK0007;//delBearerInfo
				rst = EE_GET_ST(id.getSID());
				quint16 sizeOfDelBearerInfo = rst->getSizeInByte();
				quint16 size = sizeOfDelBearerInfo * bearerNumber + sizeOfDelBearerHdr;

				id.id = DDT_ID_BLOCK0011;
				pkgLocCom.payloadPos = blockLoc.pos;
				pkgLocCom.payloadLen = size;				
				pkgLocCom.misc = id.getSID();				
				dm->insertPkgLoc(pkgLocCom);

				blockLoc.pos += size;
				whileBlockSize += size;

			}
			else if (DDT_RB_DEL_TYPE_1 == type)
			{
				id.id = DDT_ID_BLOCK0009; //rLCFailure
				rst = EE_GET_ST(id.getSID());
				quint16 sizeOfRLCFailure = rst->getSizeInByte();
				quint16 size = sizeOfRLCFailure;

				id.id = DDT_ID_BLOCK0011;
				pkgLocCom.payloadPos = blockLoc.pos;
				pkgLocCom.payloadLen = size;
				pkgLocCom.misc = id.getSID();				
				dm->insertPkgLoc(pkgLocCom);

				blockLoc.pos += size;
				whileBlockSize += size;
			}
			else if (DDT_RB_DEL_TYPE_2 == type)
			{
				id.id = DDT_ID_BLOCK0008; //ulL1OoS
				rst = EE_GET_ST(id.getSID());
				quint16 sizeOfUlL1OoS = rst->getSizeInByte();
				quint16 size = sizeOfUlL1OoS;

				id.id = DDT_ID_BLOCK0011;
				pkgLocCom.payloadPos = blockLoc.pos;
				pkgLocCom.payloadLen = size;				
				pkgLocCom.misc = id.getSID();				
				dm->insertPkgLoc(pkgLocCom);

				blockLoc.pos += size;
				whileBlockSize += size;
			}
			else
			{
				Q_ASSERT(false);
			}
		}
	}

	Q_ASSERT(((length + sizeOfCplaneHdr) == whileBlockSize));

	blockLoc.pos = blockLocOrig.pos + BYTE_ALIGN_4B(whileBlockSize);

	return true;
}

bool DdtPkgParser::parseDLTblock01(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc)
{
	CompLoc blockLocOrig = blockLoc;
	quint16 whileBlockSize = 0;

	id.id = DDT_ID_BLOCK0100;//cqiHdr;
	StrucTree* rst = EE_GET_ST(id.getSID());
	StrucTree* st = rst->clone();
	quint16 sizeOfCqiHdr = st->getSizeInByte();
	st->decode(QByteArray(GET_PDATA() + blockLoc.pos, sizeOfCqiHdr), st);
	quint8 nbOfUe = st->getFieldValue("nbOfUe");
	delete st;

	blockLoc.pos += sizeOfCqiHdr;
	whileBlockSize += sizeOfCqiHdr;

	if (nbOfUe > 0)
	{
		id.id = DDT_ID_BLOCK0101;//cqiUe
		rst = EE_GET_ST(id.getSID());
		quint16 sizeOfCqiUe = rst->getSizeInByte();
		int number = 0;
		for (number = 0; number < nbOfUe; ++number)
		{
			pkgLocCom.payloadPos = blockLoc.pos;
			pkgLocCom.payloadLen = sizeOfCqiUe;			
			pkgLocCom.misc = id.getSID();
			dm->insertPkgLoc(pkgLocCom);

			blockLoc.pos += sizeOfCqiUe;
			whileBlockSize += sizeOfCqiUe;
		}
	}

	blockLoc.pos = blockLocOrig.pos + BYTE_ALIGN_4B(whileBlockSize);

	return true;
}

bool DdtPkgParser::parseDLTblock02(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc)
{
	CompLoc blockLocOrig = blockLoc;
	quint16 whileBlockSize = 0;

	id.id = DDT_ID_BLOCK0200;//common01ms;
	StrucTree* rst = EE_GET_ST(id.getSID());
	quint16 sizeOfCommon01ms = rst->getSizeInByte();	
	quint16 msg4rnti = EE_BE_GetQUINT16(GET_PDATA() + blockLoc.pos + sizeOfCommon01ms - 2);
	if (0 == msg4rnti)
	{
		id.id = DDT_ID_BLOCK0201;
	}
	else
	{
		id.id = DDT_ID_BLOCK0202;
	}

	pkgLocCom.payloadPos = blockLoc.pos;
	pkgLocCom.payloadLen = sizeOfCommon01ms;
	pkgLocCom.misc = id.getSID();
	dm->insertPkgLoc(pkgLocCom);

	blockLoc.pos += sizeOfCommon01ms;
	whileBlockSize += sizeOfCommon01ms;
	blockLoc.pos = blockLocOrig.pos + BYTE_ALIGN_4B(whileBlockSize);

	return true;
}

bool DdtPkgParser::parseDLTblock03(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc)
{
	CompLoc blockLocOrig = blockLoc;
	quint16 whileBlockSize = 0;

	id.id = DDT_ID_BLOCK0300;//multiUe01msHdr;
	StrucTree* rst = EE_GET_ST(id.getSID());
	StrucTree* st = rst->clone();
	quint16 sizeOfMultiUe01msHdr = st->getSizeInByte();

	st->decode(QByteArray(GET_PDATA() + blockLoc.pos, sizeOfMultiUe01msHdr), st);
	quint8 nbOfUe = st->getFieldValue("nbOfUe");
	delete st;

	quint16 size = sizeOfMultiUe01msHdr + nbOfUe * sizeof(quint16)+((nbOfUe + 1) >> 1);

	if (nbOfUe > 0)
	{
		Q_ASSERT(nbOfUe <= 0xF);		
		id.id = DDT_ID_BLOCK0301;//multiUe01msBearerEligible;
		for (int idx = 0; idx < nbOfUe; ++idx)
		{	
			pkgLocCom.headerLen |= ((nbOfUe << 4|idx) << 8);
			pkgLocCom.payloadPos = blockLoc.pos;
			pkgLocCom.payloadLen = size;
			pkgLocCom.misc = id.getSID();
			dm->insertPkgLoc(pkgLocCom);

			pkgLocCom.headerLen = EE_PKG_HDR_LEN(pkgLocCom.headerLen);
		}		
	}

	blockLoc.pos += size;
	whileBlockSize += size;
	blockLoc.pos = blockLocOrig.pos + BYTE_ALIGN_4B(whileBlockSize);
	
	return true;
}

bool DdtPkgParser::parseDLTblock04(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc)
{
	CompLoc blockLocOrig = blockLoc;
	quint16 whileBlockSize = 0;

	id.id = DDT_ID_BLOCK0400;//sch01msHdr;
	StrucTree* rst = EE_GET_ST(id.getSID());
	quint16 sizeOfSch01msHdr = rst->getSizeInByte();
	blockLoc.pos += sizeOfSch01msHdr;

	id.id = DDT_ID_BLOCK0403;//<< v10_b4_3_t timeFreqResBlockOcc
	rst = EE_GET_ST(id.getSID());
	quint16 sizeOfTimeFreqResBlockOcc = rst->getSizeInByte();

#define PRBused    0xFD
#define PRBunused  0xFE
#define PRBinvalid 0xFF
#define RBG_PBCH   26
#define RBG_DBCH   27
#define RBG_PCH    28
#define RBG_SRB0   29
#define RBG_OCNS   30

	bool isShowTimeFreqResBlockOccMatrix = false;
	quint16 lastUeId = PRBinvalid;
	quint16 curUeId = PRBinvalid;

	QMap<quint16, quint16> uelist;
	quint8 nbOfSchUe = 0;
	quint8 rbgIdx = 0;
	for (rbgIdx = 0; rbgIdx < sizeOfTimeFreqResBlockOcc; ++rbgIdx)
	{
		curUeId = *(const uchar*)(GET_PDATA() + (blockLoc.pos + rbgIdx));
		if (curUeId != lastUeId)
		{
			if (curUeId == RBG_SRB0)
			{
				isShowTimeFreqResBlockOccMatrix = true;
			}
			if (curUeId != PRBused &&
				curUeId != PRBunused &&
				curUeId != PRBinvalid &&
				curUeId != RBG_PBCH &&
				curUeId != RBG_DBCH &&
				curUeId != RBG_PCH &&
				curUeId != RBG_SRB0 &&
				curUeId != RBG_OCNS)
			{
				isShowTimeFreqResBlockOccMatrix = true;
				if (!uelist.contains(curUeId))
				{
					uelist.insert(curUeId, 0);
				}
			}
		}

		lastUeId = curUeId;
	}

	if (isShowTimeFreqResBlockOccMatrix)
	{
		////CURRENTLY DISABLE IT !!!		
		//pkgLocCom.payloadPos = blockLoc.pos;
		//pkgLocCom.payloadLen = sizeOfTimeFreqResBlockOcc;
		//pkgLocCom.misc = id.getSID();
		//dm->insertPkgLoc(pkgLocCom);
	}

	blockLoc.pos += sizeOfTimeFreqResBlockOcc;
	nbOfSchUe = uelist.size();
	if (nbOfSchUe > 0)
	{
		id.id = DDT_ID_BLOCK0402;//<< v10_b4_3_t sch01ms
		rst = EE_GET_ST(id.getSID());
		quint16 sizeOfSch01ms = rst->getSizeInByte();

		int number = 0;
		for (number = 0; number < nbOfSchUe; ++number)
		{
			pkgLocCom.payloadPos = blockLoc.pos;
			pkgLocCom.payloadLen = sizeOfSch01ms;			
			pkgLocCom.misc = id.getSID();
			dm->insertPkgLoc(pkgLocCom);

			blockLoc.pos += sizeOfSch01ms;
		}
	}

	id.id = DDT_ID_BLOCK0401;//sch01msBloc;
	rst = EE_GET_ST(id.getSID());
	quint16 sizeOfSch01msBloc = rst->getSizeInByte();
	whileBlockSize += sizeOfSch01msBloc;

	blockLoc.pos = blockLocOrig.pos + BYTE_ALIGN_4B(whileBlockSize);

	return true;
}

bool DdtPkgParser::parseDLTblock05(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc)
{
	CompLoc blockLocOrig = blockLoc;
	quint16 whileBlockSize = 0;

	id.id = DDT_ID_BLOCK0500;//rlc;
	StrucTree* rst = EE_GET_ST(id.getSID());
	StrucTree* st = rst->clone();
	quint16 sizeOfRlc = st->getSizeInByte();
	st->decode(QByteArray(GET_PDATA() + blockLoc.pos, sizeOfRlc), st);
	quint16 RLC_HeadersLength = st->getFieldValue("RLC_HeadersLength");
	delete st;

	quint16 size = sizeOfRlc + RLC_HeadersLength + 1;

	id.id = DDT_ID_BLOCK0501;//rlcHeader;
	rst = EE_GET_ST(id.getSID());

	blockLoc.pos += sizeOfRlc;

	quint16 rlcHdrTotalLen = 0;
	quint16 rlcHdrLen = *(const uchar*)(GET_PDATA() + blockLoc.pos);
	while (rlcHdrLen > 0 && rlcHdrTotalLen < RLC_HeadersLength)
	{
		pkgLocCom.payloadPos = blockLoc.pos;
		pkgLocCom.payloadLen = rlcHdrLen;		
		pkgLocCom.misc = id.getSID();
		dm->insertPkgLoc(pkgLocCom);

		blockLoc.pos += rlcHdrLen;
		rlcHdrTotalLen += rlcHdrLen;

		rlcHdrLen = *(const uchar*)(GET_PDATA() + blockLoc.pos);
	}

	whileBlockSize += size;

	blockLoc.pos = blockLocOrig.pos + BYTE_ALIGN_4B(whileBlockSize);

	return true;
}

bool DdtPkgParser::parseDLTblock06(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc)
{
	CompLoc blockLocOrig = blockLoc;
	quint16 whileBlockSize = 0;

	id.id = DDT_ID_BLOCK0600;//designTrace;
	StrucTree* rst = EE_GET_ST(id.getSID());
	StrucTree* st = rst->clone();
	quint16 sizeOfDesignTrace = st->getSizeInByte();
	st->decode(QByteArray(GET_PDATA() + blockLoc.pos, sizeOfDesignTrace), st);
	quint16 totalSize = st->getFieldValue("totalSize");
	delete st;

	quint16 size = sizeOfDesignTrace + totalSize;

	pkgLocCom.payloadPos = blockLoc.pos;
	pkgLocCom.payloadLen = size;
	pkgLocCom.misc = id.getSID();
	dm->insertPkgLoc(pkgLocCom);

	blockLoc.pos += size;
	whileBlockSize += size;
	blockLoc.pos = blockLocOrig.pos + BYTE_ALIGN_4B(whileBlockSize);

	return true;
}

bool DdtPkgParser::parseDLTblock07(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc)
{
	CompLoc blockLocOrig = blockLoc;
	quint16 whileBlockSize = 0;

	id.id = DDT_ID_BLOCK0700;//dcchCcchHdr;
	StrucTree* rst = EE_GET_ST(id.getSID());
	StrucTree* st = rst->clone();
	quint16 sizeOfDcchCcchHdr = st->getSizeInByte();
	st->decode(QByteArray(GET_PDATA() + blockLoc.pos, sizeOfDcchCcchHdr), st);
	quint8 nbOfSignalingInfo = st->getFieldValue("nbOfSignalingInfo");
	quint16 totalSize = st->getFieldValue("totalSize");
	delete st;

	blockLoc.pos += sizeOfDcchCcchHdr;

	if (nbOfSignalingInfo > 0)
	{
		int number = 0;
		for (number = 0; number < nbOfSignalingInfo; ++number)
		{
			id.id = DDT_ID_BLOCK0701;//dcchCcchInfo
			rst = EE_GET_ST(id.getSID());
			st = rst->clone();
			quint16 sizeOfDcchCcchInfo = st->getSizeInByte();
			st->decode(QByteArray(GET_PDATA() + blockLoc.pos, sizeOfDcchCcchInfo), st);
			quint16 signalingInfoLength = st->getFieldValue("signalingInfoLength");
			delete st;

			quint16 size = sizeOfDcchCcchInfo + signalingInfoLength;

			pkgLocCom.payloadPos = blockLoc.pos;
			pkgLocCom.payloadLen = size;
			pkgLocCom.misc = id.getSID();
			dm->insertPkgLoc(pkgLocCom);

			blockLoc.pos += size;
		}
	}

	whileBlockSize += (sizeOfDcchCcchHdr + totalSize);
	blockLoc.pos = blockLocOrig.pos + BYTE_ALIGN_4B(whileBlockSize);

	return true;
}

bool DdtPkgParser::parseDLTblock08(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc)
{
	CompLoc blockLocOrig = blockLoc;
	quint16 whileBlockSize = 0;

	id.id = DDT_ID_BLOCK0800;//usersSpeedHdr;
	StrucTree* rst = EE_GET_ST(id.getSID());
	StrucTree* st = rst->clone();
	quint16 sizeOfUsersSpeedHdr = st->getSizeInByte();
	st->decode(QByteArray(GET_PDATA() + blockLoc.pos, sizeOfUsersSpeedHdr), st);
	quint8 nbOfUe = st->getFieldValue("nbOfUe");
	delete st;

	quint16 size = sizeOfUsersSpeedHdr + nbOfUe * sizeof(quint16)+((nbOfUe + 1) >> 1);

	pkgLocCom.payloadPos = blockLoc.pos;
	pkgLocCom.payloadLen = size;	
	pkgLocCom.misc = id.getSID();
	dm->insertPkgLoc(pkgLocCom);

	blockLoc.pos += size;
	whileBlockSize += size;
	blockLoc.pos = blockLocOrig.pos + BYTE_ALIGN_4B(whileBlockSize);

	return true;
}

bool DdtPkgParser::parseDLTblock09(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc)
{
	CompLoc blockLocOrig = blockLoc;
	quint16 whileBlockSize = 0;

	id.id = DDT_ID_BLOCK0900;//usersMimoStateHdr;
	StrucTree* rst = EE_GET_ST(id.getSID());
	StrucTree* st = rst->clone();
	quint16 sizeOfUsersMimoStateHdr = st->getSizeInByte();
	st->decode(QByteArray(GET_PDATA() + blockLoc.pos, sizeOfUsersMimoStateHdr), st);
	quint8 nbOfUe = st->getFieldValue("nbOfUe");
	delete st;

	blockLoc.pos += sizeOfUsersMimoStateHdr;
	whileBlockSize += sizeOfUsersMimoStateHdr;

	if (nbOfUe > 0)
	{
		id.id = DDT_ID_BLOCK0901;//ueMimoStoreInfo;
		rst = EE_GET_ST(id.getSID());
		quint16 sizeOfUeMimoStoreInfo = rst->getSizeInByte();

		int number = 0;
		for (number = 0; number < nbOfUe; ++number)
		{
			pkgLocCom.payloadPos = blockLoc.pos;
			pkgLocCom.payloadLen = sizeOfUeMimoStoreInfo;
			pkgLocCom.misc = id.getSID();
			dm->insertPkgLoc(pkgLocCom);

			blockLoc.pos += sizeOfUeMimoStoreInfo;
			whileBlockSize += sizeOfUeMimoStoreInfo;
		}
	}

	blockLoc.pos = blockLocOrig.pos + BYTE_ALIGN_4B(whileBlockSize);

	return true;
}

bool DdtPkgParser::parseDLTblock10(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc)
{
	CompLoc blockLocOrig = blockLoc;
	quint16 whileBlockSize = 0;

	id.id = DDT_ID_BLOCK0A00;//acqiListHdr;
	StrucTree* rst = EE_GET_ST(id.getSID());
	StrucTree* st = rst->clone();
	quint16 sizeOfAcqiListHdr = st->getSizeInByte();
	st->decode(QByteArray(GET_PDATA() + blockLoc.pos, sizeOfAcqiListHdr), st);
	quint8 nbOfUe = st->getFieldValue("nbOfUe");
	delete st;

	quint16 size = sizeOfAcqiListHdr + nbOfUe * sizeof(quint16);

	if (nbOfUe > 0)
	{
		//        CURRENTLY NOT decode IT !!!! @TODO
	}

	blockLoc.pos += size;
	whileBlockSize += size;
	blockLoc.pos = blockLocOrig.pos + BYTE_ALIGN_4B(whileBlockSize);

	return true;
}

bool DdtPkgParser::parseDLTblock11(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc)
{
	CompLoc blockLocOrig = blockLoc;
	quint16 whileBlockSize = 0;

	id.id = DDT_ID_BLOCK0B00;//mGHdr;
	StrucTree* rst = EE_GET_ST(id.getSID());
	StrucTree* st = rst->clone();
	quint16 sizeOfMGHdr = st->getSizeInByte();

	st->decode(QByteArray(GET_PDATA() + blockLoc.pos, sizeOfMGHdr), st);
	quint8 nbOfUe = st->getFieldValue("nbOfUe");
	delete st;

	blockLoc.pos += sizeOfMGHdr;
	whileBlockSize += sizeOfMGHdr;

	if (nbOfUe > 0)
	{
		id.id = DDT_ID_BLOCK0B01;//<<mG;
		rst = EE_GET_ST(id.getSID());
		quint16 sizeOfMG = rst->getSizeInByte();

		int number = 0;
		for (number = 0; number < nbOfUe; ++number)
		{
			pkgLocCom.payloadPos = blockLoc.pos;
			pkgLocCom.payloadLen = sizeOfMG;
			pkgLocCom.misc = id.getSID();
			dm->insertPkgLoc(pkgLocCom);

			blockLoc.pos += sizeOfMG;
			whileBlockSize += sizeOfMG;
		}
	}

	blockLoc.pos = blockLocOrig.pos + BYTE_ALIGN_4B(whileBlockSize);

	return true;
}

bool DdtPkgParser::parseDLTblock12(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc)
{
	CompLoc blockLocOrig = blockLoc;
	quint16 whileBlockSize = 0;

	id.id = DDT_ID_BLOCK0C00;//an2HarqHdr;
	StrucTree* rst = EE_GET_ST(id.getSID());
	StrucTree* st = rst->clone();
	quint16 sizeOfAn2HarqHdr = st->getSizeInByte();
	st->decode(QByteArray(GET_PDATA() + blockLoc.pos, sizeOfAn2HarqHdr), st);
	quint8 nbOfUe = st->getFieldValue("nbOfUe");
	delete st;

	blockLoc.pos += sizeOfAn2HarqHdr;
	whileBlockSize += sizeOfAn2HarqHdr;

	if (nbOfUe > 0)
	{
		id.id = DDT_ID_BLOCK0C01;//an2Harq;
		rst = EE_GET_ST(id.getSID());
		quint16 sizeOfAn2Harq = rst->getSizeInByte();

		int number = 0;
		for (number = 0; number < nbOfUe; ++number)
		{
			pkgLocCom.payloadPos = blockLoc.pos;
			pkgLocCom.payloadLen = sizeOfAn2Harq;		
			pkgLocCom.misc = id.getSID();
			dm->insertPkgLoc(pkgLocCom);

			blockLoc.pos += sizeOfAn2Harq;
			whileBlockSize += sizeOfAn2Harq;
		}
	}

	blockLoc.pos = blockLocOrig.pos + BYTE_ALIGN_4B(whileBlockSize);

	return true;

}

bool DdtPkgParser::parseDLTblock13(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc)
{
	Q_ASSERT(false);

	return true;
}

bool DdtPkgParser::parseDLTblock14(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc)
{
	Q_ASSERT(false);

	return true;
}

bool DdtPkgParser::parseDLTblock15(EeStrucId &id, PkgLoc &pkgLocCom, CompLoc &blockLoc)
{
	CompLoc blockLocOrig = blockLoc;
	quint16 whileBlockSize = 0;

	id.id = DDT_ID_BLOCK0F01;//ueCAmonitor;
	StrucTree* rst = EE_GET_ST(id.getSID());
	quint16 sizeOfUeCAmonitor = rst->getSizeInByte();
	id.id = DDT_ID_BLOCK0F02;//ueCAactivation;
	rst = EE_GET_ST(id.getSID());
	quint16 sizeOfUeCAactivation = rst->getSizeInByte();
	quint16 size = sizeOfUeCAmonitor + sizeOfUeCAactivation;
	quint16 leftsize = dm->pkgPageRawData->size() - blockLoc.pos;

	if (leftsize >= size)
	{
		id.id = DDT_ID_BLOCK0F01;
		pkgLocCom.payloadPos = blockLoc.pos;
		pkgLocCom.payloadLen = sizeOfUeCAmonitor;	
		pkgLocCom.misc = id.getSID();
		dm->insertPkgLoc(pkgLocCom);

		blockLoc.pos += sizeOfUeCAmonitor;
		whileBlockSize += sizeOfUeCAmonitor;


		id.id = DDT_ID_BLOCK0F02;
		pkgLocCom.payloadPos = blockLoc.pos;
		pkgLocCom.payloadLen = sizeOfUeCAactivation;
		pkgLocCom.misc = id.getSID();
		dm->insertPkgLoc(pkgLocCom);

		blockLoc.pos += sizeOfUeCAactivation;
		whileBlockSize += sizeOfUeCAactivation;
	}
	else if (leftsize >= sizeOfUeCAactivation)
	{
		id.id = DDT_ID_BLOCK0F02;
		pkgLocCom.payloadPos = blockLoc.pos;
		pkgLocCom.payloadLen = sizeOfUeCAactivation;
		pkgLocCom.misc = id.getSID();
		dm->insertPkgLoc(pkgLocCom);

		blockLoc.pos += sizeOfUeCAactivation;
		whileBlockSize += sizeOfUeCAactivation;
	}
	else if (leftsize >= sizeOfUeCAmonitor)
	{
		id.id = DDT_ID_BLOCK0F01;
		pkgLocCom.payloadPos = blockLoc.pos;
		pkgLocCom.payloadLen = sizeOfUeCAmonitor;
		pkgLocCom.misc = id.getSID();		
		dm->insertPkgLoc(pkgLocCom);

		blockLoc.pos += sizeOfUeCAmonitor;
		whileBlockSize += sizeOfUeCAmonitor;
	}
	else
	{
		EELOG_ERROR("DdtPkgParser::parseDLTblock15|failed to decode Leftsize (" 
			<< leftsize << ") UeCAmonitorSize ( " 
			<< sizeOfUeCAmonitor 
			<< ") CAactivationSize (" 
			<< sizeOfUeCAactivation << ")");

		return false;
	}

	blockLoc.pos = blockLocOrig.pos + BYTE_ALIGN_4B(whileBlockSize);

	return true;
}

bool DdtPkgParser::isValidDLTPacket(const DDTUdpHeader_t &hdr)
{
	return hdr.traceVersion >= DDT_VER_DLT_BCEM_FDD_TDD_V10 &&
		   hdr.traceVersion <= DDT_VER_DLT_BCEM_FDD_TDD_V13;
}

bool DdtPkgParser::isValidULTPacket(const ult_ct_hdr_t &hdr)
{	
	if (isFdd())
	{
		return hdr.traceVersion >= DDT_VER_ULT_BCEM_FDD_V16 &&
			   hdr.traceVersion <= DDT_VER_ULT_BCEM_FDD_V19;
	}
	else
	{
		return hdr.traceVersion >= DDT_VER_ULT_BCEM_TDD_V4 &&
			   hdr.traceVersion <= DDT_VER_ULT_BCEM_TDD_V7;
	}
}