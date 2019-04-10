#pragma once

#include "EeCommon.h"

class AbstractPkgParser;
class PkgPageThread;
class PcapPkgParser;
class TigerPkgParser;
class DdtPkgParser;
class PkgDecoderMng;
class PkgVisitorMng;
class StrucTree;

class DataManager
{
public:
	friend class AbstractPkgParser;
	friend class PcapPkgParser;
	friend class TigerPkgParser;
	friend class DdtPkgParser;

	DataManager(QWidget *parent);
	virtual ~DataManager();

	void loadPackets(const QString& fileName);

	unsigned getPkgIdByPkgIdx(unsigned pkgIdx);

	unsigned getLocalPkgIdx(unsigned glocalPkgIdx);

	PkgLoc *getPkgLocByPkgIdx(unsigned pkgIdx);

	PkgLoc *getPkgLocByPkgId(unsigned pkgId);

	unsigned getCurTabPagePkgCount(void);

	QByteArray getTime(unsigned pkgIdx);

	unsigned getDecoderId(unsigned pkgIdx);

	QByteArray getDecoderCxt(unsigned pkgIdx);

	virtual QString getFilterExpression4Export(quint32 decodeId, const StrucTree* st);	

	virtual QByteArray getTime(const PkgLoc* pkgLoc);
		
	virtual unsigned getDecoderId(const PkgLoc* pkgLoc);
		
	virtual QByteArray getDecoderCxt(const PkgLoc* pkgLoc);

	virtual QByteArray getDecoderCxt4Filter(const PkgLoc* pkgLoc);

	void filter();

	void fetchPkgIdxs(quint32 decodeId, QVector<quint32> * const pkgIdxVec);
		
	virtual std::shared_ptr<AbstractPkgParser> getPacketParser(void);		

	void insertPkgIdxPkgIdPair(unsigned pkgIdx, unsigned pkgId);

	void updatePkgIdxPkgIdPair(unsigned pkgIdx, unsigned pkgId);

	void insertPkgLoc(const PkgLoc& pkgLoc);

	void clear();

	PkgDecoderMng *getPkgDecoderMng() const;

	PkgVisitorMng *getPkgVisitorMng() const;

	QString getPacketStatus() const;

	bool isFirstPage() const;

	bool isLastPage() const;

	bool check2FetchPreviousPage();

	bool check2FetchNextPage();

	bool doesFilterOnceDone() const
	{
		return isFilterOnceDone;
	}

private:
	void check2Paging();

	void resizePkgPageSize(int pageIdx);

	void checkPkgIdxPageSize(int pageIdx);

	void updateDataProcessingState();

	void clearPkgIdxPages();

protected:
	QString fileName{""};

	Map4PkgIdxPage2PkgIdx2PkgIdVec map4PkgIdxPage2PkgIdx2PkgIdVec;
	Map4PkgPage2PkgId2PkgLocVec map4PkgPage2PkgId2PkgLocVec;
	PageContainer pageContainer;
	QByteArray *pkgPageRawData{ nullptr };
	DataProcessingState dataProcessingState;
	std::shared_ptr<PkgPageThread> pkgPageThread;
	std::shared_ptr<PkgDecoderMng> pkgDecoderMng;
	std::shared_ptr<PkgVisitorMng> pkgVisitorMng;
	QWidget *parent;
	bool isFilterOnceDone{ false };
};

#define GET_PDATA() (dm->pkgPageRawData->data())