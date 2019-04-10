#include "EeLex.h"
#include "EeLexSymbol.h"

EeLex::EeLex(const QString& exp) :
peek(' '), pos(0), expression(exp)
{
}

bool EeLex::parse(QVector<EeSymbol*>& symbols)
{
	bool rc = true;

	EeSymbol *sym = Q_NULLPTR;
	do
	{
		sym = getSymbol();
		if (Q_NULLPTR == sym)
		{
			break;
		}

		EELOG_INFO("Got: " << sym->dump().toStdString().c_str());

		if (!EeSymManager::checkValidity(sym))
		{
			EELOG_WARN("Not found: " << sym->dump().toStdString().c_str());

			delete sym;

			qDeleteAll(symbols);
			symbols.clear();

			rc = false;
			break;
		}

		symbols.push_back(sym);

	} while (true);

	return rc;
}


EeSymbol* EeLex::getSymbol()
{
	for (; !isEoExp(); readChar())
	{
		if (peek == ' ' || peek == '\t')
		{
			continue;
		}
		else
		{
			break;
		}
	}

	if (isEoExp() && peek == ' ')
	{
		return (EeSymbol*)Q_NULLPTR;
	}

	switch (peek.toLatin1())
	{
		case '&':
		{
			if (readChar('&'))
			{
				return EeSymManager::getSym("&&");
			}
			else
			{
				return new EeSymbol(LEX_SYM_ID_NA, "&");
			}
		}

		case '|':
		{
			if (readChar('|'))
			{
				return EeSymManager::getSym("||");
			}
			else
			{
				return new EeSymbol(LEX_SYM_ID_NA, "|");
			}
		}

		case '=':
		{
			if (readChar('='))
			{
				return EeSymManager::getSym("==");
			}
			else
			{
				return new EeSymbol(LEX_SYM_ID_NA, "=");
			}
		}

		case '!':
		{
			if (readChar('='))
			{
				return EeSymManager::getSym("!=");
			}
			else
			{
				return new EeSymbol(LEX_SYM_ID_NA, "!");
			}
		}

		case '<':
		{
			if (readChar('='))
			{
				return EeSymManager::getSym("<=");
			}
			else
			{
				return new EeSymbol(LEX_SYM_ID_NA, "<");
			}
		}

		case '>':
		{
			if (readChar('='))
			{
				return EeSymManager::getSym(">=");
			}
			else
			{
				return new EeSymbol(LEX_SYM_ID_NA, ">");
			}
		}

		default:
			break;
	}

	if (peek.isDigit())
	{
		int v = 0;
		do
		{
			v = v * 10 + peek.digitValue();
			readChar();
		} while (peek.isDigit());

		return new EeValue(v);
	}

	if (peek.isLetter())
	{
		QString lexeme;
		do
		{
			lexeme.append(peek);
			readChar();
		} while (peek.isLetterOrNumber() || peek == '.');

		if (EeSymManager::existSym(lexeme))
		{
			return EeSymManager::getSym(lexeme);
		}
		else
		{
			return new EeWord(LEX_SYM_ID_WORD, lexeme);
		}
	}

	EeSymbol *sym = Q_NULLPTR;
	switch (peek.toLatin1())
	{
		case '(':
		{
			sym = EeSymManager::getSym("(");
			break;
		}

		case ')':
		{
			sym = EeSymManager::getSym(")");
			break;
		}

		default:
		{
			sym = new EeSymbol(LEX_SYM_ID_NA, peek);
			break;
		}
	}

	peek = ' ';
	return sym;
}

void EeLex::readChar()
{
	if (!isEoExp())
	{
		peek = expression.at(pos);
		pos++;
	}
	else
	{
		peek = ' ';
	}
}

bool EeLex::readChar(QChar c)
{
	if (isEoExp())
	{
		return false;
	}

	readChar();
	if (peek != c)
	{
		return false;
	}
	peek = ' ';
	return true;
}

bool EeLex::isEoExp()
{
	return pos >= expression.size();
}
