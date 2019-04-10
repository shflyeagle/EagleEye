#include "TigerPkgVisitor.h"
#include "StrucTigerLUT.h"


TigerPkgVisitor::TigerPkgVisitor()
{
}

TigerPkgVisitor::~TigerPkgVisitor()
{
}

TigerPkgVisitorMng::TigerPkgVisitorMng()
{
}

TigerPkgVisitorMng::~TigerPkgVisitorMng()
{
}

PkgVisitor* TigerPkgVisitorMng::getVisitor(unsigned pkgId)
{
	if (pkgVisitors.contains(pkgId))
	{
		return pkgVisitors[pkgId];
	}

	PkgVisitor* visitor = Q_NULLPTR;
	quint16 id = STRUC_N(pkgId);
	switch (id)
	{
	case TT_ID_0x507:
		visitor = new TigerPkgVisitor;
		break;

	default:
		//EELOG_WARN("TigerPkgDecoderMng::getDecoder|failed to create PkgVisitor with Id (" << id << ")");
		break;
	}

	if (visitor)
	{
		pkgVisitors.insert(pkgId, visitor);
	}
	return visitor;
}
