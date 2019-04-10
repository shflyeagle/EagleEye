#pragma once

#include "EeCommon.h"
#include "ui_FilterDialog.h"

class FilterDialog : public QDialog, public Ui_filterDialog
{
	Q_OBJECT

public:
	FilterDialog(QWidget *parent);

	~FilterDialog();

	bool isApply() const
	{
		return toApply;
	}

	QString getFilterSentence();

private:
	void bindConnections();

	void populateData();

private slots:
	void okClicked();

	void applyClicked();

private:
	bool toApply{false};
};

