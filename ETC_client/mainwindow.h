#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QBoxLayout>

#include <QTreeView>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>

#include <QDateTime>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow(){}
    void setOnline();
    void setOffline();
    void clearView();
    void insertElement(const quint64 &timestamp, const quint8 &priority, const QString &description);

signals:
    void connectWithHost(const QString &hostName, const quint16 &port);
    void disconnectFromHost();
    void refreshData();
    void createNewElement(const quint64 &timestamp, const quint8 &priority, const QString &description);

private slots:
    void onConnectReleased();
    void onRefreshReleased();
    void onCreateReleased();
    void onConnected();
    void onDisconnected();

private:
    QPushButton *pbConnect;
    QPushButton *pbRefresh;
    QPushButton *pbCreate;
    QLineEdit *leHost;
    QLineEdit *lePort;
    QTreeView *treeView;
    enum LineState{OFFLINE, ONLINE} lineState;

    QStandardItemModel *itemModel;
    QSortFilterProxyModel *filterModel;
};

#endif // MAINWINDOW_H
