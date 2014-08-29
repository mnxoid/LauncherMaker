#-------------------------------------------------
#
# Project created by QtCreator 2014-08-22T09:28:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LauncherMaker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    custompushbutton.cpp \
    customtoolbutton.cpp \
    customlineedit.cpp

HEADERS  += mainwindow.h \
    custompushbutton.h \
    customtoolbutton.h \
    customlineedit.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc

