#include "DataTreeModel.h"
#include "StrucTree.h"


DataTreeModel::DataTreeModel(QObject *parent)
:QAbstractItemModel(parent)
{
	rootStrucTree = nullptr;
}

void DataTreeModel::setDataSource(StrucTree * st)
{
	if (rootStrucTree != nullptr)
	{
		delete rootStrucTree;
	}
	rootStrucTree = st;
}

DataTreeModel::~DataTreeModel()
{
	if (rootStrucTree != nullptr)
	{
		delete rootStrucTree;
		rootStrucTree = nullptr;
	}
}

int DataTreeModel::columnCount(const QModelIndex &parent) const
{
	if (parent.isValid())
	{
		return static_cast<StrucTree*>(parent.internalPointer())->columnCount();
	}
	else
	{
		return rootStrucTree->columnCount();
	}		
}

QVariant DataTreeModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();

	if (role != Qt::DisplayRole)
		return QVariant();

	StrucTree *st = static_cast<StrucTree*>(index.internalPointer());
	const FieldInfo* fi = st->getFieldInfo();
	const FieldDes& fd = fi->fd;
	const FieldVal& fv = fi->fv;
	if (st->childCount() > 0)
	{
		return fd.name.isEmpty() ?
			QString("%1").arg(fd.type) :
			QString("%1: %2").arg(fd.name).arg(fd.type);
	}
	else
	{
		QString type = fd.sizeInBit > 0 ?
			QString("%1 (%2 - %3 bit)").
			arg(fd.type).
			arg(fd.offsetInBit).
			arg(fd.offsetInBit + fd.sizeInBit) : fd.type;

		return fd.name.isEmpty() ?
			QString("%1 :=%2").arg(type).arg(fv.toString()) :
			QString("%1: %2 :=%3").arg(fd.name).arg(type).arg(fv.toString());
	}
}

Qt::ItemFlags DataTreeModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return 0;

	return QAbstractItemModel::flags(index);
}

QVariant DataTreeModel::headerData(int section, Qt::Orientation orientation,
	int role) const
{
	Q_UNUSED(section);

	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
	{
		return "Detailed Info: ";		
	}
	return QVariant();
}

QModelIndex DataTreeModel::index(int row, int column, const QModelIndex &parent)
const
{
	if (!hasIndex(row, column, parent))
		return QModelIndex();

	StrucTree *parentStrucTree = nullptr;
	if (!parent.isValid())
		parentStrucTree = rootStrucTree;
	else
		parentStrucTree = static_cast<StrucTree*>(parent.internalPointer());

	StrucTree *childStrucTree = parentStrucTree->getChild(row);
	if (childStrucTree)
		return createIndex(row, column, childStrucTree);
	else
		return QModelIndex();
}

QModelIndex DataTreeModel::parent(const QModelIndex &index) const
{
	if (!index.isValid())
		return QModelIndex();

	StrucTree *childStrucTree = static_cast<StrucTree*>(index.internalPointer());
	StrucTree *parentStrucTree = childStrucTree->getParent();
	if (parentStrucTree == rootStrucTree)
		return QModelIndex();

	return createIndex(parentStrucTree->row(), 0, parentStrucTree);
}

int DataTreeModel::rowCount(const QModelIndex &parent) const
{	
	if (parent.column() > 0)
		return 0;

	StrucTree *parentStrucTree = Q_NULLPTR;
	if (!parent.isValid())
		parentStrucTree = rootStrucTree;
	else
		parentStrucTree = static_cast<StrucTree*>(parent.internalPointer());

	return parentStrucTree->childCount();
}
