#pragma once

#include "PkgVisitor.h"

class TigerPkgVisitor: public PkgVisitor
{
public:
	TigerPkgVisitor();
	~TigerPkgVisitor();
};

class TigerPkgVisitorMng: public PkgVisitorMng
{
public:
	TigerPkgVisitorMng();

	~TigerPkgVisitorMng();

	PkgVisitor* getVisitor(unsigned pkgId) override;
};

