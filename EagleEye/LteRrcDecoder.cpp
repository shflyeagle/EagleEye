#include "LteRrcDecoder.h"
#include "lterrc/LteRrcMessage.h"
#include "StrucTree.h"
LteRrcDecoder::LteRrcDecoder(quint8 signalingDirection, 
	quint8 channelType, 
	const QByteArray& rrcPayload)
{
	int rc = -1;
	LteRrcMessage msg;
	QString exeInfo;

	try
	{
		if (EE_RRC_SD_DOWNLINK == signalingDirection)
		{
			if (EE_RRC_CT_PCCH == channelType)
			{
				rc = msg.decode("PCCH-Message", 
					rrcPayload.data(), 
					rrcPayload.size(), 
					false);
			}
			else if (EE_RRC_CT_CCCH == channelType)
			{
				rc = msg.decode("DL-CCCH-Message", 
					rrcPayload.data(), 
					rrcPayload.size(), 
					false);
			}
			else if (EE_RRC_CT_SRB1 == channelType ||
				     EE_RRC_CT_SRB2 == channelType)
			{
				rc = msg.decode("DL-DCCH-Message", 
					rrcPayload.data() + 1, 
					rrcPayload.size() - 1, 
					false);
			}
			else
			{
				exeInfo = QString("Unsupported RRC Downlink Channel Type (%1)")
					.arg(channelType);
				throw EeException(exeInfo);
			}
		}
		else if (EE_RRC_SD_UPLINK == signalingDirection)
		{
			if (EE_RRC_CT_CCCH == channelType)
			{
				rc = msg.decode("UL-CCCH-Message", 
					rrcPayload.data(), 
					rrcPayload.size(), 
					false);
			}
			else if (EE_RRC_CT_SRB1 == channelType ||
				     EE_RRC_CT_SRB2 == channelType)
			{
				rc = msg.decode("UL-DCCH-Message", 
					rrcPayload.data() + 1, 
					rrcPayload.size() - 1, 
					false);
			}
			else
			{
				exeInfo = QString("Unsupported RRC Uplink Channel Type (%1)")
					.arg(channelType);
				throw EeException(exeInfo);
			}
		}

		if (0 == rc)
		{
			decodedRrc = QString(msg.decoded_msg.c_str());
		}
		else
		{
			QVariant v(rrcPayload.toHex());
			exeInfo = QString("failed to decode RRC SD (%1) CT (%2) PAYLOAD(%3)")
				.arg(signalingDirection).arg(channelType).arg(v.toString());
			throw EeException(exeInfo);
		}
	}
	catch (const EeException& exe)
	{
		EELOG_WARN("LteRrcDecoder::LteRrcDecoder|" 
			<< exe.what());
	}
	catch (...)
	{
		EELOG_ERROR("LteRrcDecoder::LteRrcDecoder|unknown error");
	}
}

StrucTree* LteRrcDecoder::getStrucTree(StrucTree* root)
{
	StrucTree *st = Q_NULLPTR;
	if (!decodedRrc.isEmpty())
	{
		QDomDocument dom("lte_rrc_dom_tree");
		if (dom.setContent(decodedRrc))
		{
			FieldInfo *fi = new FieldInfo;
			fi->fd.name = "lte_rrc";			
			fi->fv = dom.documentElement().tagName();
			st = new StrucTree(fi);

			generate(dom.documentElement(), st, root);

			if (st->childCount() > 0 &&
				st->getChildren()->at(0)->childCount() > 0 &&
				st->getChildren()->at(0)->getChildren()->at(0)->childCount() > 0)
			{
				QString value = QString("%1  %2").
					arg(st->getFieldInfo()->fv.toString()).
					arg(st->getChildren()->at(0)->getChildren()
					->at(0)->getChildren()->at(0)->getFieldInfo()->fd.name);
				root->insertKV(st->getFieldInfo()->fd.name,
					value);
			}
			else
			{
				root->insertKV(st->getFieldInfo()->fd.name,"unknown");
			}
		}
	}
	return st;
}

LteRrcDecoder::~LteRrcDecoder()
{

}

void LteRrcDecoder::generate(const QDomNode& np, StrucTree* parent, StrucTree* root)
{
	QDomNode nc = np.firstChild();
	while (!nc.isNull())
	{		
		FieldInfo* fi = new FieldInfo();
		StrucTree *child = new StrucTree(fi);
		bool isSkip = false;
		if (nc.isElement())
		{
			QDomElement e = nc.toElement();
			if ((!e.firstChild().isNull() && 
				 !e.firstChild().isText()))
			{
				if (e.childNodes().size() == 1 && 
					e.firstChild().isElement() && 
					e.firstChild().firstChild().isNull())
				{
					isSkip = true;
				}
				else
				{
					fi->fd.name = e.tagName();

					//EELOG_DEBUG("tagname (" 
					//	<< QSTR2CSTR(e.tagName()) 
					//	<< ") child (" 
					//	<< nc.childNodes().size() 
					//	<< ")");
				}
			}
			else if (e.firstChild().isNull())
			{
				fi->fd.name = nc.parentNode().toElement().tagName();
				fi->fv = e.tagName().trimmed();
				root->insertKV(fi->fd.name, fi->fv);

				//EELOG_DEBUG("tagname (" 
				//	<< QSTR2CSTR(nc.parentNode().toElement().tagName()) 
				//	<< ") tagvalue (" 
				//	<< QSTR2CSTR(e.tagName().trimmed()) 
				//	<< ")");
			}
			else
			{
				isSkip = true;
			}

			if (isSkip)
			{
				delete child;
			}
			else
			{
				parent->appendChild(child);
				child->setParent(parent);
			}
			generate(nc, isSkip ? parent : child, root);
		}
		else
		{
			if (nc.isText())
			{
				parent->appendChild(child);
				child->setParent(parent);

				QString text = nc.parentNode().toElement().text();
				text.replace(QRegExp("\n\\t?"), "");

				fi->fd.name = nc.parentNode().toElement().tagName();
				fi->fv = text.trimmed();

				root->insertKV(fi->fd.name, fi->fv);

				//EELOG_DEBUG("tagname (" 
				//	<< QSTR2CSTR(nc.parentNode().toElement().tagName()) 
				//	<< ") tagvalue (" 
				//	<< QSTR2CSTR(text.trimmed()) 
				//	<< ")");
			}
			else
			{
				delete child;
			}
		}
		nc = nc.nextSibling();
	}
}
