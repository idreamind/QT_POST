#-------------------------------------------------
#
# Project created by QtCreator 2016-01-17T00:24:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WebConnection
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp

HEADERS  += Widget.h

FORMS    += Widget.ui

RESOURCES += \
    res/res.qrc

include(web/web.pri)
