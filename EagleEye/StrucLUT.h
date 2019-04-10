#pragma once

#include "EeCommon.h"
#include "StrucTreeComm.h"

enum
{	
	SHOW_MASK_NORMAL    = 0,
	SHOW_MASK_VALUE_ONLY,
	SHOW_MASK_KV_VALUE_YES,
	SHOW_MASK_KV,
	SHOW_MASK_KV_VALUE_ONLY,
	SHOW_MASK_KV_PREFIX,
	SHOW_MASK_UNKNOWN,
};

class StrucLUT
{

public:
	static quint32 strucId;
	static quint8 type;
	static quint8 ver;
	static StucId2StructProfileMap strucLut;
	static QString strucFile;
	static QString filterPrefix;
	static QString filterKey;
	static QMap<QString, quint32> fkLut;
	static QMap<QString, std::shared_ptr<QMap<quint16, QString>>> strucCatLut;
	static QMap<quint16, quint16> strucTVMap;
	static QMap<quint16, QString> strucTypeLut;
	static QMap<quint16, QString> bwLut;
	static QMap<quint16, QString> antLut;
	static QMap<quint16, QMap<QString, std::shared_ptr<QMap<quint16, QString>>>> strucCatLutMap;

public:
	static void init();
	static void setStrucFile(const QString& fileName);
	static void setType(quint8 type);
	static void setVer(quint8 ver);
	static void setFilterPrefix(const QString& prefix);
	static void setFilterKey(const QString& filterKey);
	static void check2InsertStructProfile(quint16 id);
	static void check2InsertStructProfile(quint16 id, quint16 sid);
	static void setRanks(const QString &r0name,
		const QString &r1name,
		const QString &r2name,
		const QString &r3name = "");
	static void addFieldProfile(const QString& name, quint32 showMask = SHOW_MASK_NORMAL, const QString& alias = "");
	static void prependFieldProfile4All(const QString& name, quint32 showMask = SHOW_MASK_NORMAL, const QString& alias = "");
	static void addKV4FieldProfile(const QString& key, const QString& value);
	static void addFilteringKey(const QString&filteringKey);
	static void setForceClone(bool isForceClone);
	static const StucId2StructProfileMap& getStucId2StructProfileMap();
	static const QString& getStrucFile();
	static void clear();
	static const QMap<QString, quint32>& getFKMap(quint32 strucId);
	static const FpVec& getFPVec(quint32 strucId);
	static void insertFK(const QString& filterKeyword);	
	static void generateCatLUT();
	static void initStrucTypeLUT();
	static void initBWLUT();
	static void initANTLUT();
	static QMap<QString, std::shared_ptr<QMap<quint16, QString>>>& getCatLUT(quint16 strucType);
	static void check2InsertStrucTV(quint16 stv);
	static bool findSID(quint16 id, quint32& fsid);

private:
	static StructProfile* getCurStructProfile();
};

#define SLUT_SET_FILE(fn) StrucLUT::setStrucFile(fn)
#define SLUT_SET_TYPE(type) StrucLUT::setType(type)
#define SLUT_SET_VER(ver) StrucLUT::setVer(ver)
#define SLUT_SET_FILTER_PREFIX(prefix) StrucLUT::setFilterPrefix(prefix)
#define SLUT_GET_FILTER_PREFIX() StrucLUT::filterPrefix
#define SLUT_SET_FILTER_KEY(key) StrucLUT::setFilterKey(key)
#define SLUT_GET_FILTER_KEY() StrucLUT::filterKey
#define SLUT_ADD_SP(id)	StrucLUT::check2InsertStructProfile(id)
#define SLUT_ADD_SP_DERIVE_SP(id, sid)	StrucLUT::check2InsertStructProfile(id,sid)
#define SLUT_SET_RANKS_4_SP(r0, r1, r2, r3) StrucLUT::setRanks(r0,r1,r2,r3)
#define SLUT_ADD_FP_4_SP(name, showMask, alias) StrucLUT::addFieldProfile(name,showMask,alias)
#define SLUT_PREPEND_FP_4_ALL_SP(name, showMask, alias) StrucLUT::prependFieldProfile4All(name,showMask,alias)
#define SLUT_ADD_KV_4_FP(key, value) StrucLUT::addKV4FieldProfile(key,value)
#define SLUT_ADD_FK_4_SP(filterKey) StrucLUT::addFilteringKey(filterKey)
#define SLUT_SET_FC_4_SP(isForceClone) StrucLUT::setForceClone(isForceClone)
#define SLUT_GET_SP_MAP()	StrucLUT::getStucId2StructProfileMap()
#define SLUT_GET_SF() StrucLUT::getStrucFile()
#define SLUT_GET_FKMAP(strucId) StrucLUT::getFKMap(strucId)
#define SLUT_GET_FPVEC(strucId) StrucLUT::getFPVec(strucId)
#define SLUT_INSERT_FK(fk) StrucLUT::insertFK(fk)
#define SLUT_GET_CATLUT() StrucLUT::strucCatLut
#define SLUT_GET_CATLUT_BY_ST(st) StrucLUT::getCatLUT(st)
#define SLUT_GEN_CATLUT() StrucLUT::generateCatLUT()
#define SLUT_INIT_STLUT() StrucLUT::initStrucTypeLUT()
#define SLUT_GET_STLUT() StrucLUT::strucTypeLut
#define SLUT_GET_BWLUT() StrucLUT::bwLut
#define SLUT_GET_ANTLUT() StrucLUT::antLut
#define SLUT_INIT() StrucLUT::init()


#define INIT_SYMMNG()\
do{\
	EeSymManager::init(); \
	QMapIterator<QString, quint32> i(StrucLUT::fkLut); \
	while (i.hasNext())\
	{\
		i.next(); \
		quint16 id = LEX_SYM_ID_WORD + i.value(); \
		QString identifier = SLUT_GET_FILTER_PREFIX() + i.key(); \
		EeSymManager::regSym(new EeWord(id, identifier)); \
	}\
} while (0);


#define INIT_STRUCTREE()\
do{\
	StrucTreeManager::getInstance()->generate(); \
} while (0);

#define SLUT_COMM_INIT()\
do{\
	INIT_SYMMNG()\
	INIT_STRUCTREE()\
} while (0);