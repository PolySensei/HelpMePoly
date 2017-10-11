/*
Fichier: ChoixAttaque.h
Auteur(s): Alexandre MAO
Date de creation: 15 Novembre 2016
Description: Widget graphique permettant l'affichage des boutons des attaques
*/
#ifndef CHOIXATTAQUE_H
#define CHOIXATTAQUE_H

#include <QWidget>
#include <QPushButton>
#include "Creature.h"

class ChoixAttaque : public QWidget
{
    Q_OBJECT
public:
    explicit ChoixAttaque(QWidget *parent = 0);
    QPushButton* attaque1_;
    QPushButton* attaque2_;
    QPushButton* attaque3_;
    QPushButton* attaque4_;

public slots:
    void afficherAttaques();
    void afficherAttaques(Creature* creature);
    void masquerAttaques();


};

#endif // CHOIXATTAQUE_H
