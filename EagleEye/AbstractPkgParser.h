#pragma once

#include "EeCommon.h"

class DataManager;

class AbstractPkgParser
{
public:
	AbstractPkgParser(DataManager *dm);
	virtual ~AbstractPkgParser();

	void parse(void);

protected:
	virtual void openFile(void);

	virtual void checkFileSanity(void);

	virtual void pagesLoad(void);

	virtual void parseFile(void);

	virtual bool parsePayload(CompLoc &headerLoc, CompLoc &payloadLoc) throw();

protected:
	QFile qFile;
	DataManager *dm;
	unsigned pkgNum{ 0 };
	unsigned parsedPkgNum{ 0 };
	QString errorStr;
};

