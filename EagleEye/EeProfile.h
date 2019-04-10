#pragma once

#include "EeCommon.h"
#include "StrucDDTLUT.h"

class TigerProfile
{
public:
};

class DdtProfile
{
public:
	quint8 tech{ TECH_TYPE_FDD };
	quint8 bandwith{ EE_BANDWIDTH_20 };
	quint8 antTx{ EE_ANT_2TX };
};

class EeProfile
{
public:
	EeProfile();
	~EeProfile();

	static bool isDisabled(quint16 id);

public:
	static quint16 strucType;

	static QMap<quint16, QString> disabledFeaturesLut;

	static TigerProfile tigerProfile;

	static DdtProfile ddtProfile;

	static QString getStatus();
};

#define EP_FEATURE_DISABLED(id) EeProfile::isDisabled(id)