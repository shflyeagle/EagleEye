#pragma once

#include "EeCommon.h"
#include "ui_EeOption.h"

enum
{
	OPTION_ITEM_GEN,
	OPTION_ITEM_OTHER,
	OPTION_ITEM_MAX,
};

class OptionDialog : public QDialog, public Ui_optionDialog
{
	Q_OBJECT;

public:
	OptionDialog(QWidget *parent);
	~OptionDialog();

public:
	quint16 getStrucType() const;
	quint16 getBw() const;
	quint16 getTxAnt() const;
	QMap<quint16, QString> getDisabledFeaturesMap() const;

private:
	void setupUiCustomized();

	void initListWidget();

	void bindConnections();

	void showGenContext();

	void showOtherContext();

	quint16 findKey(const QMap<quint16, QString>& lut, const QString& value) const;

private slots:
	void changeStrucType(int strucType);

	void changeOption(QListWidgetItem* item);

private:
	//gen tab controls
	QTabWidget *genTabWidget;
	QWidget *genTab;
	QWidget *tigerTab;
	QWidget *ddtTab;
	QComboBox *stComboBox;
	QComboBox *bwComboBox;
	QComboBox *antComboBox;
	QTreeWidget *featureDisabledTreeWidget;
	QLabel *strucTypeLabel;
	QLabel *featureDisabledLabel;
	QLabel *bwLabel;
	QLabel *antLabel;

	//other tab controls
	QTabWidget *otherTabWidget;
};

