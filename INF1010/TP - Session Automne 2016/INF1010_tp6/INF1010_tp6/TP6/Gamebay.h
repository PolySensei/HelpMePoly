/*
Fichier: Gamebay.h
Auteur(s): Alexandre MAO
Date de creation: 15 Novembre 2016
Description: Widget principal qui va etre utiliser pour creer la fenetre du jeu
*/
#ifndef GAMEBAY_H
#define GAMEBAY_H

#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <QTableView>
#include <QStandardItemModel>
#include <QPushButton>
#include <QLabel>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QRectF>
#include <QGraphicsScene>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "Menu.h"
#include "ChoixAttaque.h"
#include "PolyLand.h"
#include "AffichageInformationCreature.h"


namespace Ui {
class Gamebay;
}

class Gamebay : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gamebay(PolyLand* polyland, QWidget *parent = 0);
    ~Gamebay();

private:

    PolyLand* polyland_;
    Creature* creatureHero_;
    Creature* creatureAdverse_;
    QLabel* flecheGauche_;
    QLabel* flecheDroite_;
    QLabel* flecheHaut_;
    QLabel* flecheBas_;

    QPushButton* boutonA_;
    QPushButton* boutonB_;
    QPushButton* boutonStart_;
    QPushButton* boutonSelect_;

    ChoixAttaque* choixAttaque_;

    QLabel* imageAccueil_;

    AffichageInformationCreature* informationsAdversaire_;
    AffichageInformationCreature* informationsDresseur_;
    QLabel* pokomonAdversaire_;
    QLabel* pokomonDresseur_;

    bool combatEnCours_;

    void setUI();
    void setConnections();
    void chargerCreatures();
    void chargeDresseurs();
    QListWidgetItem* obtenirCreatureSelectionnee();
    QListWidgetItem* obtenirDresseurSelectionnee();
    Menu* menu_;

    QPixmap obtenirImageCreature(Creature* creature);


signals:
    //!!!!!! A COMPLETER !!!!!!
    void creatureVaincue(QListWidgetItem* item);
    void creatureAdverseVaincue();
private slots:
    //!!!!!! A COMPLETER !!!!!!
    void afficherCreaturesDresseur();
    void changerCreature(QListWidgetItem*);
    void afficherCreatures();
    void afficherDresseurs();
    void afficherInventaire();
    void afficherCombat();
    void afficherFinCombat();
    void debuterCombat(QListWidgetItem* item);
    void debuterCombat(Creature* creature);
    void attaquerCreatureAdverse();
    void gestionDuMenu();
    void afficherCapture();
    void capturerCreatureAdverse();
	void afficherAttaques();
};

#endif // GAMEBAY_H
