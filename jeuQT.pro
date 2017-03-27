#-------------------------------------------------
#
# Project created by QtCreator 2017-03-27T10:40:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = jeuQT
TEMPLATE = app


SOURCES += main.cpp\
        mario.cpp \
    game.cpp

HEADERS  += mario.h \
    game.h

FORMS    += mario.ui

RESOURCES += \
    res.qrc
