#include "StrucTreeManager_Test.h"
#include <QtWidgets/QApplication>

#include "StrucTigerLUT.h"
#include "StrucTreeManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StrucTreeManager_Test w;
    w.show();

	EELOG_INIT();

	StrucTigerLUT::init();
	SLUT_SET_FILE("D:/vs2013/sln/EagleEye/EagleEye/StrucTiger.h");

	StrucTreeManager::getInstance()->generate();

    return a.exec();
}
