/****************************************************************************
* Fichier: main.cpp
* Auteur: PolySensei & Associates
* Date: 4 février 2016
* Mise a jour : 6 février 2016
* Description: programme de test
****************************************************************************/

#include <vector>
#include <iostream>
#include "Bibliotheque.h"
#include "Abonne.h"

using namespace std;

int main()
{
	cout << "________________________________________________" << endl;
	cout << "CREATION ET AFFICHAGE DES ABONNES" << endl << endl;
	// Creation des abonnes
	Abonne john("1839456", "Doe", "John", 23);
	Abonne nicolas("1630236", "Gagnon", "Nicolas", 8);
	Abonne martin("1269348", "Tremblay", "Martin", 18);

	// Afficher les informations sur chaque abonne (en utilisant cout <<)
	cout << john << endl
		<< nicolas << endl
		<< martin << endl;


	cout << "________________________________________________" << endl;
	cout << "CREATION ET AFFICHAGE DES LIVRES" << endl << endl;
	// Creer les livres suivants (cote, titre, ann�e, age minimal, nombre exemplaires):
	// Vous devez utiliser le constructeur demandé, 
	// puis modifier les attribut en utilisant les méthodes requises.
	//
	// Constructeur par paramètre: 
	Livre* livre1 = new Livre("GA403", "Big C++", 2009, 8, 3);
	Livre* livre2 = new Livre("QA203", "Calcul a plusieurs variables partie 1", 2011, 3, 2);
	Livre* livre3 = new Livre("AC409", "Le chateau d'Ortrante", 1764, 16, 1);
	Livre* livre4 = new Livre("BD302", "Harry Potter et le prisionier d'Azkaban", 1999, 3, 1);
	
	// Constructeur par copie :
	// ("QA204", "Calcul a plusieurs variables partie 2", 2011, 3, 2)
	Livre* livre5 = new Livre(*livre2);
	livre5->modifierCote("QA204");
	livre5->modifierTitre("Calcul a plusieurs variables partie 2");

	// Opérateur =  :
	//("GA404", "Big C++", 2016, 8, 3)
	Livre* livre6 = new Livre;
	*livre6 = *livre1;
	livre6->modifierCote("GA404");
	livre6->modifierAnnee(2016);

	// Afficher les informations sur chaque livre 
	// UTILISEZ: cout <<
	cout << *livre1 << endl
		<< *livre2 << endl
		<< *livre5 << endl
		<< *livre3 << endl
		<< *livre4 << endl
		<< *livre6 << endl;

	
	Bibliotheque biblio;
	cout << "________________________________________________" << endl;
	cout  << "Ajout des livres et abonnes a la bibliotheque" << endl << endl;
	// Ajouter les abonnes et les livres a la bibliotheque
	// UTILISEZ: l'opérateur +=
	Abonne* ptrJohn = &john;
	Abonne* ptrNicolas = &nicolas;
	Abonne* ptrMartin = &martin;
	biblio += ptrJohn;
	biblio += ptrNicolas;
	biblio += ptrMartin;
	biblio += livre1;
	biblio += livre2;
	biblio += livre5;
	biblio += livre3;
	biblio += livre4; 
	biblio += livre6;
	
	// Enlever martin de la bibliotheque
	// Enlevez l'édition 2009 de Big C++
	// UTILISEZ: l'opérateur -=
	biblio -= ptrMartin;
	biblio -= livre1;
	
	// Créer les vecteurs vecMatricules et vecCote  
	// tel qu'ils contienne les éléments suivants (string)
	// Utilisez 1 SEULE ligne de code par vecteur! pas de push_back
	vector<string> vecMatricules{ "1630236", "1630236", "1839456", "1630236", "1630236", "1630236" };
	vector<string> vecCote{ "AC409", "BD302", "BD302", "BD302", "QA204", "QA203" };

	
	/*******************************************************************/
	/*                       DEBUT DES TESTS                           */
	/* Les modifications restantes sont a la fin de la fonction main.  */
	/*******************************************************************/

	
	// Test d'emprunts en utilisant les vecteurs précédents
	cout << "________________________________________________" << endl;
	cout << "TESTS D'EMPRUNTS" << endl << endl;
	for (size_t i = 0; i < vecMatricules.size(); i++)
	{
		if (biblio.emprunter(vecMatricules[i], vecCote[i], 160204))
		{
			cout << "AC409 emprunte par 1630236" << endl;
		}
		else
		{
			cout << "Echec emprunt" << endl;
		}
	}
	

	// Afficher les informations d'un abonné en utilisant la méthode infoAbonne de Bibliothèque
	cout << "________________________________________________" << endl;
	cout <<  "INFO ABONNE AVANT RETOUR" << endl << endl;
	biblio.infoAbonne("1630236");
	biblio.infoAbonne("1269348");

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

	// Afficher les informations d'un abonné en utilisant la méthode infoAbonne de Bibliothèque
	cout << "________________________________________________" << endl;
	cout  << "INFO ABONNE APRES RETOUR" << endl<< endl;
	biblio.infoAbonne("1630236");


	// test des opérateurs == des classes Livre et Abonne
	Abonne john2 = john;
	Livre livre_test1 = Livre("AAA", "livre test aaa", 1999, 10, 3);
	Livre livre_test2 = Livre("BBB", "livre test bbb", 1999, 10, 3);
	Livre livre_test3 = livre_test1;
	Livre livre_test4 = livre_test3;
	livre_test4.modifierTitre("livre test ccc");

	cout << "________________________________________________" << endl;
	cout << "TEST OPERATEURS" << endl << endl;
	cout << "matricule == abonne : \t" << ("1839456" == john) << " --- "<< ("1839456" == martin) << endl;
	cout << "abonne == matricule : \t" << (john == "1839456") << " --- " << (martin == "1839456") << endl;
	cout << "abonne == abonne : \t" << (john == john2) << " --- " << (john == martin) << endl;
	
	cout << "cote == livre : \t" << ("AAA" == livre_test1) << " --- " << ("BBB" == livre_test1) << endl;
	cout << "livre == cote : \t" << (livre_test1 == "AAA") << " --- " << (livre_test1 == "BBB") << endl;
	cout << "livre == livre : \t" << (livre_test1 == livre_test3) << " --- " << (livre_test1 == livre_test2) << endl;

	cout << "livre a < livre b : \t" << (livre_test1 < livre_test2) << " --- " << (livre_test2 < livre_test1) << endl;
	cout << "livre b < livre c : \t" << (livre_test2 < livre_test4) << " --- " << (livre_test4 < livre_test2) << endl;

	// Utiliser l'opérateur >> de Bibliothèque afin d'entrer des mots pour
	// trouver tous les livres correspondants
	
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

	// Liberer les ressources si il le faut
	// A COMPLETER...

	delete livre1;
	delete livre2;
	delete livre3;
	delete livre4;
	delete livre5;
	delete livre6;


	system("pause");
	return 0;
}

//Fin du programme de test


