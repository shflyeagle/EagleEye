#pragma once

#include "EeCommon.h"
#include "StrucTreeComm.h"

class StrucTree;

class StrucTreeManager
{
public:
	static StrucTreeManager *getInstance();

	void clrInstance();

	void generate();

	StrucTree *getStrucTree(quint32 strucId);

	quint16 getStrucTreeVecIndex(quint32 strucId);

private:
	StrucTreeManager();
	~StrucTreeManager();

	void parseStrucFile();

	void analyzeStruc(const QString& strucType, const QStringList& strucFields);

	qint16 generateStrucTree(const QString& strucType, StrucTree *parent);

private:
	static StrucTreeManager* inst;

	static QMap<QString, qint8> baseType2BytesMap;

	static QMap<QString, qint8> baseType2IdxMap;

	class FieldCxt
	{
	public:
		QString type;
		QString name;
		quint16 cards;
	};

	typedef QVector<FieldCxt> FieldCxtVec;

	typedef QMap<QString, FieldCxtVec> StrucName2FieldCxtVecMap;

	StrucName2FieldCxtVecMap strucName2FieldCxtVecMap;

	quint16 strucTVArr[INVALID_U16];

	StrucTree *strucTreeArr[EE_MAX_STRUC_TV];

	const QString& strucFile;

	const StucId2StructProfileMap& stucId2StructProfileMap;
};

#define EE_GET_ST(sid) StrucTreeManager::getInstance()->getStrucTree(sid)