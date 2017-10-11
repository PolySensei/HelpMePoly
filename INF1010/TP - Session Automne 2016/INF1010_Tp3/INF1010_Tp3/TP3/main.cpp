

/*
Fichier: main.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 30 septembre 2016 par Philippe Troclet
Description: Programme de test
*/

#include <iostream>
#include <time.h>
#include <typeinfo>

#include "Creature.h"
#include "Dresseur.h"
#include "PolyLand.h"
#include "Pouvoir.h"
#include "Professeur.h"
#include "CreatureMagique.h"
#include "PotionMagique.h"
#include "PouvoirPoison.h"
#include "PouvoirHallucinogene.h"
#include "PouvoirSoporifique.h "
#include "GreenBull.h"
#include "Elixir.h"


void appliquerEtatSelonType(Creature& creature) {
    EtatCreature* etat = creature.obtenirEtat();
    EtatEmpoisonne* etatPoison;
	EtatEndormi* etatEndormi;
    EtatConfus* etatConfus;
    switch (etat->obtenirType())
    {
    case TypeEtat_normal:
        etat->appliquerEtat(creature);
        break;
    case TypeEtat_empoisonne:
        etatPoison = static_cast<EtatEmpoisonne*>(creature.obtenirEtat());
        etatPoison->appliquerEtat(creature);
        break;
    case TypeEtat_endormi:
        etatEndormi = static_cast<EtatEndormi*>(creature.obtenirEtat());
        etatEndormi->appliquerEtat(creature);
        break;
    case TypeEtat_confus: //TODO à compléter
		etatConfus = static_cast<EtatConfus*>(creature.obtenirEtat());
		etatConfus->appliquerEtat(creature);
        break;
    default:
        break;
    }
}

//TODO à compléter appelle la méthode appropriée selon le type
//dit si la créature peut attaquer, il faut appeler la bonne
// méthode de étatCréature ou d'une de ses classes filles
bool peutAttaquerSelonType(Creature& creature) {
    bool peutAttaquer = false;
    EtatCreature* etat = creature.obtenirEtat();
    EtatEmpoisonne* etatPoison;
    EtatEndormi* etatEndormi;
    EtatConfus* etatConfus;
    switch (etat->obtenirType())
    {
    case TypeEtat_normal:
        peutAttaquer = etat->peutAttaquer();
        break;
    case TypeEtat_empoisonne:
        etatPoison = static_cast<EtatEmpoisonne*>(creature.obtenirEtat());
        peutAttaquer = etatPoison->peutAttaquer();
        break;
    case TypeEtat_endormi:
        etatEndormi = static_cast<EtatEndormi*>(creature.obtenirEtat());
        peutAttaquer = etatEndormi->peutAttaquer();
        break;
    case TypeEtat_confus:
        //TODO
		etatConfus = static_cast<EtatConfus*>(creature.obtenirEtat());
		peutAttaquer = etatConfus->peutAttaquer();
        break;
    default:
        break;
    }
    return peutAttaquer;
}

//TODO à compléter (s'inpirer des fonctions au-dessus)
bool estFiniSelonType(Creature& creature) {
    bool estFini = false;
    EtatCreature* etat = creature.obtenirEtat();
    EtatEmpoisonne* etatPoison;
    EtatEndormi* etatEndormi;
    EtatConfus* etatConfus;
    switch (etat->obtenirType())
    {
    case TypeEtat_normal:
		estFini = true;
        break;
    case TypeEtat_empoisonne:
        etatPoison = static_cast<EtatEmpoisonne*>(creature.obtenirEtat());
        etatPoison->estFini();
        break;
    case TypeEtat_endormi:
        etatEndormi = static_cast<EtatEndormi*>(creature.obtenirEtat());
        estFini = etatEndormi->estFini();
        break;
    case TypeEtat_confus:
        etatConfus = static_cast<EtatConfus*>(creature.obtenirEtat());
        estFini = etatConfus->estFini();
        break;
    default:
        break;
    }
    return estFini;
}

//TODO étudier le fonctionnement et s'en inspirer pour l'implémentation des 
//operator << dans les classes filles /!\ il est probable qu'il faille
//que l'opérateur<< ne travaille pas, il faudra sûrement adapter la méthode 
//ci-dessous
void afficherEtatSelonType(Creature& creature) {
    EtatCreature* etat = creature.obtenirEtat();
    EtatEmpoisonne* etatPoison;
    EtatEndormi* etatEndormi;
    EtatConfus* etatConfus;
    std::cout << creature.obtenirNom() << " est dans l'état: ";
    switch (etat->obtenirType())
    {
    case TypeEtat_normal:
        std::cout << *etat << std::endl;
        break;
    case TypeEtat_empoisonne:
        etatPoison = static_cast<EtatEmpoisonne*>(creature.obtenirEtat());
        std::cout << *etatPoison << std::endl;
        break;
    case TypeEtat_endormi:
        etatEndormi = static_cast<EtatEndormi*>(creature.obtenirEtat());
        std::cout << *etatEndormi << std::endl;
        break;
    case TypeEtat_confus:
        etatConfus = static_cast<EtatConfus*>(creature.obtenirEtat());
        std::cout << *etatConfus << std::endl;
        break;
    default:
        break;
    }
}

int main()
{
	srand(time(NULL));
    setlocale(LC_ALL, "");

    std::cout << "BIENVENU DANS LE MONDE MERVEILLEUX DE POLYLAND" << std::endl;
    //TODO créez un Professeur nommé Chen ("Chen", "Laboratoire Poly")
	Professeur Chen("Chen", "Laboratoire Poly");

    OutilScientifique scanner("scanner", "étudier une créature");
    std::cout << scanner << std::endl;
    Chen.modifierOutil(scanner);
    Dresseur mauvaisGars("Jessie", "Team Rocket");

    //TODO créez les créatures suivantes
    //miaouss ("Miaouss", 10, 2, 50, 22) type = Creature
	Creature miaouss("Miaouss", 10, 2, 50, 22);
    //pokachu ("Pokachu", 10, 2, 100, 25) type = Creature
	Creature pokachu("Pokachu", 10, 2, 100, 25);
	//Salimouche ("Salimouche", 12, 3, 45, 20) type = Creature
	Creature Salimouche("Salimouche", 12, 3, 45, 20);
    //rondodu ("Rondodu", 10, 2, 50, 25) type = Creature
	Creature rondodu("Rondodu", 10, 2, 50, 25);
    //mewtwo ("Mewtwo", 20, 3, 50, 25, 5) type = CreatureMagique
	CreatureMagique mewtwo("Mewtwo", 10, 3, 50, 25, 5);
    
    std::cout << "TEST : affichage de la créature magique" << std::endl;
    std::cout << mewtwo << std::endl;
    std::cout << "FIN TEST : affichage de la créature magique" << std::endl;

    //TODO Créez les pouvoirs suivants
    // eclair ("Eclair", 10, 5) type = Pouvoir
	Pouvoir eclair("Eclair", 10, 5);
    //morsureVenin ("Morsure Venin", 10, 5, 3) type = PouvoirPoison
	PouvoirPoison morsureVenin("Morsure Venin", 10, 5, 3);
    //ondeFolie ("onde Folie", 4, 5, 4) type = PouvoirHallucinogene
	PouvoirHallucinogene ondeFolie("onde Folie", 4, 5, 4);
    //berceuse ("Berceuse", 2, 5, 2) type = PouvoirSoporifique
	PouvoirSoporifique berceuse("Berceuse", 2, 5, 2);
    //telekinesie ("Telekinesie", 15, 5, 4) type = PouvoirHallucinogene
	PouvoirHallucinogene telekinesie("Telekinesie", 15, 5, 4);
    
    std::cout << "TEST AFFICHAGE Pouvoir" << std::endl;
    std::cout << eclair << std::endl;
    std::cout << morsureVenin << std::endl;
    std::cout << ondeFolie << std::endl;
    std::cout << berceuse << std::endl;
    std::cout << telekinesie << std::endl;
    std::cout << "FIN : TEST AFFICHAGE Pouvoir" << std::endl;

    pokachu.apprendrePouvoir(&eclair);
    miaouss.apprendrePouvoir(&morsureVenin);
    miaouss.apprendrePouvoir(&ondeFolie);
    rondodu.apprendrePouvoir(&berceuse);
    mewtwo.apprendrePouvoir(&telekinesie);

    mauvaisGars.ajouterCreature(&miaouss);
    Chen.ajouterCreature(&Salimouche);

    std::cout << "TEST PolyLand " << std::endl;
    PolyLand polyland;
    polyland += &miaouss;
    polyland += &pokachu;
    polyland += &rondodu;
    polyland += &mewtwo;
    polyland += &Chen; 
    polyland += &mauvaisGars;
    std::cout << polyland << std::endl;
    std::cout << "FIN TEST PolyLand " << std::endl;

    Dresseur Vous("Etudiant", "Team INF1010");
    Vous.ajouterCreature(&pokachu);
    std::cout << "LA TEAM MISSILE VOUS ATTAQUE" << std::endl;
    while (miaouss.obtenirPointDeVie() > 0 && pokachu.obtenirPointDeVie() > 0)
    {      
        miaouss.attaquer(morsureVenin, pokachu);
        morsureVenin.appliquerEffetOffensif(pokachu);
        //Pauvre pokachu, l'attaque l'a possibelment empoisonne!
        appliquerEtatSelonType(pokachu);
        if (peutAttaquerSelonType(pokachu))
            pokachu.attaquer( eclair, miaouss);

        if (estFiniSelonType(pokachu))
            pokachu.modifierEtat(new EtatCreature("normal")); //attention aux fuites mémoires

        std::cout << "affichage de l'etat de Pokachu" << std::endl;
        std::cout << "Pokachu est dans l'état: " << *(pokachu.obtenirEtat()) << std::endl;
        std::cout << "affichage de l'etat de Pokachu (autre méthode)" << std::endl;
        afficherEtatSelonType(pokachu);
    }

    if (pokachu.obtenirPointDeVie() > 0) {
        std::cout << "Felicitation vous avez gagne" << std::endl;
    }
    else {
        std::cout << "Hum Pokachu est mal en point" << std::endl;
    }
    //Test potion magique
    PotionMagique potion("Potion", 10);
    unsigned int ancienPointDeVie = pokachu.obtenirPointDeVie();
    std::cout << "Vous utilisez une potion magique" << std::endl;
    std::cout << potion << std::endl;
    potion.utiliserSur(pokachu);
    if (pokachu.obtenirPointDeVie() == ancienPointDeVie + 10)
        std::cout << "Potion: OK" << std::endl;

    //Test GreenBull
    GreenBull boissonTonique("greenBull", 10);
    unsigned int ancienneEnergie = pokachu.obtenirEnergie();
    std::cout << "Vous utilisez une boisson énergisante" << std::endl;
    std::cout << boissonTonique << std::endl;
    boissonTonique.utiliserSur(pokachu);
    if (pokachu.obtenirEnergie() == ancienneEnergie + 10)
        std::cout << "GreenBull: OK" << std::endl;

    //Test elixir
    pokachu.modifierEnergie(pokachu.obtenirEnergie() - 10);
    ancienneEnergie = pokachu.obtenirEnergie();
    ancienPointDeVie = pokachu.obtenirPointDeVie();
    Elixir elixir("elixir", 10);
    elixir.utiliserSur(pokachu);
    if (pokachu.obtenirEnergie() == ancienneEnergie + 10 &&
        pokachu.obtenirPointDeVie() == ancienPointDeVie + 20) {
        std::cout << "Elixir: OK" << std::endl;
    }
    //Le professeur soigne votre créature
    Chen.soigner(pokachu);
    if (pokachu.obtenirPointDeVie() == pokachu.obtenirPointDeVieTotal() &&
        pokachu.obtenirEnergie() == pokachu.obtenirEnergieTotale()) {
        std::cout << "Soigner: OK" << std::endl;
    }

    std::cout << "C'est incroyable, une créature magique vous attaque" << std::endl;
    while (mewtwo.obtenirPointDeVie() > 0 && pokachu.obtenirPointDeVie() > 0)
    {
        //l'attaqe devrait augmenter les points de vie de la créature
        unsigned int pointDeVie = mewtwo.obtenirPointDeVie();
        mewtwo.attaquer(telekinesie, pokachu);
        //Les points de vie de la créature doivent augmenter 
        //quand elle attaque
        if (mewtwo.obtenirPointDeVie() >= pointDeVie) {
            std::cout << "Creature magique OK" << std::endl;
        }
        telekinesie.appliquerEffetOffensif(pokachu);

        //TODO : appliquer l'état selon le type
        //Indice: regardez plus haut dans le code
        if (peutAttaquerSelonType(pokachu))
            pokachu.attaquer(eclair, mewtwo);

        if (estFiniSelonType(pokachu))
            pokachu.modifierEtat(new EtatCreature("normal"));

        //TODO : afficher l'etat en prenant en compte le type
        //Indice: regardez plus haut dans le code
        //et répondre à la question relative à l'affichage
		afficherEtatSelonType(pokachu);
    }
    Chen.soigner(pokachu);
    std::cout << "Votre Pokachu surprend un rondodu, terrifié celui-ci lui chante une berceuse" << std::endl;
    rondodu.attaquer(berceuse, pokachu);
    berceuse.appliquerEffetOffensif(pokachu);
    //rondodu devrait dormir pour deux tours
    for (unsigned int i = 0; i < 4; ++i) {
        appliquerEtatSelonType(pokachu);
    }
    if (estFiniSelonType(pokachu)) {
        std::cout << "Pokachu s'est réveillé! : Berceuse OK" << std::endl;
    }
    else {
        std::cout << "Bizarre pokachu aurait dû se réveiller..." << std::endl;
    }
    //Attention aux double free et fuites mémoires
    Professeur Phelina(Chen);
    Professeur Orme(Chen);
    Orme = Phelina;
    //vérification de la copie
    std::cout << "TEST Professeur : affichage de l'information des professeurs" << std::endl;
    std::cout << Chen << std::endl;
    std::cout << Orme << std::endl;
    std::cout << Phelina << std::endl;
    std::cout << "FIN TEST" << std::endl;

	return 0;
}