/****************************************************************************
* Fichier: Bibliotheque.cpp
* Auteur: PolySensei & Associates
* Date: 22 février 2016
* Mise a jour : 3 mars 2016
* Description: Implémentation de la classe Bibliotheque
****************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include "Bibliotheque.h"
#include "Abonne.h"
#include "Etudiant.h"
#include "Professeur.h"
#include "EtudiantBaccalaureat.h"

using namespace std;

//Constructeur par défaut
Bibliotheque::Bibliotheque()
{

}

//Destruction de la liste d'emprunts
Bibliotheque::~Bibliotheque()
{
	// Supprimer uniquement les emprunts
	for (size_t i = 0; i < vecEmprunts_.size(); i++)
	{
		delete vecEmprunts_.back();
		vecEmprunts_.pop_back();
	}
}


// Retourne l'abonné selon le matricule donné
Abonne * Bibliotheque::trouverAbonne(const std::string & matricule) const
{
	for (size_t i = 0; i < vecAbonnes_.size(); i++)
	{
		if (*(vecAbonnes_[i]) == matricule)
		{
			return vecAbonnes_[i];
		}
	}
	return nullptr;
}


// Une méthode trouverObjetEmpruntable() qui prend une cote (string) en paramètre, recherche l’objet empruntable et retourne un pointeur de type ObjetEmpruntable.Si aucun objet empruntable n’est retrouvé, un pointeur nul est retourné sinon.
ObjetEmpruntable* Bibliotheque::trouverObjetEmpruntable(const std::string& cote) const
{
	for (size_t i = 0; i < vecObj_.size(); i++)
	{
		if (vecObj_[i]->obtenirCote() == cote){
			return vecObj_[i];
		}
	}
	return nullptr;
}



// Une méthode obtenirClasseObjet() qui prend une cote (string) en paramètre, et renvoie le nom de la classe correspondant à l’objet ayant cette cote(« Livre », « DVD », « LivreNumerique »).
std::string Bibliotheque::obtenirClasseObjet(std::string const & cote) const
{
	for (int i = 0; i < vecObj_.size(); i++)
	{
		if (vecObj_[i]->obtenirCote() == cote){
			return vecObj_[i]->obtenirNomClasse();
		}
	}

	return "";
}



bool Bibliotheque::ajouterAbonne(Abonne& abonne)
{
	// Vérifier s'il est présent dans le vecteur. Si non, l'ajouter
	bool estPresent = false;
	Abonne* ab = trouverAbonne(abonne.obtenirMatricule());
	if (ab != nullptr) {
		for (size_t i = 0; i < vecAbonnes_.size(); i++)
		{
			if ((*vecAbonnes_[i]) == abonne)
				estPresent = true;
		}
	}
	if (!estPresent)
	{
		vecAbonnes_.push_back(&abonne);
	}
	return !estPresent;
}


bool Bibliotheque::retirerAbonne(const string& matricule)
{
	bool estRetire = false;

	for (size_t i = 0; i < vecAbonnes_.size(); i++)
	{
		// Si l'abonne est trouvé, alors swap sa position avec le dernier élément du vecteur, 
		// puis enlever de le dernier élément du vecteur
		if ((*vecAbonnes_[i]) == matricule)
		{
			// Retirer tous les emprunts
			vector<Emprunt*> abEmprunt = vecAbonnes_[i]->obtenirEmprunts();
			for (size_t j = 0; j < abEmprunt.size(); j++)
			{
				retourner(matricule, abEmprunt[j]->obtenirObjEmprunt()->obtenirCote());
			}

			// Retirer l'abonné
			estRetire = true;
			vecAbonnes_[i] = vecAbonnes_.back();
			vecAbonnes_.pop_back();
		}
	}

	return estRetire;
}

// La méthode ajouterObjetEmpruntable () qui permet d’ajouter l’ObjetEmpruntable reçu en paramètre seulement s’il n’est pas déjà dans le vecteur.Si l’ajout a été fait, la méthode renvoie true, false sinon.
bool Bibliotheque::ajouterObjetEmpruntable(ObjetEmpruntable* objet)
{
	// Vérifier s'il est présent dans le vecteur. Si non, l'ajouter
	bool estPresent = false;
	for (size_t i = 0; i < vecObj_.size(); i++)
	{
		if (vecObj_[i] == objet){
			estPresent = true;
		}
	}

	if (!estPresent)
	{
		vecObj_.push_back(objet);
	}
	return !estPresent;
}


// La méthode retirerObjetEmpruntable() qui permet de retirer l’objet empruntable en utilisant la cote reçue en paramètre. Il est retiré seulement s’il n’est pas emprunté. La méthode retourne donc un booléen true s’il est retiré, sinon false.
bool Bibliotheque::retirerObjetEmpruntable(const std::string & cote)
{
	ObjetEmpruntable* ptrObjet = trouverObjetEmpruntable(cote);

	for (size_t i = 0; i < vecObj_.size(); i++)
	{
		// Si l'objet est trouvé, alors swap sa position avec le dernier élément du vecteur, 
		// puis enlever de le dernier élément du vecteur
		if (vecObj_[i]->obtenirCote() == cote){
			vecObj_[i] = vecObj_.back();
			vecObj_.pop_back();
			return true;
		}
	}
	return false;
}

// La méthode rechercherObjetEmpruntable() qui prend en paramètre une chaîne de caractères(string),
//	o Cette méthode va rechercher les différents éléments empruntables de la bibliothèque qui contiennent l’information désirée en utilisant la méthode appropriée de la classe. Pour chaque élément trouvé les informations seront affichées à l’aide de la méthode afficherObjetEmpruntable() de la classe ObjetEmpruntable.La méthode prendra la variable cout comme paramètre d’entrée.
//	o N’oubliez pas de parcourir tous les éléments qui peuvent être emprunté recherche la chaine de mots parmi les attributs de type string de tous les classes de la famille ObjetEmpruntable
void Bibliotheque::rechercherObjetEmpruntable(const string& str) const
{
	bool trouve = false;
	cout << "Recherche pour le mot : " << str << endl;
	//recherche parmi les objets empruntable
	for (size_t i = 0; i < vecObj_.size(); i++)
	{
		if (vecObj_[i]->recherche(str)){
			trouve = true;


			
			vecObj_[i]->afficherObjetEmpruntable(cout);
		}

	}

	if (!trouve)
	{
		cout << "Aucun Resultat Trouve :-(" << endl;
	}
}



bool Bibliotheque::estEmpruntable(const std::string & matricule, const ObjetEmpruntable & objetEmpruntable) const
{	// Vérifie si les conditions de bases sont respectées et va vérifier aussi parmi les éléments dérivés d'Abonne
	bool empruntable = false;
	Abonne* abonne = trouverAbonne(matricule);
	//On doit vérifier que tous les vecteurs sont parcourus
	if (abonne != nullptr)
	{
		empruntable = (objetEmpruntable.obtenirNbDisponibles() >= 1) &&
			(abonne->obtenirAge() >= objetEmpruntable.obtenirAgeMinimal()) &&
			(!(abonne->estEmprunte(objetEmpruntable))) && abonne->obtenirEmprunts().size()<abonne->obtenirLimiteEmprunt();
	}
	
	return empruntable;
}


// La méthode emprunter() qui prend en paramètres le matricule d’un abonné, la cote d’unobjet empruntable et la date de retour associée en fonction du statut de l’abonné.Cette méthode doit retourner une valeur booléenne indiquant si l’emprunt a été fait ou non.
//	o Elle doit s’assurer que le nombre d’emprunts ne dépasse pas la limite par type d’abonné.
//	o Elle doit diminuer le nombre d’objets associés disponibles.
bool Bibliotheque::emprunter(const string& matricule, const string& cote, unsigned int date)
{
	//On doit vérifier que tous les vecteurs sont parcourus
	Abonne* ab = trouverAbonne(matricule);

	ObjetEmpruntable* obj = trouverObjetEmpruntable(cote);

	bool peutEmprunte = false;

	if ((ab != nullptr) && (obj != nullptr))
	{
		// Vérifier s'il est possible d'emprunter l'objet, puis l'emprunter

		peutEmprunte = (estEmpruntable(ab->obtenirMatricule(), *obj));

		if (peutEmprunte)
		{
			vecEmprunts_.push_back(new Emprunt(matricule, obj, date));
			ab->ajouterEmprunt(vecEmprunts_.back());
			obj->modifierNbDisponibles(obj->obtenirNbDisponibles() - 1);
			return true;
		}
	}
	return false;

}


bool Bibliotheque::retourner(const string& matricule, const string& cote)
{
	int emPos = -1;
	bool estRetourne = false;

	// Chercher l'emprunt
	for (size_t i = 0; i < vecEmprunts_.size(); i++)
	{
		if ((vecEmprunts_[i]->obtenirMatricule() == matricule) &&
			(*(vecEmprunts_[i]->obtenirObjEmprunt()) == cote))
			emPos = i;
	}


	if (emPos != -1)
	{
		Emprunt* em = vecEmprunts_[emPos];
		ObjetEmpruntable* obj = em->obtenirObjEmprunt();
		//On doit vérifier que tous les vecteurs sont parcourus
		Abonne* ab = trouverAbonne(matricule);
	
		// Vérifier s'il est possible de retourner l'objetEmpruntable, puis le retourner et détruire l'emprunt
		estRetourne = ab->estEmprunte(*obj);
		if (estRetourne)
		{
			ab->retirerEmprunt(obj);
			vecEmprunts_[emPos] = vecEmprunts_.back();
			vecEmprunts_.pop_back();
			delete em;
			obj->modifierNbDisponibles(obj->obtenirNbDisponibles() + 1);
		}
	}
	return estRetourne;

}

// La méthode infoAbonne() qui prend en paramètre un matricule d’abonné et affiche les informations qui le concerne en utilisant l’opérateur << approprié.
//	o Cette méthode doit déterminer de quelle sous - classe fait partie l’abonné.
//	o Une fois déterminé, la méthode doit faire un dynamic_cast<> pour obtenir un pointeur de la classe appropriée, dans le but d’appeler l’opérateur << .
void Bibliotheque::infoAbonne(const string& matricule) const
{
	//On doit vérifier que tous les vecteurs sont parcourus
	Abonne* ab = trouverAbonne(matricule);

	if (ab != nullptr)
	{
		// Utilisez dynamic_cast<>()  pour convertir les types de pointeurs et appeler le bon opérateur <<
		string typeClasse = ab->obtenirNomClasse();
		if (typeClasse == typeid(EtudiantBaccalaureat).name())
		{
			cout << *dynamic_cast<const EtudiantBaccalaureat*> (ab);
		}
		else if (typeClasse == typeid(Etudiant).name())
		{
			cout << *dynamic_cast<const Etudiant*> (ab);
		}
		else if (typeClasse == typeid(Professeur).name())
		{
			cout << *dynamic_cast<const Professeur*> (ab);
		}
		else if (typeClasse == typeid(Abonne).name())
		{
			cout << *dynamic_cast<const Abonne*> (ab);
		}
	}
	else
	{
		cout << "Abonne - " << matricule << " - non trouve" << endl;
	}

}


//Surcharges des opérateurs demandés
Bibliotheque & Bibliotheque::operator+=(Abonne * abonne)
{
	
	ajouterAbonne(*abonne);
	return *this;
}


Bibliotheque & Bibliotheque::operator+=(ObjetEmpruntable * obj)
{
	ajouterObjetEmpruntable(obj);
	return *this;
}


Bibliotheque & Bibliotheque::operator-=(Abonne * abonne)
{
	retirerAbonne(abonne->obtenirMatricule());
	return *this;
}

Bibliotheque & Bibliotheque::operator-=(ObjetEmpruntable * obj)
{
	retirerObjetEmpruntable(obj->obtenirCote());
	return *this;
}

std::istream & operator>>(std::istream & in, const Bibliotheque & biblio)
{
	string mot;
	in >> mot;
	biblio.rechercherObjetEmpruntable(mot);
	return in;
}


