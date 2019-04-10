#pragma once

#include "EeCommon.h"

class DataManager;

class DataTabModel: public QAbstractItemModel
{
	Q_OBJECT

public:
	DataTabModel(QObject *parent = 0);

	~DataTabModel();

	QVariant headerData(int section, Qt::Orientation orientation, 
		int role = Qt::DisplayRole) const override;

	QModelIndex index(int row, int column,
		const QModelIndex &parent = QModelIndex()) const override;

	QModelIndex parent(const QModelIndex &child) const Q_DECL_OVERRIDE;

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;

	int columnCount(const QModelIndex &parent = QModelIndex()) const override;

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	void setDataSource(DataManager *dm);

private:
	DataManager* dm;
};

