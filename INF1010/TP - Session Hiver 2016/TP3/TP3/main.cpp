/****************************************************************************
* Fichier: main.cpp
* Auteur: PolySensei & Associates
* Date: 11 février 2016
* Mise a jour : 21 février 2016
* Description: Programme de test
****************************************************************************/
#include <vector>
#include <iostream>
#include "Bibliotheque.h"
#include "Abonne.h"
#include <typeinfo>

using namespace std;

int main()
{
	cout << "________________________________________________" << endl;
	cout << "CREATION ET AFFICHAGE DES ABONNES" << endl << endl;
	// Creation des abonnes, des etudiants et des professeurs
	Abonne john("1839456", "Doe", "John", 23);
	Abonne nicolas("1630236", "Gagnon", "Nicolas", 8);
	Abonne martin("1269348", "Tremblay", "Martin", 18);
	
	Etudiant harry("1782965", "Potter", "Harry", 21, "Pourdlard");
	Etudiant hermione("1876458", "Granger", "Hermione", 20, "Pourdlard");
	EtudiantBaccalaureat tony("1865487", "Stark", "Tony", 42);

	Professeur albus("p878546", "Dumbledore", "Albus", 78, { "Poudlard", "UdM", "Polytechnique" });

	// Affichage des informations sur chaque abonne (en utilisant cout <<)
	cout << john;
	cout << nicolas;
	cout << martin;

	cout << harry;
	cout << hermione;
	cout << tony;

	cout << albus;

	cout << "________________________________________________" << endl;
	cout << "CREATION ET AFFICHAGE DES OBJETS EMPRUNTABLES" << endl << endl;
	// Création des livres

	Livre *livre1 = new Livre("GA403", "Big C++", 2009, 8, 2, "Cay HORTSTMANN", "Informatique");
	Livre *livre2 = new Livre("QA203", "Calcul a plusieurs variables partie 1", 2011, 3, 1, "Cay HORTSTMANN", "Informatique");
	Livre *livre3 = new Livre(*livre2);
	livre3->modifierTitre("Calcul a plusieurs variables partie 2");
	livre3->modifierCote("QA204");
	livre3->modifierNbExemplaires(1);
	Livre *livre4 = new Livre("AC409", "Le chateau d'Ortrante", 1764, 16, 2, "Cay HORTSTMANN", "Informatique");
	Livre *livre5 = new Livre("BD302", "Harry Potter et le prisionier d'Azkaban", 1999, 3, 17, "JK ROWLING", "Science-Fiction");
	Livre *livre6 = new Livre(*livre1);
	*livre6 = *livre1;
	livre6->modifierAnnee(2016);
	livre6->modifierCote("GA404");
	// Affichages des informations sur chaque livre

	cout << *livre1;
	cout << *livre2;
	cout << *livre3;
	cout << *livre4;
	cout << *livre5;
	cout << *livre6;

	// Creation des Dvds
	Dvd *dvd1 = new Dvd("D8403", "Rush Hour", 1998, 2, 13, "Al", { "Jackie Chan", "Chris Tucker" });
	Dvd *dvd2 = new Dvd("D7203", "Avenger", 2012, 3, 5, "Nick Fury", { "Iron Man", "Thor","Hulk", "Captain America", "Black Window" });

	// Affichage des informations sur les Dvds
	cout << *dvd1;
	cout << *dvd2;

	Bibliotheque biblio;
	cout << "________________________________________________" << endl;
	cout << "AJOUT DES DIFFERENTS ELEMENTS A LA BIBLIOTHEQUE" << endl << endl;
	// Ajout des éléments dans la bibliothèque
	biblio += &john;
	biblio += &nicolas;
	biblio += &martin;
	//Ajout des Etudiants et du Professeur
	biblio += &harry;
	biblio += &tony;
	biblio += &hermione;
	biblio += &albus;

	biblio += livre1;
	biblio += livre2;
	biblio += livre3;
	biblio += livre4;
	biblio += livre5;
	biblio += livre6;
	//Ajout des Dvds
	
	biblio += dvd1;
	biblio += dvd2;
	// Enlever hermione de la bibliotheque
	// Enlevez l'édition 2009 de Big C++
	
	biblio -= &hermione;
	biblio -= livre1;


	// Création de vecteur pour effectuer les emprunts

	vector<string> vecMatricules =
	{ "1630236" , "1782965" , "1865487", "p878546"};
	vector<string> vecCote =
	{ "AC409", "BD302" ,  "BD302", "D7203", "QA203", "D8403", "QA204"};


	/*******************************************************************/
	/*                       DEBUT DES TESTS                           */
	/* Les modifications restantes sont a la fin de la fonction main.  */
	/*******************************************************************/


	// Test d'emprunts en utilisant les vecteurs précédents
	cout << "________________________________________________" << endl;
	cout << "TESTS D'EMPRUNTS" << endl << endl;
	for (size_t i = 0; i < vecMatricules.size(); i++)
	{
		int nombreEmpruntReussi = 0;
		int nombreEmpruntRate = 0;
		for (unsigned int j = 0; j < vecCote.size(); j++)
		{
			if (biblio.emprunter(vecMatricules[i], vecCote[j], 160204))
				nombreEmpruntReussi++;
			else
				nombreEmpruntRate++;
			
		}
		cout << vecMatricules[i] <<" a reussi " << nombreEmpruntReussi << " emprunt(s) !" << endl;
		cout << vecMatricules[i] << " a rate " << nombreEmpruntRate << " emprunt(s) !" << endl;

	}
	
	// Affichage des informations d'Albus avec la méthode infoAbonne de Bibliothèque
	cout << "________________________________________________" << endl;
	cout << "INFO ABONNE AVANT RETOUR" << endl << endl;
	biblio.infoAbonne("p878546");
	biblio.infoAbonne("1876458");

	cout << "________________________________________________" << endl;
	cout << "TESTS RETOUR LIVRE" << endl << endl;
	// Devrait marcher
	if (biblio.retourner("1630236", "BD302"))
	{
		cout << "BD302 remis par 1630236" << endl;
	}
	else
	{
		cout << "Echec remise" << endl;
	}
	// Ne devrait pas marcher car l'abonne n'a jamais fait ce pr�t
	if (biblio.retourner("1839456", "QA203"))
	{
		cout << "QA203 remis par 1839456" << endl;
	}
	else
	{
		cout << "Echec remise" << endl;
	}
	//Test de retour pour les classes Etudiant et Professeur 
	// Devrait marcher
	if (biblio.retourner("1782965", "D8403"))
	{
		cout << "D8403 remis par 1782965" << endl;
	}
	else
	{
		cout << "Echec remise" << endl;
	}
	// Ne devrait pas marcher car l'abonne n'a jamais fait ce pr�t
	if (biblio.retourner("1865487", "CD587"))
	{
		cout << "CD587 remis par 1865487" << endl;
	}
	else
	{
		cout << "Echec remise" << endl;
	}
	// Devrait marcher
	if (biblio.retourner("p878546", "D7203"))
	{
		cout << "D7203 remis par p878546" << endl;
	}
	else
	{
		cout << "Echec remise" << endl;
	}
	// Devrait marcher
	if (biblio.retourner("p878546", "QA203"))
	{
		cout << "QA203 remis par p878546" << endl;
	}
	else
	{
		cout << "Echec remise" << endl;
	}
	// Ne devrait pas marcher car l'abonne n'a jamais fait ce pr�t
	if (biblio.retourner("p878546", "QA204"))
	{
		cout << "QA204 remis par p878546" << endl;
	}
	else
	{
		cout << "Echec remise" << endl;
	}

	// Affichage des informations sur albus avec la méthode infoAbonne de la bibliothèque
	cout << "________________________________________________" << endl;
	cout << "INFO ABONNE APRES RETOUR" << endl << endl;
	biblio.infoAbonne("p878546");
		
	// Utiliser l'opérateur >> de Bibliothèque afin d'entrer des mots pour
	// trouver tous les livres correspondants
	// Les mots doivent être recherchés dans tous les attributs string des objets empruntables

	// Rechercher mot, 1er test
	cout << "________________________________________________" << endl;
	cout << "ENTREZ UN MOT A RECHERCHER (1er test)" << endl << endl;
	cin >> biblio;

	// Rechercher mot, 2e test
	cout << "________________________________________________" << endl;
	cout << "ENTREZ UN MOT A RECHERCHER (2e test)" << endl << endl;
	cin >> biblio;

	// Rechercher mot, 3e test
	cout << "________________________________________________" << endl;
	cout << "ENTREZ UN MOT A RECHERCHER (3e test)" << endl << endl;
	cin >> biblio;
	/*******************************/
	/*       FIN DES TESTS         */
	/*******************************/

	// Liberation les ressources 
	delete livre1;
	delete livre2;
	delete livre3;
	delete livre4;
	delete livre5;
	delete livre6;

	delete dvd1;
	delete dvd2;

	system("pause");
	return 0;
}


