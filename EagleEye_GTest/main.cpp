#include <QtCore/QCoreApplication>

#include "GtCommon.h"

using namespace EeGt;

int main(int argc, char *argv[])
{
	//QCoreApplication a(argc, argv);

	testing::AddGlobalTestEnvironment(new Environment);
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	system("pause");
	return 0;
	//return a.exec();
}
