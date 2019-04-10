#pragma once

#include "EeCommon.h"

class StrucTree;

class DataTreeModel : public QAbstractItemModel
{
	Q_OBJECT

public:
	explicit DataTreeModel(QObject *parent = 0);

	~DataTreeModel();

	QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;

	Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;

	QVariant headerData(int section, Qt::Orientation orientation,
		int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

	QModelIndex index(int row, int column,
		const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

	QModelIndex parent(const QModelIndex &index) const Q_DECL_OVERRIDE;

	int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

	int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

	void setDataSource(StrucTree * st);

private:
	StrucTree* rootStrucTree;
};

