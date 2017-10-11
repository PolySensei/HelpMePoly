/*
Fichier: main.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 6 septembre 2016 par Maude Carrier
Description: Programme de test
*/

#include <iostream>
#include "CreatureMagique.h"
#include "AttaqueMagique.h"
#include "AttaqueMagiqueConfusion.h"
#include "AttaqueMagiquePoison.h"
#include "Creature.h"
#include "Dresseur.h"
#include "PolyLand.h"
#include "Pouvoir.h"
#include <time.h>


int main()
{
	srand(time(NULL));

	std::cout << "CREATION DES DRESSEURS" << std::endl;
	// Creer DYNAMIQUEMENT les dresseurs suivants (nom, equipe):
	// ("Sasha", "Team de feu")
	// ("Pierre", "Equipe de Poly")
	// ("Regis", "Equipe de Poly")
	Dresseur* Sasha = new Dresseur("Sasha", "Team de feu");
	Dresseur* Pierre = new Dresseur("Pierre", "Equipe de Poly");
	Dresseur* Regis = new Dresseur("Regis", "Equipe de Poly");

	std::cout << std::endl << "CREATION DES CREATURES" << std::endl;
	// Creer les Creatures suivantes (nom, attaque, defense, pointDeVie, energie):
	// ("Pokachu", 10, 2, 50, 25)
	// ("Salimouche", 12, 3, 45, 20)
	// ("Carapouce", 10, 1, 55, 25)
	// ("Balbazar", 11, 2, 50, 22)
	Creature Pokachu = Creature("Pokachu", 10, 2, 50, 25);
	Creature Salimouche = Creature("Salimouche", 12, 3, 45, 20);
	Creature Carapouce = Creature("Carapouce", 10, 1, 55, 25);
	Creature Balbazar = Creature("Balbazar", 11, 2, 50, 22);

	std::cout << "CRÉATION DES POUVOIRS" << std::endl;
	// Creer les pouvoirs ci-dessous (nom, degat, energie)
	// ("Boule de feu", 5, 5)
	// ("Pistolet a eau", 6, 6)
	// ("Eclair", 10, 5)
	// ("Etincelle", 8, 6)
	Pouvoir bouleDeFeu("Boule de feu", 5, 5);
	Pouvoir pistoletAEau("Pistolet a eau", 6, 6);
	Pouvoir eclair("Eclair", 10, 5);
	Pouvoir etincelle("Etincelle", 8, 6);

	// Creer le pouvoir lanceFeuille en utilisant le contructeur par copie et en utilisant le pouvoir bouleDeFeu.
	// Le nom du pouvoir lanceFeuille doit ensuite etre modifie pour "Lance Feuille".
	Pouvoir lanceFeuille(bouleDeFeu);
	lanceFeuille.modifierNom("Lance feuille");

	// Creer le pouvoir tonerre en utilisant l'operateur = et en utilisant le pouvoir eclair.
	// Le nom du pouvoir tonerre doit ensuite etre modifie pour "Tonerre" et son nombre de degat doit etre diminue a 3.
	Pouvoir tonerre;
	tonerre = eclair;
	tonerre.modifierNom("Tonerre");
	tonerre.modifierNombreDeDegat(3);

	std::cout << "CRÉATION DES CREATURES MAGIQUES" << std::endl;
	// Creer la CREATURE MAGIQUE Touflamme en utilisant la creature existante Salimouche et un bonus de 2.
	// Le nom de Touflamme devrai ensuite etre modifie pour "Touflamme" et son attaque passera de 12 a 15.
	// A COMPLETER...

	CreatureMagique Touflamme(2, Salimouche);
	Touflamme.modifierNom("Touflamme");
	Touflamme.modifierAttaque(15);

	// Creer la CREATURE MAGIQUE Pokachoum en utilisant la creature existante Pokachu et un bonus de 3.
	// Le nom de Pokachoum devrai ensuite etre modifie pour "Pokachoum" et sa defense passera de 2 a 7.
	// A COMPLETER...

	CreatureMagique Pokachoum(3, Pokachu);
	Pokachoum.modifierNom("Pokachoum");
	Pokachoum.modifierDefense(7);

	std::cout << "CRÉATION DES ATTAQUES MAGIQUES" << std::endl;
	//Creer une attaque magique de poison avec le constructeur par défaut
	// A COMPLETER...

	AttaqueMagiquePoison Poison;

	//Creer une attaque magique de confusion qui a une durée de 4
	// A COMPLETER...

	AttaqueMagiqueConfusion Confusion(4);

	std::cout << "APPRENTISSAGE DES POUVOIRS" << std::endl;
	// Ajouter le pouvoir a la creature correspondante
	// Salimouche -> bouleDeFeu
	// Carapouce -> pistoletAEau
	// Balbazar -> lanceFeuille
	// Pokachu -> eclair et tonnerre
	// Touflamme -> etincelle
	// Pokachoum -> eclair
	Salimouche.apprendrePouvoir(&bouleDeFeu);
	Carapouce.apprendrePouvoir(&pistoletAEau);
	Balbazar.apprendrePouvoir(&lanceFeuille);
	Pokachu.apprendrePouvoir(&eclair);
	Pokachu.apprendrePouvoir(&tonerre);
	Touflamme.apprendrePouvoir(&etincelle);
	Pokachoum.apprendrePouvoir(&eclair);

	std::cout << "APPRENTISSAGE DES ATTAQUES MAGIQUES" << std::endl;
	// Ajouter l'attaque magique à la créature magique correspondante
	// Pokachoum -> Confusion
	// Touflamme -> Poison
	// A COMPLETER...

	Touflamme.apprendreAttaqueMagique(&Poison);
	Pokachoum.apprendreAttaqueMagique(&Confusion);

	std::cout << std::endl << "AJOUT DE CREATURES ET DE DRESSEURS A POLYLAND" << std::endl << std::endl;

	PolyLand polyland;

	// Ajouter les dresseurs et les creatures. Attention, vous devez utiliser l'operateur += pour ajouter un dresseur.
	polyland += &Salimouche;
	polyland += &Carapouce;
	polyland += &Balbazar;
	polyland += &Pokachu;
	polyland += &Touflamme;
	polyland += &Pokachoum;

	polyland += Regis;
	polyland += Pierre;
	polyland += Sasha;

	Dresseur Vous("Hey", "Team INF1010");

	// Assignez une creature au dresseur.
	// Sasha -> Salimouche
	// Pierre -> Balbazar
	// Regis -> Touflamme
	Sasha->ajouterCreature(&Salimouche);
	Pierre->ajouterCreature(&Balbazar);
	Regis->ajouterCreature(&Touflamme);

	// Assignez à vous-meme Pokachoum
	Vous.ajouterCreature(&Pokachoum);

	std::cout << "TEST D'AFFICHAGE" << std::endl << std::endl;
	std::cout << polyland << std::endl;


	std::cout << std::endl << "COMPETITION" << std::endl;


	/*******************************************************************/
	/*                       DEBUT DES TESTS                           */
	/* Les modifications restantes sont a la fin de la fonction main.  */
	/*******************************************************************/
	//Duel entre vous et salimouche
	std::cout << std::endl << "TESTS DE COMBAT" << std::endl;

	std::cout << std::endl << "Un Salimouche surgit" << std::endl;

	std::cout << "Vous avez rencontré un Salimouche sauvage qui vous attaque..." << std::endl;


	Salimouche.attaquer(bouleDeFeu, *(Vous.obtenirUneCreature("Pokachoum")));
	Vous.obtenirUneCreature("Pokachoum")->attaquer(eclair, Salimouche);
	//Vous gagnez obligatoirement le duel
	while (Salimouche.obtenirPointDeVie() > 0) {
		((Vous.obtenirUneCreature("Pokachoum")))->attaquer(eclair, Salimouche);
	}
	std::cout << "Vous avez battu un Salimouche, vous pouvez maintenante le capturer" << std::endl;

	if (polyland.attraperCreature(&Vous, &Salimouche)) {
		std::cout << "Felicitation vous avez attrapé un Salimouche !" << std::endl;
	}
	else {
		std::cout << "Le Salimouche s'est échappé" << std::endl;
	}


	std::cout << std::endl;
	std::cout << "Vous trouvez une potion magique, vous décidez de l'utilisez sur Pokachoum" << std::endl;

	ObjetMagique potionMagique("Potion magique", 15);
	std::cout << potionMagique << std::endl;
	//Vous venez de trouver une potion magique
	Vous.modifierObjetMagique(potionMagique);
	//Soin de votre creature
	Vous.utiliserObjetMagique(Vous.obtenirUneCreature("Pokachoum"));

	//Debut du duel avec Touflamme
	std::cout << std::endl << "Touflamme se jette sur votre Pokachoum" << std::endl;
	std::cout << "Un duel entre Pokachoum et Touflamme est engagé" << std::endl;

	//Vous attaquez la créature tant que qu'elle est en vie...
	while (Touflamme.obtenirPointDeVie() > 0)
	{
		if (Vous.obtenirUneCreature("Pokachoum")->obtenirPointDeVie() > 0)
		{
			//... ou que votre créature est morte
			(Vous.obtenirUneCreature("Pokachoum"))->attaquer(eclair, Touflamme);
			if (Touflamme.obtenirPointDeVie() > 0)
			{
				Touflamme.attaquer(*(Touflamme.obtenirPouvoirs().back()), *(Vous.obtenirUneCreature("Pokachoum")));
			}
		}
		else
			break;
	}

	//Il se peut que vous gagniez...
	if (Touflamme.obtenirPointDeVie() == 0)
		std::cout << "Vous avez vaincu Touflamme" << std::endl;
	else {
		//Sinon votre seconde créature se charge de finir le combat
		while (Touflamme.obtenirPointDeVie() > 0)
			(Vous.obtenirUneCreature("Salimouche"))->attaquer(bouleDeFeu, Touflamme);
		std::cout << "Votre Pokachoum a été battu mais heuresement votre Salimouche finit par vaincre Touflamme" << std::endl;
	}


	std::cout << "Pokachoum et Salimouche n'arrete pas de se chamailler, vous decidez d'abandonner Pokachum" << std::endl;

	//Vous en avez marre des chamailleries, vous décidez de relacher Salimouche
	if (polyland.relacherCreature(&Vous, "Pokachoum")) {

		std::cout << "Vous avez bien relaché Pokachoum !" << std::endl;
	}
	else {
		//ce cas ne devrait pas s'afficher
		std::cout << "Oh il y a eu un petit problème technique... Pokachoum n'a pas pu être relaché" << std::endl;
	}


	std::cout << std::endl << "DERNIER TEST AFFICHAGE" << std::endl;
	std::cout << Salimouche << std::endl;
	std::cout << Carapouce << std::endl;
	std::cout << Salimouche << std::endl;
	std::cout << Balbazar << std::endl;
	std::cout << Pokachu << std::endl;
	std::cout << Touflamme << std::endl;
	std::cout << Pokachoum << std::endl;

	/*******************************/
	/*       FIN DES TESTS         */
	/*******************************/
	
	delete Sasha;
	delete Pierre;
	delete Regis;

	system("pause");
	return 0;
}