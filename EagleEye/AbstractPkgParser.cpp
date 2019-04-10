#include "AbstractPkgParser.h"
#include "DataManager.h"

AbstractPkgParser::AbstractPkgParser(DataManager *dm):
qFile(dm->fileName)
{
	this->dm = dm;	
}

AbstractPkgParser::~AbstractPkgParser()
{
	if (qFile.isOpen())
	{
		qFile.close();
	}	
}

void AbstractPkgParser::parse(void)
{
	try
	{
		openFile();
		checkFileSanity();
		pagesLoad();
		parseFile();
	}
	catch (const std::exception &se)
	{
		QMessageBox::warning(dm->parent, QObject::tr("EagleEye"), se.what());
	}
	catch (...)
	{
		QMessageBox::warning(dm->parent, QObject::tr("EagleEye"), "unknown exception");
	}
}

void AbstractPkgParser::openFile(void)
{
	if (false == qFile.open(QIODevice::ReadOnly))
	{
		auto exeinfo = QObject::tr("AbstractPkgParser::openFile | failed to open file (%1)")
			.arg(qFile.fileName());
		throw EeException(exeinfo);
	}
}

void AbstractPkgParser::checkFileSanity(void)
{
	EELOG_DEBUG("AbstractPkgParser::checkFileSanity");
}

void AbstractPkgParser::pagesLoad(void)
{
	EELOG_DEBUG("AbstractPkgParser::pagesLoad");
}

void AbstractPkgParser::parseFile(void)
{
	EELOG_DEBUG("AbstractPkgParser::parseFile");
}

bool AbstractPkgParser::parsePayload(CompLoc &headerLoc, CompLoc &payloadLoc)
{
	EELOG_DEBUG("AbstractPkgParser::parsePayload");

	return true;
}
