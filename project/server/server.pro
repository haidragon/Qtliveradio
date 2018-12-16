#-------------------------------------------------
#
# Project created by QtCreator 2016-09-30T12:11:22
#
#-------------------------------------------------

QT       += core gui
QT      += network
QT      += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    clientsocket.cpp \
    dbhelper.cpp \
    userdao.cpp \
    userdaoimp.cpp \
    onlinedao.cpp \
    onlinedaoimp.cpp \
    socketmanager.cpp \
    chat.cpp \
    chatmanager.cpp

HEADERS  += mainwindow.h \
    clientsocket.h \
    user.h \
    dbhelper.h \
    userdao.h \
    userdaoimp.h \
    onlinedao.h \
    onlinedaoimp.h \
    socketmanager.h \
    chat.h \
    chatmanager.h

FORMS    += mainwindow.ui

RC_FILE = res.rc
