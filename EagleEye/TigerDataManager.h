#pragma once

#include "DataManager.h"

class TigerDataManager :
	public DataManager
{
public:

	friend class AbstractPkgParser;
	friend class PcapPkgParser;
	friend class TigerPkgParser;

	TigerDataManager(QWidget *parent);
	~TigerDataManager();

	unsigned getDecoderId(const PkgLoc* pkgLoc) override;

	QByteArray getDecoderCxt(const PkgLoc* pkgLoc) override;

	QByteArray getDecoderCxt4Filter(const PkgLoc* pkgLoc) override;

	std::shared_ptr<AbstractPkgParser> getPacketParser(void) override;
};

