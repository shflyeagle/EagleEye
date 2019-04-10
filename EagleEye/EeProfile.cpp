#include "EeProfile.h"
#include "StrucLUT.h"

quint16 EeProfile::strucType = EE_STRUC_TYPE_DDT;
TigerProfile EeProfile::tigerProfile;
DdtProfile EeProfile::ddtProfile;
QMap<quint16, QString> EeProfile::disabledFeaturesLut;

EeProfile::EeProfile()
{
}


EeProfile::~EeProfile()
{
}

QString EeProfile::getStatus()
{
	if (EE_STRUC_TYPE_TIGER == strucType)
	{
		return "tiger";
	}
	else if (EE_STRUC_TYPE_DDT == strucType)
	{
		return QString("ddt (bw = %1, txant = %2)")
			.arg(SLUT_GET_BWLUT().value(ddtProfile.bandwith))
			.arg(SLUT_GET_ANTLUT().value(ddtProfile.antTx));
	}
	else
	{
		return "";
	}
}

bool EeProfile::isDisabled(quint16 id)
{
	return disabledFeaturesLut.contains(id);
}