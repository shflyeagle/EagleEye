#include "EeCommon.h"
#include "GtCommon.h"

#include "EeLexSymbol.h"
#include "EeYacc.h"

class EeLexYacc : public testing::Test 
{
protected:
	static void SetUpTestCase() 
	{
		EeSymManager::init();
		EeSymManager::regSym(new EeWord(LEX_SYM_ID_WORD + 0, "test.a"));
		EeSymManager::regSym(new EeWord(LEX_SYM_ID_WORD + 1, "test.b"));
		EeSymManager::regSym(new EeWord(LEX_SYM_ID_WORD + 2, "test.cd"));
		EeSymManager::regSym(new EeWord(LEX_SYM_ID_WORD + 3, "test.ef"));
		EeSymManager::regSym(new EeWord(LEX_SYM_ID_WORD + 4, "test.subtest.g"));
	}

	static void TearDownTestCase()
	{
		EeSymManager::clear();
	}	
};

TEST_F(EeLexYacc, TestGE)
{
	QString exp = "test.a >= 3";
	std::shared_ptr<EeYaccTreeNode> yaccTree = EeYacc::buildYaccTree(exp);

	quint32 *varr = new quint32[5];

	varr[0] = 3;
	EXPECT_EQ(1, EeYacc::compute("", varr));

	varr[0] = 2;
	EXPECT_EQ(0, EeYacc::compute("", varr));

	delete[] varr;
}

TEST_F(EeLexYacc, TestLE)
{
	QString exp = "test.a <= 3";
	std::shared_ptr<EeYaccTreeNode> yaccTree = EeYacc::buildYaccTree(exp);

	quint32 *varr = new quint32[5];

	varr[0] = 2;
	EXPECT_EQ(1, EeYacc::compute("", varr));

	varr[0] = 3;
	EXPECT_EQ(1, EeYacc::compute("", varr));

	varr[0] = 4;
	EXPECT_EQ(0, EeYacc::compute("", varr));

	delete[] varr;
}

TEST_F(EeLexYacc, TestEQ)
{
	QString exp = "test.a == 3";
	std::shared_ptr<EeYaccTreeNode> yaccTree = EeYacc::buildYaccTree(exp);

	quint32 *varr = new quint32[5];

	varr[0] = 2;
	EXPECT_EQ(0, EeYacc::compute("", varr));

	varr[0] = 3;
	EXPECT_EQ(1, EeYacc::compute("", varr));

	varr[0] = 4;
	EXPECT_EQ(0, EeYacc::compute("", varr));

	delete[] varr;
}

TEST_F(EeLexYacc, TestNE)
{
	QString exp = "test.a != 3";
	std::shared_ptr<EeYaccTreeNode> yaccTree = EeYacc::buildYaccTree(exp);

	quint32 *varr = new quint32[5];

	varr[0] = 2;
	EXPECT_EQ(1, EeYacc::compute("", varr));

	varr[0] = 3;
	EXPECT_EQ(0, EeYacc::compute("", varr));

	varr[0] = 4;
	EXPECT_EQ(1, EeYacc::compute("", varr));

	delete[] varr;
}

TEST_F(EeLexYacc, TestAnd)
{
	QString exp = "test.a != 3 && test.b == 3";
	std::shared_ptr<EeYaccTreeNode> yaccTree = EeYacc::buildYaccTree(exp);

	quint32 *varr = new quint32[5];

	varr[0] = 4;
	varr[1] = 3;
	EXPECT_EQ(1, EeYacc::compute("", varr));

	varr[0] = 3;
	EXPECT_EQ(0, EeYacc::compute("", varr));

	delete[] varr;
}

TEST_F(EeLexYacc, TestOr)
{
	QString exp = "test.a != 3 || test.b == 3";
	std::shared_ptr<EeYaccTreeNode> yaccTree = EeYacc::buildYaccTree(exp);

	quint32 *varr = new quint32[5];

	varr[0] = 2;
	varr[1] = 2;
	EXPECT_EQ(1, EeYacc::compute("", varr));

	varr[0] = 3;
	varr[1] = 2;
	EXPECT_EQ(0, EeYacc::compute("", varr));

	delete[] varr;
}