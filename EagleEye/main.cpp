#include "EeCommon.h"
#include "EeMainWindow.h"
#include "ee_buffer_manage.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	//QString dir = QApplication::applicationDirPath();
	//QDir::setCurrent(dir);
	//a.setWindowIcon(QIcon("./EagleEye.ico"));

	EELOG_INIT();

	EEBUF_INIT();

	EeMainWindow w;
	w.showMaximized();

    return a.exec();
}
