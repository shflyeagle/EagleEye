#include "StrucLUT.h"
#include "DdtInit.h"
#include "TigerInit.h"

quint32 StrucLUT::strucId = 0;
quint8 StrucLUT::type = 0;
quint8 StrucLUT::ver = 0;
QString StrucLUT::filterPrefix;
QString StrucLUT::filterKey;
StucId2StructProfileMap StrucLUT::strucLut;
QString StrucLUT::strucFile;
QMap<QString, quint32> StrucLUT::fkLut;
QMap<QString, std::shared_ptr<QMap<quint16, QString>>> StrucLUT::strucCatLut;
QMap<quint16, quint16> StrucLUT::strucTVMap;
QMap<quint16, QString> StrucLUT::strucTypeLut;
QMap<quint16, QString> StrucLUT::bwLut;
QMap<quint16, QString> StrucLUT::antLut;
QMap<quint16, QMap<QString, std::shared_ptr<QMap<quint16, QString>>>> StrucLUT::strucCatLutMap;

void StrucLUT::setStrucFile(const QString& fileName)
{
	StrucLUT::strucFile = fileName;
}

void StrucLUT::setType(quint8 type)
{
	StrucLUT::type = type;
}

void StrucLUT::setVer(quint8 ver)
{
	StrucLUT::ver = ver;
}

void StrucLUT::setFilterPrefix(const QString& prefix)
{
	filterPrefix = prefix;
}

void StrucLUT::setFilterKey(const QString& key)
{
	filterKey = key;
}

void StrucLUT::check2InsertStructProfile(quint16 id)
{
	StrucLUT::strucId = STRUC_ID(StrucLUT::type, StrucLUT::ver, id);
	if (StrucLUT::strucLut.contains(StrucLUT::strucId))
	{
		return;
	}

	quint32 rsid;
	if (findSID(id, rsid))
	{
		//EELOG_DEBUG("StrucLUT::check2InsertStructProfile|SID (" 
		//	<< StrucLUT::strucId  
		//	<< ") copied FPs from SID (" 
		//	<< rsid << ")");
		StrucLUT::strucLut[StrucLUT::strucId] =
			std::shared_ptr<StructProfile>(StrucLUT::strucLut[rsid]->clone());
		return;
	}

	StrucLUT::strucLut[StrucLUT::strucId] = std::shared_ptr<StructProfile>(new StructProfile);

	check2InsertStrucTV(STRUC_TV(StrucLUT::strucId));
}

void StrucLUT::check2InsertStructProfile(quint16 id, quint16 sid)
{
	StrucLUT::strucId = STRUC_ID(StrucLUT::type, StrucLUT::ver, id);
	if (StrucLUT::strucLut.contains(StrucLUT::strucId))
	{
		return;
	}

	quint32 ssid = STRUC_ID(StrucLUT::type, StrucLUT::ver, sid);
	auto it = StrucLUT::strucLut.find(ssid);
	if (it != StrucLUT::strucLut.end())
	{
		//EELOG_DEBUG("StrucLUT::check2InsertStructProfile(overide)|SID ("
		//	<< StrucLUT::strucId
		//	<< ") copied FPs from SID ("
		//	<< ssid << ")");
		StrucLUT::strucLut[StrucLUT::strucId] =
			std::shared_ptr<StructProfile>(StrucLUT::strucLut[ssid]->clone());
		return;		
	}

	StrucLUT::strucLut[StrucLUT::strucId] = std::shared_ptr<StructProfile>(new StructProfile);
	check2InsertStrucTV(STRUC_TV(StrucLUT::strucId));
}

StructProfile* StrucLUT::getCurStructProfile()
{
	if (!StrucLUT::strucLut.contains(StrucLUT::strucId))
	{
		Q_ASSERT(false);
	}

	return StrucLUT::strucLut[StrucLUT::strucId].get();
}

void StrucLUT::setRanks(const QString &r0name,
	const QString &r1name,
	const QString &r2name,
	const QString &r3name)
{
	StructProfile *sp = getCurStructProfile();
	sp->sr.r0Name = r0name;
	sp->sr.r1Name = r1name;
	sp->sr.r2Name = r2name;
	sp->sr.r3Name = r3name;
}

void StrucLUT::addFieldProfile(const QString& name, quint32 showMask, const QString& alias)
{
	StructProfile *sp = getCurStructProfile();

	foreach(auto sfp, sp->fpVec)
	{
		if (sfp->name == name)
		{
			sfp->showMask = showMask;
			sfp->alias = alias;
			size_t idx = sp->fpVec.indexOf(sfp);
			if (idx != sp->fpVec.size() - 1)
			{
				std::shared_ptr<FieldProfile> tmpFp = sp->fpVec[sp->fpVec.size() - 1];
				sp->fpVec[sp->fpVec.size() - 1] = sp->fpVec[idx];
				sp->fpVec[idx] = tmpFp;
			}
			return;
		}
	}

	FieldProfile *fp = new FieldProfile;
	fp->name = name;
	fp->showMask = showMask;
	fp->alias = alias;

	sp->fpVec.push_back(std::shared_ptr<FieldProfile>(fp));
}


void StrucLUT::prependFieldProfile4All(const QString& name, quint32 showMask, const QString& alias)
{
	QMapIterator<quint32, std::shared_ptr<StructProfile> > it(strucLut);
	while (it.hasNext())
	{
		FieldProfile *fp = new FieldProfile;
		fp->name = name;
		fp->showMask = showMask;
		fp->alias = alias;

		it.next();		
		it.value()->fpVec.prepend(std::shared_ptr<FieldProfile>(fp));
	}
}

void StrucLUT::addKV4FieldProfile(const QString& key, const QString& value)
{
	StructProfile *sp = getCurStructProfile();

	QMap<QString, QString> &kvMap = sp->fpVec[sp->fpVec.size() - 1]->kvMap;
	if (kvMap.contains(key))
	{
		kvMap[key] = value;
	}
	else
	{
		kvMap.insert(key, value);
	}
}

void StrucLUT::addFilteringKey(const QString&filteringKey)
{
	StructProfile *sp = getCurStructProfile();

	if (!sp->filteringKeyIdxMap.contains(filteringKey))
	{
		sp->filteringKeyIdxMap.insert(filteringKey, sp->filteringKeyIdxMap.size());
	}
}

void StrucLUT::setForceClone(bool isForceClone)
{
	StructProfile *sp = getCurStructProfile();

	sp->forceClone = isForceClone;
}

const StucId2StructProfileMap& StrucLUT::getStucId2StructProfileMap()
{
	return strucLut;
}

const QString& StrucLUT::getStrucFile()
{
	return strucFile;
}

void StrucLUT::clear()
{
	strucLut.clear();
	fkLut.clear();
	strucCatLut.clear();
	strucTVMap.clear();
}

const QMap<QString, quint32>& StrucLUT::getFKMap(quint32 strucId)
{
	if (!StrucLUT::strucLut.contains(strucId))
	{
		Q_ASSERT(false);
	}

	return StrucLUT::strucLut[strucId]->filteringKeyIdxMap;
}

const FpVec& StrucLUT::getFPVec(quint32 strucId)
{
	if (!StrucLUT::strucLut.contains(strucId))
	{
		Q_ASSERT(false);
	}

	return StrucLUT::strucLut[strucId]->fpVec;
}

void StrucLUT::insertFK(const QString& filterKeyword)
{
	if (fkLut.contains(filterKeyword))
		return;
	
	Q_ASSERT(fkLut.size() < MAX_NUM_FILTER_KW);
	fkLut.insert(filterKeyword, fkLut.size());
}

void StrucLUT::generateCatLUT()
{
	for (auto it = strucLut.constBegin(); 
		      it != strucLut.constEnd(); 
			  ++it)
	{
		QString& category = it.value()->sr.r2Name;
		QString& dec = it.value()->sr.r1Name;
		quint16 id = STRUC_N(it.key());
		
		if (category.isEmpty() || dec.isEmpty())
		{
			continue;
		}

		if (strucCatLut.contains(category))
		{
			if (!strucCatLut.value(category)->contains(id))
			{
				strucCatLut.value(category)->insert(id, dec);
			}
		}
		else
		{
			std::shared_ptr<QMap<quint16, QString>> ptr(new QMap<quint16, QString>());
			ptr->insert(id, dec);
			strucCatLut.insert(category, ptr);
		}		
	}
}

void StrucLUT::initStrucTypeLUT()
{
	strucTypeLut.clear();
	strucTypeLut.insert(EE_STRUC_TYPE_TIGER, "tiger");
	strucTypeLut.insert(EE_STRUC_TYPE_DDT, "ddt");
	//strucTypeLut.insert(EE_STRUC_TYPE_TTI, "tti");
}

void StrucLUT::initBWLUT()
{
	bwLut.clear();
	bwLut.insert(EE_BANDWIDTH_05, "BW_5");
	bwLut.insert(EE_BANDWIDTH_10, "BW_10");
	bwLut.insert(EE_BANDWIDTH_15, "BW_15");
	bwLut.insert(EE_BANDWIDTH_20, "BW_20");
}

void StrucLUT::initANTLUT()
{
	antLut.clear();
	antLut.insert(EE_ANT_2TX, "2Tx");
	antLut.insert(EE_ANT_4TX, "4Tx");
}

void StrucLUT::init()
{
	initStrucTypeLUT();
	initBWLUT();
	initANTLUT();
	
	for (auto it = strucTypeLut.constBegin();
		it != strucTypeLut.constEnd();
		++it)
	{
		clear();

		switch (it.key())
		{
		case EE_STRUC_TYPE_TIGER:
			TIGER_INIT_LUT();
			break;

		case EE_STRUC_TYPE_DDT:
			DDT_INIT_LUT();
			break;

		default:
			Q_ASSERT(false);
			break;
		}

		strucCatLutMap.insert(it.key(), strucCatLut);
	}

	clear();
}

QMap<QString, std::shared_ptr<QMap<quint16, QString>>>&
StrucLUT::getCatLUT(quint16 strucType)
{
	if (!strucCatLutMap.contains(strucType))
	{
		Q_ASSERT(false);
	}

	return strucCatLutMap[strucType];
}

void StrucLUT::check2InsertStrucTV(quint16 stv)
{
	if (!strucTVMap.contains(stv))
	{
		strucTVMap.insert(stv, strucTVMap.size());
	}
}

bool StrucLUT::findSID(quint16 id, quint32& fsid)
{
	QMap<quint16, quint16>::const_iterator i = 
		strucTVMap.constBegin();
	while (i != strucTVMap.constEnd()) 
	{
		quint32 sid = (i.key() << 16) | id;
		if (strucLut.contains(sid))
		{
			fsid = sid;
			return true;
		}
		++i;
	}

	return false;
}