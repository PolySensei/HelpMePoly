/*
Fichier: Menu.h
Auteur(s): Alexandre MAO
Date de creation: 15 Novembre 2016
Description: Widget graphique qui servir de menu au jeu
*/
#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <QTableView>
#include <QStandardItemModel>
#include <QPushButton>
#include <QLabel>
#include <QGraphicsView>
#include <QtGui>
#include <QListWidget>
#include <list>
#include <QListWidgetItem>
#include <QString>
#include <QVariant>

#include "Creature.h"
#include "Dresseur.h"


Q_DECLARE_METATYPE(Creature*)
Q_DECLARE_METATYPE(Dresseur*)


class Menu : public QWidget
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = 0);

    QPushButton* boutonAttaques_;
    QPushButton* boutonAffichageCreaturesDresseur_;
    QPushButton* boutonAffichageCreatures_;
    QPushButton* boutonAffichageDresseurs_;
    QPushButton* boutonAffichageInventaire_;
    QPushButton* boutonFuir_;
    QPushButton* boutonCapturer_;

    QListWidget* listeCreaturesDresseur_;
    QListWidget* listeDresseurs_;
    QListWidget* listeCreatures_;
    QListWidget* listeObjets_;

    bool isOpened();

signals:

public slots:
    void masquerBoutons();
    void afficherBoutons();
    void gestionDuMenu();
    void afficherListeCreaturesDresseur(Dresseur& dresseur);
    void afficherListeCreatures(std::list<Creature*> creatures);
    void affichierListeDresseurs(std::list<Dresseur*> dresseurs);
    void afficherInventaire(Dresseur* dresseur);

    QListWidgetItem* obtenirCreatureDresseurSelectionne();
    QListWidgetItem* obtenirCreatureSelectionne();
    QListWidgetItem* obtenirDresseurSelectionne();
    QListWidgetItem* obtenirObjetMagiqueSelectionne();
    void afficherAttaque();

private:
    bool opened_;
};



#endif // MENU_H
