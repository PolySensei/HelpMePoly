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

	std::cout << "CREATION DES DRESSEURS" << std::endl;
	// Creer DYNAMIQUEMENT les dresseurs suivants (nom):
	Dresseur* Sasha = new Dresseur("Sasha", "Poly");
	Dresseur* Pierre = new Dresseur("Pierre", "Poly");
	Dresseur* Regis = new Dresseur("Regis", "Poly");
	
	

	std::cout << std::endl << "CREATION ET AFFICHAGE DES CREATURES" << std::endl;
	// Creer les Creatures suivantes (nom, attaque, defense, pointDeVie, mana):
	Creature Pokachu("Pokachu", 10, 2, 50, 25);
	Creature Salimouche("Salimouche", 12, 3, 45, 20);
	Creature Carapouce("Carapouce", 10, 1, 55, 25);
	Creature Balbazar("Balbazar", 11, 2, 50, 22);
	// A COMPLETER...

	// Creer la Creature Touflamme en utilisant l'opérateur = et en utilisant la creature existante Salimouche.
	// Le nom de Touflamme devrai ensuite etre modifie pour "Touflamme" et son attaque passera de 12 a 15.
	// A COMPLETER...
	Creature Touflamme = Salimouche;
	Touflamme.modifierNom("Touflamme");
	Touflamme.modifierAttaque(15);
	// Creer la Creature Pokachoum en utilisant le constructeur de copie et en utilisant la creature existante Pokachu.
	// Le nom de Pokachoum devrai ensuite etre modifie pour "Pokachoum" et sa defense passera de 2 a 7.
	// A COMPLETER...
	Creature Pokachoum = Pokachu;
	Pokachoum.modifierNom("Pokachoum");
	Pokachoum.modifierDefense(7);
	// Afficher les informations sur Pokachu, Touflamme et Pokachum
	// A COMPLETER...
	cout << Pokachu << Touflamme << Pokachoum << endl;
	
	// Creer les pouvoirs suivants
	Pouvoir bouleDeFeu("Boule de feu", 5, 5);
	Pouvoir pistoletAEau("pistoletAEau", 6, 6);
	Pouvoir eclair("Eclair", 10, 5);



		// Creer le pouvoir lanceFeuille en utilisant le contructeur par copie et en utilisant le pouvoir bouleDeFeu.
		// Le nom du pouvoir lanceFeuille doit ensuite etre modifie pour "Lance Feuille".
	Pouvoir lanceFeuille = bouleDeFeu;
	lanceFeuille.modifierNom("Lance Feuille");

	// Creer le pouvoir tonerre en utilisant l'operateur = et en utilisant le pouvoir eclair.
	// Le nom du pouvoir tonerre doit ensuite etre modifie pour "Tonerre" et son nombre de degat doit etre diminue a 3.
	// A COMPLETER...
	Pouvoir tonerre = eclair;
	tonerre.modifierNom("Tonerre");
	tonerre.modifierNombreDeDegat(7);

	// Faites afficher les informations des pouvoirs bouleDeFeu, lanceFeuille et tonnerre.
	// A COMPLETER...
	cout << bouleDeFeu << lanceFeuille << tonerre << endl;

	// Ajouter le pouvoir a la creature correspondante
	Salimouche.apprendrePouvoir(&bouleDeFeu);
	Carapouce.apprendrePouvoir(&pistoletAEau);
	Balbazar.apprendrePouvoir(&lanceFeuille);
	Pokachu.apprendrePouvoir(&eclair);
	Pokachu.apprendrePouvoir(&tonerre);
	Touflamme.apprendrePouvoir(&tonerre);
	Pokachoum.apprendrePouvoir(&eclair);
	// A COMPLETER...

	std::cout << std::endl << "AJOUT DE CREATURES ET DE DRESSEURS A POLYLAND" << std::endl << std::endl;
	
	PolyLand polyland;

	// Ajouter les dresseurs et les creatures. Attention, vous devez utiliser l'operateur += pour ajouter un dresseur.
	// A COMPLETER...
	polyland += Sasha;
	polyland += Regis;
	polyland += Pierre;

	polyland += &Salimouche;
	polyland += &Carapouce;
	polyland += &Balbazar;
	polyland += &Pokachu;
	polyland += &Touflamme;
	polyland += &Pokachoum;
	//Ce dresseur est deja present, il ne devrais pas s'ajouter.
	// A COMPLETER...
	polyland += Pierre;

	std::cout << "TEST D'AFFICHAGE" << std::endl << std::endl;
	// Tests d'affichage
	std::cout << polyland << std::endl;
	std::cout << *(polyland.choisirCreatureAleatoire()) << std::endl;
	std::cout << *(polyland.choisirDresseurAleatoire()) << std::endl;

	std::cout << std::endl << "COMPETITION" << std::endl;
	// Debut de la competition
	std::cout << std::endl << "Bienvenue a Polyland" << std::endl;
	Dresseur Vous("Hey", "Team INF1010");


	// Cette commande ne devrait pas fonctionner (effectivement, elle ne fonctionne pas!)
	Carapouce.oublierPouvoir("eclair");


	// Assignez une creature au dresseur.
	Sasha->ajouterCreature(&Salimouche);
	Pierre->ajouterCreature(&Balbazar);
	Regis->ajouterCreature(&Carapouce);
	// A COMPLETER...

	// Assignez à vous-meme Pokachu
	Vous.ajouterCreature(&Pokachu);
	// A COMPLETER...
	
	/*******************************************************************/
	/*                       DEBUT DES TESTS                           */
	/* Les modifications restantes sont a la fin de la fonction main.  */
	/*******************************************************************/
	//Duel entre vous et salimouche
	std::cout << std::endl << "TESTS DE COMBAT" << std::endl;

	std::cout << std::endl << "Un Salimouche surgit" << std::endl;

	std::cout << "Vous avez rencontré un Salimouche sauvage qui vous attaque..." << std::endl;
	
	Salimouche.attaquer(bouleDeFeu, *(Vous.obtenirUneCreature("Pokachu")));
	Vous.obtenirUneCreature("Pokachu")->attaquer(eclair, Salimouche);
	//Vous gagnez obligatoirement le duel
	while (Salimouche.obtenirPointDeVie() > 0) { 
		((Vous.obtenirUneCreature("Pokachu")))->attaquer(eclair, Salimouche); 
	}
	std::cout << "Vous avez battu un Salimouche, vous pouvez maintenante le capturer" << std::endl;

	if (polyland.attraperCreature(&Vous, &Salimouche)) { 
		std::cout << "Felicitation vous avez attrapé un Salimouche !" << std::endl;
	}
	else {
		std::cout << "Le Salimouche s'est échappé" << std::endl;
	}


	std::cout << std::endl;
	std::cout << "Vous trouvez une potion magique, vous décidez de l'utilisez sur Pokachu" << std::endl;

	ObjetMagique potionMagique("Potion magique", 15);
	std::cout << potionMagique << std::endl;
	//Vous venez de trouver une potion magique
	Vous.modifierObjetMagique(potionMagique);
	//Soin de votre creature
	Vous.utiliserObjetMagique(Vous.obtenirUneCreature("Pokachu"));

	//Choix d'une creature aleatoirement parmi celles possibles
	Creature* creatureAleatoire = polyland.choisirCreatureAleatoire();
	//Debut du duel avec la creature choisie aléatoirement
	std::cout << std::endl << "Un " << creatureAleatoire->obtenirNom() << " se jette sur votre Pokachu" << std::endl;
	std::cout << "Un duel entre Pokachu et " << creatureAleatoire->obtenirNom() << " est engagé" << std::endl;

	//Vous attaquez la créature tant que qu'elle est en vie...
	while (creatureAleatoire->obtenirPointDeVie() > 0) {
		if (Vous.obtenirUneCreature("Pokachu")->obtenirPointDeVie() > 0) {
			//... ou que votre créature est morte
			(Vous.obtenirUneCreature("Pokachu"))->attaquer(eclair, *creatureAleatoire);
			if (creatureAleatoire->obtenirPointDeVie() > 0)
				creatureAleatoire->attaquer(*(creatureAleatoire->obtenirPouvoirs()[0]), *(Vous.obtenirUneCreature("Pokachu"))); //modif
		}
		else
			break;
	}

	//Il se peut que vous gagniez...
	if (creatureAleatoire->obtenirPointDeVie() == 0)
		std::cout << "Vous avez vaincu " << creatureAleatoire->obtenirNom() << std::endl;
	else {
		//Sinon votre seconde créature se charge de finir le combat
		while (creatureAleatoire->obtenirPointDeVie() > 0)
			(Vous.obtenirUneCreature("Salimouche"))->attaquer(bouleDeFeu, *creatureAleatoire);
		std::cout << "Votre Pokachu a été battu mais heuresement votre Salimouche finit par vaincre " << creatureAleatoire->obtenirNom() << std::endl;
	}





	std::cout << "Pokachu et salimouche n'arrete pas de se chamailler, vous decidez d'abandonner Salimouche" << std::endl;
	
	//Vous en avez marre des chamailleries, vous décidez de relacher Salimouche
	if (polyland.relacherCreature(&Vous, "Salimouche")) {
		std::cout << "Vous avez decidé de relacher Salimouche !" << std::endl;
	}
	else {
		//ce cas ne devrait pas s'afficher
		std::cout << "Oh il y a eu un petit problème technique... Salimouche n'a pas pu être relaché" << std::endl;
	}
	
	/*******************************/
	/*       FIN DES TESTS         */
	/*******************************/


	std::cout << std::endl << "INFO DRESSEUR APRES TOUTES CES PERIPETIES" << std::endl;
	// Afficher les informations de Polyland
	// A COMPLETER...
	cout << polyland << endl;

	std::cout << std::endl << "DERNIER TESTS" << std::endl;
	// Cette commande ne devrait pas fonctionner (effectivement!)
	Carapouce.oublierPouvoir("eclair");

	// Suite a un combat intense, Carapouce perd son pouvoir pistoletAEau. Retirez ce pouvoir.
	// A COMPLETER...
	Carapouce.oublierPouvoir("pistoletAEau");

	// test des opérateurs == de la classe Dresseur
	Dresseur test1("test", "testeur");
	Dresseur test2("test", "testeur");
	test1.ajouterCreature(&Pokachu);
	test1.ajouterCreature(&Touflamme);
	test2.ajouterCreature(&Touflamme);
	test2.ajouterCreature(&Pokachu);

	std::cout << "________________________________________________" << std::endl;
	std::cout << "TEST OPERATEURS" << std::endl << std::endl;
	std::cout << "dresseur == dresseur : \t" << (test1 == test2) << " --- Reponse attendue : 1" << std::endl;
	std::cout << "dresseur == nom : \t" << (test1 == test2.obtenirNom()) << " --- Reponse attendue : 1" << std::endl;
	std::cout << "nom == dresseur : \t" << (test1.obtenirNom() == test2) << " --- Reponse attendue : 1" << std::endl;

	test1.ajouterCreature(&Carapouce);
	std::cout << "dresseur == dresseur : \t" << (test1 == test2) << " --- Reponse attendue : 0" << std::endl;

	test1.modifierNom("testNouveau");
	std::cout << "dresseur == nom : \t" << (test1 == test2.obtenirNom()) << " --- Reponse attendue : 0" << std::endl;
	std::cout << "nom == dresseur : \t" << (test1.obtenirNom() == test2) << " --- Reponse attendue : 0" << std::endl;


	// Liberer les ressources s'il le faut
	// A COMPLETER...
	delete Sasha;
	Sasha = nullptr;
	delete  Pierre;
	Pierre = nullptr;
	delete  Regis;
	Regis = nullptr;

	system("pause");
	return 0;
}