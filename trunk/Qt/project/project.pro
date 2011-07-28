#-------------------------------------------------
#
# Project created by QtCreator 2011-07-25T09:20:02
#
#-------------------------------------------------

QT       += core gui

TARGET = project
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mywidget.cpp \
    palnet.cpp \
    palnetwidget.cpp

HEADERS  += mainwindow.h \
    call.h \
    mywidget.h \
    data.h \
    palnet.h \
    palnetwidget.h

FORMS    += mainwindow.ui

#-------------------------------------------------
#
# The following are added by MSq
#
#-------------------------------------------------

QT += opengl

LIBS += -glut32
