#pragma once

#include "EeCommon.h"

class EeSymbol;

class EeYaccTreeNode
{
public:
	EeYaccTreeNode(EeSymbol* sym);

	~EeYaccTreeNode();

	void setChilds(const QVector<EeYaccTreeNode* >& childs);

	const QVector<EeYaccTreeNode* >& getChilds() const;

	void addChild(EeYaccTreeNode* child);

	void setParent(EeYaccTreeNode * parent);

	EeSymbol *getSymb() const;

	void dump() const;

private:
	EeSymbol *sym{ nullptr };

	QVector<EeYaccTreeNode*> childs;

	EeYaccTreeNode * parent{nullptr};
};

class EeYaccSyntacticChecker
{
public:
	EeYaccSyntacticChecker();

	bool check(QVector<EeSymbol*>& symbols);
};

class EeYacc
{
public:		
	static std::shared_ptr<EeYaccTreeNode> buildYaccTree(const QString& expr);

	static quint32 compute(const QString& subdomain,		
		const quint32 *varr = Q_NULLPTR);
private:
	static bool syntacticChecker(const QString& expr, QVector<EeSymbol*>& symbols);

	static bool buildPostStack(const QString& expr, QStack<EeSymbol *> &postStack);

	static quint32 computeYaccTree(const QString& subdomain, EeYaccTreeNode *yaccTree, const quint32 *varr = Q_NULLPTR);

public:
	static std::shared_ptr<EeYaccTreeNode> yaccTree;
};
