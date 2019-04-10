#include "TigerPkgDecoder.h"
#include "StrucTree.h"
#include "StrucTreeManager.h"
#include "StrucTigerLUT.h"
#include "StrucLUT.h"


TigerPkgDecoder::TigerPkgDecoder(unsigned pkgId):
PkgDecoder(pkgId)
{
}

void TigerPkgDecoder::decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter)
{
	PkgDecoder::decode(b, pkgLoc, is4Filter);

	StrucTree* rst = 
		StrucTreeManager::getInstance()->getStrucTree(pkgId);
	if (Q_NULLPTR != rst)
	{
		strucTree = rst->clone();
		strucTree->decode(b, (is4Filter ? Q_NULLPTR : strucTree), pkgLoc);
	}
}

PkgDecoder* TigerPkgDecoderMng::getDecoder(unsigned pkgId)
{
	if (pkgDecoders.contains(pkgId))
	{
		return pkgDecoders[pkgId];
	}

	PkgDecoder* decoder = Q_NULLPTR;
	quint16 id = STRUC_N(pkgId);
	switch (id)
	{
	case TT_ID_0x507:
		decoder = new TigerPkgDecoder(pkgId);
		break;

	default:
		//EELOG_WARN("TigerPkgDecoderMng::getDecoder|failed to create PkgDecoder with Id (" << id << ")");
		break;
	}

	if (decoder)
	{
		pkgDecoders.insert(pkgId, decoder);
	}	
	return decoder;
}
