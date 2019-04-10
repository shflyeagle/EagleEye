#include "OptionDialog.h"
#include "EeProfile.h"
#include "StrucLUT.h"
#include "FilterTreeWidgetItem.h"


OptionDialog::OptionDialog(QWidget *parent):
QDialog(parent)
{
	setupUi(this);
	setupUiCustomized();
	initListWidget();
	bindConnections();	
}

OptionDialog::~OptionDialog()
{
}

void OptionDialog::initListWidget()
{
	optionListWidget->setViewMode(QListView::IconMode);

	QListWidgetItem **optionItems = 
		new QListWidgetItem *[OPTION_ITEM_MAX];
	for (int i = 0; i < OPTION_ITEM_MAX; ++i)
	{
		optionItems[i] = new QListWidgetItem();
	}

	QListWidgetItem *genItem = optionItems[OPTION_ITEM_GEN];
	genItem->setIcon(QIcon(":/images/general.png"));
	genItem->setText("general");
	genItem->setData(Qt::UserRole, OPTION_ITEM_GEN);
	genItem->setTextAlignment(Qt::AlignCenter);

	QListWidgetItem *otherItem = optionItems[OPTION_ITEM_OTHER];
	otherItem->setIcon(QIcon(":/images/general.png"));
	otherItem->setText("other");
	otherItem->setData(Qt::UserRole, OPTION_ITEM_OTHER);
	otherItem->setTextAlignment(Qt::AlignCenter);

	for (int i = 0; i < OPTION_ITEM_MAX; ++i)
	{
		optionListWidget->addItem(optionItems[i]);
	}

	changeOption(genItem);

	delete [] optionItems;
}

void OptionDialog::bindConnections()
{
	connect(stComboBox, SIGNAL(currentIndexChanged(int)),
		this, SLOT(changeStrucType(int)));

	connect(optionListWidget, SIGNAL(itemClicked(QListWidgetItem*)),
		this, SLOT(changeOption(QListWidgetItem*)));
}

void OptionDialog::changeStrucType(int strucType)
{
	featureDisabledTreeWidget->clear();

	const QMap<QString, std::shared_ptr<QMap<quint16, QString>>>& catLut =
		SLUT_GET_CATLUT_BY_ST(strucType);

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
			if (EeProfile::strucType == stComboBox->currentIndex() && 
				EeProfile::disabledFeaturesLut.contains(it2.key()))
			{
				child->setCheckState(0, Qt::Checked);
			}
			else
			{
				child->setCheckState(0, Qt::Unchecked);
			}			
			parent->addChild(child);
		}
	}

	featureDisabledTreeWidget->addTopLevelItems(twiL);


}

void OptionDialog::setupUiCustomized()
{
	//init general tab widget
	genTabWidget = new QTabWidget(layoutWidget);
	genTabWidget->setObjectName(QStringLiteral("genTabWidget"));
	genTab = new QWidget();
	genTab->setObjectName(QStringLiteral("genTab"));
	stComboBox = new QComboBox(genTab);
	stComboBox->setObjectName(QStringLiteral("stComboBox"));
	stComboBox->setGeometry(QRect(88, 20, 71, 22));
	stComboBox->setEditable(false);
	strucTypeLabel = new QLabel(genTab);
	strucTypeLabel->setObjectName(QStringLiteral("strucTypeLabel"));
	strucTypeLabel->setGeometry(QRect(10, 20, 71, 16));
	strucTypeLabel->setText("Trace Type: ");
	featureDisabledTreeWidget = new QTreeWidget(genTab);
	QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
	__qtreewidgetitem->setText(0, QStringLiteral("1"));
	featureDisabledTreeWidget->setHeaderItem(__qtreewidgetitem);
	featureDisabledTreeWidget->setObjectName(QStringLiteral("featureDisabledTreeWidget"));
	featureDisabledTreeWidget->setGeometry(QRect(10, 70, 541, 351));
	featureDisabledTreeWidget->setRootIsDecorated(true);
	featureDisabledTreeWidget->header()->setVisible(false);
	featureDisabledLabel = new QLabel(genTab);
	featureDisabledLabel->setObjectName(QStringLiteral("featureDisabledLabel"));
	featureDisabledLabel->setGeometry(QRect(10, 50, 91, 16));
	featureDisabledLabel->setText("Feature Disabled: ");
	genTabWidget->addTab(genTab, QString());
	ddtTab = new QWidget();
	ddtTab->setObjectName(QStringLiteral("ddtTab"));
	bwLabel = new QLabel(ddtTab);
	bwLabel->setObjectName(QStringLiteral("bwLabel"));
	bwLabel->setGeometry(QRect(10, 20, 61, 16));
	bwLabel->setText("Bandwidth: ");
	bwComboBox = new QComboBox(ddtTab);
	bwComboBox->setObjectName(QStringLiteral("bwComboBox"));
	bwComboBox->setGeometry(QRect(80, 20, 69, 22));
	antLabel = new QLabel(ddtTab);
	antLabel->setObjectName(QStringLiteral("antLabel"));
	antLabel->setGeometry(QRect(10, 60, 71, 16));
	antLabel->setText("Tx Antennas: ");
	antComboBox = new QComboBox(ddtTab);
	antComboBox->setObjectName(QStringLiteral("antComboBox"));
	antComboBox->setGeometry(QRect(80, 60, 69, 22));
	genTabWidget->addTab(ddtTab, QString());
	tigerTab = new QWidget();
	tigerTab->setObjectName(QStringLiteral("tigerTab"));
	genTabWidget->addTab(tigerTab, QString());

	genTabWidget->setTabText(genTabWidget->indexOf(genTab), "general");
	genTabWidget->setTabText(genTabWidget->indexOf(tigerTab), "tiger");
	genTabWidget->setTabText(genTabWidget->indexOf(ddtTab), "ddt");

	quint16 curIdx;
	QMap<quint16, QString>& stLut = SLUT_GET_STLUT();
	for (auto it = stLut.constBegin();
		it != stLut.constEnd();
		++it)
	{
		stComboBox->addItem(it.value());
		if (it.key() == EeProfile::strucType)
		{
			curIdx = it.key();
		}		
	}
	stComboBox->setCurrentIndex(curIdx);

	QMap<quint16, QString>& bwLut = SLUT_GET_BWLUT();
	for (auto it = bwLut.constBegin();
		it != bwLut.constEnd();
		++it)
	{
		bwComboBox->addItem(it.value());
		if (it.key() == EeProfile::ddtProfile.bandwith)
		{
			curIdx = it.key();
		}
	}
	bwComboBox->setCurrentIndex(curIdx);


	QMap<quint16, QString>& antLut = SLUT_GET_ANTLUT();
	for (auto it = antLut.constBegin();
		it != antLut.constEnd();
		++it)
	{
		antComboBox->addItem(it.value());
		if (it.key() == EeProfile::ddtProfile.antTx)
		{
			curIdx = it.key();
		}
	}
	antComboBox->setCurrentIndex(curIdx);

	genTabWidget->setVisible(false);



	//init other tab widget
	otherTabWidget = new QTabWidget(layoutWidget);
	otherTabWidget->setObjectName(QStringLiteral("otherTabWidget"));
	otherTabWidget->setVisible(false);
}

void OptionDialog::changeOption(QListWidgetItem* item)
{
	QList<QWidget*> wl;
	for (int i = 0; i < tabVerticalLayout->count(); ++i)
	{
		QLayoutItem *li = tabVerticalLayout->itemAt(i);
		if (li->widget())
		{
			wl.append(li->widget());
		}
	}

	for (auto it = wl.constBegin(); it != wl.constEnd(); ++it)
	{
		tabVerticalLayout->removeWidget(*it);
		(*it)->setVisible(false);
	}

	quint16 itemType = item->data(Qt::UserRole).toInt();
	switch (itemType)
	{
	case OPTION_ITEM_GEN:
		showGenContext();
		break;

	case OPTION_ITEM_OTHER:
		showOtherContext();
		break;

	default:
		Q_ASSERT(false);
		break;
	}
}

void OptionDialog::showGenContext()
{
	headlineLineEdit->setText("General Setting");
	genTabWidget->setCurrentIndex(genTabWidget->indexOf(genTab));
	changeStrucType(stComboBox->currentIndex());
	tabVerticalLayout->addWidget(genTabWidget);
	genTabWidget->setVisible(true);
}

void OptionDialog::showOtherContext()
{
	headlineLineEdit->setText("Other Setting");
	tabVerticalLayout->addWidget(otherTabWidget);
	otherTabWidget->setVisible(true);
}

quint16 OptionDialog::getStrucType() const
{
	return findKey(SLUT_GET_STLUT(), 
		stComboBox->currentText());
}

quint16 OptionDialog::getBw() const
{
	return findKey(SLUT_GET_BWLUT(), 
		bwComboBox->currentText());
}

quint16 OptionDialog::getTxAnt() const
{
	return findKey(SLUT_GET_ANTLUT(), 
		antComboBox->currentText());
}

QMap<quint16, QString> OptionDialog::getDisabledFeaturesMap() const
{
	QMap<quint16, QString> felut;
	QTreeWidgetItemIterator it(featureDisabledTreeWidget,
		QTreeWidgetItemIterator::NoChildren | QTreeWidgetItemIterator::Checked);
	while (*it)
	{
		QVariant v = (*it)->data(0, Qt::UserRole);
		DataItem *dataItem =
			v.value<DataItem *>();

		felut.insert(dataItem->id, dataItem->desc);

		++it;
	}

	return felut;
}

quint16 OptionDialog::findKey(const QMap<quint16, QString>& lut, const QString& value) const
{
	for (auto it = lut.constBegin();
		it != lut.constEnd();
		++it)
	{
		if (it.value() == value)
		{
			return it.key();
		}		
	}

	Q_ASSERT(false);
	return 0xFFFF;
}
