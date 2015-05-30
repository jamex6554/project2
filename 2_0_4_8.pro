#-------------------------------------------------
#
# Project created by QtCreator 2015-05-23T21:46:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2_0_4_8
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    image/image.cpp \
    start.cpp

HEADERS  += mainwindow.h \
    start.h

FORMS    += mainwindow.ui \
    start.ui

RESOURCES += \
    image.qrc
