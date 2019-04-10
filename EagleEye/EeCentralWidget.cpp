#include "EeCentralWidget.h"
#include "DataTabModel.h"
#include "DataTreeModel.h"
#include "EeProfile.h"
#include "TigerInit.h"
#include "DdtInit.h"
#include "PkgDecoder.h"
#include "PkgVisitor.h"
#include "StrucTree.h"
#include "ee_buffer_manage.h"
#include <QtXlsx/QtXlsx>

EeCentralWidget::EeCentralWidget(QWidget *parent)
	: QSplitter(parent)
{

	tabView = new QTableView;
	treeView = new QTreeView;
	textEdit = new QTextEdit;
	tabModel = new DataTabModel;
	treeModel = new DataTreeModel(Q_NULLPTR);	
	
	dm = std::shared_ptr<DataManager>(Q_NULLPTR);

	this->addWidget(tabView);
	this->addWidget(treeView);
	this->addWidget(textEdit);
	this->setOrientation(Qt::Vertical);

	tabView->setGridStyle(Qt::NoPen);
	tabView->clearSpans();
	tabView->setSelectionBehavior(QAbstractItemView::SelectRows);
	tabView->setContextMenuPolicy(Qt::CustomContextMenu);
	textEdit->setReadOnly(true);
	treeView->setContextMenuPolicy(Qt::CustomContextMenu);

	connect(tabView, SIGNAL(clicked(const QModelIndex &)),
		this, SLOT(clickTabViewRow(const QModelIndex &)));
	connect(treeView, SIGNAL(clicked(const QModelIndex &)),
		this, SLOT(clickTreeViewRow(const QModelIndex &)));

	treeviewContextMenu = new QMenu(this);
	expandAllAction = new QAction("Expand All", this);
	collapseAllAction = new QAction("Collapse All", this);
	expandAllAction->setEnabled(true);
	collapseAllAction->setEnabled(true);
	connect(treeView, SIGNAL(customContextMenuRequested(const QPoint&)),
		this, SLOT(showTreeViewContextMenu(const QPoint&)));
	connect(expandAllAction, SIGNAL(triggered()),
		this, SLOT(expandAll()));
	connect(collapseAllAction, SIGNAL(triggered()),
		this, SLOT(collapseAll()));

	tabviewContextMenu = new QMenu(this);
	copyAction = new QAction("Copy", this);
	exportAction = new QAction("Export", this);
	analyzeAction = new QAction("Analyze", this);
	copyAction->setEnabled(true);
	exportAction->setEnabled(true);
	analyzeAction->setEnabled(true);
	connect(tabView, SIGNAL(customContextMenuRequested(const QPoint&)),
		this, SLOT(showTabViewContextMenu(const QPoint&)));
	connect(copyAction, SIGNAL(triggered()),
		this, SLOT(copyContext()));
	connect(exportAction, SIGNAL(triggered()),
		this, SLOT(exportTo()));
	connect(analyzeAction, SIGNAL(triggered()),
		this, SLOT(analyze()));
}

EeCentralWidget::~EeCentralWidget()
{
	reset();
}

void EeCentralWidget::load(const QString& fileName)
{
	EELOG_TRACE("Enter EeCentralWidget::load");

	if (dm.get())
	{
		dm->loadPackets(fileName);

		tabModel->setDataSource(dm.get());		
		tabView->setModel(tabModel);
		resizeTabViewColumnsWidth();
	
	}

	EELOG_TRACE("Leave EeCentralWidget::load");
}

void EeCentralWidget::unload()
{
	EELOG_INFO("Enter unload");
	tabView->setModel(Q_NULLPTR);
	EELOG_INFO("End setModel");
	tabModel->setDataSource(Q_NULLPTR);
	EELOG_INFO("End setDataSource");
	treeView->setModel(Q_NULLPTR);
	EELOG_INFO("End setModel");
	textEdit->clear();
	dm->clear();
	EELOG_INFO("Leave unload");	
}

void EeCentralWidget::init()
{
	SLUT_INIT();

	switch (EeProfile::strucType)
	{
	case EE_STRUC_TYPE_TIGER:
		TIGER_INIT();
		break;

	case EE_STRUC_TYPE_DDT:
		DDT_INIT();
		break;

	case EE_STRUC_TYPE_TTI:
	default:
		EELOG_WARN("EeCentralWidget::init|unsupported type (" << EeProfile::strucType << ")");
		break;
	}
}

void EeCentralWidget::reinit()
{
	reset();
	init();
}

void EeCentralWidget::reset()
{
	EELOG_INFO("Enter reset");
	unload();	
	EELOG_INFO("End unload");
	EeSymManager::clear();
	EELOG_INFO("End EeSymManager::clear()");
	StrucLUT::clear();
	EELOG_INFO("End StrucLUT::clear()");
	StrucTreeManager::getInstance()->clrInstance();
	EELOG_INFO("Leave reset");
	EEBUF_SHOW();
}

bool EeCentralWidget::isFirstPage() const
{
	if (dm.get())
	{
		return dm->isFirstPage();
	}

	return false;
}

bool EeCentralWidget::isLastPage() const
{
	if (dm.get())
	{
		return dm->isLastPage();
	}

	return false;
}

QString EeCentralWidget::getPacketStatus() const
{	
	if (dm.get())
	{
		return dm->getPacketStatus();
	}
	else
	{
		return QString("No Packets");
	}
}

void EeCentralWidget::fetchPreviousPage()
{
	if (nullptr == dm.get())
		return;
	
	if (dm->check2FetchPreviousPage())
	{
		tabView->setModel(Q_NULLPTR);
		tabView->setModel(tabModel);
		resizeTabViewColumnsWidth();
	}
}

void EeCentralWidget::fetchNextPage()
{
	if (nullptr == dm.get())
		return;

	if (dm->check2FetchNextPage())
	{
		tabView->setModel(Q_NULLPTR);
		tabView->setModel(tabModel);
		resizeTabViewColumnsWidth();
	}
}

void EeCentralWidget::clickTabViewRow(const QModelIndex &index)
{
	PkgLoc* pkgLoc = dm->getPkgLocByPkgIdx(index.row());
	Q_ASSERT(pkgLoc != Q_NULLPTR);
	quint32 decoderId = dm->getDecoderId(pkgLoc);
	PkgDecoder* refDecoder = dm->getPkgDecoderMng()->getDecoder(decoderId);
	if (Q_NULLPTR == refDecoder)
	{
		treeView->setModel(Q_NULLPTR);
		treeModel->setDataSource(Q_NULLPTR);
		textEdit->clear();
	}
	else
	{		
		const QByteArray& b = dm->getDecoderCxt(pkgLoc);				
		std::shared_ptr<PkgDecoder> decode(refDecoder->clone());
		decode->decode(b, pkgLoc);

		treeModel->setDataSource(decode->detachStrucTree());
		treeView->setModel(Q_NULLPTR);
		treeView->setModel(treeModel);		
		if (collapseAllAction->isEnabled())
		{
			treeView->expandAll();
		}

		QVariant v(b.toHex());
		textEdit->setText(v.toString());
	}
}

void EeCentralWidget::clickTreeViewRow(const QModelIndex &index)
{
	if (!index.isValid())
		return;

	StrucTree *st = 
		static_cast<StrucTree*>(index.internalPointer());
	if (Q_NULLPTR == st)
		return;

	quint16 offsetInByte = 
		st->data(StrucTree::FI_IDX_OFFSET_IN_BYTE).toUInt();
	quint16 sizeInByte =
		st->data(StrucTree::FI_IDX_SIZE_IN_BYTE).toUInt();

	QTextCursor cur = textEdit->textCursor();
	cur.setPosition(0, QTextCursor::MoveAnchor);
	cur.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
	textEdit->setTextCursor(cur);

	QTextCharFormat cf;
	cf.setFontWeight(QFont::Normal);
	cur.mergeCharFormat(cf);

	cur.setPosition(offsetInByte * 2, QTextCursor::MoveAnchor);
	cur.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, sizeInByte * 2);
	textEdit->setTextCursor(cur);

	cf.setFontWeight(QFont::ExtraBold);
	cur.mergeCharFormat(cf);
}

void EeCentralWidget::showTreeViewContextMenu(const QPoint & pos)
{
	QTreeView* senderTV = qobject_cast<QTreeView*>(sender());
	if (senderTV != treeView)
	{
		return;
	}

	if (Q_NULLPTR == treeView->model())
	{
		return;
	}

	treeviewContextMenu->clear();
	treeviewContextMenu->addAction(expandAllAction);
	treeviewContextMenu->addAction(collapseAllAction);
	treeviewContextMenu->exec(QCursor::pos());
}

void EeCentralWidget::expandAll()
{
	treeView->expandAll();
	expandAllAction->setEnabled(false);
	collapseAllAction->setEnabled(true);
}

void EeCentralWidget::collapseAll()
{
	treeView->collapseAll();
	expandAllAction->setEnabled(true);
	collapseAllAction->setEnabled(false);
}

void EeCentralWidget::showTabViewContextMenu(const QPoint & pos)
{
	QTableView* senderTV = qobject_cast<QTableView*>(sender());
	if (senderTV != tabView)
	{
		return;
	}

	QModelIndex index = tabView->currentIndex();
	if (index.isValid())
	{
		tabviewContextMenu->clear();
		tabviewContextMenu->addAction(copyAction);
		if (dm.get() != nullptr && 
			dm->doesFilterOnceDone())
		{
			tabviewContextMenu->addAction(exportAction);
			tabviewContextMenu->addAction(analyzeAction);
		}
		tabviewContextMenu->exec(QCursor::pos());
	}
}

void EeCentralWidget::copyContext()
{
	QAbstractItemModel *model = tabView->model();
	int col = 2;
	int row = tabView->currentIndex().row();	
	QModelIndex index = model->index(row, col);
	QVariant info = model->data(index);

	QClipboard *clipboard = QApplication::clipboard();
	clipboard->setText(info.toString());	
}

void EeCentralWidget::exportTo()
{
	QModelIndex index = tabView->currentIndex();
	PkgLoc* pkgLoc = dm->getPkgLocByPkgIdx(index.row());
	Q_ASSERT(pkgLoc != Q_NULLPTR);
	quint32 decoderId = dm->getDecoderId(pkgLoc);
	PkgDecoder* decoder = dm->getPkgDecoderMng()->getDecoder(decoderId);
	if (Q_NULLPTR == decoder)
	{
		QMessageBox::warning(this,
			QObject::tr("EagleEye"), 
			QString("Not Supported for decodedId (%1)").arg(decoderId));
		return;
	}

	QDateTime local(QDateTime::currentDateTime());
	QString filename = QString("D:/vs2013/sln/EagleEye/export/Export_b%1_%2.csv")
		.arg(decoderId)
		.arg(local.toString("yyyymmddhhmmss"));
	QFile exportFie(filename);
	if (!exportFie.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QMessageBox::warning(this,
			QObject::tr("EagleEye"),
			QString("Faile to open file (%1)").arg(filename));
		return;
	}
	QTextStream out(&exportFie);
	QString titleline;

	const QByteArray& b = dm->getDecoderCxt(pkgLoc);
	decoder->decode(b, pkgLoc);
	auto kv =
		decoder->getStrucTree()->getKvMap();
	QHashIterator<QString, QVariant> i(*kv);
	while (i.hasNext())
	{
		i.next();
		titleline.append(i.key()).append(",");
	}
	out << titleline << "\n";

	QVector<quint32> filteredPkgIdxs;
	dm->fetchPkgIdxs(decoderId, &filteredPkgIdxs);

	QProgressDialog progress("Export packet...", "Stop",
		0, filteredPkgIdxs.size(), this);
	progress.setAutoClose(true);
	progress.setWindowModality(Qt::WindowModal);

	for (quint32 pkgIdx = 0; pkgIdx < filteredPkgIdxs.size(); ++pkgIdx)
	{
		if (0 == (pkgIdx & 0xFFF))
		{
			progress.setValue(pkgIdx);
		}		

		QString line;

		pkgLoc = dm->getPkgLocByPkgIdx(filteredPkgIdxs[pkgIdx]);
		const QByteArray& b = dm->getDecoderCxt(pkgLoc);
		decoder->decode(b, pkgLoc);
		auto kv = 
			decoder->getStrucTree()->getKvMap();
		QHashIterator<QString, QVariant> i(*kv);
		while (i.hasNext())
		{
			i.next();
			line.append(i.value().toString()).append(",");
		}

		out << line << "\n";
	}

	EELOG_DEBUG("EeCentralWidget::exportTo|filename (" << QSTR2CSTR(filename) << ")");
}

void EeCentralWidget::analyze()
{

}

void EeCentralWidget::applyFilter()
{
	EELOG_TRACE("Enter EeCentralWidget::applyFilter");

	tabView->setModel(Q_NULLPTR);
	treeView->setModel(Q_NULLPTR);
	textEdit->clear();
	dm->filter();
	tabView->setModel(tabModel);
	resizeTabViewColumnsWidth();

	EELOG_TRACE("Leave EeCentralWidget::applyFilter");
}

void EeCentralWidget::resizeTabViewColumnWidth(int column)
{
	int columnWidth = tabView->columnWidth(column);
	tabView->setColumnWidth(column, columnWidth + columnWidth >> 1);
}

void EeCentralWidget::resizeTabViewColumnsWidth()
{	
	tabView->resizeColumnsToContents();
	//resizeTabViewColumnWidth(0);
	//resizeTabViewColumnWidth(1);
}