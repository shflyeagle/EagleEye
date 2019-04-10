#include "DdtDataManager.h"
#include "DdtPkgParser.h"
#include "StrucDDTLUT.h"
#include "DdtPkgDecoder.h"
#include "DdtPkgVisitor.h"
#include "StrucTree.h"

DdtDataManager::DdtDataManager(QWidget *parent) :
DataManager(parent)
{
	pkgDecoderMng = std::shared_ptr<PkgDecoderMng>(new DdtPkgDecoderMng);
	pkgVisitorMng = std::shared_ptr<PkgVisitorMng>(new DdtPkgVisitorMng);
}

DdtDataManager::~DdtDataManager()
{
}

QString DdtDataManager::getFilterExpression4Export(quint32 decodeId, const StrucTree* st)
{
	QString filterExp = QString("ddt.blockId == %1").arg(decodeId);
	if (st->getKvMap()->contains("rnti"))
	{
		filterExp.append(" && ddt.rnti == ")
			     .append(st->getKvMap()->value("rnti").toString());
	}

	return filterExp;
}

unsigned DdtDataManager::getDecoderId(const PkgLoc* pkgLoc)
{
	return pkgLoc->misc;	
}

QByteArray DdtDataManager::getDecoderCxt(const PkgLoc* pkgLoc)
{
	quint16 headerLen = EE_PKG_HDR_LEN(pkgLoc->headerLen);
	QByteArray &header =
		QByteArray(pkgPageRawData->data() + pkgLoc->headerPos, 
		headerLen);
	header.append(pkgPageRawData->data() + pkgLoc->payloadPos, pkgLoc->payloadLen);

	if (headerLen == sizeof(DDTUdpHeader_t))
	{
		header.append('N');
	}
	else if (headerLen == sizeof(DDTUdpHeaderCA_t))
	{
		header.append('C');
	}
	else
	{
		header.append('M');
	}

	return header;
}

QByteArray DdtDataManager::getDecoderCxt4Filter(const PkgLoc* pkgLoc)
{
	return QByteArray(pkgPageRawData->data() + pkgLoc->payloadPos,
		pkgLoc->payloadLen);
}

std::shared_ptr<AbstractPkgParser> DdtDataManager::getPacketParser(void)
{
	return std::shared_ptr<AbstractPkgParser>(new DdtPkgParser(this));
}

