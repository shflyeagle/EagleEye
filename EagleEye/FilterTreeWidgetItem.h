#pragma once

#include "EeCommon.h"

class DataItem
{
public:
	DataItem(quint16 id = 0, const QString& desc = "")
	{
		this->id = id;
		this->desc = desc;
	}

public:
	quint16 id;
	QString desc;
};

Q_DECLARE_METATYPE(DataItem*)

class FilterTreeWidgetItem : public QTreeWidgetItem
{
public:
	virtual QVariant data(int column, int role) const override;

public:
	FilterTreeWidgetItem();
	~FilterTreeWidgetItem();
};
