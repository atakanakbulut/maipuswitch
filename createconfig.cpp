#include "createconfig.h"
#include "ui_createconfig.h"

#include<QDebug>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QFileDialog>
createConfig::createConfig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createConfig)
{
    ui->setupUi(this);

}

createConfig::~createConfig()
{
    delete ui;

}

void createConfig::on_pushButton_2_clicked()
{
    QString d1 = ui->lineEdit->text();
          QString d2 = ui->lineEdit_2->text();
           QString d3 =ui->lineEdit_3->text();
       QString d4 = ui->lineEdit_4->text();
         QString d5 =ui->lineEdit_5->text();

     //QString ret = d1,d2,d3,d4;
         //ui->textEdit->setText(d1,d2);


         QFile file("/home/atakan/Desktop/setuper.sh");
         if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
                  return;
       //  QFile::write(QString d1);

         QTextStream out(&file);
            out << "The magic number is: " << d1 << "\n";



            //QMessageBox::information(this,"",dd);




}
