#pragma once

#include "EeCommon.h"
#include "DataDefine.h"
#include "ee_buffer_manage.h"

class FieldDes
{
public:
	QString type{ "" };
	QString name{ "" };
	qint16  offsetInByte{ 0 };
	qint16  sizeInByte{ 0 };
	qint8   offsetInBit{ 0 };
	qint8   sizeInBit{ 0 };
#define BASE_TYPE_IDX_QINT8		0
#define BASE_TYPE_IDX_QINT16	1
#define BASE_TYPE_IDX_QINT32	2
#define BASE_TYPE_IDX_QUINT8	3
#define BASE_TYPE_IDX_QUINT16	4
#define BASE_TYPE_IDX_QUINT32	5
#define BASE_TYPE_IDX_MAX	BASE_TYPE_IDX_QUINT32 + 1
	quint8   baseTypeIdx{ 0xFF };
	quint8   fkIdx{ 0xFF };
};

using FieldVal = QVariant;

class FieldInfo
{
public:
	FieldDes fd;
	FieldVal fv;

	//void* operator new(size_t size) throw (std::bad_alloc)
	//{
	//	//EELOG_DEBUG("FieldInfo::operator new size (" << size << ")");
	//	void * buf = EE_ALLOC(size);
	//	if (nullptr == buf)
	//	{
	//		throw std::bad_alloc();
	//	}
	//	else
	//	{
	//		return buf;
	//	}
	//}

	//void operator delete(void* buf)
	//{
	//	if (nullptr != buf)
	//	{
	//		EE_FREE(buf);
	//	}		
	//}
};

inline void dumpFieldInfo(const FieldInfo& fi)
{
	const FieldDes &fd = fi.fd;
	QString value;
	if (fi.fv.isValid())
	{
		value = QString(", value (%1)").arg(fi.fv.toString());
	}

	EELOG_DEBUG("FI: name (" << QSTR2CSTR(fd.name) <<
				"), type (" << QSTR2CSTR(fd.type) <<
				"), offsetInByte (" << fd.offsetInByte <<
				"), sizeInByte (" << fd.sizeInByte << 
				"), offsetInBit (" << fd.offsetInBit << 
				"), sizeInBit (" << fd.sizeInBit << 
				"), baseTypeIdx (" << fd.baseTypeIdx <<
				"), fkIdx (" << fd.fkIdx <<
				")" << QSTR2CSTR(value));
}

class StrucTree
{
public:	
	enum
	{
		FI_IDX_TYPE,
		FI_IDX_NAME,
		FI_IDX_SIZE_IN_BYTE,
		FI_IDX_SIZE_IN_BIT,
		FI_IDX_OFFSET_IN_BYTE,
		FI_IDX_OFFSET_IN_BIT,
		FI_IDX_VALUE,
	};

public:
	explicit StrucTree(FieldInfo *fi, StrucTree *parent = Q_NULLPTR);

	StrucTree() = default;

	~StrucTree();

	StrucTree(const StrucTree& st);

	StrucTree& operator = (const StrucTree& st);

	//void* operator new(size_t size) throw (std::bad_alloc)
	//{		
	//	//EELOG_DEBUG("StrucTree::operator new size (" << size << ")");
	//	void * buf = EE_ALLOC(size);
	//	if (nullptr == buf)
	//	{
	//		throw std::bad_alloc();
	//		return nullptr;
	//	}
	//	else
	//	{
	//		//EELOG_DEBUG("ALLOCATED BUF ptr = " << buf);
	//		return buf;
	//	}
	//}

	//void operator delete(void* buf)
	//{
	//	if (nullptr != buf)
	//	{
	//		//EELOG_DEBUG("DEALLOCATED BUF ptr = " << buf);
	//		EE_FREE(buf);
	//	}		
	//}

	void appendChild(StrucTree *child);

	const QList<StrucTree*> *getChildren() const;

	StrucTree *getChild(int row);

	int childCount() const;

	int columnCount() const;

	QVariant data(int column) const;

	int row() const;

	StrucTree *getParent();

	void setParent(StrucTree *pst = 0);

	void decode(const QByteArray& a, StrucTree *rst, PkgLoc* pkgLoc = nullptr);

	StrucTree *clone();

	StrucTree *getChild(const QString &fieldName);

	int getFieldValue(const QString &fieldName) const;

	quint16 getOffsetInByte(const QString &fieldName);

	void shiftOffsetInByte(quint16 offset);

	quint16 getSizeInByte() const;

	void shiftSizeInByte(quint16 offset);

	FieldInfo *getFieldInfo() const;

	const QHash<QString, QVariant> *getKvMap() const;

	void insertKV(const QString &k, const QVariant& v);

	QString dump(int ident = 0);

	//const quint32* getFK() const;

	void addFK(QString &key, QVariant &value);

	void setId(quint16 id)
	{
		this->id = id;
	}

	quint16 getId() const
	{
		return id;
	}

private:
	void copyFrom(const StrucTree& st);

private:
	QList<StrucTree*> childs;

	FieldInfo *fi{nullptr};

	StrucTree *parent{nullptr};

	//quint32 fk[MAX_NUM_FILTER_KW];

	QHash<QString, QVariant> kv;

	quint16 id{INVALID_U16};

	static std::vector<std::function<void(const QByteArray&, StrucTree*)> > fiDCBs;
};

template<typename T>
void decodeFieldValue(const QByteArray& a, StrucTree* st);