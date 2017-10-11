/*
Fichier: Bibliotheque.h
Auteur(s): Mohamed Amine Kibiche
Date de creation:
Date de modification: 25 février 2016
Description:
*/

#include "Bibliotheque.h"
#include "MemeElement.h"
#include "RechercheObjetEmpruntable.h"
#include "Empruntable.h"
#include "DetruireEmprunt.h"
#include "TrieParTitre.h"
#include "Professeur.h"
#include "Etudiant.h"
#include "EtudiantBaccalaureat.h"

#include "ExceptionEchecRetour.h" // Ajouté pour la méthode retourner()
#include "ExceptionEchecEmprunt.h" // Ajouté pour la méthode emprunter()

#include <list>

using namespace std;


Bibliotheque::Bibliotheque()
{

}

Bibliotheque::~Bibliotheque()
{
			//gestEmprunts_.retirerContenu([](Emprunt* a) { delete a; return true; });
	DetruireEmprunt detruire;
	gestEmprunts_.retirerContenu(detruire);
}

list<Abonne*> Bibliotheque::obtenirListeAbonnes() const
{
    return gestAbonnes_.trouverContenu([](Abonne*){return true;});
}

list<Emprunt*> Bibliotheque::obtenirListeEmprunts() const
{
    return gestEmprunts_.trouverContenu([](Emprunt*){return true;});
}

list<ObjetEmpruntable*> Bibliotheque::obtenirListeObjets() const
{
    return gestObj_.trouverContenu([](ObjetEmpruntable*){return true;});
}

// Retourne l'abonné selon le matricule donné
Abonne* Bibliotheque::trouverAbonne(const string & matricule) const
{
			//return gestAbonnes_.trouverElement([matricule](Abonne* ab) {if (*ab == matricule) return true; return false; });
	MemeElement<Abonne, const string> trouve(&matricule);
	return gestAbonnes_.trouverElement(trouve);
}


// Retourne l'objet empruntable selon la cote donnée
ObjetEmpruntable* Bibliotheque::trouverObjetEmpruntable(const string& cote) const
{
			//return gestObj_.trouverElement([cote](ObjetEmpruntable* obj) {if (*obj == cote) return true; return false; });
	MemeElement<ObjetEmpruntable, const string> trouve(&cote);
	return gestObj_.trouverElement(trouve);
}

bool Bibliotheque::ajouterAbonne(Abonne& abonne)
{
	return gestAbonnes_.ajouterElement(&abonne);
}

bool Bibliotheque::retirerAbonne(const string& matricule)
{
			//return gestAbonnes_.retirerContenu([matricule](Abonne* ab) {if (*ab == matricule) return true; return false; });
	MemeElement<Emprunt, const string> trouve(&matricule);
	//trouver tous les emprunts de l'abonne
	list<Emprunt*> listLocal = gestEmprunts_.trouverContenu(trouve);
	// retourner ses emprunts
	for (list<Emprunt*>::iterator it = listLocal.begin(); it != listLocal.end(); it++)
		retourner(matricule, (*it)->obtenirObjetEmpruntable()->obtenirCote());
	//retirer l'abonne 
	Abonne* ab = trouverAbonne(matricule);
	return gestAbonnes_.retirerElement(ab);
}

bool Bibliotheque::ajouterObjetEmpruntable(ObjetEmpruntable* objet)
{
	return gestObj_.ajouterElement(objet);
}

bool Bibliotheque::retirerObjetEmpruntable(const string & cote)
{
			//return gestObj_.retirerContenu([cote](ObjetEmpruntable* obj) {if (*obj == cote) return true; return false; });
	MemeElement<Emprunt, const string> trouve(&cote);
	//verifier si l'objet n'est pas emprunté
	Emprunt* emprunt = gestEmprunts_.trouverElement(trouve);
	//on le retire si aucune exemplaire n'est empruntee 
	if (emprunt == nullptr) {
		ObjetEmpruntable* obj = trouverObjetEmpruntable(cote);
		return gestObj_.retirerElement(obj);
	}
	return false;
}

//recherche la chaine de mots parmi les attributs de type string de tous les classes de la famille ObjetEmpruntable
void Bibliotheque::rechercherObjetEmpruntable(const string& str) const
{
	cout << "Recherche pour le mot : " << str << endl;
			//list<ObjetEmpruntable*> listObj = gestObj_.trouverContenu([str](ObjetEmpruntable* obj) {return obj->recherche(str); });
	//creer le foncteur
	RechercheObjetEmpruntable recherche(str);
	//recherche parmi les objets empruntable à l'aide d'un prédicate
	list<ObjetEmpruntable*> listObj = gestObj_.trouverContenu(recherche);

	//creer un foncteur de trie
	TrieParTitre trie;
	//trier la liste des objetEmpruntable selon l'ordre aphabitique
	listObj.sort(trie);
			//Solution avec des lambdas
			//listObj.sort([](ObjetEmpruntable* a, ObjetEmpruntable* b) {if (a->obtenirTitre() < b->obtenirTitre()) return true; return false; });

	//Affciher les objets triés
	for (list<ObjetEmpruntable*>::iterator it = listObj.begin(); it != listObj.end(); it++)
		cout << (*(*it)) << endl;

	if (listObj.empty())
		cout << "Aucun Resultat Trouve :-(" << endl;

}

// Emprunte l'objet selon d'après sa cote pour la personne correspondant au matricule
void Bibliotheque::emprunter(const string& matricule, const string& cote, unsigned int date)
{
	//On doit vérifier que tous les vecteurs sont parcourus
	Abonne* ab = trouverAbonne(matricule);

	ObjetEmpruntable* obj = trouverObjetEmpruntable(cote);


    // On s'assure qu'il est possible d'emprunter l'objet

	///////////////////////////////////////////////////////////////
	//                    !!!!! A FAIRE !!!!!
	// Vérifier les conditions d'emprunts et lancer l'exception
	// appropriée avec le message approprié le cas échéant.
	///////////////////////////////////////////////////////////////


    //Exceptions de la méthode emprunter demandés
    if (ab == nullptr)
    {
        throw ExceptionEchecEmprunt("Abonné non trouve");
    }
    if (obj == nullptr)
    {
        throw ExceptionEchecEmprunt("Objet empruntable non trouve");
    }
    if(obj->obtenirNbDisponibles() == 0)
    {
        throw ExceptionEchecEmprunt("Aucun exemplaire disponible");
    }
    if (ab->obtenirAge() < obj->obtenirAgeMinimal())
    {
        throw ExceptionEchecEmprunt("L'abonne n'a pas l'âge minimal requis");
    }



    // vérifier si l'abonné à déjà emprunter l'objet ou s'il a atteint la limite d'emprunter
    unsigned int count = 0;
    bool estTrouve = false;
    Empruntable empruntable(matricule, cote, estTrouve, count);
    gestEmprunts_.trouverContenu(empruntable);
    
	///////////////////////////////////////////////////////////////
	//                    !!!!! A FAIRE !!!!!
	// Vérifier les que l'abonné n'a pas déjà emprunté cet objet
	// et qu'il n'a pas atteint sa limite d'emprunts. Lancer 
	// l'exception appropriée avec le message approprié le cas échéant.
	///////////////////////////////////////////////////////////////

	//Exceptions de la méthode emprunter demandés
    if (estTrouve == true)
    {
        throw ExceptionEchecEmprunt("L'abonne a deja emprunte cet objet");
    }
    if (count >= ab->obtenirLimiteEmprunt())
    {
        throw ExceptionEchecEmprunt("L'abonne a atteint sa limite d'emprunts");
    }

    //On ajoute l'emprunt
    Emprunt* nouvelEmprunt = new Emprunt(ab->obtenirMatricule(), obj, date);
    gestEmprunts_.ajouterElement(nouvelEmprunt);
    obj->modifierNbDisponibles(obj->obtenirNbDisponibles() - 1);
}

void Bibliotheque::retourner(const string& matricule, const string& cote)
{
    pair<string, string> paire(matricule, cote);
    MemeElement<Emprunt, pair<string, string>> trouve(&paire);

    // Chercher l'emprunt
    Emprunt* em = gestEmprunts_.trouverElement(trouve);


    ///////////////////////////////////////////////////////////////
    //                    !!!!! A FAIRE !!!!!
    // Lancer l'exception appropriée si l'emprunt n'est pas trouvé.
    ///////////////////////////////////////////////////////////////

   
	//Exception de la méthode retourner demandé
    if (em==nullptr)
    {
        throw ExceptionEchecRetour("Emprunt non trouve");
    }



    ObjetEmpruntable* obj = em->obtenirObjetEmpruntable();
    gestEmprunts_.retirerContenu(trouve);
    delete em;
    obj->modifierNbDisponibles(obj->obtenirNbDisponibles() + 1);
}

// Afficher l'information de l'abonné correspondant au matricule
void Bibliotheque::infoAbonne(const string& matricule) const
{
	//On doit vérifier que tous les vecteurs sont parcourus
	Abonne* ab = trouverAbonne(matricule);

	if (ab != nullptr)
	{
		if (ab->obtenirNomClasse() == typeid(Abonne).name())
		{
			cout << *ab;
		}
		else if (ab->obtenirNomClasse() == typeid(Etudiant).name())
		{
			Etudiant * et = dynamic_cast<Etudiant*>(ab);
			cout << *et;
		}
		else if (ab->obtenirNomClasse() == typeid(EtudiantBaccalaureat).name())
		{
			EtudiantBaccalaureat * etB = dynamic_cast<EtudiantBaccalaureat*>(ab);
			cout << *etB;
		}
		else if (ab->obtenirNomClasse() == typeid(Professeur).name())
		{
			Professeur * pro = dynamic_cast<Professeur*>(ab);
			cout << *pro;
		}

		cout << "LISTE DE LIVRES :" << endl;
		//appeler la fonction de trie
        map<string, Emprunt*> map = trierEmprunt(ab);
        int i = 0;
        //Afficher les Objets triés
        for each (pair<string, Emprunt*> paire in map)
            cout << ++i << " - " << (*paire.second) << endl;
    }
	else
	{
		cout << "Abonne - " << matricule << " - non trouve" << endl;
	}
}

map<string, Emprunt*> Bibliotheque::trierEmprunt(Abonne * abonne) const
{
	//creer un foncteur 
	string mat = abonne->obtenirMatricule();
	MemeElement<Emprunt, string> trouve(&mat);
	// trouver les emprunt de l'abonne
	list<Emprunt*> listEmp = gestEmprunts_.trouverContenu(trouve);

	map<string, Emprunt*> map;
	for (list<Emprunt*>::iterator it = listEmp.begin(); it != listEmp.end(); it++)
		map[(*it)->obtenirObjetEmpruntable()->obtenirTitre()] = (*it);

	return map;
}

// Retourne un string correspondant au nom de la classe selon la cote donnée
std::string Bibliotheque::obtenirClasseObjet(std::string const & cote) const
{
	ObjetEmpruntable* obj = trouverObjetEmpruntable(cote);
	
	if (obj != nullptr)
		return obj->obtenirNomClasse();
	return "";
}


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


