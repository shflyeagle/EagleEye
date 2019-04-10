#include "FilterTreeWidgetItem.h"


FilterTreeWidgetItem::FilterTreeWidgetItem() :QTreeWidgetItem()
{
}


FilterTreeWidgetItem::~FilterTreeWidgetItem()
{
	QVariant v = QTreeWidgetItem::data(0, Qt::UserRole);
	if (v.isNull() || !v.isValid())
	{
		Q_ASSERT(false);
	}

	DataItem *dataItem =
		v.value<DataItem *>();

	delete dataItem;	
}

QVariant FilterTreeWidgetItem::data(int column, int role) const
{
	if (Qt::EditRole == role ||
		Qt::DisplayRole == role)
	{
		QVariant v = QTreeWidgetItem::data(column, Qt::UserRole);
		if (v.isNull() || !v.isValid())
		{
			Q_ASSERT(false);
		}

		DataItem *dataItem = 
			v.value<DataItem *>();
		if (0 == dataItem->id)
		{
			return dataItem->desc;
		}
		else
		{
			return QString("[0x%1]     %2")
				.arg(dataItem->id, 4, 16, QChar('0'))
				.arg(dataItem->desc);
		}
	}
	else
	{
		return QTreeWidgetItem::data(column, role);
	}
}