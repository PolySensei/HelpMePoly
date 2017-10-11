/*
Fichier: main.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 4 septembre 2016
Description: Programme de test
*/

#include <iostream>
#include "Creature.h"
#include "Dresseur.h"
#include "PolyLand.h"
#include "Pouvoir.h"
#include <time.h>
#include <clocale>  // pour setlocale
using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "");

	cout << "CREATION DES DRESSEURS" << endl;
	// Creer les dresseurs suivants (nom):
	// A COMPLETER...
	Dresseur* Sasha = new Dresseur("Sasha");
	Dresseur* Pierre = new Dresseur("Pierre");
	Dresseur* Regis = new Dresseur("Regis");
	

	cout << endl << "CREATION ET AFFICHAGE DES CREATURES" << endl;
	
	Pouvoir bouleDeFeu("Boule de feu", 5, 5);
	Pouvoir pistoletAEau("Pistolet a eau", 6, 6);
	Pouvoir eclair("Eclair", 10, 5);
	Pouvoir lanceFeuille("Lance feuille", 5, 5);
	// Creer les Creatures suivantes (nom, attaque, defense, pointDeVie, energue, pouvoir):

	Creature Pokachu("Pokachu", 10, 2, 50, 25, eclair);
	Creature Salimouche("Salimouche", 12, 3, 45, 20, bouleDeFeu);
	Creature Carapouce("Carapouce", 10, 1, 55, 25, pistoletAEau);
	Creature Balbazar("Balbazar", 11, 2, 50, 22, lanceFeuille);
	
	// Afficher les informations sur Pokachu creature (en utilisant la m�thode d'affichage)
	Pokachu.information();

	cout << endl << "Ajout des creatures et dresseurs de Polyland" << endl;

	PolyLand polyland;
	Dresseur Vous("Vous");

	// Ajouter les dresseurs et les creatures à Polyland
	polyland.ajouterDresseur(Sasha);
	polyland.ajouterDresseur(Regis);
	polyland.ajouterDresseur(Pierre);

	polyland.ajouterCreature(Pokachu);
	polyland.ajouterCreature(Salimouche);
	polyland.ajouterCreature(Carapouce);
	polyland.ajouterCreature(Balbazar);
	
	/*******************************************************************/
	/*                       DEBUT DES TESTS                           */
	/* Les modifications restantes sont a la fin de la fonction main.  */
	/*******************************************************************/
	cout << endl << "BIENVENUE A POLYLAND" << endl;
	
	Sasha->ajouterCreature(Salimouche);
	Pierre->ajouterCreature(Balbazar);
	Regis->ajouterCreature(Carapouce);

	cout << endl << "Choix de la premiere creature" << endl;

	Vous.ajouterCreature(Pokachu);

	cout << "Vous etes chanceux voici un Pokachu rien que pour vous" << endl;
	cout << "tests";
	Vous.obtenirCreatures()[0]->information();

	//Duel entre vous et salimouche
	cout << endl << "TESTS DE COMBAT" << endl;

	cout << endl << "Un Salimouche surgit" << endl;

	cout << "Vous avez rencontré un Salimouche sauvage qui vous attaque..." << endl;

	Salimouche.attaquer(*(Vous.obtenirCreatures())[0]);
	Vous.obtenirCreatures()[0]->attaquer(Salimouche);
	//Vous gagnez obligatoirement le duel
	while (Salimouche.obtenirPointDeVie() > 0) {
		((Vous.obtenirCreatures())[0])->attaquer(Salimouche);
	}
	cout << "Vous avez battu un Salimouche, vous pouvez maintenant le capturer" << endl;

	//Vous avez déjà le droit a votre seconde creature
	if (polyland.attraperCreature(&Vous, Salimouche)) {
		cout << "Felicitation vous avez attrapé un Salimouche !" << endl;
	}
	else {
		//ce cas ne devrait pas s'afficher
		cout << "Le salimouche s'est échappé" << endl;
	}

	cout << endl;
	cout << endl << "LA DECOUVERTE DE LA POTION MAGIQUE" << endl;
	cout << "Vous trouvez une potion magique, vous décidez de l'utilisez sur Pokachu" << endl;

	ObjetMagique potionMagique("Potion magique", 15);
	//Vous venez de trouver une potion magique
	Vous.modifierObjetMagique(potionMagique);
	//Soin de votre creature
	Vous.obtenirObjetMagique().affichage();
	Vous.utiliserObjetMagique(Vous.obtenirCreatures()[0]);

	//Choix d'une creature aleatoirement parmi celles possibles
	Creature* creatureAleatoire = polyland.choisirCreatureAleatoire();

	//Debut du duel avec la creature choisie aléatoirement
	cout << endl << "Un " << creatureAleatoire->obtenirNom() << " se jette sur votre Pokachu" << endl;
	cout << "Un duel entre Pokachu et " << creatureAleatoire->obtenirNom() << " est engagé" << endl;

	//Vous attaquez la créature tant que qu'elle est en vie...
	while (creatureAleatoire->obtenirPointDeVie() > 0) {
		if (Vous.obtenirCreatures()[0]->obtenirPointDeVie() > 0) {
			//... ou que votre créature est morte
			(Vous.obtenirCreatures()[0])->attaquer(*creatureAleatoire);
			if (creatureAleatoire->obtenirPointDeVie() > 0)
				creatureAleatoire->attaquer(*Vous.obtenirCreatures()[0]);
		}
		else
			break;
	}

	//Il se peut que vous gagniez...
	if (creatureAleatoire->obtenirPointDeVie() == 0)
		cout << "Vous avez vaincu " << creatureAleatoire->obtenirNom() << endl;
	else {
		//Sinon votre seconde créature se charge de finir le combat
		while (creatureAleatoire->obtenirPointDeVie() > 0)
			(Vous.obtenirCreatures()[1])->attaquer(*creatureAleatoire);
		cout << "Votre Pokachu a été battu mais heuresement votre Salimouche finit par vaincre " << creatureAleatoire->obtenirNom() << endl;
	}
	cout << "Vous essayez d'attraper " << creatureAleatoire->obtenirNom() << endl;
	//Vous ne pouvez pas attraper la nouvel créature, vous avez déjà ateint la limite
	if (polyland.attraperCreature(&Vous, *creatureAleatoire)) {
		//ce cas ne devrait pas s'afficher
		cout << "Felicitation vous avez attrapé un " << creatureAleatoire->obtenirNom() << " !" << endl;
	}
	else {
		//Elle s'échappe donc
		cout << creatureAleatoire->obtenirNom() << " s'est échappé" << endl;
	}

	cout << endl << "AFFICHAGE DE VOS INFORMATIONS" << endl;
	Dresseur* dresseurAleatoire = polyland.choisirDresseurAleatoire();
	polyland.ajouterDresseur(&Vous);
	polyland.infoDresseur("Vous");

	cout << "Pokachu et salimouche n'arrete pas de se chamailler, vous decidez d'abandonner Salimouche" << endl;
	polyland.infoDresseur("Sasha");
	//Vous en avez marre des chamailleries, vous décidez de relacher Salimouche
	if (polyland.relacherCreature(&Vous, Salimouche.obtenirNom())) {
		cout << "Vous avez decidé de relacher Salimouche !" << endl;
	}
	else {
		//ce cas ne devrait pas s'afficher
		cout << "Oh il y a eu un petit problème technique... Salimouche n'a pas pu être relaché" << endl;
	}

	//On soigne votre Pokachu
	Vous.obtenirCreatures()[0]->modifierPointDeVie(Vous.obtenirCreatures()[0]->obtenirPointDeVieTotal());
	Vous.obtenirCreatures()[0]->modifierEnergie(Vous.obtenirCreatures()[0]->obtenirEnergieTotale());

	cout << endl << "UN DRESSEUR SOUHAITE VOUS DEFIEZ" << endl;
	dresseurAleatoire->affichage();
	//Vous vous faites toujours attaquer dans Polyland, ça serait presque une terre hostile...
	cout << dresseurAleatoire->obtenirNom() << " surgit avec son " << dresseurAleatoire->obtenirCreatures()[0]->obtenirNom() << endl;

	cout << "Un duel entre Pokachu et " << dresseurAleatoire->obtenirCreatures()[0]->obtenirNom() << " est engagé" << endl;
	//Mais vous allez gagner ;)
	while (dresseurAleatoire->obtenirCreatures()[0]->obtenirPointDeVie() > 0) {
		if (Vous.obtenirCreatures()[0]->obtenirPointDeVie() > 0) {
			(Vous.obtenirCreatures()[0])->attaquer(*dresseurAleatoire->obtenirCreatures()[0]);
			if (dresseurAleatoire->obtenirCreatures()[0]->obtenirPointDeVie() > 0)
				dresseurAleatoire->obtenirCreatures()[0]->attaquer(*Vous.obtenirCreatures()[0]);
		}
		else {
			//Vous avez trouvé un puit de potion pour régénrer votre Pokachu
			cout << "Votre Pokachu est mal en point, vous utilisez une potion sur lui " << endl;
			Vous.utiliserObjetMagique(Vous.obtenirCreatures()[0]);
		}
	}

	//Vous n'êtes pas sympa vous avez fait fuir un dresseur de Polyland...
	cout << endl << "Suite à sa défaite " << dresseurAleatoire->obtenirNom() << " s'enfuit de Polyland" << endl;
	if (polyland.retirerDresseur(dresseurAleatoire->obtenirNom())) {
		cout << dresseurAleatoire->obtenirNom() << " s'est bien enfuit de Polyland..." << endl;
	}
	else {
		//ce cas ne devrait pas s'afficher
		cout << "Oh il y a eu un petit problème technique... " << dresseurAleatoire->obtenirNom() << "n'a pas pu s'enfuir" << endl;
	}


	cout << endl << "INFO DRESSEUR APRES TOUTES CES PERIPETIES" << endl;
	polyland.infoDresseur("Vous");
	//On ne devrait plus avoir d'information sur le dresseur aleatoire qui s'est enfui
	polyland.infoDresseur(dresseurAleatoire->obtenirNom());
	/*******************************/
	/*       FIN DES TESTS         */
	/*******************************/

	delete Sasha;
	Sasha = nullptr;
	delete Pierre;
	Pierre = nullptr;
	delete Regis;
	Regis = nullptr;

    system("pause");
	return 0;
}
