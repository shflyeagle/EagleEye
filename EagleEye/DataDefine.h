#pragma once

#include <QVariant>

#include <vector>

class DataProcessingState
{
public:
	unsigned packets{ 0 };
	unsigned filteredPackets{ 0 };
	unsigned curPageFilteredPackets{ 0 };
	unsigned elapsedTime{ 0 };
	unsigned totalKBSize{ 0 };
	unsigned loadedKBSize{ 0 };
	unsigned curPageNo{ 0 };
	unsigned totalPageNum{ 0 };
};

struct EeStrucId
{
public:
	EeStrucId() = default;
	EeStrucId(quint8 type, quint8 ver, quint16 id)
	{
		this->type = type;
		this->ver = ver;
		this->id = id;
	}

	EeStrucId(quint32 strucId)
	{
		this->type = (strucId >> 24);
		this->ver = ((strucId >> 16) & 0x00FF);
		this->id = (strucId & 0xFFFF);
	}

	quint8 type{0};
	quint8 ver{ 0 };
	quint16 id{0};
	quint32 getSID() const
	{
		return type << 24 | ver << 16 | id;
	}
};

struct CompLoc
{
	quint32 pos{ 0 };
	quint32 len{ 0 };
};
//
//struct PkgLoc
//{
//	CompLoc time;
//	CompLoc header;
//	CompLoc prefix;
//	CompLoc payload;
//	QVariant fk[MAX_NUM_FILTER_KW];
//};

struct PkgLoc
{
	PkgLoc()
	{
		for (int i = 0; i < MAX_NUM_FILTER_KW; ++i)
		{
			fk[i] = 0;
		}
	}
	quint32 timePos{ 0 };
	quint32 headerPos{ 0 };
	quint16 headerLen{ 0 };
	quint16 payloadLen{ 0 };
	quint32 payloadPos{ 0 };
	quint32 misc{ 0 };
	quint32 fk[MAX_NUM_FILTER_KW];
};

#define EE_PKG_HDR_LEN(headerLen) (headerLen & 0x00FF)

struct PkgPage
{	
	unsigned startPos{ 0 };
	unsigned endPos{ 0 };
	unsigned startPkgNo{ 0 };
	unsigned endPkgNo{ 0 };
	unsigned totalPkgNo{ 0 };
};

class PkgIdxPage
{
public:
	unsigned firstPkgIdx{ 0 };
	unsigned lastPkgIdx{ 0 };
	unsigned totalPkgIdx{ 0 };
};

class TabIdxPage
{
public:
	unsigned firstIdx{ 0 };
	unsigned idxCnt{ 0 };
};

using PkgPageList = std::vector<PkgPage>;
using PkgIdxPageList = std::vector<PkgIdxPage>;
using TabIdxPageList = std::vector<TabIdxPage>;

class PageContainer
{
public:
	int curPkgIdxPage{ -1 };
	unsigned totalPkgIdx{ 0 };
	int curPkgPage{ -1 };
	unsigned totalPkg{ 0 };
	unsigned curTabIdxPage{ -1 };
	unsigned isPkgPageSwitchSend{ false };
	PkgPageList pkgPageList;
	PkgIdxPageList pkgIdxPageList;
	TabIdxPageList tabIdxPageList;

public:
	void rstPkgPage(void)
	{
		curPkgPage = -1;
		totalPkg = 0;
		pkgPageList.clear();
		isPkgPageSwitchSend = false;
	}

	void rstPkgIdxPage(void)
	{
		curPkgIdxPage = -1;
		totalPkgIdx = 0;
		pkgIdxPageList.clear();
	}

	void rstTabIdxPage(void)
	{
		curTabIdxPage = -1;
		tabIdxPageList.clear();
	}

	void rst(void)
	{
		rstTabIdxPage();
		rstPkgIdxPage();
		rstPkgPage();
	}
};

using PkgIdx2PkgIdVec = QVector<quint32>;
using PkgId2PkgLocVec = QVector<PkgLoc>;
using RolesMap = QMap<int, QVariant>;

using Map4PkgIdxPage2PkgIdx2PkgIdVec = QMap<unsigned, PkgIdx2PkgIdVec*>;
using Map4PkgPage2PkgId2PkgLocVec = QMap<unsigned, PkgId2PkgLocVec*>;