/****************************************************************************
* Fichier: main.cpp
* Auteur: PolySensei & Associates
* Date: 22 février 2016
* Mise a jour : 22 février 2016
* Description: Programmme de test
****************************************************************************/
#include <vector>
#include <iostream>
#include "Bibliotheque.h"
#include "Abonne.h"
#include "EtudiantBaccalaureat.h"
#include "LivreNumerique.h"
#include <typeinfo>

using namespace std;

int main()
{
	cout << "________________________________________________" << endl;
	cout << "CREATION DES ABONNES ET DES OBJETS EMPRUNTABLES" << endl << endl;
	
	// Creation des abonnes, des etudiants et des professeurs
	Abonne john("1839456", "Doe", "John", 23);
	Abonne nicolas("1630236", "Gagnon", "Nicolas", 8);
	Abonne martin("1269348", "Tremblay", "Martin", 18);
	
	Etudiant harry("1782965", "Potter", "Harry", 21, "Pourdlard");
	Etudiant hermione("1876458", "Granger", "Hermione", 20, "Pourdlard");
	EtudiantBaccalaureat tony("1865487", "Stark", "Tony", 42);

	Professeur albus("p878546", "Dumbledore", "Albus", 78, { "Poudlard", "UdM", "Polytechnique" });
		
	// Création des livres et DVD
	Livre *livre1 = new Livre("GA403", "Big C++", 2009, 8, 2, "Cay HORTSTMANN", "Informatique");
	Livre *livre2 = new Livre("QA203", "Calcul a plusieurs variables partie 1", 2011, 3, 1, "Cay HORTSTMANN", "Informatique");
	Livre *livre3 = new Livre("QA204", "Calcul a plusieurs variables partie 2", 2011, 3, 1, "Cay HORTSTMANN", "Informatique");
	Livre *livre4 = new Livre("AC409", "Le chateau d'Ortrante", 1764, 16, 2, "Cay HORTSTMANN", "Informatique");
	Livre *livre5 = new Livre("BD302", "Harry Potter et le prisionier d'Azkaban", 1999, 3, 17, "JK ROWLING", "Science-Fiction");
	Livre *livre6 = new Livre("GA404", "Big C++", 2016, 8, 2, "Cay HORTSTMANN", "Informatique");
	
	Dvd *dvd1 = new Dvd("D8403", "Rush Hour", 1998, 2, 13, "Al", { "Jackie Chan", "Chris Tucker" });
	Dvd *dvd2 = new Dvd("D7203", "Avenger", 2012, 3, 5, "Nick Fury", { "Iron Man", "Thor","Hulk", "Captain America", "Black Window" });

	// Creation de la bibliotheque, et ajout des elements
	Bibliotheque biblio;
	cout << "________________________________________________" << endl;
	cout << "AJOUT DES DIFFERENTS ELEMENTS A LA BIBLIOTHEQUE" << endl << endl;
	
	//Ajout des Abonnes
	biblio += &john;	biblio += &nicolas;	biblio += &martin;
	biblio += &harry;	biblio += &tony;	biblio += &hermione;
	biblio += &albus;

	// Ajout des livres et DVD
	biblio += livre1;	biblio += livre2;	biblio += livre3;
	biblio += livre4;	biblio += livre5;	biblio += livre6;
	biblio += dvd1;		biblio += dvd2;

	// Quelques retraits
	biblio -= &hermione;	biblio -= livre1;


	///
	// Creation des objets numeriques et ajout à la bibliotheque
	cout << "________________________________________________" << endl;
	cout << "CREATION DES OBJETS NUMERIQUES" << endl << endl;
	LivreNumerique *livNum1 = new LivreNumerique(
		FORMAT_EPUB, 1270, "vvv.3Mousquetaire.com", "NUM392",
		"Les 3 mousquetaires", 1844, 11, 5, "A. Dumas", "Roman");
	LivreNumerique *livNum2 = new LivreNumerique(
		FORMAT_EPUB, 1270, "vvv.3Mousquetaire.com", "NUM393",
		"Les 3 mousquetaires 2", 1846, 11, 5, "A. Dumas", "Roman");
	cout << *livNum1 << endl;
	cout << *livNum2;
	biblio += livNum1;
	biblio += livNum2;

	// Création de vecteur pour effectuer les emprunts

	vector<string> vecMatricules =
	{ "1630236" , "1782965" , "1865487", "p878546"};
	vector<string> vecCote =
	{ "AC409", "BD302" ,  "BD302", "D7203", "QA203", "QA204", "NUM392"};


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
		for (int j = 0; j < vecCote.size(); j++)
		{
			if (biblio.emprunter(vecMatricules[i], vecCote[j], 160204))
				nombreEmpruntReussi++;
			else
				nombreEmpruntRate++;
			
		}
		cout << vecMatricules[i] <<" a reussi " << nombreEmpruntReussi << " emprunt(s) !" << endl;
		cout << vecMatricules[i] << " a rate " << nombreEmpruntRate << " emprunt(s) !" << endl;

	}
	
	vector<string> vecMatriculesRetour =
	{ "1630236" ,	"1839456" , "1782965",	"1865487",	"p878546", "p878546",	"p878546" };
	vector<string> vecCoteRetour =
	{ "BD302",		"QA203" ,	"D8403",	"CD587",	"D7203",	"QA203",	"QA204" };


	// Affichage des informations d'Albus avec la méthode infoAbonne de Bibliothèque
	cout << "________________________________________________" << endl;
	cout << "INFO ABONNE AVANT RETOUR" << endl << endl;
	biblio.infoAbonne("p878546");

	cout << "________________________________________________" << endl;
	cout << "TESTS RETOUR LIVRE" << endl << endl;
	
	// Boucle de retours
	for (size_t i = 0; i < vecMatriculesRetour.size(); i++)
	{
		if (biblio.retourner(vecMatriculesRetour[i], vecCoteRetour[i]))
		{
			cout << vecCoteRetour[i] << " remis par " << vecMatriculesRetour[i] << endl;
		}
		else
		{
			cout << "Echec remise" << endl;
		}
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

	//// Rechercher mot, 3e test
	//cout << "________________________________________________" << endl;
	//cout << "ENTREZ UN MOT A RECHERCHER (3e test)" << endl << endl;
	//cin >> biblio;
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

	delete livNum1;
	delete livNum2;

	system("pause");
	return 0;
}





