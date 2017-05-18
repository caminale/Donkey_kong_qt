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
    game.cpp \
    platform.cpp \
    goomba.cpp \
    health.cpp \
    mainwindow.cpp

HEADERS  += mario.h \
    game.h \
    platform.h \
    goomba.h \
    health.h \
    mainwindow.h

FORMS    += mario.ui \
    mainwindow.ui

RESOURCES += \
    res.qrc
