#include "tcpqt.h"
#include "ui_tcpqt.h"

//        LİBS
#include "createconfig.h"
#include <QtCore>
#include <QHostAddress>
#include <QDebug>
#include <QObject>
#include <QTcpSocket>
#include <QString>
#include <QProcess>
#include <QStringList>
#include <QtGui>
#include <QMessageBox>
#include <QStringList>
#include <QFileDialog>

//         DEFINE TO COLORS

#define red "background-color: red"
#define blue "background-color: blue"
#define gray "background-color: gray"
#define green "background-color: green"


tcpQt::tcpQt(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tcpQt)
{
    ui->setupUi(this);

    ui->toolButton->setStyleSheet(gray);
    //ui->toolButton_2->setStyleSheet(gray);
    ui->toolButton_commonPoe->setStyleSheet(gray);


    QString sPatch ="./ ";
    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllEntries );
    dirmodel->setRootPath(sPatch);
    ui->listView->setModel(dirmodel);

    filemodel = new QFileSystemModel(this);
    filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files );
    filemodel->setRootPath(sPatch);
    ui->listView_2->setModel(filemodel);
    connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(sQProcess()));
    //sockets->is


}



void tcpQt::sConnect()
{
    sockets = new QTcpSocket(this);
    connect(ui->pushbutton2,SIGNAL(pressed()),this,SLOT(sUsernamePw()));
    connect(sockets, SIGNAL(disconnected()),this,SLOT(sDisconnect()));
    connect(sockets, SIGNAL(connected()),this,SLOT(sconnected()));
    connect(sockets, SIGNAL(bytesWritten(qint64)),this,SLOT(sReadyforRead(qint64)));
    connect(ui->pbSend , SIGNAL(clicked(bool)),this, SLOT(onSendClicked()));
    connect(ui->leCmds, SIGNAL(returnPressed()),this, SLOT(onSendClicked()));
    connect(ui->pbSend, SIGNAL(clicked(bool)),this, SLOT(sReadyRead()));
}
// standard connection

void tcpQt::toConnect(){
}
//İP PORT Connection

void tcpQt::sUsernamePw(){

    qDebug() << "connecting";
    QString hst = ui->hostadr->text();
    // QString port = ui->portno->text();
    sockets->connectToHost(QHostAddress(hst),23);
    //sockets->isc

    if(!sockets->waitForConnected(5000)){
        qDebug() << "Error" << sockets->errorString();
        ui->label->setStyleSheet(red);
    }
    else
    {
        ui->label->setStyleSheet(red);
    }

}

void tcpQt::sconnected(){
    qDebug() << "connected...";
    // ui->label->setText("connected");
    ui->toolButton->setStyleSheet(green);
    //  sockets->write("HEAD / HTTP/1.0\r\n\r\n\r\n\r\n");
    sockets->write("dsasdsa");
}

void tcpQt::sDisconnect(){
    qDebug() << "disconnected";
    ui->toolButton->setStyleSheet(green);
}

void tcpQt::sByteR(){

    qDebug() << "reading...";
    qDebug() << sockets->readAll();
}

void tcpQt::aOutput(){

    //QString ans = tcpQt::sReadyforRead(qint64 bytes);
    qDebug() << "written" ;

}

void tcpQt::onSendClicked()
{
    if(ui->leCmds->text().length() == 0) return;

    // // ui->leCmds->text().toStdString().c_str();
    ui->leCmds->text().length();
    //    QString tes =  ui->leCmds->text().toStdString().c_str();
    QString tes = ui->leCmds->text();
    sockets->write("");
    qDebug() << tes << "written";

    ui->leCmds->clear();
}

void tcpQt::sReadyforRead(qint64 bytes){

    qDebug() << bytes << " bytes written...";
    ui->toolButton->setStyleSheet(green);
}

void tcpQt::sGetData(){
}
void tcpQt::sReadyRead(){
    qDebug() << "reading ...";
    //  qDebug() << sockets->readAll();
    QString aa = sockets->readAll();
    qDebug() << aa;
    ui->lineEdit->setText(aa);

    //ui->listWidget = sockets->readAll();
}

tcpQt::~tcpQt()
{
    delete ui;
}
void tcpQt::on_pushButton_2_clicked()
{
    connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(close()));
}


void tcpQt::on_listView_clicked(const QModelIndex &index)
{
    QString sPatch = dirmodel->fileInfo(index).absoluteFilePath();
    ui->listView_2->setRootIndex(filemodel->setRootPath(sPatch));
}

void tcpQt::on_pushButton_3_clicked()
{
    QProcess *procesrestart = new QProcess(this);
    QString programrs = "/bin/sh";
    QString listrs ="/home/atakan/Desktop/smallcity/source/Qrestart.sh";
    procesrestart->start(programrs,QStringList()<< "-c" << listrs);
    procesrestart->waitForFinished();
    QMessageBox::information(this,"Message","Restarting");
}
void tcpQt::on_pushButton_4_clicked()

{
    QProcess *procesOpenPoE = new QProcess(this);
    QString programoP = "/bin/sh";
    QString listoP ="/home/atakan/Desktop/smallcity/source/Qopenp.sh";
    procesOpenPoE->start(programoP,QStringList()<< "-c" << listoP);
    procesOpenPoE->waitForFinished();
    if(listoP.isNull()){
        ui->toolButton_commonPoe->setStyleSheet(red);
        QMessageBox::warning(this,"Error","config file error!!");
    }

    else{
        {ui->toolButton_commonPoe->setStyleSheet(green);
            QMessageBox::information(this,"İnfo","Poe is opened");
        }
    }
}
void tcpQt::on_pushButton_5_clicked()
{
    QProcess *procesClosePoE = new QProcess(this);
    QString programcP = "/bin/sh";
    QString listcP ="/home/atakan/Desktop/smallcity/source/Qclosep.sh";
    procesClosePoE->start(programcP,QStringList()<< "-c" << listcP);
    procesClosePoE->waitForFinished();
    if(listcP.isNull()){
        ui->toolButton_commonPoe->setStyleSheet(red);
        QMessageBox::warning(this,"Error","config file error!!");
    }

    else{ui->toolButton_commonPoe->setStyleSheet(green);
        QMessageBox::information(this,"İnfo","Poe is closed");
    }
}
//          FILE OPEN AND SELECT CONFİG SCRİPT
void tcpQt::on_pushButton_6_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select to config"), "/home/atakan", tr("Config Files(.sh) (*.sh)"));
    QMessageBox::information(this,"this",fileName);
    qDebug().nospace() << qPrintable(fileName);
    ui->label_5->setText(fileName);
}

//      SEND SETTİNG
void tcpQt::sQProcess()
{

    QProcess *process = new QProcess(this);
    QString program = "/bin/sh";
    QString labelname = ui->label_5->text();
    //  QString list ="/home/atakan/Desktop/smallcity/source/QSendcommand.sh";
    qDebug() << labelname << "config file will setup";
    process->start(program,QStringList()<< "-c" << labelname);
    process->waitForFinished();
    if(labelname.isNull()){
        ui->progressBar->setDisabled(false);
        //ui->toolButton_2->setStyleSheet(red);
        QMessageBox::warning(this,"warning!!","wrong cursor!!");
    }
    else{
        ui->progressBar->setEnabled(true);
        QMessageBox::information(this,"İnformation","Successfull");


    }
}

void tcpQt::on_createconfig_triggered(){
f.show();
}
