#ifndef TCPQT_H
#define TCPQT_H

#include <QMainWindow>
#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QString>
#include  <QFileSystemModel>
#include "createconfig.h"
namespace Ui {
class tcpQt;
}

class tcpQt : public QMainWindow
{
    Q_OBJECT


public:
    explicit tcpQt(QWidget *parent = 0);
    ~tcpQt();

    void sConnect();

    void aOutput();
    QString send_text;
    //tcpQt s;
    //QProcess *process = new QProcess(this);

signals:

public slots:

    void toConnect();
    void sconnected();
    void sDisconnect();
    void sByteR();
    void sReadyforRead(qint64 bytes);
    void sGetData();
    void sReadyRead();
    void sUsernamePw();
    void sQProcess();
    void on_pushButton_6_clicked();
signals:

private:
    Ui::tcpQt *ui;
    QTcpSocket *sockets;
    tcpQt *tracker;
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;
    createConfig f;

private slots:

    void onSendClicked();
    void on_pushButton_2_clicked();
    void ssConsole();
    void on_listView_clicked(const QModelIndex &index);
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_createconfig_triggered();
};

#endif // TCPQT_H
