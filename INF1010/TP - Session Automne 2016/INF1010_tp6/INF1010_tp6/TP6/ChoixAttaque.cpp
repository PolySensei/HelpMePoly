/****************************************************************************
* Fichier: ChoixAttaque.cpp
* Auteur: PolySensei and Associates
* Date: 23 novembre 2016
* Mise a jour : 10 décembre 2016
* Description: Implémentation de la classe ChoixAttaque
****************************************************************************/

#include "ChoixAttaque.h"
#include <QGridLayout>

ChoixAttaque::ChoixAttaque(QWidget *parent) : QWidget(parent)
{
    //Creation des differents boutons d'attaques
    attaque1_ = new QPushButton("Attaque 1", this);
    attaque2_ = new QPushButton("Attaque 2", this);
    attaque3_ = new QPushButton("Attaque 3", this);
    attaque4_ = new QPushButton("Attaque 4", this);

    // Layout principal du Widget
    //!!!!!! A COMPLETER !!!!!!
    //Vous devez creer un gridLayout et y placer les differents boutons
    //N'oubliez pas de mettre en place le layout sur le widget
	QGridLayout* boutonGLayout = new QGridLayout;
    boutonGLayout->addWidget(attaque1_, 0, 0);
    boutonGLayout->addWidget(attaque2_, 0, 1);
    boutonGLayout->addWidget(attaque3_, 1, 0);
    boutonGLayout->addWidget(attaque4_, 1, 1);
    this->setLayout(boutonGLayout);
    masquerAttaques();

}

void ChoixAttaque::afficherAttaques(){
    //Cette methode affiche et desactive les boutons d'attaques
    attaque1_->show();
    attaque1_->setDisabled(true);
    attaque2_->show();
    attaque2_->setDisabled(true);
    attaque3_->show();
    attaque3_->setDisabled(true);
    attaque4_->show();
    attaque4_->setDisabled(true);
}

void ChoixAttaque::masquerAttaques(){
    //Cette methode masque les boutons d'attaques
    attaque1_->hide();
    attaque2_->hide();
    attaque3_->hide();
    attaque4_->hide();
}

void ChoixAttaque::afficherAttaques(Creature* creature){
    //Cette methode va afficher les boutons en fonction des attaques de la creature passee en parametre
    if(creature->obtenirPouvoirs().size() > 0){
        attaque1_->show();
        attaque1_->setText(QString::fromStdString(creature->obtenirPouvoirs()[0]->obtenirNom()));
        attaque1_->setEnabled(true);
    }else{
        attaque1_->setText("Attaque non disponible");
        attaque1_->setDisabled(true);
    }
    if(creature->obtenirPouvoirs().size() > 1){
        attaque2_->show();
        attaque2_->setText(QString::fromStdString(creature->obtenirPouvoirs()[1]->obtenirNom()));
        attaque2_->setEnabled(true);
    }else{
        attaque2_->setText("Attaque non disponible");
        attaque2_->setDisabled(true);
    }
    if(creature->obtenirPouvoirs().size() > 2){
        attaque3_->show();
        attaque3_->setText(QString::fromStdString(creature->obtenirPouvoirs()[2]->obtenirNom()));
        attaque3_->setEnabled(true);
    }else{
        attaque3_->setText("Attaque non disponible");
        attaque3_->setDisabled(true);
    }
    if(creature->obtenirPouvoirs().size() > 3){
        attaque4_->show();
        attaque4_->setText(QString::fromStdString(creature->obtenirPouvoirs()[3]->obtenirNom()));
        attaque4_->setEnabled(true);
    }else{
        attaque4_->setText("Attaque non disponible");
        attaque4_->setDisabled(true);
    }
}
