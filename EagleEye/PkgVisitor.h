#pragma once

#include "EeCommon.h"

class PkgDecoder;
class PkgVisitor
{
public:
	PkgVisitor();
	~PkgVisitor();

	virtual QString show(const PkgDecoder* decoder);
};

class PkgVisitorMng
{
public:
	~PkgVisitorMng()
	{
		for (auto it = pkgVisitors.begin(); it != pkgVisitors.end(); ++it)
		{
			delete it.value();
		}

		pkgVisitors.clear();
	}

	virtual PkgVisitor* getVisitor(unsigned pkgId) = 0;

protected:
	QMap<unsigned, PkgVisitor*> pkgVisitors;
};