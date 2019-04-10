#include "DataTabModel.h"
#include "DataManager.h"
#include "PkgDecoder.h"
#include "PkgVisitor.h"

DataTabModel::DataTabModel(QObject *parent) :
QAbstractItemModel(parent)
{
	this->dm = nullptr;
}


DataTabModel::~DataTabModel()
{
	this->dm = nullptr;
}

QVariant DataTabModel::headerData(int section,
	Qt::Orientation orientation, int role) const
{
	if (role != Qt::DisplayRole)
	{
		return QVariant();
	}

	if (Qt::Horizontal == orientation)
	{
		switch (section)
		{
		case 0:
			return tr("No.");
		case 1:
			return tr("Time");
		case 2:
			return tr("Info");
		default:
			return QVariant();
		}
	}
	return QVariant();
}

QModelIndex DataTabModel::index(int row,
	int column,
	const QModelIndex &parent) const
{
	if (!hasIndex(row, column, parent))
	{
		return QModelIndex();
	}

	if (Q_NULLPTR != dm)
	{
		unsigned pkgId = dm->getPkgIdByPkgIdx(row);

		PkgLoc* pkgLoc =
			dm->getPkgLocByPkgId(pkgId);
		if (pkgLoc != Q_NULLPTR)
		{
			return  createIndex(row, column, pkgLoc);
		}
		else
		{
			EELOG_WARN("DataTabModel::index|failed to get PkgLoc via pkgId ("
				<< pkgId
				<< ") by row ( "
				<< row << ")");

			return QModelIndex();
		}
	}
	else
	{
		return QModelIndex();
	}
}

QModelIndex DataTabModel::parent(const QModelIndex &child) const
{
	Q_UNUSED(child);

	return QModelIndex();
}

int DataTabModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);

	if (Q_NULLPTR != dm)
	{
		return dm->getCurTabPagePkgCount();
	}
	else
	{
		return 0;
	}
}

int DataTabModel::columnCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return 3;
}

QVariant DataTabModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();

	if (Q_NULLPTR != dm)
	{
		if (Qt::DisplayRole == role)
		{
			switch (index.column())
			{
				case 0:
				{
					return dm->getPkgIdByPkgIdx(index.row()) + 1;
				}

				case 1:
				{
					QByteArray timeVal = dm->getTime(index.row());
					TimeVal *tv = reinterpret_cast<TimeVal*>(timeVal.data());
					QDateTime dt = QDateTime::fromTime_t(tv->tv_sec, Qt::UTC);
					return QString("%1.%2").
						arg(dt.toString("yyyy-MM-dd.hh:mm:ss")).
						arg(tv->tv_usec / 1000);					
				}

				case 2:
				{
					PkgLoc* pkgLoc = dm->getPkgLocByPkgIdx(index.row());
					Q_ASSERT(pkgLoc != Q_NULLPTR);
					quint32 decoderId = dm->getDecoderId(pkgLoc);
					PkgDecoder* decoder = dm->getPkgDecoderMng()->getDecoder(decoderId);
					PkgVisitor* visitor = dm->getPkgVisitorMng()->getVisitor(decoderId);
					if (Q_NULLPTR == decoder ||
						Q_NULLPTR == visitor)
					{
						return QString("Not Support Struc Id(%1)").arg(decoderId);
					}
					
					const QByteArray& b = dm->getDecoderCxt(pkgLoc);
///*					QVariant v(b.toHex());
//					EELOG_DEBUG("DataTabModel::data|cxt (" << QSTR2CSTR(v.toString()) << ")");*/					
					decoder->decode(b, pkgLoc);
					return visitor->show(decoder);
				}

				default:
				{
					return QVariant();
				}				
			}
		}
		else
		{
			return QVariant();
		}
	}
	else
	{
		return QVariant();
	}
}

void DataTabModel::setDataSource(DataManager *dm)
{
	this->dm = dm;
}