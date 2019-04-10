#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_StrucTreeManager_Test.h"

class StrucTreeManager_Test : public QMainWindow
{
    Q_OBJECT

public:
    StrucTreeManager_Test(QWidget *parent = Q_NULLPTR);

private:
    Ui::StrucTreeManager_TestClass ui;
};
