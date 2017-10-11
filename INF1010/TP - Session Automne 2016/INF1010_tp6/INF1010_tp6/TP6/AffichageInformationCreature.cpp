/****************************************************************************
* Fichier: AffichageInformationCreature.cpp
* Auteur: PolySensei and Associates
* Date: 23 novembre 2016
* Mise a jour : 10 décembre 2016
* Description: Implémentation de la classe AffichageInformationCreature
****************************************************************************/

#include "AffichageInformationCreature.h"

AffichageInformationCreature::AffichageInformationCreature(QWidget *parent)
{
    //On cree ici la GraphicsScene pour afficher les informations sur la creature
    contenuInformations = new QGraphicsScene(parent);
    informations = new QGraphicsView(contenuInformations);
    //informations->setStyleSheet("QGraphicsScene{background-color:white;}");
    //Creation des differents brush pour dessiner
    QPen outlinePen(Qt::black);
    QPen outlinePen1(Qt::transparent);
    QBrush blueBrush(Qt::blue);
    QBrush greenBrush(Qt::green);
    QBrush redBrush(Qt::red);
    qreal hauteur = contenuInformations->height();
    hauteur /= 6;
    qreal largeur = contenuInformations->width();
    //Creation de la partie nom
    pokomonName = contenuInformations->addText("Name");
    pokomonName->setPos(0, 0);

    //Creation du texte PV
    textPV = contenuInformations->addText("PV");
    textPV->setPos(20, 40);
    //Creation du rectangle pour les points de vie
    pv = contenuInformations->addRect(30, 60, 80, 20, outlinePen1, greenBrush);
    pvTotal = contenuInformations->addRect(30, 60, 250, 20, outlinePen);

    //Mise en place du texte energie
    textEnergie = contenuInformations->addText("Energie");
    textEnergie->setPos(20, 100);

    //Creation du rectangle pour l'energie
    energie = contenuInformations->addRect(30, 120, 80, 20, outlinePen1, blueBrush);
    energieTotal = contenuInformations->addRect(30, 120, 250, 20, outlinePen);

    //Mise en place du texte xp
    textXp = contenuInformations->addText("XP");
    textXp->setPos(20, 160);

    //Creation du rectangle pour l'experience
    xp = contenuInformations->addRect(30, 180, 80, 20, outlinePen1, redBrush);
    xpTotal = contenuInformations->addRect(30, 180, 250, 20, outlinePen);
}

void AffichageInformationCreature::modifierAffichageInformationCreature(Creature* creature)
{
    //Methode permettant de mettre a jour la scene graphique avec les informations de la creature
    QPen outlinePen(Qt::black);
    QPen outlinePen1(Qt::transparent);
    QBrush blueBrush(Qt::blue);
    QBrush greenBrush(Qt::green);
    QBrush redBrush(Qt::red);
    qreal hauteur = contenuInformations->height();
    qreal largeur = contenuInformations->width();
    //On affiche le nom de la creature et son niveau
    pokomonName->setPlainText(QString::fromStdString(creature->obtenirNom() + "\t lvl:" + std::to_string(creature->obtenirNiveau())));
    //On met a jour les points de vie
    int pointVie = (creature->obtenirPointDeVie() * TAILLE_BARRE) / creature->obtenirPointDeVieTotal();
    pv->setRect(40, 60, pointVie, 20);
    pvTotal->setRect(40, 60, 250, 20);
    //On met a jour l'energie
    int tailleEnergie = (creature->obtenirEnergie() * TAILLE_BARRE) / creature->obtenirEnergieTotale();
    energie->setRect(40, 120, tailleEnergie, 20);
    energieTotal->setRect(40, 120, 250, 20);
    //On met ajour l'experience
    int valeurXp = (creature->obtenirExperience() * TAILLE_BARRE) / creature->obtenirExperienceNecessaire();
    xp->setRect(40, 180, valeurXp, 20);
    xpTotal->setRect(40, 180, 250, 20);
}
