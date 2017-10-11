#include "Menu.h"
#include <QVBoxLayout>
/****************************************************************************
* Fichier: Menu.cpp
* Auteur: PolySensei and Associates
* Date: 23 novembre 2016
* Mise a jour : 10 décembre 2016
* Description: Implémentation de la classe Menu
****************************************************************************/



Menu::Menu(QWidget *parent) : QWidget(parent), opened_(false)
{
        //Definition des boutons differents boutons
        boutonAttaques_ = new QPushButton("Attaques", this);
        boutonAffichageCreaturesDresseur_ = new QPushButton("Vos Creatures", this);
        boutonAffichageCreatures_ = new QPushButton("Affichage Creatures Sauvages", this);
        boutonAffichageDresseurs_ = new QPushButton("Affichage Dresseurs", this);
        boutonAffichageInventaire_ = new QPushButton("AffichageInventaire", this);
        boutonFuir_ = new QPushButton("Fuir", this);
        boutonCapturer_ = new QPushButton("Capturer", this);

        listeCreaturesDresseur_ = new QListWidget(this);
        listeDresseurs_ = new QListWidget(this);
        listeCreatures_ = new QListWidget(this);
        listeObjets_ = new QListWidget(this);
        // Layout principal du Widget
        QVBoxLayout* layoutPrincipal = new QVBoxLayout();
        layoutPrincipal->addWidget(boutonAttaques_);
        layoutPrincipal->addWidget(boutonAffichageCreaturesDresseur_);
        layoutPrincipal->addWidget(listeCreaturesDresseur_);

        layoutPrincipal->addWidget(boutonAffichageCreatures_);
        layoutPrincipal->addWidget(listeCreatures_);

        layoutPrincipal->addWidget(boutonAffichageDresseurs_);
        layoutPrincipal->addWidget(listeDresseurs_);

        layoutPrincipal->addWidget(boutonAffichageInventaire_);
        layoutPrincipal->addWidget(listeObjets_);

        layoutPrincipal->addWidget(boutonFuir_);
        layoutPrincipal->addWidget(boutonCapturer_);


        // Crée un nouveau Widget comprenant le layout principal
        this->setLayout(layoutPrincipal);
        masquerBoutons();
        boutonAttaques_->hide();
        boutonCapturer_->hide();

}

void Menu::masquerBoutons(){
    //Cette methode va masquer les boutons necessaires a la gestion du menu
    boutonAffichageCreaturesDresseur_->hide();
    boutonAffichageCreatures_->hide();
    boutonAffichageDresseurs_->hide();
    boutonAffichageInventaire_->hide();
    listeCreaturesDresseur_->hide();
    listeCreatures_->hide();
    listeDresseurs_->hide();
    listeObjets_->hide();
    boutonFuir_->hide();
}

void Menu::afficherBoutons(){
    //Cette methode affiche les boutons utiles
    boutonAffichageCreaturesDresseur_->show();
    boutonAffichageCreatures_->show();
    boutonAffichageDresseurs_->show();
    boutonAffichageInventaire_->show();
}

void Menu::gestionDuMenu(){
    //Cette methode permet la gestion de l'affichage du menu
    if(opened_){
        masquerBoutons();
        boutonFuir_->hide();
        listeCreaturesDresseur_->hide();
        listeDresseurs_->hide();
        listeCreatures_->hide();
        listeObjets_->hide();
        opened_ = false;
    }else{
        afficherBoutons();
        opened_ = true;
    }
}

bool Menu::isOpened(){
    return opened_;
}

void Menu::afficherListeCreaturesDresseur(Dresseur& dresseur){
    // remplit la liste de creatures
    listeCreaturesDresseur_->clear();
    if(!listeCreaturesDresseur_->isVisible()){
        listeCreaturesDresseur_->show();
        std::vector<Creature*> creatures = dresseur.obtenirCreatures();
        if(creatures.size() >0){
            for (auto it = creatures.begin(); it != creatures.end(); it++) {
                QString s(QString::fromStdString((*it)->obtenirNom() + "\t\t V:" + std::to_string((*it)->obtenirPointDeVie())
                + "/" +  std::to_string((*it)->obtenirPointDeVieTotal()) + "\t E:" + std::to_string((*it)->obtenirEnergie())
                + "/" +  std::to_string((*it)->obtenirEnergieTotale())));
                //QString s(QString::fromStdString((*it)->obtenirNom()));
                QListWidgetItem* item = new QListWidgetItem(s, listeCreaturesDresseur_);
                item->setData(Qt::UserRole, QVariant::fromValue<Creature*>(*it));
            }
        }
    }else{
        listeCreaturesDresseur_->hide();
    }
}

void Menu::afficherListeCreatures(std::list<Creature*> creatures){
    // remplit la liste de creatures
    listeCreatures_->clear();
    if(!listeCreatures_->isVisible()){
        listeCreatures_->show();
        for (auto it = creatures.begin(); it != creatures.end(); it++) {
            QString s(QString::fromStdString((*it)->obtenirNom() + "\t\t V:" + std::to_string((*it)->obtenirPointDeVie())
            + "/" +  std::to_string((*it)->obtenirPointDeVieTotal()) + "\t E:" + std::to_string((*it)->obtenirEnergie())
            + "/" +  std::to_string((*it)->obtenirEnergieTotale())));
            QListWidgetItem* item = new QListWidgetItem(s, listeCreatures_);
            item->setData(Qt::UserRole, QVariant::fromValue<Creature*>(*it));
        }
    }else{
        listeCreatures_->hide();
    }
}

void Menu::affichierListeDresseurs(std::list<Dresseur*> dresseurs){
    // remplit la liste de dresseurs
    listeDresseurs_->clear();
    if(!listeDresseurs_->isVisible()){
        listeDresseurs_->show();
        for (auto it = dresseurs.begin(); it != dresseurs.end(); it++) {
            QString s(QString::fromStdString((*it)->obtenirNom()));
            QListWidgetItem* item = new QListWidgetItem(s, listeDresseurs_);
            item->setData(Qt::UserRole, QVariant::fromValue<Dresseur*>(*it));
        }
    }else{
        listeDresseurs_->hide();
    }
}

// Fonction qui retourne l'item correspondant a l'abonne selectionne dans la liste
QListWidgetItem* Menu::obtenirCreatureSelectionne()
{
    QList<QListWidgetItem*> selection = listeCreatures_->selectedItems();
    if (selection.isEmpty()) {
        throw std::length_error("Aucune creature n'est selectionne!");
    }
    return selection.back();
}

// Fonction qui retourne l'item correspondant a l'abonne selectionne dans la liste
QListWidgetItem* Menu::obtenirDresseurSelectionne()
{
    QList<QListWidgetItem*> selection = listeDresseurs_->selectedItems();
    if (selection.isEmpty()) {
        throw std::length_error("Aucune creature n'est selectionne!");
    }
    return selection.back();
}

void Menu::afficherInventaire(Dresseur* dresseur){
    // remplit la liste de dresseurs
    listeObjets_->clear();
    if(!listeObjets_->isVisible()){
        listeObjets_->show();
    }else{
        listeObjets_->hide();
    }
}

// Fonction qui retourne l'item correspondant a l'abonne selectionne dans la liste
QListWidgetItem* Menu::obtenirObjetMagiqueSelectionne()
{
    QList<QListWidgetItem*> selection = listeObjets_->selectedItems();
    if (selection.isEmpty()) {
        throw std::length_error("Aucune creature n'est selectionne!");
    }
    return selection.back();
}

QListWidgetItem* Menu::obtenirCreatureDresseurSelectionne()
{
    QList<QListWidgetItem*> selection = listeCreaturesDresseur_->selectedItems();
    if (selection.isEmpty()) {
        throw std::length_error("Aucune creature n'est selectionne!");
    }
    return selection.back();
}


void Menu::afficherAttaque(){
    boutonAttaques_->show();
}
