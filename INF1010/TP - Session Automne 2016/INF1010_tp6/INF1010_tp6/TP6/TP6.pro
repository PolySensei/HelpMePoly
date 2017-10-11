#-------------------------------------------------
#
# Project created by QtCreator 2016-11-21T00:31:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TP6
TEMPLATE = app


RESOURCES += \
    images.qrc

SOURCES += main.cpp\
        Gamebay.cpp \
    Menu.cpp \
    ChoixAttaque.cpp \
    Creature.cpp \
    Dresseur.cpp \
    Polyland.cpp \
    Pouvoir.cpp \
    ObjetMagique.cpp \
    AffichageInformationCreature.cpp \
    ExceptionCreatureMorte.cpp

HEADERS  += Gamebay.h \
    Menu.h \
    ChoixAttaque.h \
    Creature.h \
    Dresseur.h \
    Polyland.h \
    Pouvoir.h \
    ObjetMagique.h \
    AffichageInformationCreature.h \
    ExceptionCreatureMorte.h \
    ExceptionAttaqueEchouee.h \
    ExceptionEchecCapture.h

