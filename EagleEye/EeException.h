#pragma once

#include <exception>

#include <QString>

class EeException: public std::exception
{
public:
	explicit EeException(const QString& exeStr) :exception(exeStr.toStdString().c_str())
	{	
	}

	explicit EeException(const char* const exeStr) :exception(exeStr)
	{
	}
};