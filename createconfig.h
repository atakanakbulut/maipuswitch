#ifndef CREATECONFIG_H
#define CREATECONFIG_H

#include <QWidget>

namespace Ui {
class createConfig;
}

class createConfig : public QWidget
{
    Q_OBJECT

public:
    explicit createConfig(QWidget *parent = 0);
    ~createConfig();
void createfiles();
void createfilee();
signals:

public slots:

private slots:

void on_pushButton_2_clicked();

private:
    Ui::createConfig *ui;
    QString mfileName;
};



#endif // CREATECONFIG_H
