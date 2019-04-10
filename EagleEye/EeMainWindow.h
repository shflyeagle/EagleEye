#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_EeMainWindow.h"
#include "EeCommon.h"
#include "EeCentralWidget.h"

class EeMainWindow : public QMainWindow, public Ui_EeMainWindowClass
{
    Q_OBJECT

public:
    EeMainWindow(QWidget *parent = Q_NULLPTR);

	~EeMainWindow();

protected:
	void closeEvent(QCloseEvent *event);

	void dragEnterEvent(QDragEnterEvent *event);

	void dropEvent(QDropEvent *event);

private:
	void initUi();

	void bindConnections();

	void updateWindowTitle(const QString& title = "Untitled");

	void openFile(const QString& fileName);

	void setCurrentFile(const QString& fileName = "");

	void updateRecentFileActions();

	void updateStatusBar();

	void updatePageActionStatus();

	void writeSettings();

	void readSettings();

	QString strippedName(const QString &fullFileName);

	void initFilterComboBox();

private slots:
	void open();

	void openRecentFile();

	void closeFile();

	void about();

	void fetchPreviousPage();

	void fetchNextPage();

	void clearFilterContext();

	void openFilterDialog();

	bool checkExp2GenLY(const QString &express);

	void applyFilter();

	void setOptions();

private:
	QString curFile{""};

	QStringList recentFiles;

	QToolBar *filterToolBar;

	QLabel *filterLabel;

	QComboBox *filterComboBox;	

	QAction *recentFileActions[EE_MAX_NUM_RECENT_FILES];

	QLabel *fileLabel;

	QLabel *packetLabel;

	QLabel *profileLabel;

	EeCentralWidget *centralWidget;	
};
