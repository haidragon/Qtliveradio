#-------------------------------------------------
#
# Project created by QtCreator 2016-09-30T12:11:54
#
#-------------------------------------------------

QT       += core gui
QT      += network
QT      += multimedia
QT      += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    clientsocket.cpp \
    chatroom.cpp \
    videosurface.cpp \
    roommanager.cpp

HEADERS  += mainwindow.h \
    user.h \
    dialog.h \
    clientsocket.h \
    chatroom.h \
    videosurface.h \
    roommanager.h

FORMS    += mainwindow.ui \
    dialog.ui \
    chatroom.ui

RESOURCES += \
    image.qrc

RC_FILE = res.rc
