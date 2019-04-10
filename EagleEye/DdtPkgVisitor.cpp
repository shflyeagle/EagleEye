#include "DdtPkgVisitor.h"
#include "StrucDDTLUT.h"


DdtPkgVisitor::DdtPkgVisitor()
{
}

DdtPkgVisitor::~DdtPkgVisitor()
{
}

DdtPkgVisitorMng::DdtPkgVisitorMng()
{
}

DdtPkgVisitorMng::~DdtPkgVisitorMng()
{
}

PkgVisitor* DdtPkgVisitorMng::getVisitor(unsigned pkgId)
{
	if (pkgVisitors.contains(pkgId))
	{
		return pkgVisitors[pkgId];
	}

	PkgVisitor* visitor = Q_NULLPTR;
	quint16 id = STRUC_N(pkgId);
	switch (id)
	{
	case DDT_ID_BLOCK0010:
	case DDT_ID_BLOCK0011:
	case DDT_ID_BLOCK0501:
	case DDT_ID_BLOCK0701:
	case DDT_ID_BLOCK0101:
	case DDT_ID_BLOCK0200:
	case DDT_ID_BLOCK0201://MSG3
	case DDT_ID_BLOCK0202://MSG4
	case DDT_ID_BLOCK0300:
	case DDT_ID_BLOCK0301:
	case DDT_ID_BLOCK0402:
	case DDT_ID_BLOCK0403:
	case DDT_ID_BLOCK0800:
	case DDT_ID_BLOCK0901:
	case DDT_ID_BLOCK0A00:
	case DDT_ID_BLOCK0B01:
	case DDT_ID_BLOCK0C01:
	case DDT_ID_BLOCK0F01:
	case DDT_ID_BLOCK0F02:

	case DDT_ID_BLOCK1800://rach_msg2
	case DDT_ID_BLOCK1801://rach_msg2_misc
	case DDT_ID_BLOCK180A://catm_rach_cfg
	case DDT_ID_BLOCK180B://catm_rach_msg2
	case DDT_ID_BLOCK1900://PHICH
	case DDT_ID_BLOCK1A00://sps
	case DDT_ID_BLOCK1B00://rfns
	case DDT_ID_BLOCK1C00://meas
	case DDT_ID_BLOCK1D00://counter
	case DDT_ID_pdcch_pkt_hdr_t://unkonw dci
	case DDT_ID_mpdcch_pkt_hdr_t://unkonw mtc dci
	case DDT_ID_BLOCK2501://mtc_unicast_scd
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
		visitor = new DdtPkgVisitor;
		break;

	default:
		EELOG_WARN("DdtPkgVisitorMng::getDecoder|failed to create PkgVisitor with Id (" << id << ")");
		break;
	}

	if (visitor)
	{
		pkgVisitors.insert(pkgId, visitor);
	}
	return visitor;
}
