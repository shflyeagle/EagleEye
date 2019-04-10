#pragma once

#include "EeCommon.h"

//std::map<std::string, unsigned> BaseDataType2BytesMap = 
//{ 
//	{ "quint8"		,1},
//	{ "quint16"		,2},
//	{ "quint32"		,4},
//	{ "qint8"		,1},
//	{ "qint16"		,2},
//	{ "qint32"		,4}
//};

class StrucRanks
{
public:
	QString r0Name;
	QString r1Name;
	QString r2Name;
	QString r3Name;
};

class FieldProfile
{
public:
	QString name;
	QString alias;
	quint32 showMask;
	QMap<QString, QString> kvMap;
};

using FpVec = QVector<std::shared_ptr<FieldProfile> >;

class StructProfile
{
public:
	StrucRanks sr;
	FpVec fpVec;
	QMap<QString, quint32> filteringKeyIdxMap;
	bool forceClone{ 1 };

public:
	StructProfile *clone()
	{
		StructProfile *sp = new StructProfile;
		sp->sr = this->sr;
		foreach(auto sfp, fpVec)
		{
			FieldProfile *fp = new FieldProfile(*sfp);
			sp->fpVec.push_back(std::shared_ptr<FieldProfile>(fp));
		}
		sp->filteringKeyIdxMap = this->filteringKeyIdxMap;
		sp->forceClone = this->forceClone;
		return sp;
	}
};

using StucId2StructProfileMap = QMap<quint32, std::shared_ptr<StructProfile> >;