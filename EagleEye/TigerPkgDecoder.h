#pragma once

#include "PkgDecoder.h"

class TigerPkgDecoderMng : public PkgDecoderMng
{
public:	
	PkgDecoder* getDecoder(unsigned pkgId) override;
};

class TigerPkgDecoder: public PkgDecoder
{
public:
	TigerPkgDecoder() = default;

	TigerPkgDecoder(unsigned pkgId);

	virtual PkgDecoder* createInstance() override
	{
		return new TigerPkgDecoder;
	}

	void decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter = false) override;
};

