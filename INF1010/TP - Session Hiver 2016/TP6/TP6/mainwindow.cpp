/****************************************************************************
* Fichier: mainwindow.cpp
* Auteur: PolySensei & Associates
* Date: 1 avril 2016
* Mise a jour : 13 avril 2016
* Description: Implémentation de la classe mainwindow
****************************************************************************/
#include "MainWindow.h"
#include "ui_mainwindow.h"

#include <QDialog>
#include <QLabel>
#include <QListWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QStringList>
#include <QStandardItemModel>
#include <QTableView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QVariant>

#include <iostream>
#include <list>

#include "DialogEmprunter.h"

#include "ExceptionEchecRetour.h" // Ajouté pour la fonction retirerEmprunt()
#include "ExceptionEchecEmprunt.h" // Ajouté pour la fonction ajouterEmprunt()
#include <Qstring>


using namespace std;

Q_DECLARE_METATYPE(Abonne*)


MainWindow::MainWindow(Bibliotheque * biblio, QWidget *parent) :
    QMainWindow(parent)
{
    biblio_ = biblio;

    // crée l'interface
    setUI();

    // Connexions entre les signaux et les slots
    setConnections();

    // charge la liste d'abonnes dans l'interface
    chargerAbonnes();
}

MainWindow::~MainWindow()
{

}

//méthode privée setUI()
void MainWindow::setUI()
{
    // Widget et layout pour la liste d'abonnes
    listeAbonnes_ = new QListWidget(this);
    listeAbonnes_->setSortingEnabled(true);
    listeAbonnes_->setFixedWidth(180);
    QVBoxLayout* listeAbLayout = new QVBoxLayout;
    listeAbLayout->addWidget(new QLabel("Liste d'abonnés"));
    listeAbLayout->addWidget(listeAbonnes_);

    // Widget et layout pour le tableau d'emprunts d'un abonne
    tabEmprunts_ = new QTableView(this);
    model_ = new QStandardItemModel(0,3,this);
    model_->setHorizontalHeaderLabels(QStringList() << "Cote" << "Titre" << "Retour prévu");
    tabEmprunts_->setModel(model_);
    int w[3] = {60,220,80};
    for (int i = 0; i < 3; i++) {
        tabEmprunts_->setColumnWidth(i,w[i]);
    }
    tabEmprunts_->setFixedWidth(w[0]+w[1]+w[2]+18);
    QVBoxLayout* tabEmpruntsLayout = new QVBoxLayout;
    tabEmpruntsLayout->addWidget(new QLabel("Emprunts"));
    tabEmpruntsLayout->addWidget(tabEmprunts_);


	///////////////////////////////////////////////////
	//            !!!!! A FAIRE !!!!!
	// Ajout des boutons Retourner et Ajouter emprunt
	// (avec la même apparence que dans l'exemple)
    ///////////////////////////////////////////////////
    //Ajout des boutons
    boutonAjoutEmprunt_ = new QPushButton("Ajouter emprunt");
    boutonRetourner_ = new QPushButton("Retourner");
    QHBoxLayout* boutonHLayout = new QHBoxLayout;
    boutonHLayout->addWidget(boutonRetourner_);
    boutonHLayout->addWidget(boutonAjoutEmprunt_);
    tabEmpruntsLayout->addLayout(boutonHLayout);



    // Layout principal de la fenetre
    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addLayout(listeAbLayout);
    mainLayout->addLayout(tabEmpruntsLayout);
    // Crée un nouveau Widget comprenant le layout principal
    QWidget* widget = new QWidget;
    widget->setLayout(mainLayout);
    // Définit ce widget comme etant le widget central de notre classe
    setCentralWidget(widget);

    // Titre de la fenêtre
    setWindowTitle("Gestion de bibliothèque");
}
// Méthode privée setConnections()
void MainWindow::setConnections()
{
    connect(listeAbonnes_, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(afficherEmpruntsAbonne(QListWidgetItem*)));


	//////////////////////////////////////
	//       !!!!! A FAIRE !!!!!
	// Ajout des connexions manquantes
	//////////////////////////////////////
    // ajout des connections
    connect(boutonAjoutEmprunt_,SIGNAL(clicked(bool)),this,SLOT(ajouterEmprunt()));
    connect(boutonRetourner_,SIGNAL(clicked(bool)),this,SLOT(retirerEmprunt()));
    connect(this, SIGNAL(empruntAjoute(QListWidgetItem*)),this,SLOT(afficherEmpruntsAbonne(QListWidgetItem*)));

}

// Fonction qui remplit la liste d'abonnes a partir de ceux de la bibliotheque
void MainWindow::chargerAbonnes()
{
    // remplit la liste d'abonnes
    list<Abonne*> abonnes = biblio_->obtenirListeAbonnes();
    for (auto it = abonnes.begin(); it != abonnes.end(); it++) {
        QString s = ((*it)->obtenirNom() + ", " + (*it)->obtenirPrenom()).c_str();
        QListWidgetItem* item = new QListWidgetItem(s, listeAbonnes_);
        item->setData(Qt::UserRole, QVariant::fromValue<Abonne*>(*it));
    }
}

// Fonction qui recupere le pointeur de l'abonne selectionne dans la liste
// et charge les emprunts de cet abonne pour les afficher dans le tableau
void MainWindow::afficherEmpruntsAbonne(QListWidgetItem* item)
{
    Abonne* ab = item->data(Qt::UserRole).value<Abonne*>();
    map<string, Emprunt*> map = biblio_->trierEmprunt(ab);

    model_->removeRows(0,model_->rowCount());
    for (auto it = map.begin(); it != map.end(); it++) {
        Emprunt* e = (*it).second;
        QString cote = e->obtenirObjetEmpruntable()->obtenirCote().c_str();
        QString titre = e->obtenirObjetEmpruntable()->obtenirTitre().c_str();
        QString retour = QString::number(e->obtenirDateRetour());
        QList<QStandardItem*> row;
        row << (new QStandardItem(cote)) << (new QStandardItem(titre)) << (new QStandardItem(retour));
        model_->appendRow(row);
    }
}

// Fonction pour l'ajout d'un emprunt a l'abonne selectionne
void MainWindow::ajouterEmprunt()
{

	/////////////////////////////////////////////////////////////
	//                  !!!!! A FAIRE !!!!!
	// - Intercepter les exceptions pouvant être lancées lors 
	//   de l'exécution de cette méthode et afficher des boîtes 
	//   de message appropriées (voir exemple).
	// - Émettre le signal approprié lorsqu'un emprunt est 
	//   réussi pour permettre la mise à jour du tableau 
	//   d'emprunts de l'abonné.
    /////////////////////////////////////////////////////////////
    try
    {
	// Recupere le pointeur de l'abonne selectionne
    QListWidgetItem* itemAb = obtenirAbonneSelectionne(); // exception possible ici
    Abonne* ab = itemAb->data(Qt::UserRole).value<Abonne*>();

	// Cree et affiche la fenetre dialogue pour selectionner un nouvel objet a emprunter
    DialogEmprunter* dialog = new DialogEmprunter(biblio_->obtenirListeObjets());
    int result = dialog->exec();
	
	// Tente d'effectuer l'emprunt si on clique sur le bouton Ajouter emprunt
	// (rien de particulier se produit si on clique sur le bouton Annuler)
    if (result == QDialog::Accepted) {
		// pointeur sur l'objet selectionne dans la liste:
        ObjetEmpruntable* obj = dialog->obtenirObjetSelectionne();
		// tentative d'emprunt:
        biblio_->emprunter(ab->obtenirMatricule(),obj->obtenirCote(),160530); // exception possible ici
    }
    delete dialog;

    emit empruntAjoute(itemAb); // ajout emit
    }
    catch(ExceptionEchecEmprunt erreur)
    {
        QString titreMessageBox = QString("Echec d'emprunt (%1e erreur)").arg(ExceptionEchecEmprunt::obtenirValeurCompteur());
        QMessageBox::critical(this,titreMessageBox,erreur.what());
    }
    catch(std::length_error erreur2)
    {
        QMessageBox::critical(this,"Erreur de selecction",erreur2.what());
    }

}

// Fonction de retour d'objet emprunte
void MainWindow::retirerEmprunt()
{

	///////////////////////////////////////////////////////////////
	//                    !!!!! A FAIRE !!!!!
	// Intercepter l'exception lancée par la méthode retourner()
	// et afficher une boîte de message appropriée (voir exemple)
	///////////////////////////////////////////////////////////////
	// Interception de l'exeption et affichage demandé  
    try
    {
    biblio_->retourner("0","0"); // genere une erreur car cet emprunt n'existe pas
    }
    catch(ExceptionEchecRetour erreur)
    {
        QMessageBox::critical(this,"Echec de retour",erreur.what());
    }
}

// Fonction qui retourne l'item correspondant a l'abonne selectionne dans la liste
QListWidgetItem* MainWindow::obtenirAbonneSelectionne()
{
    QList<QListWidgetItem*> selection = listeAbonnes_->selectedItems();
    if (selection.isEmpty()) {
        throw std::length_error("Aucun abonne n'est selectionne!");
    }
    return selection.back();
}

