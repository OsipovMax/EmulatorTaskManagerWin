#-------------------------------------------------
#
# Project created by QtCreator 2016-02-17T10:37:32
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = emitationWindows
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    proces.cpp \
    allprocess.cpp \
    menu.cpp \
    dialog1.cpp

HEADERS  += mainwindow.h \
    proces.h \
    allprocess.h \
    menu.h \
    dialog1.h

FORMS    += mainwindow.ui \
    menu.ui \
    dialog1.ui

RESOURCES += \
    note.qrc

DISTFILES +=
