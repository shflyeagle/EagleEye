#include "EeMainWindow.h"
#include "EeLexSymbol.h"
#include "EeYacc.h"
#include "EeLex.h"
#include "FilterDialog.h"
#include "OptionDialog.h"
#include "EeProfile.h"
#include "ee_buffer_manage.h"

EeMainWindow::EeMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	try
	{
		initUi();
		bindConnections();
		readSettings();
		updateWindowTitle();
		updateStatusBar();
	}
	catch (...)
	{
		EELOG_WARN("EeMainWindow::EeMainWindow|failed to construct");
	}
}

EeMainWindow::~EeMainWindow()
{
	writeSettings();

	if (centralWidget != Q_NULLPTR)
	{
		delete centralWidget;
		centralWidget = Q_NULLPTR;
	}
}

void EeMainWindow::initUi()
{
	setupUi(this);

	actionNextPage->setDisabled(true);
	actionPreviousPage->setDisabled(true);

	filterToolBar = addToolBar(tr("filter ToolBar"));
	filterToolBar->setAllowedAreas(Qt::TopToolBarArea | Qt::BottomToolBarArea);
	//addToolBarBreak(Qt::TopToolBarArea);
	addToolBar(filterToolBar);
	filterLabel = new QLabel(" Filter:  ");
	filterToolBar->addWidget(filterLabel);
	filterComboBox = new QComboBox(filterToolBar);
	filterToolBar->addWidget(filterComboBox);
	filterComboBox->setEditable(true);
	filterComboBox->setMinimumContentsLength(50);
	filterComboBox->setMaxCount(100);
	filterComboBox->setMaxVisibleItems(50);
	filterComboBox->setInsertPolicy(QComboBox::NoInsert);
	filterComboBox->completer()->setCompletionMode(QCompleter::PopupCompletion);

	fileLabel = new QLabel();
	fileLabel->setAlignment(Qt::AlignHCenter);
	fileLabel->setMinimumSize(fileLabel->sizeHint());
	packetLabel = new QLabel();
	profileLabel = new QLabel();
	QMainWindow::statusBar()->addWidget(fileLabel);
	QMainWindow::statusBar()->addWidget(packetLabel, 1);
	QMainWindow::statusBar()->addWidget(profileLabel, 1);

	for (int i = 0; i < EE_MAX_NUM_RECENT_FILES; ++i)
	{
		recentFileActions[i] = new QAction(this);
		recentFileActions[i]->setVisible(false);
		menuFile->addAction(recentFileActions[i]);
	}

	centralWidget = new EeCentralWidget(this);
	centralWidget->init();
	setCentralWidget(centralWidget);
	centralWidget->setAcceptDrops(false);
	setAcceptDrops(true);

	initFilterComboBox();
}

void EeMainWindow::bindConnections()
{
	connect(actionOpen, SIGNAL(triggered()), this, SLOT(open()));
	connect(actionClose, SIGNAL(triggered()), this, SLOT(closeFile()));
	connect(actionExit, SIGNAL(triggered()), this, SLOT(close()));

	connect(actionAbout, SIGNAL(triggered()), this, SLOT(about()));
	connect(actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

	connect(filterComboBox->lineEdit(), SIGNAL(returnPressed()), this, SLOT(applyFilter()));
	connect(filterComboBox->lineEdit(), SIGNAL(textChanged(const QString&)), this, SLOT(checkExp2GenLY(const QString&)));
	connect(actionSetFilter, SIGNAL(triggered()), this, SLOT(openFilterDialog()));
	connect(actionResetFilter, SIGNAL(triggered()), this, SLOT(clearFilterContext()));

	connect(actionPreviousPage, SIGNAL(triggered()), this, SLOT(fetchPreviousPage()));
	connect(actionNextPage, SIGNAL(triggered()), this, SLOT(fetchNextPage()));

	connect(actionOptions, SIGNAL(triggered()), this, SLOT(setOptions()));

	for (int i = 0; i < EE_MAX_NUM_RECENT_FILES; ++i)
	{
		connect(recentFileActions[i], SIGNAL(triggered()), this, SLOT(openRecentFile()));
	}
}

void EeMainWindow::updateWindowTitle(const QString& title)
{
	setWindowTitle(tr("%1[*] - %2")
		.arg(title)
		.arg(tr("EagleEye")));
}

void EeMainWindow::updateStatusBar()
{
	QString fileStatus;
	QString packetStatus;
	QString profileStatus = EeProfile::getStatus();

	if (curFile.isEmpty())
	{
		fileStatus = "Ready to load file";
		packetStatus = "No Packets";
	}
	else
	{
		fileStatus = tr("File: \"%1\"").arg(curFile);
		packetStatus = centralWidget->getPacketStatus();
	}

	fileLabel->setText(fileStatus);
	packetLabel->setText(packetStatus);
	profileLabel->setText(profileStatus);
}

void EeMainWindow::open()
{
	QString fileName = 
		QFileDialog::getOpenFileName(this,
		tr("Open EagleEye"), ".",
		tr("EagleEye files (*.*)"));

	if (fileName.isEmpty())
	{
		return;
	}

	closeFile();

	openFile(fileName);
}

void EeMainWindow::openFile(const QString& fileName)
{
	centralWidget->load(fileName);

	setCurrentFile(fileName);
}

void EeMainWindow::setCurrentFile(const QString& fileName)
{
	curFile = fileName;

	QString mainWindowText = tr("Untitled");
	if (!curFile.isEmpty())
	{
		mainWindowText = strippedName(curFile);
		recentFiles.removeAll(curFile);
		recentFiles.prepend(curFile);
		updateRecentFileActions();
	}

	updateWindowTitle(mainWindowText);

	updatePageActionStatus();

	updateStatusBar();
}

void EeMainWindow::updateRecentFileActions()
{
	QMutableStringListIterator i(recentFiles);
	while (i.hasNext())
	{
		if (!QFile::exists(i.next()))
		{
			i.remove();
		}
	}

	for (int j = 0; j < EE_MAX_NUM_RECENT_FILES; ++j)
	{
		if (j < recentFiles.count())
		{
			QString text = tr("&%1 %2")
				.arg(j + 1)
				.arg(strippedName(recentFiles[j]));
			recentFileActions[j]->setText(text);
			recentFileActions[j]->setData(recentFiles[j]);
			recentFileActions[j]->setVisible(true);
		}
		else
		{
			recentFileActions[j]->setVisible(false);
		}
	}
}

void EeMainWindow::updatePageActionStatus()
{
	if (centralWidget->isFirstPage())
	{
		actionPreviousPage->setDisabled(true);
	}
	else
	{
		actionPreviousPage->setEnabled(true);
	}

	if (centralWidget->isLastPage())
	{
		actionNextPage->setDisabled(true);
	}
	else
	{
		actionNextPage->setEnabled(true);
	}
}

void EeMainWindow::openRecentFile()
{
	QAction *action = qobject_cast<QAction *>(sender());
	if (Q_NULLPTR != action)
	{
		QString fileName = action->data().toString();
		if (fileName != curFile)
		{
			closeFile();
			openFile(fileName);
		}
	}
}

void EeMainWindow::closeFile()
{
	if (!curFile.isEmpty())
	{
		centralWidget->unload();
	}

	setCurrentFile();
}

void EeMainWindow::about()
{
	QMessageBox::about(this, tr("About EagelEye"),
		tr("<h2>EagelEye 0.1</h2>"
		"<p>Copyright &copy; 2017 Nokia Shanghai Bell Inc. qiongbo.deng@nokia-sbell.com"
		"<p>EagelEye is a small application that "
		"assists LTE modem L2 guys to "
		"decode and analyze tiger/DDT/TTI trace."
		"Comments are welcome."));
}

void EeMainWindow::fetchPreviousPage()
{
	centralWidget->fetchPreviousPage();
	updatePageActionStatus();
	updateStatusBar();
}

void EeMainWindow::fetchNextPage()
{
	centralWidget->fetchNextPage();
	updatePageActionStatus();
	updateStatusBar();
}

void EeMainWindow::openFilterDialog()
{
	FilterDialog filterDialog(this);
	if (filterDialog.exec())
	{
		QString filterSentence 
			= filterDialog.getFilterSentence();
		filterComboBox->lineEdit()->setText(filterSentence);
		if (filterDialog.isApply())
		{
			applyFilter();
		}
	}	
}

void EeMainWindow::clearFilterContext()
{
	filterComboBox->lineEdit()->clear();
	applyFilter();
}

void EeMainWindow::applyFilter()
{
	EELOG_TRACE("Enter EeMainWindow::applyFilter");

	if (checkExp2GenLY(filterComboBox->lineEdit()->text()))
	{
		centralWidget->applyFilter();
		updatePageActionStatus();
		updateStatusBar();
	}

	EELOG_TRACE("Leave EeMainWindow::applyFilter");
}

void EeMainWindow::readSettings()
{
	QSettings settings("NSB Software Inc.", "EagleEye");
	restoreGeometry(settings.value("geometry").toByteArray());
	recentFiles = settings.value("recentFiles").toStringList();

	updateRecentFileActions();
}

void EeMainWindow::writeSettings()
{
	QSettings settings("NSB Software Inc.", "EagleEye");
	settings.setValue("geometry", saveGeometry());
	settings.setValue("recentFiles", recentFiles);
}

QString EeMainWindow::strippedName(const QString &fullFileName)
{
	return QFileInfo(fullFileName).fileName();
}

void EeMainWindow::closeEvent(QCloseEvent *event)
{
	if (1)
	{
		event->accept();
	}
	else
	{
		event->ignore();
	}
}

void EeMainWindow::dragEnterEvent(QDragEnterEvent *event)
{
	if (event->mimeData()->hasFormat("text/uri-list"))
	{
		event->acceptProposedAction();
	}
}

void EeMainWindow::dropEvent(QDropEvent *event)
{
	QList<QUrl> urls = event->mimeData()->urls();
	if (urls.isEmpty())
	{
		return;
	}

	QString fileName = urls.first().toLocalFile();
	if (fileName.isEmpty() || !fileName.compare(curFile))
	{
		return;
	}

	closeFile();

	openFile(fileName);
}

bool EeMainWindow::checkExp2GenLY(const QString &express)
{
	//EELOG_TRACE("Enter EeMainWindow::checkExp2GenLY");
	//EELOG_INFO("EeMainWindow::checkExp2GenLY|express (" << QSTR2CSTR(express) << ")");

	bool rc = true;
	if (express.isEmpty())
	{
		filterComboBox->lineEdit()->
			setStyleSheet(QString("background-color: white"));
		EeYacc::yaccTree = 
			std::shared_ptr<EeYaccTreeNode>(Q_NULLPTR);		
	}
	else
	{
		std::shared_ptr<EeYaccTreeNode> yaccTree = 
			EeYacc::buildYaccTree(express);
		if (yaccTree.get())
		{
			filterComboBox->lineEdit()->
				setStyleSheet(QString("background-color: cyan"));
		}
		else
		{
			filterComboBox->lineEdit()->
				setStyleSheet(QString("background-color: red"));
			rc = false;
		}
	}	
	return rc;

	//EELOG_TRACE("Leave EeMainWindow::checkExp2GenLY");
}

void EeMainWindow::initFilterComboBox()
{
	filterComboBox->clear();
	foreach(auto sym, EeSymManager::symMap.values())
	{
		if (sym->isWord())
		{
			filterComboBox->addItem(sym->getIdentifier());
		}
	}
}

void EeMainWindow::setOptions()
{
	OptionDialog optionDialog(this);
	if (optionDialog.exec())
	{
		EeProfile::strucType = 
			optionDialog.getStrucType();
		EeProfile::ddtProfile.bandwith = 
			optionDialog.getBw();
		EeProfile::ddtProfile.antTx = 
			optionDialog.getTxAnt();
		EeProfile::disabledFeaturesLut = 
			optionDialog.getDisabledFeaturesMap();

		centralWidget->reinit();

		initFilterComboBox();

		closeFile();
	}
}