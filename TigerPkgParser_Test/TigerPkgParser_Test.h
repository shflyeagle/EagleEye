#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TigerPkgParser_Test.h"

class TigerPkgParser_Test : public QMainWindow
{
    Q_OBJECT

public:
    TigerPkgParser_Test(QWidget *parent = Q_NULLPTR);

private:
    Ui::TigerPkgParser_TestClass ui;
};
