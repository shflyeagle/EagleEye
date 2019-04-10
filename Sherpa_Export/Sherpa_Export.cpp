#include "Sherpa_Export.h"
#include <QFileDialog>
#include <QProcess>
#include <QTimer>

Sherpa_Export::Sherpa_Export(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
	
	bindConnections();

	miscInit();
}

void Sherpa_Export::miscInit()
{
	typeComboBox->setCurrentIndex(1);

	//QTimer *timer = new QTimer(this);
	//connect(timer, SIGNAL(timeout()), this, SLOT(processOneThing()));
	//timer->start();
}

void Sherpa_Export::bindConnections()
{
	connect(cmdPushButton, SIGNAL(clicked(bool)), this, SLOT(cmdClicked()));
	connect(inPushButton, SIGNAL(clicked(bool)), this, SLOT(inClicked()));
	connect(typeComboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(changeType(const QString &)));
	connect(exportPushButton, SIGNAL(clicked(bool)), this, SLOT(exportClicked()));
	connect(workDirPushButton, SIGNAL(clicked(bool)), this, SLOT(workDirClicked()));
}

void Sherpa_Export::workDirClicked()
{
	QString dir = QFileDialog::getExistingDirectory(this, tr("Open Work Directory"),
		"./",
		QFileDialog::ShowDirsOnly
		| QFileDialog::DontResolveSymlinks);

	workDirLineEdit->setText(dir);
}

void Sherpa_Export::cmdClicked()
{
	QString file = QFileDialog::getOpenFileName(
		this,
		"Select sherpa executive program",
		"C:/Program Files (x86)/NOKIA/Sherpa/",
		"Sherpagtgui (*.exe)");

	cmdLineEdit->setText(file);
}

void Sherpa_Export::inClicked()
{
	QStringList files = QFileDialog::getOpenFileNames(
		this,
		"Select one or more sherpa files to open",
		"E:/Troubleshooting",
		"Sherpa (*.pcap)");

	inLineEdit->setText(files.join(' '));
}

#define TYPE_GS		"Global Statistic"
#define TYPE_SS		"Scheduling Statistic"
#define TYPE_MICRO  "Micro"

void Sherpa_Export::changeType(const QString &text)
{
	if (text == TYPE_GS)
	{
		switchGlobalStatistic();
	}
	else if (text == TYPE_SS)
	{
		switchSchedulingStatistic();
	}
	else if (text == TYPE_MICRO)
	{
		switchMicro();
	}
	else
	{
		//do nothing
	}
}

void Sherpa_Export::exportClicked()
{
	QString type = typeComboBox->currentText();
	if (type == TYPE_GS)
	{
		exportGlobalStatistic();
	}
	else if (type == TYPE_SS)
	{
		exportSchedulingStatistic();
	}
	else if (type == TYPE_MICRO)
	{
		exportMicro();
	}
	else
	{
		//do nothing
	}
}

void Sherpa_Export::focusSpecGlobalStatistic()
{
	periodLineEdit->setDisabled(false);
	ttibMinStartPrbLineEdit->setDisabled(false);
	ttibMaxStartPrbLineEdit->setDisabled(false);

	useLocaleSystemCheckBox->setDisabled(false);
	useGroupSeparatorCheckBox->setDisabled(false);
	cceCheckBox->setDisabled(false);
	utcCheckBox->setDisabled(false);
	bcem2CheckBox->setDisabled(false);
}

void Sherpa_Export::unfocusSpecGlobalStatistic()
{
	periodLineEdit->setDisabled(true);
	ttibMinStartPrbLineEdit->setDisabled(true);
	ttibMaxStartPrbLineEdit->setDisabled(true);
}

void Sherpa_Export::unfocusSpecSchedulingStatistic()
{
	durationLineEdit->setDisabled(true);
	minDurationLineEdit->setDisabled(true);
	startSfnLineEdit->setDisabled(true);
	startLineEdit->setDisabled(true);
	minPLLineEdit->setDisabled(true);
	maxPLLineEdit->setDisabled(true);
}

void Sherpa_Export::focusSpecSchedulingStatistic()
{
	durationLineEdit->setDisabled(false);
	minDurationLineEdit->setDisabled(false);
	startSfnLineEdit->setDisabled(false);
	startLineEdit->setDisabled(false);
	minPLLineEdit->setDisabled(false);
	maxPLLineEdit->setDisabled(false);
}

void Sherpa_Export::focusSpecMicro()
{
	durationLineEdit->setDisabled(false);

	useLocaleSystemCheckBox->setDisabled(false);
	useGroupSeparatorCheckBox->setDisabled(false);
	cceCheckBox->setDisabled(false);
	utcCheckBox->setDisabled(false);
	callflowCheckBox->setDisabled(false);
	ulcallflowCheckBox->setDisabled(false);
	dlcallflowCheckBox->setDisabled(false);
	rlcCheckBox->setDisabled(false);
	sduCheckBox->setDisabled(false);
	cqiCheckBox->setDisabled(false);
	block7CheckBox->setDisabled(false);
	uestateCheckBox->setDisabled(false);
	othercceCheckBox->setDisabled(false);
}

void Sherpa_Export::unfocusSpecMicro()
{
	durationLineEdit->setDisabled(true);
}

void Sherpa_Export::switchSchedulingStatistic()
{
	unfocusSpecMicro();
	unfocusSpecGlobalStatistic();
	disableAllDedicatedSheets();
	focusSpecSchedulingStatistic();
}

void Sherpa_Export::switchMicro()
{
	unfocusSpecGlobalStatistic();
	unfocusSpecSchedulingStatistic();
	disableAllDedicatedSheets();
	focusSpecMicro();
}

void Sherpa_Export::switchGlobalStatistic()
{
	unfocusSpecMicro();
	unfocusSpecSchedulingStatistic();
	disableAllDedicatedSheets();
	focusSpecGlobalStatistic();
}


void Sherpa_Export::disableAllDedicatedSheets()
{
	useLocaleSystemCheckBox->setDisabled(true);
	useGroupSeparatorCheckBox->setDisabled(true);
	cceCheckBox->setDisabled(true);
	utcCheckBox->setDisabled(true);
	bcem2CheckBox->setDisabled(true);
	callflowCheckBox->setDisabled(true);
	ulcallflowCheckBox->setDisabled(true);
	dlcallflowCheckBox->setDisabled(true);
	rlcCheckBox->setDisabled(true);
	sduCheckBox->setDisabled(true);
	cqiCheckBox->setDisabled(true);
	block7CheckBox->setDisabled(true);
	uestateCheckBox->setDisabled(true);
	othercceCheckBox->setDisabled(true);
}

void Sherpa_Export::exportGlobalStatistic()
{
	QString program = cmdLineEdit->text();
	QStringList args;
	args.append("-in");
	args.append(inLineEdit->text());
	args.append("-out");
	args.append(outLineEdit->text());
	args.append("-period");
	args.append(periodLineEdit->text());
	if (!BwComboBox->currentText().isEmpty())
	{
		args.append("-bw");
		args.append(BwComboBox->currentText());
	}
	if (!CellComboBox->currentText().isEmpty())
	{
		args.append("-slot");
		args.append(CellComboBox->currentText());
	}
	if (tx4CheckBox->isChecked())
	{
		args.append("-4tx");
	}
	if (!AntComboBox->currentText().isEmpty())
	{
		args.append("-tx");
		args.append(AntComboBox->currentText());
	}
	if (!sepLineEdit->text().isEmpty())
	{
		args.append("-sep");
		args.append(sepLineEdit->text());
	}
	if (!ulRetransLineEdit->text().isEmpty())
	{
		args.append("-ulRetrans");
		args.append(ulRetransLineEdit->text());
	}
	if (!ulRetransRachMsg3LineEdit->text().isEmpty())
	{
		args.append("-ulRetransRachMsg3");
		args.append(ulRetransRachMsg3LineEdit->text());
	}
	if (!dlRetransLineEdit->text().isEmpty())
	{
		args.append("-dlRetrans");
		args.append(dlRetransLineEdit->text());
	}
	if (!ulSpsRetransLineEdit->text().isEmpty())
	{
		args.append("-ulSpsRetrans");
		args.append(ulSpsRetransLineEdit->text());
	}
	if (!dlSpsRetransLineEdit->text().isEmpty())
	{
		args.append("-dlSpsRetrans");
		args.append(dlSpsRetransLineEdit->text());
	}
	if (!bundlingRetransLineEdit->text().isEmpty())
	{
		args.append("-bundlingRetrans");
		args.append(bundlingRetransLineEdit->text());
	}
	if (!rlcRetransLineEdit->text().isEmpty())
	{
		args.append("-rlcRetrans");
		args.append(rlcRetransLineEdit->text());
	}
	if (!pollRetransUlLineEdit->text().isEmpty())
	{
		args.append("-pollRetransUl");
		args.append(pollRetransUlLineEdit->text());
	}
	if (!pollRetransDlLineEdit->text().isEmpty())
	{
		args.append("-pollRetransDl");
		args.append(pollRetransDlLineEdit->text());
	}
	if ((!ttibMinStartPrbLineEdit->text().isEmpty()) &&
		(!ttibMaxStartPrbLineEdit->text().isEmpty()))
	{
		args.append("-ttibMinMaxStartPrb");
		args.append(ttibMinStartPrbLineEdit->text());
		args.append(ttibMaxStartPrbLineEdit->text());
	}
	if (useLocaleSystemCheckBox->isChecked())
	{
		args.append("-useLocaleSystem");
	}
	if (useGroupSeparatorCheckBox->isChecked())
	{
		args.append("-useGroupSeparator");
	}
	if (cceCheckBox->isChecked())
	{
		args.append("-cce");
	}
	if (utcCheckBox->isChecked())
	{
		args.append("-utc");
	}
	if (bcem2CheckBox->isChecked())
	{
		args.append("-bcem2");
	}

	exeExport(program, args);
}

void Sherpa_Export::exportSchedulingStatistic()
{
	QString program = cmdLineEdit->text();
	QStringList args;
	args.append("-in");
	args.append(inLineEdit->text());
	args.append("-out");
	args.append(outLineEdit->text());
	args.append("-duration");
	args.append(durationLineEdit->text());
	if (!minDurationLineEdit->text().isEmpty())
	{
		args.append("-minduration");
		args.append(minDurationLineEdit->text());
	}
	if (!BwComboBox->currentText().isEmpty())
	{
		args.append("-bw");
		args.append(BwComboBox->currentText());
	}
	if (!CellComboBox->currentText().isEmpty())
	{
		args.append("-slot");
		args.append(CellComboBox->currentText());
	}
	if (tx4CheckBox->isChecked())
	{
		args.append("-4tx");
	}
	if (!AntComboBox->currentText().isEmpty())
	{
		args.append("-tx");
		args.append(AntComboBox->currentText());
	}
	if (!sepLineEdit->text().isEmpty())
	{
		args.append("-sep");
		args.append(sepLineEdit->text());
	}
	if (!startLineEdit->text().isEmpty())
	{
		args.append("-start");
		args.append(startLineEdit->text());
	}
	if (!startSfnLineEdit->text().isEmpty())
	{
		args.append("-startsfn");
		args.append(startSfnLineEdit->text());
	}
	if (!ulRetransLineEdit->text().isEmpty())
	{
		args.append("-ulRetrans");
		args.append(ulRetransLineEdit->text());
	}
	if (!ulRetransRachMsg3LineEdit->text().isEmpty())
	{
		args.append("-ulRetransRachMsg3");
		args.append(ulRetransRachMsg3LineEdit->text());
	}
	if (!dlRetransLineEdit->text().isEmpty())
	{
		args.append("-dlRetrans");
		args.append(dlRetransLineEdit->text());
	}
	if (!ulSpsRetransLineEdit->text().isEmpty())
	{
		args.append("-ulSpsRetrans");
		args.append(ulSpsRetransLineEdit->text());
	}
	if (!dlSpsRetransLineEdit->text().isEmpty())
	{
		args.append("-dlSpsRetrans");
		args.append(dlSpsRetransLineEdit->text());
	}	
	if (!minPLLineEdit->text().isEmpty())
	{
		args.append("-minPathloss");
		args.append(minPLLineEdit->text());
	}
	if (!maxPLLineEdit->text().isEmpty())
	{
		args.append("-maxPathloss");
		args.append(maxPLLineEdit->text());
	}

	exeExport(program, args);
}

void Sherpa_Export::exportMicro()
{
	QString program = cmdLineEdit->text();
	QStringList args;
	args.append("-in");
	args.append(inLineEdit->text());
	args.append("-out");	
	args.append(outLineEdit->text());
	args.append("-micro");
	args.append("-duration");
	args.append(durationLineEdit->text());
	if (!BwComboBox->currentText().isEmpty())
	{
		args.append("-bw");
		args.append(BwComboBox->currentText());
	}
	if (!CellComboBox->currentText().isEmpty())
	{
		args.append("-slot");
		args.append(CellComboBox->currentText());
	}
	if (tx4CheckBox->isChecked())
	{
		args.append("-4tx");
	}
	if (!AntComboBox->currentText().isEmpty())
	{
		args.append("-tx");
		args.append(AntComboBox->currentText());
	}
	if (!sepLineEdit->text().isEmpty())
	{
		args.append("-sep");
		args.append(sepLineEdit->text());
	}
	if (!ulRetransLineEdit->text().isEmpty())
	{
		args.append("-ulRetrans");
		args.append(ulRetransLineEdit->text());
	}
	if (!ulRetransRachMsg3LineEdit->text().isEmpty())
	{
		args.append("-ulRetransRachMsg3");
		args.append(ulRetransRachMsg3LineEdit->text());
	}
	if (!dlRetransLineEdit->text().isEmpty())
	{
		args.append("-dlRetrans");
		args.append(dlRetransLineEdit->text());
	}
	if (!ulSpsRetransLineEdit->text().isEmpty())
	{
		args.append("-ulSpsRetrans");
		args.append(ulSpsRetransLineEdit->text());
	}
	if (!dlSpsRetransLineEdit->text().isEmpty())
	{
		args.append("-dlSpsRetrans");
		args.append(dlSpsRetransLineEdit->text());
	}	
	if (!rlcRetransLineEdit->text().isEmpty())
	{
		args.append("-rlcRetrans");
		args.append(rlcRetransLineEdit->text());
	}
	if (!pollRetransUlLineEdit->text().isEmpty())
	{
		args.append("-pollRetransUl");
		args.append(pollRetransUlLineEdit->text());
	}
	if (!pollRetransDlLineEdit->text().isEmpty())
	{
		args.append("-pollRetransDl");
		args.append(pollRetransDlLineEdit->text());
	}	
	if (useLocaleSystemCheckBox->isChecked())
	{
		args.append("-useLocaleSystem");
	}
	if (useGroupSeparatorCheckBox->isChecked())
	{
		args.append("-useGroupSeparator");
	}
	if (cceCheckBox->isChecked())
	{
		args.append("-cce");
	}
	if (utcCheckBox->isChecked())
	{
		args.append("-utc");
	}
	if (callflowCheckBox->isChecked())
	{
		args.append("-callflow");
	}
	if (ulcallflowCheckBox->isChecked())
	{
		args.append("-ulcallflow");
	}
	if (dlcallflowCheckBox->isChecked())
	{
		args.append("-dlcallflow");
	}
	if (sduCheckBox->isChecked())
	{
		args.append("-sdu");
	}
	if (cqiCheckBox->isChecked())
	{
		args.append("-cqi");
	}
	if (block7CheckBox->isChecked())
	{
		args.append("-bloc7");
	}
	if (uestateCheckBox->isChecked())
	{
		args.append("-uestate");
	}
	if (cceCheckBox->isChecked())
	{
		args.append("-cce");
	}
	if (othercceCheckBox->isChecked())
	{
		args.append("-othercce");
	}

	exeExport(program, args);
}

#define WORK_DIR  "E:/Troubleshooting/sherp_export"
void Sherpa_Export::exeExport(const QString & program, const QStringList& args)
{
	QString wkdir = 
		workDirLineEdit->text().isEmpty() ? WORK_DIR : workDirLineEdit->text();
	QString cmd = 
		QString("%1 %2 \n\nNote:\n  working directory:%3")
		.arg(program)
		.arg(args.join(' '))
		.arg(wkdir);

	execPlainTextEdit->clear();
	execPlainTextEdit->setPlainText(cmd);

	QProcess *qp = new QProcess(this);
	qp->setWorkingDirectory(wkdir);
	qp->start(program, args);
	//qp->waitForFinished();
	//delete qp;
}


