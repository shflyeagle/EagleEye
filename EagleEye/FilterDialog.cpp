#include "FilterDialog.h"
#include "StrucLUT.h"
#include "FilterTreeWidgetItem.h"

FilterDialog::FilterDialog(QWidget *parent):
QDialog(parent)
{
	setupUi(this);
	bindConnections();
	populateData();
}

FilterDialog::~FilterDialog()
{
}

void FilterDialog::bindConnections()
{
	connect(cancelPushButton, SIGNAL(clicked(bool)), this, SLOT(reject()));
	connect(okPushButton, SIGNAL(clicked(bool)), this, SLOT(okClicked()));
	connect(applyPushButton, SIGNAL(clicked(bool)), this, SLOT(applyClicked()));
}

void FilterDialog::populateData()
{
	const QMap<QString, std::shared_ptr<QMap<quint16, QString>>>& catLut =
		SLUT_GET_CATLUT();

	QList<QTreeWidgetItem *> twiL;
	for (auto it = catLut.constBegin(); it != catLut.constEnd(); ++it)
	{
		QVariant v;
		v.setValue(new DataItem(0, it.key()));
		QTreeWidgetItem *parent = new FilterTreeWidgetItem();
		parent->setData(0, Qt::UserRole, v);
		parent->setFlags(parent->flags() | Qt::ItemIsTristate | Qt::ItemIsUserCheckable);
		twiL.append(parent);

		std::shared_ptr<QMap<quint16, QString>> lut = it.value();
		for (auto it2 = lut->constBegin(); it2 != lut->constEnd(); ++it2)
		{
			QVariant v;
			v.setValue(new DataItem(it2.key(), it2.value()));
			QTreeWidgetItem *child = new FilterTreeWidgetItem();
			child->setData(0, Qt::UserRole, v);
			child->setFlags(child->flags() | Qt::ItemIsUserCheckable);
			child->setCheckState(0, Qt::Unchecked);
			parent->addChild(child);
		}
	}

	treeWidget->addTopLevelItems(twiL);
}

QString FilterDialog::getFilterSentence()
{
	QString filterSentence;	

	QTreeWidgetItemIterator it(treeWidget, 
		QTreeWidgetItemIterator::NoChildren | QTreeWidgetItemIterator::Checked);
	while (*it)
	{
		QVariant v = (*it)->data(0, Qt::UserRole);
		DataItem *dataItem =
			v.value<DataItem *>();

		if (filterSentence.isEmpty())
		{
			filterSentence = QString("%1 == %2")
				.arg(SLUT_GET_FILTER_KEY())
				.arg(dataItem->id);
		}
		else
		{
			filterSentence = QString("%1 || %2 == %3")
				.arg(filterSentence)
				.arg(SLUT_GET_FILTER_KEY())
				.arg(dataItem->id);
		}

		++it;
	}

	return filterSentence;
}

void FilterDialog::okClicked()
{
	this->accept();
}

void FilterDialog::applyClicked()
{
	toApply = true;
	okClicked();
}
