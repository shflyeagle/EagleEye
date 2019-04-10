#include "TigerDataManager.h"
#include "TigerPkgParser.h"
#include "StrucTigerLUT.h"
#include "TigerPkgDecoder.h"
#include "TigerPkgVisitor.h"

TigerDataManager::TigerDataManager(QWidget *parent) :
DataManager(parent)
{
	pkgDecoderMng = std::shared_ptr<PkgDecoderMng>(new TigerPkgDecoderMng);
	pkgVisitorMng = std::shared_ptr<PkgVisitorMng>(new TigerPkgVisitorMng);
}

TigerDataManager::~TigerDataManager()
{
}

unsigned TigerDataManager::getDecoderId(const PkgLoc* pkgLoc)
{
	return EE_BE_GetPkgIdFromTTPackageHeader(pkgPageRawData->data() + pkgLoc->payloadPos);
}

QByteArray TigerDataManager::getDecoderCxt(const PkgLoc* pkgLoc)
{
	quint16 headerLen = EE_PKG_HDR_LEN(pkgLoc->headerLen);
	QByteArray header =
		QByteArray(pkgPageRawData->data() + pkgLoc->headerPos, headerLen);

	return header.append(pkgPageRawData->data() + pkgLoc->payloadPos, pkgLoc->payloadLen);
}

QByteArray TigerDataManager::getDecoderCxt4Filter(const PkgLoc* pkgLoc)
{
	return getDecoderCxt(pkgLoc);
}

std::shared_ptr<AbstractPkgParser> TigerDataManager::getPacketParser(void)
{
	return std::shared_ptr<AbstractPkgParser>(new TigerPkgParser(this));
}
