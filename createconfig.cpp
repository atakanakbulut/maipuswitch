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
    QString d1 = ui->lineEdit->text();  //vlan_no
    QString d2 = ui->lineEdit_2->text(); // ipadr
    QString d3 =ui->lineEdit_3->text(); //mask
    QString d4 = ui->lineEdit_4->text(); // gateway

    //dhcp settings
    QString d5 =ui->lineEdit_5->text(); //subnet
    QString d6 =ui->lineEdit_6->text(); //mask
    QString d7 =ui->lineEdit_7->text(); //start
    QString d8 =ui->lineEdit_8->text(); //last

    QFile file("/home/atakan/Desktop/setuperderes.sh");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    else{
        //  QFile::write(QString d1);
        QTextStream out(&file);
        out << "#!/bin/bash\nenable\nconfigure\nvlan 1\nvlan "<<d1<<"\nexit\ninterface vlan "<<d1;
        out <<"\nip address "<<d2<<" "<<d3<<" gateway "<<d4<<"\nexit\n";
        //adjust to poe and dhcp
        if(ui->radioButton->isChecked()){
            qDebug() <<"DHCP on";
            out<<"ip dhcp pool 1\nnetwork "<<d5<<" "<<d6<<" "<<d7<<" "<<d8;
            out<<"\nlease 0 1 0\nexit\nip dhcp-server\n";
        }
        else
        {
            qDebug() <<"DHCP off";
        }

        if("PoE off" == ui->comboBox_2->currentText())
        {
            qDebug() <<"poe off";
            for(int counters=1; counters <= 8; counters++){
                out<<"interface gigabitethernet "<<counters<<"\nno poe enable\nexit\n";
            }

        }
        if("PoE on" == ui->comboBox_2->currentText()){
            qDebug() <<"poe on";
            out<<"poe reset\n";
        }

        // THİS PART ADJUST TRUNK AND ACCES PORT
        if(ui->checkBox->isChecked())
        { out<<"switchport gigabitethernet 1\nswitchport mode trunk\nswitchport trunk allowed vlan add "<<d1<<"\nexit\n";} // port 1
        else{out<<"interface gigabitethernet 1\nswitchport mode access\nswitchport access vlan "<<d1<<"\nexit\n";}

        if(ui->checkBox_2->isChecked())
        { out<<"switchport gigabitethernet 2\nswitchport mode trunk\nswitchport trunk allowed vlan add "<<d1<<"\nexit\n";} // port 2
        else{out<<"interface gigabitethernet 2\nswitchport mode access\nswitchport access vlan "<<d1<<"\nexit\n";}

        if(ui->checkBox_3->isChecked())
        { out<<"switchport gigabitethernet 3\nswitchport mode trunk\nswitchport trunk allowed vlan add "<<d1<<"\nexit\n";} // port 3
        else{out<<"interface gigabitethernet 3\nswitchport mode access\nswitchport access vlan "<<d1<<"\nexit\n";}

        if(ui->checkBox_4->isChecked())
        { out<<"switchport gigabitethernet 4\nswitchport mode trunk\nswitchport trunk allowed vlan add "<<d1<<"\nexit\n";} // port 4
        else{out<<"interface gigabitethernet 4\nswitchport mode access\nswitchport access vlan "<<d1<<"\nexit\n";}

        if(ui->checkBox_5->isChecked())
        { out<<"switchport gigabitethernet 5\nswitchport mode trunk\nswitchport trunk allowed vlan add "<<d1<<"\nexit\n";} // port 5
        else{out<<"interface gigabitethernet 5\nswitchport mode access\nswitchport access vlan "<<d1<<"\nexit\n";}

        if(ui->checkBox_6->isChecked())
        { out<<"switchport gigabitethernet 6\nswitchport mode trunk\nswitchport trunk allowed vlan add "<<d1<<"\nexit\n";} // port 6
        else{out<<"interface gigabitethernet 6\nswitchport mode access\nswitchport access vlan "<<d1<<"\nexit\n";}

        if(ui->checkBox_7->isChecked())
        { out<<"switchport gigabitethernet 7\nswitchport mode trunk\nswitchport trunk allowed vlan add "<<d1<<"\nexit\n";} // port 7
        else{out<<"interface gigabitethernet 7\nswitchport mode access\nswitchport access vlan "<<d1<<"\nexit\n";}

        if(ui->checkBox_8->isChecked())
        { out<<"switchport gigabitethernet 8\nswitchport mode trunk\nswitchport trunk allowed vlan add "<<d1<<"\nexit\n";} // port 8
        else{out<<"interface gigabitethernet 8\nswitchport mode access\nswitchport access vlan "<<d1<<"\nexit\n";}

        out<<"write";
    }

}
