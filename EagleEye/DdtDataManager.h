#pragma once

#include "DataManager.h"

class DdtDataManager :
	public DataManager
{
public:

	friend class AbstractPkgParser;
	friend class PcapPkgParser;
	friend class DdtPkgParser;

	DdtDataManager(QWidget *parent);
	~DdtDataManager();

	QString getFilterExpression4Export(quint32 decodeId, const StrucTree* st) override;

	unsigned getDecoderId(const PkgLoc* pkgLoc) override;

	QByteArray getDecoderCxt(const PkgLoc* pkgLoc) override;

	QByteArray getDecoderCxt4Filter(const PkgLoc* pkgLoc) override;

	std::shared_ptr<AbstractPkgParser> getPacketParser(void) override;
};