
#include "StrucTree.h"
#include "StrucTreeComm.h"
#include "StrucLUT.h"


template<typename T>
void decodeFieldValue(const QByteArray& a, StrucTree* st)
{
	FieldInfo* fi = st->getFieldInfo();
	FieldDes &fd = fi->fd;
	qint16 offsetInByte = fd.offsetInByte;
	qint8 offsetInBit = fd.offsetInBit;
	qint8 sizeInBit = fd.sizeInBit;

	const uchar* fvPos = PTR_CVT_Any2ConstUchar(a.data() + offsetInByte);
	T tmpFv = qFromBigEndian<T>(fvPos);

	if (0 == sizeInBit)
	{
		fi->fv = tmpFv;
	}
	else
	{
		qint32 mask = 0;
		quint8 pos;
		for (pos = 0; pos < sizeInBit; ++pos)
		{
			mask |= (1 << pos);
		}
		quint8 shift = sizeof(T)* 8 - (sizeInBit + offsetInBit);

		fi->fv = ((tmpFv & (mask << shift)) >> (shift));
	}

	//EELOG_DEBUG("StrucTree::decodeFieldValue|value (" 
	//	<< (fi->fv.isValid() ? QSTR2CSTR(fi->fv.toString()) : "") 
	//	<< ")");
}

std::vector<std::function<void(const QByteArray&, StrucTree*)> > StrucTree::fiDCBs =
{
	std::bind(decodeFieldValue<qint8>,	 
	std::placeholders::_1, std::placeholders::_2),
	std::bind(decodeFieldValue<qint16>,  
	std::placeholders::_1, std::placeholders::_2),
	std::bind(decodeFieldValue<qint32>,	 
	std::placeholders::_1, std::placeholders::_2),
	std::bind(decodeFieldValue<quint8>,  
	std::placeholders::_1, std::placeholders::_2),
	std::bind(decodeFieldValue<quint16>, 
	std::placeholders::_1, std::placeholders::_2),
	std::bind(decodeFieldValue<quint32>, 
	std::placeholders::_1, std::placeholders::_2),
};

StrucTree::StrucTree(FieldInfo *fi, StrucTree *parent)
{
	this->fi = fi;
	this->parent = parent;
	childs.clear();
	kv.clear();
}

StrucTree::~StrucTree()
{
	delete fi;
	fi = nullptr;

	qDeleteAll(childs);
	childs.clear();

	parent = nullptr;

	kv.clear();
}

StrucTree::StrucTree(const StrucTree& st)
{
	copyFrom(st);
}

StrucTree& StrucTree::operator = (const StrucTree& st)
{
	if (this == &st)
	{
		return *this;
	}

	copyFrom(st);

	return *this;
}

void StrucTree::copyFrom(const StrucTree& st)
{
	id = st.id;
	fi = new FieldInfo(*(st.fi));
	parent = nullptr;
	kv.clear();

	StrucTree *c;
	foreach(c, st.childs)
	{
		StrucTree *cClone = c->clone();
		cClone->setParent(this);
		childs.append(cClone);
	}
}

StrucTree *StrucTree::clone()
{
	StrucTree *pClone = 
		new StrucTree(new FieldInfo(*(fi)));
	pClone->setId(id);

	//dumpFieldInfo(*(pClone->getFieldInfo()));	

	StrucTree *c;
	foreach(c, childs)
	{
		StrucTree *cClone = c->clone();
		cClone->setParent(pClone);
		pClone->childs.append(cClone);
	}

	return pClone;
}

int StrucTree::getFieldValue(const QString &fieldName) const
{
	if (kv.contains(fieldName))
	{
		return kv.value(fieldName).toInt();
	}
	else
	{
		EELOG_ERROR("StrucTree::getFieldValue|failed to get (" << QSTR2CSTR(fieldName) << ")");
		Q_ASSERT(false);
		return 0;
	}
}


StrucTree* StrucTree::getChild(const QString &fieldName)
{
	StrucTree* retSt = Q_NULLPTR;

	if (fi != Q_NULLPTR)
	{
		if (fi->fd.name == fieldName)
		{
			retSt = this;
		}
		else if (childCount())
		{
			StrucTree *c;
			foreach(c, childs)
			{
				retSt = c->getChild(fieldName);
				if (retSt != Q_NULLPTR)
				{
					break;
				}
			}
		}
	}

	return retSt;
}

quint16 StrucTree::getOffsetInByte(const QString &fieldName)
{
	StrucTree* cst = getChild(fieldName);
	if (Q_NULLPTR == cst)
	{
		Q_ASSERT(false);
	}

	return cst->fi->fd.offsetInByte;
}

void StrucTree::shiftOffsetInByte(quint16 offset)
{
	if (fi)
	{		
		fi->fd.offsetInByte += offset;

		StrucTree *c;
		foreach(c, childs)
		{
			c->shiftOffsetInByte(offset);
		}
	}
}


quint16 StrucTree::getSizeInByte() const
{
	if (fi)
	{		
		return fi->fd.sizeInByte;
	}
	else
	{
		return 0;
	}
}

void StrucTree::shiftSizeInByte(quint16 offset)
{
	if (fi)
	{		
		fi->fd.sizeInByte += offset;
	}
}

FieldInfo* StrucTree::getFieldInfo() const
{
	return fi;
}

const QHash<QString, QVariant> *StrucTree::getKvMap() const
{
	return &kv;
}

void StrucTree::insertKV(const QString &k, const QVariant& v)
{
	auto it = kv.find(k);
	if (it == kv.end())
	{
		kv.insert(k, v);
	}
}

QString StrucTree::dump(int ident)
{
	if (Q_NULLPTR == fi)
	{
		return QString();
	}

	QString dump;
	dump.sprintf("%s%-55s|%-15s|%-4d|%-4d|%-4d|%-4d|%-4d|\n",
		QString(ident, ' ').toStdString().c_str(),
		fi->fd.name.toStdString().c_str(),
		fi->fd.type.toStdString().c_str(),
		(int)fi->fd.offsetInByte,
		(int)fi->fd.sizeInByte,
		(int)fi->fd.offsetInBit,
		(int)fi->fd.sizeInBit,
		(int)fi->fd.baseTypeIdx);

	StrucTree *c;
	foreach(c, childs)
	{
		dump.append(c->dump(ident + 2));
	}

	return dump;
}

void StrucTree::decode(const QByteArray& a, StrucTree *rst, PkgLoc* pkgLoc)
{
	StrucTree* st = Q_NULLPTR;
	foreach(st, childs)
	{
		if (st->childs.size())
		{
			st->decode(a, rst, pkgLoc);
		}
		else
		{
			quint8 baseTypeIdx = st->fi->fd.baseTypeIdx;		
			if (baseTypeIdx < BASE_TYPE_IDX_MAX)
			{
				StrucTree::fiDCBs[baseTypeIdx](a, st);
			}			
			else
			{
				EELOG_ERROR("StrucTree::decode|baseTypeIdx (" 
					<< baseTypeIdx 
					<< ") beyond (" 
					<< BASE_TYPE_IDX_MAX - 1 
					<< ")");

				Q_ASSERT((baseTypeIdx < BASE_TYPE_IDX_MAX));
			}
			
			if (st->fi->fd.fkIdx != 0xFF && pkgLoc != Q_NULLPTR)
			{	
				//pkgLoc->fk[MAX_NUM_FILTER_KW - 1] = true;
				pkgLoc->fk[st->fi->fd.fkIdx] = st->fi->fv.toUInt();
				//fk[StrucLUT::fkLut.value(st->fi->fd.name)] = st->fi->fv;				
			}

			if (rst)
			{
				//EELOG_INFO("StrucTree::decode|insert key (" 
				//	<< QSTR2CSTR(st->fi->fd.name)
				//	<< ") value (" 
				//	<< QSTR2CSTR(st->fi->fv.toString()) 
				//	<< ")");
				rst->insertKV(st->fi->fd.name, st->fi->fv);
			}			
	
			//dumpFieldInfo(*(st->fi));
		}
	}
}

void StrucTree::appendChild(StrucTree *child)
{
	childs.append(child);
}

const QList<StrucTree*> *StrucTree::getChildren() const
{
	return &childs;
}

StrucTree *StrucTree::getChild(int row)
{
	return childs.value(row);
}

int StrucTree::childCount() const
{
	return childs.count();
}

int StrucTree::columnCount() const
{
	return 1;
}

QVariant StrucTree::data(int column) const
{
	if (Q_NULLPTR == fi)
	{
		return QVariant();
	}

	const FieldDes &fd = fi->fd;
	switch (column)
	{
		case FI_IDX_NAME:                return fd.name;
		case FI_IDX_SIZE_IN_BYTE:        return fd.sizeInByte;
		case FI_IDX_SIZE_IN_BIT:         return fd.sizeInBit;
		case FI_IDX_VALUE:               return fi->fv;
		case FI_IDX_OFFSET_IN_BYTE:      return fd.offsetInByte;
		case FI_IDX_OFFSET_IN_BIT:       return fd.offsetInBit;
		case FI_IDX_TYPE:				 return fd.type;
		default:                         return QVariant();
	}
}

StrucTree *StrucTree::getParent()
{
	return parent;
}

void StrucTree::setParent(StrucTree *pst)
{
	parent = pst;
}

int StrucTree::row() const
{
	if (parent)
	{
		return parent->childs.indexOf(const_cast<StrucTree*>(this));
	}

	return 0;
}

//const quint32* StrucTree::getFK() const
//{
//	return fk;
//}

void StrucTree::addFK(QString &key, QVariant &value)
{
	//auto it = StrucLUT::fkLut.find(key);
	//if (it == StrucLUT::fkLut.end())
	//{
	//	EELOG_ERROR("StrucTree::addFK|no key (" << QSTR2CSTR(key) << ")");
	//	Q_ASSERT(false);
	//	return;
	//}	

	//fk[it.value()] = value;
}