#pragma once

#include "EeCommon.h"

enum
{
	LEX_SYM_DU		= 0,
	LEX_WORD_DU		= 1,
	LEX_KEYWORD_DU  = 2,
	LEX_OPERATOR_DU = 3,
	LEX_VALUE_DU    = 4,
};
#define LEX_DU_SHIFT	8

enum
{
	LEX_SYM_ID_LEFT_BRACKET		= LEX_SYM_DU << LEX_DU_SHIFT,
	LEX_SYM_ID_RIGHT_BRACKET,
	LEX_SYM_ID_NA,
	LEX_SYM_ID_WORD				= LEX_WORD_DU << LEX_DU_SHIFT,
	LEX_SYM_ID_TRUE				= LEX_KEYWORD_DU << LEX_DU_SHIFT,
	LEX_SYM_ID_FALSE,
	LEX_SYM_ID_AND				= LEX_OPERATOR_DU << LEX_DU_SHIFT,
	LEX_SYM_ID_OR,
	LEX_SYM_ID_EQ,
	LEX_SYM_ID_GE,
	LEX_SYM_ID_LE,
	LEX_SYM_ID_NE,
	LEX_SYM_ID_VALUE			= LEX_VALUE_DU << LEX_DU_SHIFT,
};

#define GET_LEX_SYM_DU(id)		(((quint16) id) >> LEX_DU_SHIFT)

enum
{
	LEX_OPERAND_NUM_1 = 1,
	LEX_OPERAND_NUM_2 = 2,
	LEX_OPERAND_NUM_MAX = LEX_OPERAND_NUM_2,
};

enum
{
	LEX_OPERATOR_PRI_1 = 1,
	LEX_OPERATOR_PRI_2 = 2,
	LEX_OPERATOR_PRI_3 = 3,
	LEX_OPERATOR_PRI_HIGHEST = LEX_OPERATOR_PRI_3
};

enum
{
	LEX_WORD_SUBDOMAIN_NUM_1 = 1,
	LEX_WORD_SUBDOMAIN_NUM_2 = 2,
	LEX_WORD_SUBDOMAIN_NUM_3 = 3,
};

class EeSymbol
{
public:
	EeSymbol(quint16 id, const QString& identifier) 
	{
		this->id = id;
		this->lexeme = identifier;
	}

	virtual ~EeSymbol()
	{
	}

	quint16 getId() const
	{
		return id;
	}

	const QString& getIdentifier() const
	{
		return lexeme;
	}

	bool equals(quint16 id) const
	{
		return this->id == id;
	}

	bool isSymbol() const
	{
		return LEX_SYM_DU == GET_LEX_SYM_DU(id);
	}

	bool isOperator() const
	{
		return LEX_OPERATOR_DU == GET_LEX_SYM_DU(id);
	}

	bool isWord() const
	{
		return LEX_WORD_DU == GET_LEX_SYM_DU(id);
	}

	bool isKeyword() const
	{
		return LEX_KEYWORD_DU == GET_LEX_SYM_DU(id);
	}

	bool isValue() const
	{
		return LEX_VALUE_DU == GET_LEX_SYM_DU(id);
	}

	virtual EeSymbol* clone()
	{
		return new EeSymbol(*this);
	}

	virtual quint32 interpret(const QString &subdoman,
		const quint32 *varr = Q_NULLPTR)
	{
		Q_UNUSED(subdoman);
		Q_UNUSED(varr);

		return false;
	}

	virtual QString dump() const
	{
		return QString("Symbol: id(%1) - lexeme(%2)")
			.arg(id).arg(lexeme);
	}

protected:
	quint16 id;

	QString lexeme;
};


class EeValue : public EeSymbol
{
public:
	EeValue(const QVariant &value);

	EeSymbol *clone();

	quint32 interpret(const QString &subdoman,
		const quint32 *varr = Q_NULLPTR) override;

	const QVariant& getValue() const;

	QString dump() const;

private:
	QVariant value;
};


class EeWord : public EeSymbol
{
public:
	EeWord(quint16 id, const QString& identifier);

	EeSymbol *clone();	

	QString dump() const;

	quint32 interpret(const QString &subdoman,
		const quint32 *varr = Q_NULLPTR) override;

	const QString &getDomain(quint8 pos) const;

	quint8 getDomainSize() const;

	void setValueFollowed(bool isValueFollowed);

private:
	QStringList subdomains;

	bool isValueFollowed{ true };

	quint16 valueIdx{ 0XFF };
};


class EeOperator : public EeSymbol
{
public:
	EeOperator(quint16 id, const QString& lexeme,
		quint8 priority, quint8 dimension = LEX_OPERAND_NUM_2);

	quint8 getPriority() const;

	quint8 getDimension() const;

	const QVector<quint32> &getOperands() const;

	void setOperands(const QVector<quint32> &operands);

protected:
	quint8 priority;

	quint8 dimension;

	QVector<quint32> operands;
};


class EeOperatorAND : public EeOperator
{
public:
	EeOperatorAND();

	EeSymbol *clone();

	QString dump() const;

	quint32 interpret(const QString &subdoman,
		const quint32 *varr = Q_NULLPTR) override;
};


class EeOperatorOR : public EeOperator
{
public:
	EeOperatorOR();

	EeSymbol *clone();

	QString dump() const;

	quint32 interpret(const QString &subdoman,
		const quint32 *varr = Q_NULLPTR) override;
};


class EeOperatorEQ : public EeOperator
{
public:
	EeOperatorEQ();

	EeSymbol *clone();

	QString dump() const;

	quint32 interpret(const QString &subdoman,
		const quint32 *varr = Q_NULLPTR) override;

};


class EeOperatorGE : public EeOperator
{
public:
	EeOperatorGE();

	EeSymbol *clone();

	QString dump() const;

	quint32 interpret(const QString &subdoman,
		const quint32 *varr = Q_NULLPTR) override;
};


class EeOperatorLE : public EeOperator
{
public:
	EeOperatorLE();

	EeSymbol *clone();

	QString dump() const;

	quint32 interpret(const QString &subdoman,
		const quint32 *varr = Q_NULLPTR) override;
};


class EeOperatorNE : public EeOperator
{
public:
	EeOperatorNE();

	EeSymbol *clone();

	QString dump() const;

	quint32 interpret(const QString &subdoman,
		const quint32 *varr = Q_NULLPTR) override;
};


class EeSymManager
{
public:	
	static void init();

	static void clear();

	static bool regSym(EeSymbol* symb);

	static bool existSym(const QString& identifier);

	static EeSymbol* getSym(const QString& identifier);
	
	static bool checkValidity(EeSymbol* symb);

public:
	static QHash<QString, EeSymbol*> symMap;
};
