#pragma once

#include "EeCommon.h"

class DataTabModel;
class DataTreeModel;
class DataManager;

class EeCentralWidget : public QSplitter
{
	Q_OBJECT

public:
	EeCentralWidget(QWidget *parent);

	~EeCentralWidget();

	void load(const QString& fileNmae);

	void unload();

	void init();

	void reinit();

	void reset();

	bool isFirstPage() const;

	bool isLastPage() const;

	QString getPacketStatus() const;

	void fetchPreviousPage();

	void fetchNextPage();

	void applyFilter();

private:
	void resizeTabViewColumnsWidth();
	void resizeTabViewColumnWidth(int column);

private slots:
	void clickTabViewRow(const QModelIndex &index);

	void clickTreeViewRow(const QModelIndex &index);

	void showTreeViewContextMenu(const QPoint & pos);

	void expandAll();

	void collapseAll();

	void showTabViewContextMenu(const QPoint & pos);

	void copyContext();

	void exportTo();

	void analyze();
private:
	QTableView *tabView;

	QTreeView *treeView;

	QTextEdit *textEdit;

	DataTabModel *tabModel;

	DataTreeModel *treeModel;

	QMenu *treeviewContextMenu;

	QAction *expandAllAction;

	QAction *collapseAllAction;

	QMenu *tabviewContextMenu;

	QAction *copyAction;

	QAction *exportAction;

	QAction *analyzeAction;

	std::shared_ptr<DataManager> dm;
};
