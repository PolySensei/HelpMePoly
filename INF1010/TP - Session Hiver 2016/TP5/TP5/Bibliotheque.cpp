/****************************************************************************
* Fichier: Bibliotheque.h
* Auteur: PolySensei & Associates
* Date: 7 mars 2016
* Mise a jour : 28 mars 2016
* Description: Définition du foncteur Bibliotheque
****************************************************************************/

#include "Bibliotheque.h"
#include <map>
using namespace std; 

//Un constructeur par défaut.
Bibliotheque::Bibliotheque() {}


//Un destructeur (foncteur DetruireEmprunt).
Bibliotheque::~Bibliotheque()
{
	gestEmprunts_.retirerContenu(DetruireEmprunt());
}


// Une méthode trouverAbonne () qui prend un matricule (string) en paramètre, elle doit créer le foncteur MemeObjet, recherche l’abonné dans le gestionnaire et retourne un pointeur de type Abonne.Si aucun abonné n’est retrouvé, un pointeur nul est retourné sinon.
Abonne* Bibliotheque::trouverAbonne(const std::string& matricule) const 
{

	Abonne* ptrAbonne;
	MemeObjet<Abonne, const string> memeAbonne(&matricule);
	ptrAbonne = gestAbonnes_.trouverElement(memeAbonne);
	return ptrAbonne; //
}


// La méthode ajouterAbonne () qui permet d’ajouter l’abonné reçu en paramètre dans le gestionnaire approprié.
bool Bibliotheque::ajouterAbonne(Abonne& abonne) 
{
	bool estAjoute = false;
	estAjoute = gestAbonnes_.ajouterElement(&abonne);
	return estAjoute;
}


// La méthode retirerAbonne () qui permet de retirer l’abonné en utilisant le matricule reçu en paramètre.La méthode doit créer le foncteur MemeObjet. Avant de le retirer, il faut retourner tous les objets qu’il a empruntés.La méthode retourne donc un booléen true s’il est retiré, sinon false.
bool Bibliotheque::retirerAbonne(const std::string& matricule)
{
	bool estRetire = false;
	Abonne* ptrAbonne = trouverAbonne(matricule);

	if (ptrAbonne == nullptr){
		estRetire = false;
	}
	else
	{
		MemeObjet<Emprunt, const string> memeAbonne(&matricule); 
		list<Emprunt*> listeEmprunt = gestEmprunts_.trouverContenu(memeAbonne); // On trouve tous les emprunts de l'abonne

		//Boucle pour retourner tous les objets empruntés par l'abonné.
		for (list<Emprunt*>::iterator it = listeEmprunt.begin(); it != listeEmprunt.end(); it++)
		{
			retourner(matricule, ((**it).obtenirObjetEmpruntable()->obtenirCote()));
		}
		gestAbonnes_.retirerElement(ptrAbonne);
		estRetire = true;
	}
	return estRetire;
}


// Une méthode trouverObjetEmpruntable () qui prend une cote (string) en paramètre, elle doit créer le foncteur MemeObjet, recherche l’objet empruntable dans le gestionnaire et retourne un pointeur de type ObjetEmpruntable.Si aucun objet empruntable n’est retrouvé, un pointeur nul est retourné sinon.
ObjetEmpruntable* Bibliotheque::trouverObjetEmpruntable(const std::string& cote) const 
{
	MemeObjet<ObjetEmpruntable, const string> memeObjetEmpruntable(&cote);
	ObjetEmpruntable* ptrObjet = gestObj_.trouverElement(memeObjetEmpruntable);
	return ptrObjet;
}


// La méthode ajouterObjetEmpruntable () qui permet d’ajouter l’ObjetEmpruntable reçu en paramètre dans le gestionnaire approprié.
bool Bibliotheque::ajouterObjetEmpruntable(ObjetEmpruntable* objet) 
{
	bool estAjoute = false;
	estAjoute = gestObj_.ajouterElement(objet);
	return estAjoute;
}


// La méthode retirerObjetEmpruntable() qui permet de retirer l’objet empruntable en utilisant la cote(string) reçue en paramètre, elle doit créer le foncteur MemeObjet.L’objet est retiré seulement s’il n’est pas emprunté.La méthode retourne donc un booléen true s’il est retiré, sinon false.
bool Bibliotheque::retirerObjetEmpruntable(const std::string& cote)
{
	bool estRetire = false;

	MemeObjet<Emprunt, const string> memeObjetEmpruntable(&cote);
	list<Emprunt*> listeEmpruntObjet = gestEmprunts_.trouverContenu(memeObjetEmpruntable); //Trouve les emprunts associé à l'objet.
	ObjetEmpruntable* ptrObjet = trouverObjetEmpruntable(cote);	// Trouve l'adresse de l'objet.

	if (listeEmpruntObjet.size() == 0) //Si l'objet n'est pas emprunté.
	{
		estRetire = gestObj_.retirerElement(ptrObjet);
	}

	return estRetire;
}


// La méthode rechercherObjetEmpruntable() qui prend en paramètre une chaîne de caractères(string), elle doit créer les foncteurs RechercheObjetEmpruntable et TrieParTitre .
//	o Cette méthode va rechercher les différents éléments empruntables de la bibliothèque qui contiennent l’information désirée en utilisant la méthode appropriée de la classe gestionnaire.
//	o La méthode doit trier les objets par ordre alphabétique selon leur titre à l’aide du foncteur et de l’algorithme de tri avant de les afficher.
//	o Pour chaque élément trouvé, les informations seront affichées à l’aide de la fonction opérator << .
//	o Si rien n’a été trouvé, affichez un message.
void Bibliotheque::rechercherObjetEmpruntable(const std::string& str) const
{
	cout << "Recherche pour le mot : " << str << endl;
	RechercheObjetEmpruntable rechercheMot(str);
	list<ObjetEmpruntable*> listeObjetTrouve = gestObj_.trouverContenu(rechercheMot);
	listeObjetTrouve.sort(TrieParTitre());

	if (listeObjetTrouve.empty())
	{
		cout << "Aucun resultat trouve :(" << endl;
	}
	else
	{
		for (list<ObjetEmpruntable*>::iterator it = listeObjetTrouve.begin(); it != listeObjetTrouve.end(); it++)
		{
			cout << *(*it) << endl;
		}
	}
}



// La méthode emprunter() qui prend en paramètres le matricule d’un abonné, la cote d’un objet empruntable et la date de retour associée.Cette méthode doit retourner une valeur booléenne indiquant si l’emprunt a été fait ou non.
//	o Elle doit s’assurer que le nombre d’emprunts ne dépasse pas la limite par type d’abonné.
//	o Elle doit diminuer le nombre d’objets associés disponibles.
//	o Elle doit utiliser le foncteur Empruntable .
bool Bibliotheque::emprunter(const std::string& matricule, const std::string& cote, unsigned int date)
{
	bool peutEmprunter = false;

	Abonne* ptrAbonne = trouverAbonne(matricule);
	ObjetEmpruntable* ptrObjet = trouverObjetEmpruntable(cote);

	//Pour compter le nombre d'emprunt d'un abonné, allons voir la liste d'emprunt
	bool dejaEmprunte = false;
	int compteur = 0;
	Empruntable predicatEmpruntable(matricule, cote, &compteur, &dejaEmprunte);
	list<Emprunt*> listeDEmprunt = gestEmprunts_.trouverContenu(predicatEmpruntable);

	peutEmprunter = ((!dejaEmprunte) &&
					  (compteur < ptrAbonne->obtenirLimiteEmprunt()) &&
					  (ptrObjet->obtenirNbDisponibles() >= 1 ) &&
					  (ptrAbonne->obtenirAge() >= ptrObjet->obtenirAgeMinimal()));
		
	if (peutEmprunter)
	{
		ptrObjet->modifierNbDisponibles(ptrObjet->obtenirNbDisponibles() - 1); //diminuer le nombre d’objets associés disponibles
		Emprunt* nouveauEmprunt = new Emprunt(matricule, ptrObjet, date);
		gestEmprunts_.ajouterElement(nouveauEmprunt);
	}

	return peutEmprunter;
}


// La méthode retourner() qui prend en paramètres le matricule d’un abonné, la cote d’un objet empruntable.Cette méthode doit retourner une valeur booléenne indiquant si l’emprunt a été retourné ou non.
//	o Elle doit utiliser le foncteur MemeObjet pour trouver l’emprunt.
//	o Elle doit augmenter le nombre d’objets associés disponibles.
//	o Elle doit détruire l’objet de la mémoire après son retrait du gestionnaire.
bool Bibliotheque::retourner(const std::string& matricule, const std::string& cote) 
{
	bool retourEffectue = false;
	ObjetEmpruntable* ptrObjet = trouverObjetEmpruntable(cote);

	MemeObjet<Emprunt, const string> memeAbonne(&matricule);
	list<Emprunt*> listeEmprunt = gestEmprunts_.trouverContenu(memeAbonne); // On trouve tous les emprunts de l'abonne

	for (list<Emprunt*>::iterator it = listeEmprunt.begin(); it != listeEmprunt.end(); it++)
	{
		if ((*it)->obtenirObjetEmpruntable() == ptrObjet) //Vérifie que l'objet est bel et bien emprunté.
		{
			retourEffectue = true;
			ptrObjet->modifierNbDisponibles(ptrObjet->obtenirNbDisponibles() + 1);
			gestEmprunts_.retirerElement(*it);
			delete *it;
			return true;
		}
	}
	return retourEffectue;
}


// La méthode trierEmprunt () qui prend en paramètre un pointeur d’abonné et retourne une map, cette méthode doit chercher et trier les emprunts en ordre alphabétique selon les titres des objets empruntés.Elle utilise le foncteur MemeObjet.Cette méthode est appelée par la méthode infoAbonne().
map<string, Emprunt*> Bibliotheque::trierEmprunt(Abonne * abonne) const 
{
	map<string, Emprunt*> mapRetour;

	string  matricule = abonne->obtenirMatricule();
	MemeObjet<Emprunt, string> memeAbonne(&matricule);
	list<Emprunt*> listeDEmprunt = gestEmprunts_.trouverContenu(memeAbonne);

	for (list<Emprunt*>::iterator it = listeDEmprunt.begin(); it != listeDEmprunt.end(); it++)
	{
		mapRetour.insert(mapRetour.begin(), pair<string, Emprunt*>((*it)->obtenirObjetEmpruntable()->obtenirTitre(), *it));
	}

	return mapRetour;
}



// La méthode infoAbonne() qui prend en paramètre un matricule d’abonné et affiche les informations qui le concerne en utilisant l’opérateur << approprié.
//	o Cette méthode doit déterminer de quelle sous - classe fait partie l’abonné (typeid).
//	o Une fois déterminé, la méthode doit faire un dynamic_cast<> pour obtenir un pointeur de la classe appropriée, dans le but d’appeler l’opérateur << .
//	o Finalement, la méthode doit afficher les emprunts retournés par la méthode trierEmprunt().
void Bibliotheque::infoAbonne(const std::string& matricule) const 
{
		//On doit vérifier que tous les vecteurs sont parcourus
		Abonne* ptrAbonne = trouverAbonne(matricule);

		if (ptrAbonne != nullptr)
		{
			// Utilisez dynamic_cast<>()  pour convertir les types de pointeurs et appeler le bon opérateur <<
			string typeClasse = ptrAbonne->obtenirNomClasse();
			if (typeClasse == typeid(EtudiantBaccalaureat).name())
			{
				cout << *dynamic_cast<const EtudiantBaccalaureat*> (ptrAbonne);
			}
			else if (typeClasse == typeid(Etudiant).name())
			{
				cout << *dynamic_cast<const Etudiant*> (ptrAbonne);
			}
			else if (typeClasse == typeid(Professeur).name())
			{
				cout << *dynamic_cast<const Professeur*> (ptrAbonne);
			}
			else if (typeClasse == typeid(Abonne).name())
			{
				cout << *dynamic_cast<const Abonne*> (ptrAbonne);
			}
		}
		else
		{
			cout << "Abonne - " << matricule << " - non trouve" << endl;
		}

		map<string, Emprunt*> mapEmprunt = trierEmprunt(ptrAbonne); 
		cout << "LISTE DE LIVRE : " << endl;
		int i = 1;
		for (map<string, Emprunt*>::iterator it = mapEmprunt.begin(); it != mapEmprunt.end(); it++) {
			cout << i << " - " << *it->second << endl; 
			i++;
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


