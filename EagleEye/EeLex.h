#pragma once

#include "EeCommon.h"

class EeSymbol;
class EeLex
{
public:
	EeLex(const QString& exp);

	bool parse(QVector<EeSymbol*>& symbols);

protected:
	EeSymbol* getSymbol();

	void readChar();

	bool readChar(QChar c);

	bool isEoExp();

private:
	QChar peek;
	quint16 pos;
	QString expression;
};