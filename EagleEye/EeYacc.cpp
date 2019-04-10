#include "EeYacc.h"
#include "EeLexSymbol.h"
#include "EeLex.h"

EeYaccTreeNode::EeYaccTreeNode(EeSymbol* sym)
{
	this->sym = sym;
	childs.reserve(LEX_OPERAND_NUM_MAX);
	childs.clear();
}

EeYaccTreeNode::~EeYaccTreeNode()
{
	//EELOG_DEBUG("EeYaccTreeNode::~EeYaccTreeNode|to delete: " 
	//	<< sym->dump().toStdString().c_str());

	delete sym;

	foreach(EeYaccTreeNode* c, childs)
	{
		delete c;
	}
}

void EeYaccTreeNode::dump() const
{
	EELOG_DEBUG("Parent: " << sym->dump().toStdString().c_str());
	foreach(EeYaccTreeNode* c, childs)
	{
		EELOG_DEBUG("Child: " << c->sym->dump().toStdString().c_str());
	}
}

void EeYaccTreeNode::setChilds(const QVector<EeYaccTreeNode* >& childs)
{
	this->childs = childs;
}

const QVector<EeYaccTreeNode* >& EeYaccTreeNode::getChilds() const
{
	return childs;
}

void EeYaccTreeNode::addChild(EeYaccTreeNode* child)
{
	childs.push_back(child);
}

void EeYaccTreeNode::setParent(EeYaccTreeNode * parent)
{
	this->parent = parent;
}

EeSymbol *EeYaccTreeNode::getSymb() const
{
	return sym;
}

EeYaccSyntacticChecker::EeYaccSyntacticChecker()
{
}

// just simple rules check !!!
bool EeYaccSyntacticChecker::check(QVector<EeSymbol*>& symbols)
{
	int rc = true;
	QStack<EeSymbol *> leftBracketStack;

	int pos;
	for (pos = 0; pos < symbols.size(); pos++)
	{
		EeSymbol *sym = symbols.at(pos);		
		if (0 == pos || (symbols.size() - 1) == pos)
		{
			if (sym->isOperator() || (0 == pos && sym->isValue()))
			{
				rc = false;
				EELOG_WARN("EeYaccSyntacticChecker::check|NOT support at begin or end for " 
					<< sym->dump().toStdString().c_str());
				break;
			}

			if ((symbols.size() - 1) == pos && sym->isWord())
			{
				dynamic_cast<EeWord*>(sym)->setValueFollowed(false);				
			}
		}

		if (pos < (symbols.size() - 1))
		{
			EeSymbol *nextSym = symbols.at(pos + 1);
			if ((sym->isOperator() && nextSym->isOperator()) ||
				(sym->equals(LEX_SYM_ID_LEFT_BRACKET) && nextSym->equals(LEX_SYM_ID_RIGHT_BRACKET)) ||
				(sym->equals(LEX_SYM_ID_RIGHT_BRACKET) && nextSym->equals(LEX_SYM_ID_LEFT_BRACKET)) ||
				(sym->equals(LEX_SYM_ID_RIGHT_BRACKET) &&
				(nextSym->isKeyword() ||
				nextSym->isValue() ||
				nextSym->isWord())) ||
				((sym->isKeyword() ||
				sym->isValue() ||
				sym->isWord()) &&
				nextSym->equals(LEX_SYM_ID_LEFT_BRACKET)) ||
				(sym->isWord() && nextSym->isWord()) ||
				(sym->isWord() && nextSym->isValue()) ||
				(sym->isValue() && nextSym->isValue()) ||
				(sym->isValue() && nextSym->isWord()))
			{
				rc = false;

				EELOG_WARN("EeYaccSyntacticChecker::check|NOT support adjacent ( " 
					<< sym->dump().toStdString().c_str()
					<< "<==>" 
					<< nextSym->dump().toStdString().c_str() 
					<< " )");
				break;
			}

			if (sym->isWord() &&
				((nextSym->getId() != LEX_SYM_ID_EQ) &&
				(nextSym->getId() != LEX_SYM_ID_GE) &&
				(nextSym->getId() != LEX_SYM_ID_LE) &&
				(nextSym->getId() != LEX_SYM_ID_NE)))
			{
				dynamic_cast<EeWord*>(sym)->setValueFollowed(false);
			}
		}

		EELOG_DEBUG("EeYaccSyntacticChecker::check|" << sym->dump().toStdString().c_str());

		if (sym->equals(LEX_SYM_ID_LEFT_BRACKET))
		{
			leftBracketStack.push(sym);
		}
		else if (sym->equals(LEX_SYM_ID_RIGHT_BRACKET))
		{
			if (leftBracketStack.isEmpty() ||
				!leftBracketStack.top()->equals(LEX_SYM_ID_LEFT_BRACKET))
			{
				rc = false;
				EELOG_WARN("EeYaccSyntacticChecker::check|bracket mismatch for " 
					<< sym->dump().toStdString().c_str());				
				break;
			}
			else
			{
				leftBracketStack.pop();
			}
		}
	}

	if (rc && !leftBracketStack.isEmpty())
	{
		EELOG_WARN("EeYaccSyntacticChecker::check|bracket mismatch");
		rc = false;
	}

	if (rc && 1 == symbols.size())
	{
		if (symbols.at(0)->isWord())
		{
			dynamic_cast<EeWord*>(symbols.at(0))->setValueFollowed(false);
		}
		else
		{
			rc = false;
			EELOG_WARN("EeYaccSyntacticChecker::check|NOT support orphan " << 
				symbols.at(0)->dump().toStdString().c_str());
		}
	}

	if (!rc)
	{
		qDeleteAll(symbols);
		symbols.clear();
	}

	return rc;
}


std::shared_ptr<EeYaccTreeNode> EeYacc::yaccTree = Q_NULLPTR;

std::shared_ptr<EeYaccTreeNode> EeYacc::buildYaccTree(const QString& expr)
{
	EELOG_TRACE("Enter EeYacc::buildYaccTree");
	QStack<EeSymbol* > postStack;
	if (!buildPostStack(expr, postStack))
	{
		qDeleteAll(postStack);
		EeYacc::yaccTree = std::shared_ptr<EeYaccTreeNode>(Q_NULLPTR);

		EELOG_TRACE("Leave EeYacc::buildYaccTree(abnormal)");
		return EeYacc::yaccTree;
	}

	QStack<EeSymbol*> revPostStack;
	while (!postStack.isEmpty())
	{
		revPostStack.push(postStack.pop());
	}

	QStack<EeYaccTreeNode *> nodeStack;
	while (!revPostStack.isEmpty())
	{
		EeSymbol* sym = revPostStack.pop();

		EELOG_DEBUG("EeYacc::buildYaccTree|pop ( " 
			<< sym->dump().toStdString().c_str() << " )");

		EeYaccTreeNode *node = new EeYaccTreeNode(sym);
		if (sym->isOperator())
		{
			qint8 dimension = dynamic_cast<EeOperator*>(sym)->getDimension();
			QVector<EeYaccTreeNode*> children;
			for (qint16 j = dimension - 1; j >= 0; j--)
			{
				EeYaccTreeNode* child = nodeStack.pop();
				child->setParent(node);
				children.push_front(child);
			}
			node->setChilds(children);
			nodeStack.push(node);
		}
		else
		{
			nodeStack.push(node);
		}
	}

	yaccTree = std::shared_ptr<EeYaccTreeNode>(nodeStack.pop());

	//yaccTree->dump();

	EELOG_TRACE("Leave EeYacc::buildYaccTree");

	return yaccTree;
}

quint32 EeYacc::compute(const QString& subdomain,
	const quint32 *varr)
{
	//EELOG_TRACE("Enter EeYacc::compute");
	if (Q_NULLPTR == yaccTree.get())
	{
		EELOG_TRACE("Leave EeYacc::compute(abnormal)");
		return false;
	}
	else
	{
		bool v = computeYaccTree(subdomain, yaccTree.get(), varr);

		//EELOG_TRACE("Leave EeYacc::compute");
		return v;
	}	
}

quint32 EeYacc::computeYaccTree(const QString& subdomain,
	EeYaccTreeNode *yaccTree, 
	const quint32 *varr)
{
	if (Q_NULLPTR == yaccTree)
	{
		return false;
	}

	//EELOG_DEBUG("EeYacc::computeYaccTree|" << yaccTree->getSymb()->dump().toStdString().c_str());

	if (!yaccTree->getSymb()->isOperator())
	{
		return yaccTree->getSymb()->interpret(subdomain, varr);
	}

	const QVector<EeYaccTreeNode* >& childs = yaccTree->getChilds();
	QVector<quint32> operands;
	foreach(EeYaccTreeNode* child, childs)
	{		
		operands.append(computeYaccTree(subdomain, child, varr));
	}

	//Q_ASSERT(operands.size() == LEX_OPERAND_NUM_MAX);

	dynamic_cast<EeOperator*>(yaccTree->getSymb())->setOperands(operands);

	quint32 v = yaccTree->getSymb()->interpret(subdomain, varr);

	//EELOG_DEBUG("EeYacc::computeYaccTree| interpret (" 
	//	<< v.toInt() 
	//	<< ") for " 
	//	<< yaccTree->getSymb()->dump().toStdString().c_str());

	return v;
}

bool EeYacc::syntacticChecker(const QString& expr, QVector<EeSymbol*>& symbols)
{
	EeLex lex(expr);

	if (!lex.parse(symbols))
	{
		return false;
	}

	EeYaccSyntacticChecker checker;
	if (!checker.check(symbols))
	{
		return false;
	}

	return true;
}

bool EeYacc::buildPostStack(const QString& expr, QStack<EeSymbol *> &postStack)
{
	postStack.clear();

	QVector<EeSymbol *> symbols;
	if (!syntacticChecker(expr, symbols))
	{
		return false;
	}

	QStack<EeSymbol *> operStack;

	foreach(EeSymbol *sym, symbols)
	{
		if (sym->equals(LEX_SYM_ID_LEFT_BRACKET))
		{
			operStack.push(sym);
		}
		else if (sym->isOperator())
		{
			while (!operStack.isEmpty() &&
				!operStack.top()->equals(LEX_SYM_ID_LEFT_BRACKET) &&
				(dynamic_cast<EeOperator*>(sym)->getPriority()
				<= dynamic_cast<EeOperator*>(operStack.top())->getPriority())
				)
			{
				postStack.push(operStack.pop());
			}
			operStack.push(sym);
		}
		else if (sym->equals(LEX_SYM_ID_RIGHT_BRACKET))
		{
			delete sym;

			while (!operStack.top()->equals(LEX_SYM_ID_LEFT_BRACKET))
			{
				postStack.push(operStack.pop());
			}

			delete operStack.pop();
		}
		else
		{
			postStack.push(sym);
		}
	}

	while (!operStack.isEmpty())
	{
		postStack.push(operStack.pop());
	}

	return true;
}

