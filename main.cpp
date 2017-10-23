#include "tcpqt.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tcpQt w;
    w.show();

    tcpQt s;
 s.sConnect();
 s.show();

    return a.exec();
}
