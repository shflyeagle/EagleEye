#include <QtCore/QCoreApplication>

#include "EeCommon.h"

#include "EeLex.h"
#include "EeLexSymbol.h"
#include "EeYacc.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	EELOG_INIT();

	EeSymManager::init();
	EeSymManager::regSym(new EeWord(LEX_SYM_ID_WORD + 0, "test.a"));
	EeSymManager::regSym(new EeWord(LEX_SYM_ID_WORD + 1, "test.b"));
	EeSymManager::regSym(new EeWord(LEX_SYM_ID_WORD + 2, "test.cd"));
	EeSymManager::regSym(new EeWord(LEX_SYM_ID_WORD + 3, "test.ef"));
	EeSymManager::regSym(new EeWord(LEX_SYM_ID_WORD + 4, "test.subtest.g"));

	unsigned *varr = new unsigned[5];

	QString exp = "test.a >= 3";
	std::shared_ptr<EeYaccTreeNode> yaccTree = EeYacc::buildYaccTree(exp);

	varr[0] = 3;

	bool result = EeYacc::compute("", varr);

	delete[] varr;

	EELOG_DEBUG("result = " << result);

	system("pause");
	return 0;
	//return a.exec();
}
