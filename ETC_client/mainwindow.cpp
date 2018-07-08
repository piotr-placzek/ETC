#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    pbConnect(new QPushButton(tr("Connect"))),
    pbRefresh(new QPushButton(tr("Refresh"))),
    pbCreate(new QPushButton(tr("Create"))),
    leHost(new QLineEdit("localhost")),
    lePort(new QLineEdit("50000")),
    treeView(new QTreeView()),
    itemModel(new QStandardItemModel(0,3)),
    filterModel(new QSortFilterProxyModel())
{
    leHost->setMaximumWidth(150);
    leHost->setAlignment(Qt::AlignCenter);
    leHost->setPlaceholderText(tr("HOST"));

    QIntValidator *portValidator = new QIntValidator(0,65535);
    lePort->setValidator(portValidator);
    lePort->setMaximumWidth(75);
    lePort->setAlignment(Qt::AlignCenter);
    lePort->setPlaceholderText(tr("PORT"));

    QStringList treeViewHeaders = {tr("Time"),
                                   tr("Priority"),
                                   tr("Description")};
    itemModel->setSortRole(Qt::StatusTipRole);
    for(int i=0; i<3; ++i){
        itemModel->setHeaderData(i, Qt::Horizontal, treeViewHeaders.at(i));
    }

    /*
      READY FOR FILTER
        filterModel->setSourceModel(itemModel);
        filterModel->setFilterRegExp("[0-4]");
        filterModel->setFilterKeyColumn(1);
        filterModel->setSortRole(Qt::StatusTipRole);
        treeView->setModel(filterModel);
    */

    treeView->setModel(itemModel);
    treeView->setSortingEnabled(true);
    treeView->setAlternatingRowColors(true);
    treeView->sortByColumn(1,Qt::DescendingOrder);
    treeView->setIndentation(0);
    treeView->header()->setStretchLastSection(true);
    treeView->setColumnWidth(0,8*16);
    treeView->setColumnWidth(1,8*10);

    QBoxLayout *topLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    topLayout->addWidget(pbConnect);
    topLayout->addWidget(leHost);
    topLayout->addWidget(lePort);
    topLayout->addStretch(0);
    topLayout->addWidget(pbRefresh);
    topLayout->addWidget(pbCreate);

    QBoxLayout *mainLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(treeView);

    QWidget *myCentralWidget = new QWidget();
    myCentralWidget->setLayout(mainLayout);

    setCentralWidget(myCentralWidget);

    setOffline();

    connect(pbConnect,SIGNAL(released()),this,SLOT(onConnectReleased()));
    connect(pbRefresh,SIGNAL(released()),this,SLOT(onRefreshReleased()));
    connect(pbRefresh,SIGNAL(released()),this,SLOT(onCreateReleased()));
}

void MainWindow::setOnline()
{
    pbRefresh->setDisabled(false);
    pbCreate->setDisabled(false);
    leHost->setDisabled(true);
    lePort->setDisabled(true);
    pbConnect->setText(tr("Disconnect"));
    lineState = ONLINE;
}

void MainWindow::setOffline()
{
    pbRefresh->setDisabled(true);
    pbCreate->setDisabled(true);
    leHost->setDisabled(false);
    lePort->setDisabled(false);
    pbConnect->setText(tr("Connect"));
    lineState = OFFLINE;
}

void MainWindow::clearView()
{
    if(itemModel->hasChildren()){
        itemModel->removeRows(0,itemModel->rowCount());
    }
}

void MainWindow::insertElement(const quint64 &timestamp, const quint8 &priority, const QString &description)
{
    QStringList priorityStrings = {tr("Very low"),
                                  tr("Low"),
                                  tr("Medium"),
                                  tr("High"),
                                  tr("Very high")};

    QDateTime datetime;
    datetime.setTime_t(timestamp);

    QStandardItem *elementItem[3];
    elementItem[0] = new QStandardItem(datetime.toString(Qt::SystemLocaleShortDate));
    elementItem[0]->setData(datetime.toString(Qt::SystemLocaleShortDate),Qt::StatusTipRole);
    elementItem[1] = new QStandardItem(priorityStrings.at(priority));
    elementItem[1]->setData(priority,Qt::StatusTipRole);
    elementItem[2] = new QStandardItem(description);
    elementItem[2]->setData(description,Qt::StatusTipRole);

    itemModel->insertRow(0);
    for(int i=0; i<3; ++i){
        itemModel->setItem(0,i,elementItem[i]);
    }

}

void MainWindow::onConnectReleased()
{
    emit connectWithHost(leHost->text(), lePort->text().toUInt());
}

void MainWindow::onRefreshReleased()
{
    emit refreshData();
}

void MainWindow::onCreateReleased()
{

}

void MainWindow::onConnected()
{
    setOnline();
}

void MainWindow::onDisconnected()
{
    setOffline();
}
