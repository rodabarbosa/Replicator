#-------------------------------------------------
#
# Project created by QtCreator 2015-05-23T09:12:15
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Replicater
TEMPLATE = app


SOURCES += main.cpp \
    bullet.cpp \
    ship.cpp \
    enemy.cpp \
    score.cpp \
    game.cpp \
    live.cpp

HEADERS  += \
    bullet.h \
    ship.h \
    enemy.h \
    score.h \
    game.h \
    live.h

FORMS    +=

RESOURCES += \
    res.qrc
