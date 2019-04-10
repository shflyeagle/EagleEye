#pragma once

#include "PkgVisitor.h"

class DdtPkgVisitor : public PkgVisitor
{
public:
	DdtPkgVisitor();
	~DdtPkgVisitor();
};

class DdtPkgVisitorMng : public PkgVisitorMng
{
public:
	DdtPkgVisitorMng();

	~DdtPkgVisitorMng();

	PkgVisitor* getVisitor(unsigned pkgId) override;
};