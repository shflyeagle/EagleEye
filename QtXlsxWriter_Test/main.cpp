#include <QtCore/QCoreApplication>
#include <QtXlsx/QtXlsx>  

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QXlsx::Document xlsx;
	xlsx.write("A1", "Hello Qt!");
	xlsx.saveAs("Test.xlsx");

	system("pause");
	return 0;
	//return a.exec();
}
