#pragma once

#include "PkgDecoder.h"

class DdtPkgDecoderMng : public PkgDecoderMng
{
public:
	PkgDecoder* getDecoder(unsigned pkgId) override;
};

class DdtPkgDecoder : public PkgDecoder
{
public:
	DdtPkgDecoder() = default;

	DdtPkgDecoder(unsigned pkgId);

	virtual PkgDecoder* createInstance() override
	{
		return new DdtPkgDecoder;
	}

	void decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter = false) override;
};

class DdtDlPkgDecoderComm : public DdtPkgDecoder
{
public:
	DdtDlPkgDecoderComm() = default;

	DdtDlPkgDecoderComm(unsigned pkgId);

	virtual PkgDecoder* createInstance() override
	{
		return new DdtDlPkgDecoderComm;
	}

	void decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter = false) override;
};

class DdtDlPkgDecoder : public DdtDlPkgDecoderComm
{
public:
	DdtDlPkgDecoder() = default;

	DdtDlPkgDecoder(unsigned pkgId);

	virtual PkgDecoder* createInstance() override
	{
		return new DdtDlPkgDecoder;
	}

	void decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter = false) override;
};

class DdtPkgDecoderB0010 : public DdtDlPkgDecoder
{
public:
	DdtPkgDecoderB0010() = default;

	DdtPkgDecoderB0010(unsigned pkgId);

	virtual PkgDecoder* createInstance() override
	{
		return new DdtPkgDecoderB0010;
	}

	void decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter = false) override;
};

class DdtPkgDecoderB0011 : public DdtDlPkgDecoder
{
public:
	DdtPkgDecoderB0011() = default;

	DdtPkgDecoderB0011(unsigned pkgId);

	virtual PkgDecoder* createInstance() override
	{
		return new DdtPkgDecoderB0011;
	}

	void decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter = false) override;
};

class DdtPkgDecoderB0501 : public DdtDlPkgDecoder
{
public:
	DdtPkgDecoderB0501() = default;

	DdtPkgDecoderB0501(unsigned pkgId);

	virtual PkgDecoder* createInstance() override
	{
		return new DdtPkgDecoderB0501;
	}

	void decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter = false) override;
};

class DdtPkgDecoderB0701 : public DdtDlPkgDecoder
{
public:
	DdtPkgDecoderB0701() = default;

	DdtPkgDecoderB0701(unsigned pkgId);

	virtual PkgDecoder* createInstance() override
	{
		return new DdtPkgDecoderB0701;
	}

	void decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter = false) override;
};

class DdtPkgDecoderB0301 : public DdtDlPkgDecoderComm
{
public:
	DdtPkgDecoderB0301() = default;

	DdtPkgDecoderB0301(unsigned pkgId);

	virtual PkgDecoder* createInstance() override
	{
		return new DdtPkgDecoderB0301;
	}

	void decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter = false) override;
};

class DdtPkgDecoderB2501 : public DdtDlPkgDecoderComm
{
public:
	DdtPkgDecoderB2501() = default;

	DdtPkgDecoderB2501(unsigned pkgId);

	virtual PkgDecoder* createInstance() override
	{
		return new DdtPkgDecoderB2501;
	}

	void decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter = false) override;
};

class DdtPkgDecoderB1801 : public DdtDlPkgDecoder
{
public:
	DdtPkgDecoderB1801() = default;

	DdtPkgDecoderB1801(unsigned pkgId);

	virtual PkgDecoder* createInstance() override
	{
		return new DdtPkgDecoderB1801;
	}

	void decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter = false) override;
};

class DdtUlPkgDecoder : public DdtPkgDecoder
{
public:
	DdtUlPkgDecoder() = default;

	DdtUlPkgDecoder(unsigned pkgId);

	virtual PkgDecoder* createInstance() override
	{
		return new DdtUlPkgDecoder;
	}

	void decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter = false) override;
};