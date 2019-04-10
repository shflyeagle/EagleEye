#include "EeLexSymbol.h"

EeSymbol* EeValue::clone()
{
	return new EeValue(*this);
}

QString EeValue::dump() const
{
	return QString("EeValue: id(%1) - lexeme(%2) - value(%3)")
		.arg(id).arg(lexeme).arg(value.toInt());
}

const QVariant& EeValue::getValue() const
{
	return value;
}

EeValue::EeValue(const QVariant & value):
EeSymbol(LEX_SYM_ID_VALUE, "CONST")
{
	this->value = value;
}

quint32 EeValue::interpret(const QString &subdoman,
	const quint32 *varr)
{
	Q_UNUSED(subdoman);
	Q_UNUSED(varr);

	return value.toUInt();
}

EeSymbol* EeWord::clone()
{
	return new EeWord(*this);
}

QString EeWord::dump() const
{
	return QString("EeWord: id(%1) - lexeme(%2) - subdomain(%3) - valueFollowed(%4) - valueIdx(%5)")
		.arg(id).arg(lexeme).arg(subdomains.join(':')).arg(isValueFollowed).arg(valueIdx);
}

EeWord::EeWord(quint16 id, const QString& identifier):
EeSymbol(id, identifier)
{
	subdomains = identifier.split('.');	
	valueIdx = id - LEX_SYM_ID_WORD;
}

const QString &EeWord::getDomain(quint8 pos) const
{
	return subdomains.at(pos);
}

quint8 EeWord::getDomainSize() const
{
	return subdomains.size();
}

void EeWord::setValueFollowed(bool isValueFollowed)
{
	this->isValueFollowed = isValueFollowed;
}

quint32 EeWord::interpret(const QString &subdoman,
	const quint32 *varr)
{
	//if (Q_NULLPTR == varr)
	//{
	//	return QVariant();
	//}

	//if (LEX_WORD_SUBDOMAIN_NUM_3 == subdomains.size())
	//{
	//	if (0 != subdoman.compare(subdomains.at(1)))
	//	{
	//		return false;
	//	}
	//}

	const quint32 & v = varr[valueIdx];
	if (isValueFollowed)
	{
		return v;
	}
	else
	{
		return true;
	}		
}

EeOperator::EeOperator(quint16 id, 
	const QString& lexeme, quint8 priority, quint8 dimension) :
	EeSymbol(id, lexeme), priority(priority), dimension(dimension)
{
}

quint8 EeOperator::getPriority() const
{
	return priority;
}

quint8 EeOperator::getDimension() const
{
	return dimension;
}

const QVector<quint32> &EeOperator::getOperands() const
{
	return operands;
}

void EeOperator::setOperands(const QVector<quint32> &operands)
{
	this->operands = operands;
}

EeOperatorAND::EeOperatorAND() :
EeOperator(LEX_SYM_ID_AND, "&&", LEX_OPERATOR_PRI_1, LEX_OPERAND_NUM_2)
{
}

EeSymbol * EeOperatorAND::clone()
{
	return new EeOperatorAND(*this);
}

QString EeOperatorAND::dump() const
{
	return QString("EeOperatorAND: id(%1) - lexeme(%2) - priority(%3) - dimension(%4)")
		.arg(id).arg(lexeme).arg(priority).arg(dimension);
}

quint32 EeOperatorAND::interpret(const QString &subdoman,
	const quint32 *varr)
{
	Q_UNUSED(subdoman);
	Q_UNUSED(varr);

	//Q_ASSERT(LEX_OPERAND_NUM_2 == operands.size());

	return operands.at(0) && operands.at(1);	
}

EeOperatorOR::EeOperatorOR():
EeOperator(LEX_SYM_ID_OR, "||", LEX_OPERATOR_PRI_1, LEX_OPERAND_NUM_2)
{
}

EeSymbol * EeOperatorOR::clone()
{
	return new EeOperatorOR(*this);
}

QString EeOperatorOR::dump() const
{
	return QString("EeOperatorOR: id(%1) - lexeme(%2) - priority(%3) - dimension(%4)")
		.arg(id).arg(lexeme).arg(priority).arg(dimension);
}

quint32 EeOperatorOR::interpret(const QString &subdoman,
	const quint32 *varr)
{
	Q_UNUSED(subdoman);
	Q_UNUSED(varr);

	//Q_ASSERT(LEX_OPERAND_NUM_2 == operands.size());

	return operands.at(0) || operands.at(1);
}

EeOperatorEQ::EeOperatorEQ():
EeOperator(LEX_SYM_ID_EQ, "==", LEX_OPERATOR_PRI_2, LEX_OPERAND_NUM_2)
{
}

EeSymbol * EeOperatorEQ::clone()
{
	return new EeOperatorEQ(*this);
}

QString EeOperatorEQ::dump() const
{
	return QString("EeOperatorEQ: id(%1) - lexeme(%2) - priority(%3) - dimension(%4)")
		.arg(id).arg(lexeme).arg(priority).arg(dimension);
}

quint32 EeOperatorEQ::interpret(const QString &subdoman,
	const quint32 *varr)
{
	Q_UNUSED(subdoman);
	Q_UNUSED(varr);

	//Q_ASSERT(LEX_OPERAND_NUM_2 == operands.size());

	return operands.at(0) == operands.at(1);
}

EeOperatorGE::EeOperatorGE():
EeOperator(LEX_SYM_ID_GE, ">=", LEX_OPERATOR_PRI_2, LEX_OPERAND_NUM_2)
{
}

EeSymbol * EeOperatorGE::clone()
{
	return new EeOperatorGE(*this);
}

QString EeOperatorGE::dump() const
{
	return QString("EeOperatorGE: id(%1) - lexeme(%2) - priority(%3) - dimension(%4)")
		.arg(id).arg(lexeme).arg(priority).arg(dimension);
}

quint32 EeOperatorGE::interpret(const QString &subdoman,
	const quint32 *varr)
{
	Q_UNUSED(subdoman);
	Q_UNUSED(varr);

	//Q_ASSERT(LEX_OPERAND_NUM_2 == operands.size());

	return operands.at(0) >= operands.at(1);
}

EeOperatorLE::EeOperatorLE():
EeOperator(LEX_SYM_ID_LE, "<=", LEX_OPERATOR_PRI_2, LEX_OPERAND_NUM_2)
{
}

EeSymbol * EeOperatorLE::clone()
{
	return new EeOperatorLE(*this);
}

QString EeOperatorLE::dump() const
{
	return QString("EeOperatorLE: id(%1) - lexeme(%2) - priority(%3) - dimension(%4)")
		.arg(id).arg(lexeme).arg(priority).arg(dimension);
}

quint32 EeOperatorLE::interpret(const QString &subdoman,
	const quint32 *varr)
{
	Q_UNUSED(subdoman);
	Q_UNUSED(varr);

	//Q_ASSERT(LEX_OPERAND_NUM_2 == operands.size());

	return operands.at(0) <= operands.at(1);
}

EeOperatorNE::EeOperatorNE() :
EeOperator(LEX_SYM_ID_NE, "!=", LEX_OPERATOR_PRI_2, LEX_OPERAND_NUM_2)
{
}

EeSymbol * EeOperatorNE::clone()
{
	return new EeOperatorNE(*this);
}

QString EeOperatorNE::dump() const
{
	return QString("EeOperatorNE: id(%1) - lexeme(%2) - priority(%3) - dimension(%4)")
		.arg(id).arg(lexeme).arg(priority).arg(dimension);
}

quint32 EeOperatorNE::interpret(const QString &subdoman,
	const quint32 *varr)
{
	Q_UNUSED(subdoman);
	Q_UNUSED(varr);

	//Q_ASSERT(LEX_OPERAND_NUM_2 == operands.size());

	return operands.at(0) != operands.at(1);
}

QHash<QString, EeSymbol*> EeSymManager::symMap;

void EeSymManager::init()
{
	clear();

	try
	{
		regSym(new EeSymbol(LEX_SYM_ID_LEFT_BRACKET, "("));
		regSym(new EeSymbol(LEX_SYM_ID_RIGHT_BRACKET, ")"));
		regSym(new EeWord(LEX_SYM_ID_TRUE, "true"));
		regSym(new EeWord(LEX_SYM_ID_FALSE, "false"));
		regSym(new EeOperatorAND());
		regSym(new EeOperatorOR());
		regSym(new EeOperatorEQ());
		regSym(new EeOperatorGE());
		regSym(new EeOperatorLE());
		regSym(new EeOperatorNE());
	}
	catch (...)
	{
		EELOG_WARN("EeSymManager::init|rcv exception");
	}
}

void EeSymManager::clear()
{
	QList<EeSymbol*> syms = symMap.values();
	qDeleteAll(syms);
	symMap.clear();
}

bool EeSymManager::regSym(EeSymbol* symb)
{
	symMap.insert(symb->getIdentifier(), symb);
	return true;
}

bool EeSymManager::existSym(const QString& identifier)
{
	return symMap.contains(identifier);
}

EeSymbol* EeSymManager::getSym(const QString& identifier)
{
	if (symMap.contains(identifier))
	{
		return symMap.value(identifier)->clone();
	}
	else
	{
		return (EeSymbol*)Q_NULLPTR;
	}
}

bool EeSymManager::checkValidity(EeSymbol* symb)
{
	if (Q_NULLPTR == symb)
	{
		return false;
	}

	if (symb->isValue())
	{
		return true;
	}

	if (symb->isWord())
	{
		if (dynamic_cast<EeWord*>(symb)->getDomainSize()
			<= LEX_WORD_SUBDOMAIN_NUM_1)
		{
			return false;
		}
	}

	return existSym(symb->getIdentifier());
}