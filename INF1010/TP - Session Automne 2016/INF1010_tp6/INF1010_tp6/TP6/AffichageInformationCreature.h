/****************************************************************************
* Fichier: AffichageInformationCreature.h
* Auteur: PolySensei and Associates
* Date: 23 novembre 2016
* Mise a jour : 10 décembre 2016
* Description: Définition de la classe AffichageInformationCreature
****************************************************************************/

#ifndef AFFICHAGEINFORMATIONCREATURE_H
#define AFFICHAGEINFORMATIONCREATURE_H
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QRectF>
#include <QGraphicsScene>
#include "Creature.h"

#define TAILLE_BARRE 250

class AffichageInformationCreature : QGraphicsView
{
    Q_OBJECT
    public:
    explicit AffichageInformationCreature(QWidget *parent = 0);

    //Different elements graphiques pour l'affichage des informations sur une creature
    QGraphicsView* informations;
    QGraphicsScene* contenuInformations;
    QGraphicsRectItem *pv;
    QGraphicsRectItem *pvTotal;
    QGraphicsRectItem *energie;
    QGraphicsRectItem *energieTotal;
    QGraphicsRectItem *xp;
    QGraphicsRectItem *xpTotal;
    QGraphicsTextItem *pokomonName;
    QGraphicsTextItem *textPV;
    QGraphicsTextItem *textCurrentPv;
    QGraphicsTextItem *textEnergie;
    QGraphicsTextItem *textCurrentEnergie;
    QGraphicsTextItem *textXp;
    QGraphicsTextItem *textCurrentXp;

    public slots:
    //Slot permettant de mettre a jour l'affichage graphique des informations sur la creature
    void modifierAffichageInformationCreature(Creature* creature);


};

#endif // AFFICHAGEINFORMATIONCREATURE_H
