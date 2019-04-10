#include "Sherpa_Export.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Sherpa_Export w;
    w.show();
    return a.exec();
}
