/****************************************************************************
* Fichier: Bibliotheque.cpp
* Auteur: PolySensei & Associates
* Date: 4 février 2016
* Mise a jour : 6 février 2016
* Description: Implémentation de la classe Bibliotheque
****************************************************************************/
#include <iostream>
#include <vector>
#include "Bibliotheque.h"

using namespace std;

/****************************************************************************
* Fonction:	Bibliotheque::Biliotheque
* Description: Constructeur par défaut
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
Bibliotheque::Bibliotheque()
{
	
}
/****************************************************************************
* Fonction:	Bibliotheque::~Biliotheque
* Description: Destructeur
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
Bibliotheque::~Bibliotheque()
{
	for (int unsigned i = 0; i < listeEmprunts_.size(); i++)
		delete listeEmprunts_[i];
}


/****************************************************************************
* Fonction:	Bibliotheque::estEmpruntable
* Description: Vérifie si les conditions de bases sont respectées pour qu'un livre soit empruntable
* Paramètres:	const Abonne & abonne,  l'abonné désirant faire l'emprunt.
*				const Livre & livre,	le livre a emprunter.
* Retour:		un booléen qui est true si c'est empruntable et false en cas contraire.
****************************************************************************/
bool Bibliotheque::estEmpruntable(const Abonne & abonne, const Livre & livre) const
{	// Vérifie si les conditions de bases sont respectées
	return (
		(livre.obtenirNbDisponibles() >= 1) &&
		(abonne.obtenirAge() >= livre.obtenirAgeMinimal()) &&
		(!(abonne.estEmprunte(livre))));
}

/****************************************************************************
* Fonction:	Bibliotheque::trouverAbonne
* Description: Cherche un abonne a l aide de son matricule
* Paramètres:	std::string const unMatricule: matricule de l abonne
* Retour:		Abonne* ptrAbonne, un pointeur vers l'abonné si l'abonné est trouvé,
*				sinon un pointeur nul 
****************************************************************************/
Abonne* Bibliotheque::trouverAbonne(std::string const unMatricule) const{
	Abonne* ptrAbonne = nullptr;
	for (int unsigned i = 0; i < listeAbonnes_.size(); i++){
		if (listeAbonnes_[i]->obtenirMatricule() == unMatricule)
			ptrAbonne = listeAbonnes_[i];
	}
	return ptrAbonne;
}

/****************************************************************************
* Fonction:	Bibliotheque::trouverLivre
* Description: Cherche un livre a l aide de sa cote
* Paramètres:	std::string const unCote: Cote d un livre
* Retour:		Livre* ptrLivre, Un pointeur nul si le livre n est pas trouve ou un pointeur pointant au livre.
****************************************************************************/
Livre* Bibliotheque::trouverLivre(std::string const unCote) const{
	Livre* ptrLivre = nullptr;
	for (int unsigned i = 0; i < listeLivres_.size(); i++){
		if (listeLivres_[i]->obtenirCote() == unCote)
			ptrLivre = listeLivres_[i];
	}
	return ptrLivre;
}


/****************************************************************************
* Fonction:	Bibliotheque::ajouterAbonne
* Description: Ajouter l’abonné reçu en paramètre, seulement s’il n’est pas déjà dans le vecteur.
* Paramètres:	Abonne& unAbonne, l'abonné à ajouter
* Retour:		aucun
****************************************************************************/
void Bibliotheque::ajouterAbonne(Abonne& unAbonne){
	if (trouverAbonne(unAbonne.obtenirMatricule()) == nullptr)
		listeAbonnes_.push_back(&unAbonne);
}


/****************************************************************************
* Fonction:	Bibliotheque::retirerAbonne
* Description:	Permet de retirer l’abonné en utilisant le matricule reçu en paramètre. 
*				Avant de le retirer, il faut retourner tous les livres qu’il possède en appelant la méthode appropriée.
* Paramètres:	std::string const unMatricule, le matricule de l'abonné a retirer.
* Retour:		aucun
****************************************************************************/
void Bibliotheque::retirerAbonne(std::string const unMatricule){

	Abonne* ptrAbonne = trouverAbonne(unMatricule);

	//Retourne les livres de l'abonné.
	for (int unsigned i = 0; i < ptrAbonne->obtenirListeEmprunt().size(); i++){
		retourner(unMatricule, ptrAbonne->obtenirListeEmprunt()[i]->obtenirLivre()->obtenirCote());
	}
	//Retire l'abonné.
	for (int unsigned i = 0; i < listeAbonnes_.size(); i++){
		if (listeAbonnes_[i]->obtenirMatricule() == unMatricule){
			listeAbonnes_[i] = listeAbonnes_[listeAbonnes_.size()-1];
			listeAbonnes_.pop_back();
		}
	}
}


/****************************************************************************
* Fonction:	Bibliotheque::ajouterLivre
* Description:	Ajouter le livre reçu en paramètre seulement s’il n’est pas déjà dans le vecteur
* Paramètres:	Livre& unLivre, Le livre a ajouter.
* Retour:		aucun
****************************************************************************/
void Bibliotheque::ajouterLivre(Livre& unLivre){
	if (trouverLivre(unLivre.obtenirCote()) == nullptr)
		listeLivres_.push_back(&unLivre);
}


/****************************************************************************
* Fonction:	Bibliotheque::retirerLivre
* Description:	Retirer le livre en utilisant la cote reçue en paramètre. Le livre est retiré seulement s’il n’est pas emprunté.
* Paramètres:	std::string const uneCote,  la cote du livre a retirer
* Retour:		retourne un booléen true si le livre est retiré, sinon false.
****************************************************************************/
bool Bibliotheque::retirerLivre(std::string const uneCote){
	bool estEmprunte = false;

	//Vérifier si le livre est emprunté.
	for (int unsigned i = 0; i < listeEmprunts_.size(); i++){
		if (*listeEmprunts_[i]->obtenirLivre() == uneCote)
			estEmprunte = true;
			return false; //On ne peut retirer le livre.
	}
	if (!estEmprunte){
		//Trouver le livre dans la listes.
		for (int unsigned i = 0; i < listeLivres_.size(); i++){
			if (listeLivres_[i]->obtenirCote() == uneCote){
				listeLivres_[i] = listeLivres_[listeLivres_.size() - 1];
				listeLivres_.pop_back();
				return true;
			}	
		}
	}
	return false;
}


/*La méthode rechercherLivre() qui prend en paramètre une chaîne de caractères(string),
oCette méthode va rechercher les livres qui contiennent l’information désirée en utilisant la 
	méthode appropriée de la classe Livre.Pour chaque livre trouvé les informations seront affichées 
	à l’aide de l’opérateur << de la classe Livre.
o Si aucun livre n’est trouvé, affichez un message.*/
void Bibliotheque::rechercherLivre(const std::string chaineCaracteres) const{

	cout << "Recherche pour le mot : "<< chaineCaracteres << endl;

	bool estTrouve = false;
	for (int unsigned i = 0; i < listeLivres_.size(); i++){
		if (listeLivres_[i]->recherche(chaineCaracteres)){
			estTrouve = true;
			cout << *listeLivres_[i] << endl;
		}
	}
	if (!estTrouve)
		cout << "Aucun Resultat Trouve :(" << endl;
}



/*La méthode emprunter() qui prend en paramètres le matricule d’un abonné, la cote d’un livre et la date de retour.Cette méthode doit retourner une valeur booléenne indiquant si l’emprunt a été fait ou non.
o Elle doit aussi appeler la méthode estEmpruntable().
o Elle doit s’assurer que le nombre d’emprunts ne dépasse pas la limite de 2 par abonné.
o Elle doit diminuer le nombre de livres disponibles.*/
bool Bibliotheque::emprunter(const std::string unMatricule, const std::string uneCote, unsigned int dateRetour){
	Abonne* ptrAbonne = trouverAbonne(unMatricule);
	Livre* ptrLivre = trouverLivre(uneCote);
	
	if (estEmpruntable(*ptrAbonne, *ptrLivre)){
		if (ptrAbonne->obtenirListeEmprunt().size() < LIMITE_EMPRUNTS){
			Emprunt* nouveauEmprunt = new Emprunt(unMatricule, ptrLivre, dateRetour);
			listeEmprunts_.push_back(nouveauEmprunt);
			ptrAbonne->ajouterEmprunt(nouveauEmprunt);
			ptrLivre->modifierNbDisponibles(ptrLivre->obtenirNbDisponibles() - 1);
			return true;
		}
	}
	return false;
}


/*La méthode retourner() qui prend en paramètres le matricule d’un abonné et la cote d’un livre.Si l’abonné avait bien emprunté ce livre, l’emprunt en question est retiré du vecteur d’emprunts.
o Cette méthode doit retourner une valeur booléenne indiquant si le retour a été fait ou non.
o Elle doit aussi appeler la méthode retirerEmprunt() de la classe Abonne.
o N'oubliez pas de retirer l'emprunt du vecteur d'emprunts de la Bibliothèque.
o Elle doit augmenter le nombre de livres disponibles.*/
bool Bibliotheque::retourner(const std::string matricule, const std::string cote){

	Abonne* ptrAbonne = trouverAbonne(matricule);
	Livre* ptrLivre = trouverLivre(cote);

	//Vérifie si l'abonné a bel et bien le livre et retire le livre de sa liste d'emprunts si c'est le cas.
	if (ptrAbonne->retirerEmprunt(*ptrLivre)){

		//Pour retourner le livre à la bibliotheque,
		//Allons scruter le tableau d'Emprunt
		for (int unsigned i = 0; i < listeEmprunts_.size(); i++){

			//lorsqu'on trouve l'emprunt 
			if ((listeEmprunts_[i]->obtenirLivre() == ptrLivre) &&(listeEmprunts_[i]->obtenirMatricule() == matricule)){

				//Ajouter une disponibilité et enlever l'emprunt de la liste
				ptrLivre->modifierNbDisponibles(ptrLivre->obtenirNbDisponibles() + 1);
				delete listeEmprunts_[i];
				listeEmprunts_[i] = listeEmprunts_[listeEmprunts_.size() - 1];
				listeEmprunts_.pop_back();
				return true;
			}
		}
	}

	return false;
}


//La méthode infoAbonne() qui prend en paramètre un matricule d’abonné et affiche les informations qui le concerne en utilisant l’opérateur << approprié
void Bibliotheque::infoAbonne(const std::string matricule) const{
	Abonne* ptrAbonne = trouverAbonne(matricule);
	if (ptrAbonne == nullptr)
		cout << endl << "Abonne - " << matricule << " - non trouve" << endl;
	else
		cout << *ptrAbonne;
}

//Un opérateur >> qui permet d’entrer un mot - clé à chercher, puis qui appelle la méthode rechercherLivre().
void operator>>(istream& entre, Bibliotheque& uneBibliotheque){
	string chaineCaracteres = "";
	entre >> chaineCaracteres;
	uneBibliotheque.rechercherLivre(chaineCaracteres);
}

//L’opérateur += qui prend en paramètre un pointeur Abonne. Son comportement est similaire à ajouterAbonne().
void Bibliotheque::operator+=(Abonne* ptrAbonne){
	ajouterAbonne(*ptrAbonne);
}

//L’opérateur += qui prend en paramètre un pointeur Livre. Son comportement est similaire à ajouterLivre().
void Bibliotheque::operator+=(Livre* ptrLivre){
	ajouterLivre(*ptrLivre);
}

//L’opérateur -= qui prend en paramètre un pointeur Abonne. Son comportement est similaire à retirerAbonne().
void Bibliotheque::operator-=(Abonne* ptrAbonne){
	retirerAbonne(ptrAbonne->obtenirMatricule());
}

//L’opérateur -= qui prend en paramètre un pointeur Livre. Son comportement est similaire à retirerLivre().
void Bibliotheque::operator-=(Livre* ptrLivre){
	retirerLivre(ptrLivre->obtenirCote());
}
