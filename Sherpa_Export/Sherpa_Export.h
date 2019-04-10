#pragma once

#include <QtWidgets/QDialog>
#include "ui_Sherpa_Export.h"

class Sherpa_Export : public QDialog, Ui::Sherpa_ExportClass
{
    Q_OBJECT

public:
    Sherpa_Export(QWidget *parent = Q_NULLPTR);

private:
	void miscInit();

	void bindConnections();

	void switchGlobalStatistic();

	void switchSchedulingStatistic();

	void switchMicro();

	void exportGlobalStatistic();

	void exportSchedulingStatistic();

	void exportMicro();

	void focusSpecGlobalStatistic();

	void unfocusSpecGlobalStatistic();

	void focusSpecSchedulingStatistic();

	void unfocusSpecSchedulingStatistic();

	void focusSpecMicro();

	void unfocusSpecMicro();

	void disableAllDedicatedSheets();

	void exeExport(const QString & program, const QStringList& args);

private slots:
	void cmdClicked();

	void inClicked();

	void workDirClicked();

	void changeType(const QString &text);

	void exportClicked();
};
