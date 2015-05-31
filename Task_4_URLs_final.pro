#-------------------------------------------------
#
# Project created by QtCreator 2015-05-25T18:06:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Task_4_URLs_final
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    linkrecord.cpp \
    fileparser.cpp \
    childwindow.cpp \
    resultwidget.cpp

HEADERS  += mainwindow.h \
    linkrecord.h \
    analyzeresultdocument.h \
    fileparser.h \
    childwindow.h \
    resultwidget.h

FORMS    += mainwindow.ui \
    resultwidget.ui

RESOURCES += \
    icons.qrc
