#-------------------------------------------------
#
# Project created by QtCreator 2016-07-28T16:58:00
#
#-------------------------------------------------

QT += core gui
QT += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NotePad
TEMPLATE = app


SOURCES += main.cpp\
    MainWindowSlots.cpp \
    MainWindowUI.cpp \
    FindDialog.cpp \
    ReplaceDialog.cpp \
    AboutDialog.cpp \
    AppConfig.cpp

HEADERS  += MainWindow.h \
    FindDialog.h \
    ReplaceDialog.h \
    AboutDialog.h \
    AppConfig.h

RESOURCES += \
    Res.qrc
