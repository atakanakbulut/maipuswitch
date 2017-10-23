#-------------------------------------------------
#
# Project created by QtCreator 2017-10-09T09:27:27
#
#-------------------------------------------------

QT       += core gui
QT       += network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tcpsocketqt
TEMPLATE = app


SOURCES += main.cpp\
        tcpqt.cpp \
    createconfig.cpp

HEADERS  += tcpqt.h \
    createconfig.h

FORMS    += tcpqt.ui \
    createconfig.ui
