/****************************************************************************
* Fichier: Creature.cpp
* Auteur: PolySensei and Associates
* Date: 23 novembre 2016
* Mise a jour : 10 décembre 2016
* Description: Implémentation de la classe Gamebay
****************************************************************************/

#include "Gamebay.h"
#include <iostream>

Gamebay::Gamebay(PolyLand* polyland, QWidget *parent) :
    QMainWindow(parent), polyland_(polyland), combatEnCours_(false), creatureHero_(nullptr), creatureAdverse_(nullptr)//,ui(new Ui::Gamebay)
{
    setUI();
    setConnections();
}

Gamebay::~Gamebay()
{

    delete flecheGauche_;
    delete flecheDroite_;
    delete flecheHaut_;
    delete flecheBas_;

    delete boutonA_;
    delete boutonB_;
    delete boutonStart_;
    delete boutonSelect_;

    //delete choixAttaque_;

    delete imageAccueil_;

    delete informationsAdversaire_;
    delete informationsDresseur_;
    delete pokomonAdversaire_;
    delete pokomonDresseur_;
}

//Une méthode privée setUI() qui crée les différents éléments de l’interface. Vous devez modifier
//cette fonction pour ajouter la partie qui va permettre de sélectionner les attaques que votre
//créature va lancer. Veuillez-vousréférer à la figure explicative (figure 2) et aux commentaires dans
//la méthode.

void Gamebay::setUI(){

    //Definition des fleches de navigations
    flecheGauche_ = new QLabel("G");
    QPixmap fleche_gauche(":/images/fleche_gauche.png");
    flecheGauche_->setPixmap(fleche_gauche);

    QPixmap fleche_droite(":/images/fleche_droite.png");
    flecheDroite_ = new QLabel("D");
    flecheDroite_->setPixmap(fleche_droite);

    QPixmap fleche_haut(":/images/fleche_haut.png");
    flecheHaut_ = new QLabel("H");
    flecheHaut_->setPixmap(fleche_haut);

    QPixmap fleche_bas(":/images/fleche_bas.png");
    flecheBas_ = new QLabel("B");
    flecheBas_->setPixmap(fleche_bas);

    //Definition des boutons differents boutons
    boutonA_ = new QPushButton("A", this);
    boutonA_->setFixedSize(60,60);
    boutonB_ = new QPushButton("B", this);
    boutonB_->setFixedSize(60,60);

    //Ajout d'un stylesheet pour rendre les boutons A et B plus cool :)
    std::string styleBouton("QPushButton{ padding : 5px; "
                            "border-radius: 30px; "
                            "background-color: black ;"
                            "color : grey;}\n");
    //On utilise ici du CSS pour modifier le rendu des boutons
    boutonA_->setStyleSheet(QString::fromStdString(styleBouton));
    boutonB_->setStyleSheet(QString::fromStdString(styleBouton));


    //Creation des boutons de la partie centrale
    boutonStart_ = new QPushButton("Start", this);
    boutonSelect_ = new QPushButton("Select", this);
    // Layout principal de la fenetre
    QVBoxLayout* layoutPrincipal = new QVBoxLayout();
    //Layout permettant de scinder la fenetre en deux
    QHBoxLayout* layoutAffichagePrincipal = new QHBoxLayout();
    QHBoxLayout* layoutCommandes = new QHBoxLayout();

    //Layout correspondant a l'ecran de la fenetre
    QVBoxLayout* layoutEcran = new QVBoxLayout();


    // Creation des differentes informations d'affichage dans la partie ecran
    informationsAdversaire_ = new AffichageInformationCreature(this);
    informationsDresseur_ = new AffichageInformationCreature(this);
    //Creation des labels pour l'affichage des creatures
    pokomonAdversaire_ = new QLabel(this);
    pokomonAdversaire_->setFixedSize(250, 200);
    QPixmap image_pokemon_adversaire(":/images/pikachu_fight.png");
    //On recupere l'image dans un QPixmap et on la fait prendre la taille que l'on a impose
    pokomonAdversaire_->setPixmap(image_pokemon_adversaire.scaled(pokomonAdversaire_->width()
                                                                 , pokomonAdversaire_->height(),
                                                                 Qt::KeepAspectRatio));

    pokomonDresseur_ = new QLabel(this);
    pokomonDresseur_->setFixedSize(250, 200);
    QPixmap image_pokemon_dresseur(":/images/pikachu_fight.png");
    pokomonDresseur_->setPixmap(image_pokemon_dresseur.scaled(pokomonAdversaire_->width()
                                                                , pokomonAdversaire_->height(),
                                                                Qt::KeepAspectRatio));
    //layoutcombat va contenir les differents elements du combat
    QGridLayout* layoutCombat = new QGridLayout();
    layoutCombat->addWidget(informationsAdversaire_->informations, 0, 0);
    layoutCombat->addWidget(informationsDresseur_->informations, 1, 1);
    layoutCombat->addWidget(pokomonAdversaire_, 0, 1);
    layoutCombat->addWidget(pokomonDresseur_, 1, 0);

    //Creation du widget pour les boutons d'attaques
	QGridLayout* boutonGLayout = new QGridLayout;
    choixAttaque_ = new ChoixAttaque(this);


    //Creation de l'image d'accueil
    imageAccueil_ = new QLabel(this);
    imageAccueil_->setFixedSize(600,400);
    QPixmap image_accueil(":/images/pokamon_logo.png");
    imageAccueil_->setPixmap(image_accueil.scaled(imageAccueil_->width()
                                                                , imageAccueil_->height(),
                                                                Qt::KeepAspectRatio));
    imageAccueil_->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    layoutAffichagePrincipal->addWidget(imageAccueil_);
    layoutEcran->addLayout(layoutCombat);
    //Vous devez ajouter le widget pour le choix d'attaque dans le layoutEcran
    //!!!!!! A COMPLETER !!!!!!    //! 
    boutonGLayout->addWidget(choixAttaque_);
    layoutEcran->addLayout(boutonGLayout);
    layoutAffichagePrincipal->addLayout(layoutEcran);

    //Layout permettant d'ordonner la partie basse de la fenetre
    QVBoxLayout* layoutBoutonsNavigation = new QVBoxLayout();
    QVBoxLayout* layoutCentralBas = new QVBoxLayout();
    QVBoxLayout* layoutBoutonsAction = new QVBoxLayout();

    //Layout permettant l'agencement des differents elements dans la partie basse
    QGridLayout* gridLayoutNavigation = new QGridLayout();
    gridLayoutNavigation->addWidget(flecheGauche_, 1, 0);
    gridLayoutNavigation->addWidget(flecheDroite_, 1, 2);
    gridLayoutNavigation->addWidget(flecheHaut_, 0, 1);
    gridLayoutNavigation->addWidget(flecheBas_, 2, 1);
    layoutBoutonsNavigation->addLayout(gridLayoutNavigation);

    //Creation du layout contenant les boutons centraux
    QHBoxLayout* layoutBoutonsCentral = new QHBoxLayout();
    layoutBoutonsCentral->addWidget(boutonSelect_);
    layoutBoutonsCentral->addWidget(boutonStart_);

    //Mise en place de l'image Nintondo
    QPixmap nintondoLogo(":/images/Nintondo.png");
    QLabel* deviceName = new QLabel("GameBay", this);
    deviceName->setPixmap(nintondoLogo);
    layoutCentralBas->addWidget(deviceName);
    layoutCentralBas->addLayout(layoutBoutonsCentral);

    QGridLayout* gridLayoutAction = new QGridLayout();
    gridLayoutAction->addWidget(boutonA_, 0, 1);
    gridLayoutAction->addWidget(boutonB_, 1, 0);
    layoutBoutonsAction->addLayout(gridLayoutAction);

    //Mise en place des differents layout dans la partie basse
    layoutCommandes->addLayout(layoutBoutonsNavigation);
    layoutCommandes->addLayout(layoutCentralBas);
    layoutCommandes->addLayout(layoutBoutonsAction);
    //Creation et mise en place de la partie menu
    menu_ = new Menu();
    layoutAffichagePrincipal->addWidget(menu_);
    layoutPrincipal->addLayout(layoutAffichagePrincipal);
    layoutPrincipal->addLayout(layoutCommandes);
    // Crée un nouveau Widget comprenant le layout principal
    QWidget* widget = new QWidget;
    widget->setLayout(layoutPrincipal);
    // Définit ce widget comme etant le widget central de notre classe
    setCentralWidget(widget);
    afficherFinCombat();
    // Titre de la fenêtre
    setWindowTitle("Pokomon");
    this->setStyleSheet("QMainWindow {background-color:white}"
                        "QPushButton:hover {\n"
                         "background-color: qlineargradient(x1: 0, y1: 1, x2: 0, y2: 0,"
                         " stop: 0 #cccccc , stop: 1#f2f2f2);"
                         "}\n"
                         "QPushButton:pressed{ background-color: #cccccc; }");
}

//Une méthode privée setConnections() qui connecte les évènements des éléments de l’interface
//aux méthodes private slots. Vous devez compléter les connexions suivantes :

void Gamebay::setConnections(){
    //!!!!!! A COMPLETER !!!!!!

    //Connexions de differents slots sur des signaux
    QObject::connect(menu_->boutonAffichageCreatures_, SIGNAL(clicked(bool)), this, SLOT(afficherCreatures()));
    QObject::connect(menu_->boutonAffichageDresseurs_, SIGNAL(clicked(bool)), this, SLOT(afficherDresseurs()));
    QObject::connect(menu_->boutonAffichageInventaire_, SIGNAL(clicked(bool)), this, SLOT(afficherInventaire()));
    QObject::connect(menu_->listeCreatures_, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(debuterCombat(QListWidgetItem*)));
    QObject::connect(menu_->listeCreaturesDresseur_, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(changerCreature(QListWidgetItem*)));
    QObject::connect(menu_->boutonCapturer_, SIGNAL(clicked(bool)), this, SLOT(capturerCreatureAdverse()));
	QObject::connect(boutonStart_, SIGNAL(clicked(bool)), this, SLOT(gestionDuMenu()));
    QObject::connect(choixAttaque_->attaque1_, SIGNAL(clicked(bool)), this, SLOT(attaquerCreatureAdverse()));
    QObject::connect(choixAttaque_->attaque2_, SIGNAL(clicked(bool)), this, SLOT(attaquerCreatureAdverse()));
    QObject::connect(choixAttaque_->attaque3_, SIGNAL(clicked(bool)), this, SLOT(attaquerCreatureAdverse()));
    QObject::connect(choixAttaque_->attaque4_, SIGNAL(clicked(bool)), this, SLOT(attaquerCreatureAdverse()));

    QObject::connect(menu_->boutonAffichageCreaturesDresseur_, SIGNAL(clicked(bool)), this, SLOT(afficherCreaturesDresseur()));
    //La connexion du signal creatureAdverseVaincue() qui permettra d’afficher un bouton pour
    //capturer la creature
    QObject::connect(menu_->boutonAttaques_, SIGNAL(clicked(bool)), this, SLOT(afficherAttaques()));
	QObject::connect(this, SIGNAL(creatureAdverseVaincue()), this, SLOT(boutonCapturer_));
}

void Gamebay::afficherAttaques()
{
    choixAttaque_->afficherAttaques(creatureHero_);
}

//Une méthode privée afficherCreaturesDresseur () qui remplit l’objet QListWidget avec la liste
//des créatures que vous possédez(Aide : Vous pouvez vous aider de ce qui a déjà été implementee
//dans la Classe Menu.)

void Gamebay::afficherCreaturesDresseur()
{
    menu_->afficherListeCreaturesDresseur(polyland_->obtenirHero());
}


void Gamebay::afficherCapture(){
    //Affichage du bouton qui permettra la capture de la creature adverse
    menu_->boutonCapturer_->show();
}

void Gamebay::afficherCreatures(){
    //Affichage des differentes creatures de Polyland
    menu_->afficherListeCreatures(polyland_->obtenirListCompagnon());
}

void Gamebay::afficherDresseurs(){
    //Affichage des differents dresseurs dans Polyland
    menu_->affichierListeDresseurs(polyland_->obtenirListMaitre());
}

void Gamebay::afficherInventaire(){
    //Cette methode ne fait rien
}


void Gamebay::afficherCombat(){
    //Affichage des differents elements pour permettre le combat
    combatEnCours_ = true;
    imageAccueil_->hide();
    informationsAdversaire_->informations->show();
    informationsDresseur_->informations->show();
    pokomonDresseur_->show();
    pokomonAdversaire_->show();
    menu_->boutonFuir_->show();
}

void Gamebay::afficherFinCombat(){
    //A la fin du combat on masque les elements inutiles
    combatEnCours_ = false;
    imageAccueil_->show();
    informationsAdversaire_->informations->hide();
    informationsDresseur_->informations->hide();
    pokomonDresseur_->hide();
    pokomonAdversaire_->hide();
    menu_->boutonFuir_->hide();
}

//Le signal creatureVaincue() doit être émis lorsque vous sélectionnez une créature n’ayant plus
//de point de vie dans le slot changerCreature().

void Gamebay::changerCreature(QListWidgetItem* item){
    //La methode ici va permettre de changer de creature
    choixAttaque_->masquerAttaques();
    //On recupere la creature selectionnee de la liste
    Creature* creature = item->data(Qt::UserRole).value<Creature*>();
    if(creature->obtenirPointDeVie() >0){
        //Si la creature est vivante on peut alors la selectionner
        creatureHero_ = creature;
        informationsDresseur_->modifierAffichageInformationCreature(creatureHero_);
        pokomonDresseur_->setPixmap(obtenirImageCreature(creatureHero_).scaled(pokomonDresseur_->width()
                                                    , pokomonDresseur_->height(),
                                                                    Qt::KeepAspectRatio));
    }else{
        //!!!!!! A COMPLETER !!!!!!

        emit creatureVaincue(item);

        //Sinon la creature est deja vaincue;
    }
}

void Gamebay::debuterCombat(QListWidgetItem* item){
    //Cette Slot permet de lancer le combat avec la creature adverse selectionnee
    Creature* creature = item->data(Qt::UserRole).value<Creature*>();
    debuterCombat(creature);
}

void Gamebay::debuterCombat(Creature* creature){
    menu_->boutonCapturer_->hide();
    Creature* creatureDresseur = nullptr;
    //Le combat commence avec votre premiere creature vivante
    for(int i = 0; i< polyland_->obtenirHero().obtenirCreatures().size(); i++){
        if(polyland_->obtenirHero().obtenirCreatures()[i]->obtenirPointDeVie()>0){
            creatureDresseur = polyland_->obtenirHero().obtenirCreatures()[i];
            break;
        }
    }
    if(creatureDresseur != nullptr){
        afficherCombat();
        //Si vous avez une creature disponible on lance le combat
        informationsDresseur_->modifierAffichageInformationCreature(creatureDresseur);
        informationsAdversaire_->modifierAffichageInformationCreature(creature);
        pokomonDresseur_->setPixmap(obtenirImageCreature(creatureDresseur).scaled(pokomonDresseur_->width()
                                                                    , pokomonDresseur_->height(),
                                                                    Qt::KeepAspectRatio));
        pokomonAdversaire_->setPixmap(obtenirImageCreature(creature).scaled(pokomonAdversaire_->width()
                                                                    , pokomonAdversaire_->height(),
                                                                    Qt::KeepAspectRatio));
        pokomonDresseur_->setAlignment(Qt::AlignCenter);
        pokomonAdversaire_->setAlignment(Qt::AlignCenter);
        menu_->boutonAttaques_->show();
        creatureHero_ = creatureDresseur;
        creatureAdverse_ = creature;
    }else{
        //Sinon ne fait rien
    }
}

QPixmap Gamebay::obtenirImageCreature(Creature* creature){
    //Cette methode permet de recuperer la bonne image pour la creature
    if(creature->obtenirNom() == "Pokachu" ){
        return QPixmap(":/images/pikachu_fight.png");
    }else if(creature->obtenirNom() == "Salimouche"){
        return QPixmap(":/images/salameche.png");
    }else if(creature->obtenirNom() == "Balbazar"){
        return QPixmap(":/images/balbazar.png");
    }else if(creature->obtenirNom() == "Carapouce"){
        return QPixmap(":/images/carapouce.png");
    }else{
        return QPixmap(":/images/Nintondo.png");
    }
}
//Une méthode (slot) privée attaquerCreatureAdverse () qui va vous permettre d’attaquer la
//creature adverse. (voir Figure 3)

void Gamebay::attaquerCreatureAdverse(){
    //Cette methode va permettre de voir les consequences de votre attaque sur la creature adverse
     //!!!!!! A COMPLETER !!!!!!
     QObject* button = QObject::sender();
     try{
         //On va faire l'attaque en fonction du bouton clique
         if(button == choixAttaque_->attaque1_){
            creatureHero_->attaquer(*(creatureHero_->obtenirPouvoirs()[0]), *creatureAdverse_);
         }else if(button == choixAttaque_->attaque2_){
            creatureHero_->attaquer(*(creatureHero_->obtenirPouvoirs()[1]), *creatureAdverse_);
         }else if(button == choixAttaque_->attaque3_){
            creatureHero_->attaquer(*(creatureHero_->obtenirPouvoirs()[2]), *creatureAdverse_);
         }else{
            creatureHero_->attaquer(*(creatureHero_->obtenirPouvoirs()[3]), *creatureAdverse_);
         }
         //On met a jour les informations des creatures
         informationsAdversaire_->modifierAffichageInformationCreature(creatureAdverse_);
         informationsDresseur_->modifierAffichageInformationCreature(creatureHero_);
     }

     //Nous vous demandons d'attraper deux types d'exception ici, a vous de voir lesquels

	 catch (ExceptionAttaqueEchouee erreur1)
	 {
         QString titreMessageBox = QString("Echec de l'attaque");
         QMessageBox::critical(this, titreMessageBox, erreur1.what());
	 }

	 //Pour l'exception que vous trouverez pertinente, vous devez afficher :
	 //-Un certain message lorsque cette exception a ete lance strictement moins de 3 fois
	 //-Un autre message lorsque cette exception a ete lance strictement moins de 5 fois
	 //-Un dernier message lorsque cette exception a ete lance plus de 5 fois

	 catch (ExceptionCreatureMorte erreur2)
	 {
        QString titreMessageBox;
        if(ExceptionCreatureMorte::obtenirValeurCompteur() < 3)
             titreMessageBox = QString("Arretez c'est déjà fini!");
        else if(ExceptionCreatureMorte::obtenirValeurCompteur() < 5)
             titreMessageBox = QString("Hey ca fait deja 3 fois que vous essayez...");
        else
             titreMessageBox = QString("Vous dis donc...Vous etes vraiment sadique a vous acharner sur une pauvre creature deja morte");
        QMessageBox::critical(0, titreMessageBox, erreur2.what());
	 }
     if(creatureAdverse_->obtenirPointDeVie() <= 0){
         emit creatureAdverseVaincue();
     }
}

void Gamebay::gestionDuMenu(){
    //Cette methode va permettre l'affichage du menu
    if(!menu_->boutonAttaques_->isVisible() && creatureHero_ != nullptr)
        menu_->boutonAttaques_->show();
    else
        menu_->boutonAttaques_->hide();
    menu_->gestionDuMenu();
    //On affiche les attaques que si un combat est en cours
    if(combatEnCours_){
        choixAttaque_->afficherAttaques(creatureHero_);
    }
}

//Le slot attraperCreatureAdverse() qui doit permettre de capturer la créature adverse une fois
//vaincue si le dresseur(hero_) ne possède pas la créature, sinon cette méthode lève une exception
//que vous devez gérer comme sur la figure5.

void Gamebay::capturerCreatureAdverse(){
    //!!!!!! A COMPLETER !!!!!!
    QMessageBox msg;
    try{
        polyland_->attraperCreature(&polyland_->obtenirHero(), creatureAdverse_);
    }
	catch (ExceptionEchecCapture erreur3)
	{
        QString titreMessageBox = QString("Echec de capture");
            QMessageBox::critical(this, titreMessageBox, erreur3.what());
	}
}
