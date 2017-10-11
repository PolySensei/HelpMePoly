#-------------------------------------------------
#
# Project created by QtCreator 2016-03-21T18:41:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Abonne.cpp \
    Bibliotheque.cpp \
    DialogEmprunter.cpp \
    Dvd.cpp \
    Emprunt.cpp \
    Empruntable.cpp \
    Etudiant.cpp \
    EtudiantBaccalaureat.cpp \
    Livre.cpp \
    LivreNumerique.cpp \
    ObjetEmpruntable.cpp \
    Professeur.cpp \
    ExceptionEchecEmprunt.cpp

HEADERS  += mainwindow.h \
    Abonne.h \
    Bibliotheque.h \
    DetruireEmprunt.h \
    DialogEmprunter.h \
    Dvd.h \
    Emprunt.h \
    Empruntable.h \
    Etudiant.h \
    EtudiantBaccalaureat.h \
    Gestionnaire.h \
    Livre.h \
    LivreNumerique.h \
    MemeElement.h \
    ObjetEmpruntable.h \
    ObjetNumerique.h \
    Professeur.h \
    RechercheObjetEmpruntable.h \
    TrieParTitre.h \
    ExceptionEchecEmprunt.h \
    ExceptionEchecRetour.h

FORMS    += mainwindow.ui

DISTFILES += \
    test.pro.user
