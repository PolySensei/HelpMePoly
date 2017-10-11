/****************************************************************************
* Fichier: Bibliotheque.cpp
* Auteur: PolySensei & Associates
* Date: 11 février 2016
* Mise a jour : 19 février 2016
* Description: Implémentation de la classe Bibliotheque
****************************************************************************/


#include <iostream>
#include <vector>
#include "Bibliotheque.h"

using namespace std;

// Un constructeur par défaut.
Bibliotheque::Bibliotheque()
{

}

// Un destructeur.
Bibliotheque::~Bibliotheque()
{
	while (!vecEmprunts_.empty()){
		delete vecEmprunts_.back();
		vecEmprunts_.pop_back();
	}
}

// Une méthode trouveAbonne() qui prend un matricule (string) en paramètre, recherche
// dans le vecteur d’abonnés et retourne un pointeur Abonne associé à ce matricule.Si
// aucun abonné n’est retrouvé, un pointeur nul est retourné.
Abonne* Bibliotheque::trouveAbonne(const std::string& unMatricule) const{
	Abonne* ptrAbonne = nullptr;
	for (int unsigned i = 0; i < vecAbonnes_.size(); i++){
		if (vecAbonnes_[i]->obtenirMatricule() == unMatricule)
			ptrAbonne = vecAbonnes_[i];
	}
	return ptrAbonne;
}

// Une méthode trouverObjetEmpruntable() qui prend une cote (string) en paramètre,
// recherche l’objet empruntable et retourne un pointeur de type ObjetEmpruntable.Si
// aucun objet empruntable n’est retrouvé, un pointeur nul est retourné sinon.
ObjetEmpruntable* Bibliotheque::trouverObjetEmpruntable(const std::string& unCote) const{

	ObjetEmpruntable* ptrObjetEmpruntable = nullptr;

	//recherche dans la liste de livres
	for (int unsigned i = 0; i < vecLivres_.size(); i++){
		if (vecLivres_[i]->obtenirCote() == unCote)
			ptrObjetEmpruntable = vecLivres_[i];
	}
	//recherche dans la liste de DVD
	if (ptrObjetEmpruntable == nullptr){
		for (int unsigned i = 0; i < vecDVD_.size(); i++){
			if (vecDVD_[i]->obtenirCote() == unCote)
				ptrObjetEmpruntable = vecDVD_[i];
		}
	}
	return ptrObjetEmpruntable;

}


// Une méthode obtenirClasseObjet() qui prend une cote(string) en paramètre, et renvoie
// le nom de la classe correspondant à l’objet ayant cette cote(« Livre », « DVD »).
string Bibliotheque::obtenirClasseObjet(const std::string& unCote) const{
	string typeObjet = "";

	//Si la cote correspond a un DVD
	for (int unsigned i = 0; i < vecDVD_.size(); i++){
		if (vecDVD_[i]->obtenirCote() == unCote)
			typeObjet = "DVD";
	}

	//Si la cote correspond a un livre
	for (int unsigned i = 0; i < vecLivres_.size(); i++){
		if (vecLivres_[i]->obtenirCote() == unCote)
			typeObjet = "Livre";

	}
	
	return typeObjet;
}


// Une méthode ajouterAbonne() qui permet d’ajouter l’abonné reçu en paramètre,
// seulement s’il n’est pas déjà dans le vecteur.Si l’ajout a été fait, la méthode renvoie
// true, false sinon.
bool Bibliotheque::ajouterAbonne(Abonne& unAbonne){
	bool estAjoute = false;
	if (trouveAbonne(unAbonne.obtenirMatricule()) == nullptr){
		vecAbonnes_.push_back(&unAbonne);
		estAjoute = true;
	}
	return estAjoute;
}




// La méthode retirerAbonne() qui permet de retirer l’abonné en utilisant le matricule reçu
// en paramètre.Avant de le retirer, il faut retourner tous les éléments que l’abonné a
// emprunté en appelant la méthode appropriée.Si le retrait a été fait, la méthode renvoie
// true, false sinon.
bool Bibliotheque::retirerAbonne(const std::string & unMatricule){

	bool estRetire = false;
	Abonne* ptrAbonne = trouveAbonne(unMatricule);

	//Retourne l'objet emprunté de l'abonné.
	for (int unsigned i = 0; i < ptrAbonne->obtenirEmprunts().size(); i++){
		retourner(unMatricule, ptrAbonne->obtenirEmprunts()[i]->obtenirObjetEmpruntable()->obtenirCote());
	}
	//Retire l'abonné.
	for (int unsigned i = 0; i < vecAbonnes_.size(); i++){
		if (vecAbonnes_[i]->obtenirMatricule() == unMatricule){
			vecAbonnes_[i] = vecAbonnes_[vecAbonnes_.size() - 1];
			vecAbonnes_.pop_back();
			estRetire = true;
		}
	}
	return estRetire;
}


// La méthode ajouterLivre() qui permet d’ajouter le Livre reçu en paramètre seulement s’il
// n’est pas déjà dans le vecteur.Si l’ajout a été fait, la méthode renvoie true, false sinon.
bool Bibliotheque::ajouterLivre(Livre& unLivre){
	bool estAjoute = false;
	if (trouverObjetEmpruntable(unLivre.obtenirCote()) == nullptr){ //on regarde si le livre n est pas deja dans la bibliotheque
		vecLivres_.push_back(&unLivre);
		estAjoute = true;
	}
	return estAjoute;
}

// La méthode ajouterDVD() qui permet d’ajouter le DVD reçu en paramètre seulement s’il
// n’est pas déjà dans le vecteur.Si l’ajout a été fait, la méthode renvoie true, false sinon.
bool Bibliotheque::ajouterDVD(Dvd& unDVD){
	bool estAjoute = false;
	if (trouverObjetEmpruntable(unDVD.obtenirCote()) == nullptr){ //on regarde si le DVD n est pas deja dans la bibliotheque
		vecDVD_.push_back(&unDVD);
		estAjoute = true;
	}
	return estAjoute;
}


// La méthode retirerObjetEmpruntable() qui permet de retirer l’objet empruntable en
// utilisant la cote reçue en paramètre.Il est retiré seulement s’il n’est pas emprunté.La
// méthode retourne donc un booléen true s’il est retiré, sinon false.
bool Bibliotheque::retirerObjetEmpruntable(const std::string& uneCote){

	bool estEmprunte = false;
	string typeObjet = obtenirClasseObjet(uneCote);

	//Vérifier si l'objet est emprunté.
	for (int unsigned i = 0; i < vecEmprunts_.size(); i++){
		if (*vecEmprunts_[i]->obtenirObjetEmpruntable() == uneCote)
			estEmprunte = true;
		return false; //On ne peut retirer l'objet.
	}
	if (!estEmprunte){
		//S'il s'agit d'un livre
		if (typeObjet == "Livre"){
			//Trouver l'objet dans le vecteur de Livres et le retirer.
			for (int unsigned i = 0; i < vecLivres_.size(); i++){
				if (vecLivres_[i]->obtenirCote() == uneCote){
					vecLivres_[i] = vecLivres_[vecLivres_.size() - 1];
					vecLivres_.pop_back();
					return true;
				}
			}
		}
		//S'il s'agit d'un DVD
		if (typeObjet == "DVD"){
			//Trouver l'objet dans le vecteur de DVD et le retirer.
			for (int unsigned i = 0; i < vecDVD_.size(); i++){
				if (vecDVD_[i]->obtenirCote() == uneCote){
					vecDVD_[i] = vecDVD_[vecDVD_.size() - 1];
					vecDVD_.pop_back();
					return true;
				}
			}
		}
	}
	return false;
}


// La méthode rechercher() qui prend en paramètre une chaîne de caractères (string),
//		o	Cette méthode va rechercher les différents éléments empruntables de la bibliothèque qui contiennent 
//			l’information désirée en utilisant la méthode appropriée de la classe.Pour chaque élément trouvé les 
//			informations seront affichées à l’aide de l’opérateur << de la classe appropriée.
//		o	N’oubliez pas de parcourir tous les éléments qui peuvent être empruntés
//		o	Si aucun rien n’a été trouvé, affichez un message.
void Bibliotheque::rechercher(const std::string& chaineCaracteres) const {

	cout << "Recherche pour le mot : " << chaineCaracteres << endl;

	bool estTrouve = false;

	//correspondance avec un livre
	for (int unsigned i = 0; i < vecLivres_.size(); i++){
		if (vecLivres_[i]->recherche(chaineCaracteres)){
			estTrouve = true;
			cout << *vecLivres_[i];
		}
	}

	//correspondance avec un DVD
	for (int unsigned i = 0; i < vecDVD_.size(); i++){
		if (vecDVD_[i]->recherche(chaineCaracteres)){
			estTrouve = true;
			cout << *vecDVD_[i];
		}
	}

	//message si aucune correspondance
	if (!estTrouve)
		cout << "Aucun Resultat Trouve :(" << endl;
}


// Une méthode estEmpruntable() qui prend en paramètre un matricule et un objet empruntable.
//	o	Cette méthode vérifie s’il est possible pour l’abonné d’effectuer l’emprunt en question.
//		Il est possible pour un abonné d’emprunter un objet empruntable si ce dernier est disponible, 
//		qu’il a l’âge minimal requis, qu’il n’a pas déjà emprunté celui - ci et que sa limite 
//		d’emprunts n’est pas encore atteinte
//	o	Cette méthode doit retourner une valeur booléenne indiquant si l’emprunt est possible ou non.
bool Bibliotheque::estEmpruntable(const string & matricule, const ObjetEmpruntable & objetEmpruntable) const {

	Abonne* ptrAbonne = trouveAbonne(matricule);
	return (
		(objetEmpruntable.obtenirNbDisponibles() >= 1) &&
		(ptrAbonne->obtenirAge() >= objetEmpruntable.obtenirAgeMinimal()) &&
		(!(ptrAbonne->estEmprunte(objetEmpruntable.obtenirCote()))) &&
		(ptrAbonne->obtenirEmprunts().size() < ptrAbonne->obtenirLimiteEmprunts()));
}


// La méthode emprunter() qui prend en paramètres le matricule d’un abonné, la cote d’un objet empruntable 
// et la date de retour associée en fonction du statut de l’abonné.Cette méthode doit retourner une valeur 
// booléenne indiquant si l’emprunt a été fait ou non.
//	o	Elle doit s’assurer que le nombre d’emprunts ne dépasse pas la limite par type d’abonné.
//	o	Elle doit diminuer le nombre d’objets associés disponibles.
//	o	Indice : Utilisez la méthode obtenirClasseObjet pour prendre en compte la bonne classe de l’objet emprunté
bool Bibliotheque::emprunter(const std::string& unMatricule, const std::string uneCote, unsigned int dateRetour){

	Abonne* ptrAbonne = trouveAbonne(unMatricule);
	ObjetEmpruntable* ptrObjet = trouverObjetEmpruntable(uneCote);
	string typeObjet = obtenirClasseObjet(uneCote);

	if (estEmpruntable(unMatricule, *ptrObjet)){
		
		Emprunt* nouveauEmprunt;

		if (typeObjet == "Livre"){
			for (unsigned int i = 0; i < vecLivres_.size(); i++){
				if (vecLivres_[i]->obtenirCote() == uneCote)
					nouveauEmprunt = new Emprunt(unMatricule, vecLivres_[i], dateRetour);
			}
		}

		if (typeObjet == "DVD"){
			for (unsigned int i = 0; i < vecDVD_.size(); i++){
				if (vecDVD_[i]->obtenirCote() == uneCote){
					nouveauEmprunt = new Emprunt(unMatricule, vecDVD_[i], dateRetour);
				}
			}
		}

		vecEmprunts_.push_back(nouveauEmprunt);
		ptrAbonne->ajouterEmprunt(nouveauEmprunt);
		ptrObjet->modifierNbDisponibles(ptrObjet->obtenirNbDisponibles() - 1);
		return true;
	}

	return false;
}


// La méthode retourner() qui prend en paramètres le matricule d’un abonné et la cote d’un objet empruntable.
// Si l’abonné avait bien emprunté cet élément, l’emprunt en question est retiré du vecteur d’emprunts.
//	o	Cette méthode doit retourner une valeur booléenne indiquant si le retour a été fait ou non.
//	o	Elle doit augmenter le nombre d’objets empruntables disponibles.
bool Bibliotheque::retourner(const std::string & matricule, const std::string & cote){

	Abonne* ptrAbonne = trouveAbonne(matricule);
	ObjetEmpruntable* ptrObjet = trouverObjetEmpruntable(cote);


	//Vérifie si l'abonné a bel et bien l'objetEmpruntable et retire celui-ci de sa liste d'emprunts si c'est le cas.
	if (ptrAbonne->retirerEmprunt(*ptrObjet)){

		//Pour retourner l'objetEmpruntable à la bibliotheque,
		//Allons scruter le tableau d'Emprunt
		for (int unsigned i = 0; i < vecEmprunts_.size(); i++){

			//lorsqu'on trouve l'emprunt 
			if ((vecEmprunts_[i]->obtenirObjetEmpruntable() == ptrObjet) && (vecEmprunts_[i]->obtenirMatricule() == matricule)){

				//Ajouter une disponibilité et enlever l'emprunt de la liste
				ptrObjet->modifierNbDisponibles(ptrObjet->obtenirNbDisponibles() + 1);
				delete vecEmprunts_[i];
				vecEmprunts_[i] = vecEmprunts_[vecEmprunts_.size() - 1];
				vecEmprunts_.pop_back();
				return true;
			}
		}
	}

	return false;
}


// La méthode infoAbonne() qui prend en paramètre un matricule d’abonné et affiche les 
// informations qui le concerne en utilisant l’opérateur << approprié.
void Bibliotheque::infoAbonne(const std::string & matricule) const{
	Abonne* ptrAbonne = trouveAbonne(matricule);
	if (ptrAbonne == nullptr)
		cout << "Abonne - " << matricule << " - non trouve" << endl; //l abonne n existe pas
	else
		cout << *ptrAbonne;
}

// Un opérateur >> qui permet d’entrer un mot-clé à chercher, puis qui appelle la méthode rechercher().
istream& operator>>(istream& in, Bibliotheque& uneBibliotheque){
	string chaineCaracteres = "";
	in >> chaineCaracteres;
	uneBibliotheque.rechercher(chaineCaracteres);
	return in;
}

// L’opérateur += qui est défini 3 fois, avec un paramètre d’entrée différent :
//	o	Une définition pour chaque type d’abonné qui prend en paramètre un pointeur 
//		de la classe correspondante. Son comportement est similaire à ajouterAbonne().
Bibliotheque& Bibliotheque::operator+=(Abonne* ptrAbonne){
	ajouterAbonne(*ptrAbonne);
	return *this;
}

Bibliotheque& Bibliotheque::operator+=(Etudiant* ptrEtudiant){
	ajouterAbonne(*ptrEtudiant);
	return *this;
}

Bibliotheque& Bibliotheque::operator+=(EtudiantBaccalaureat* ptrEtudiantBaccalaureat){
	ajouterAbonne(*ptrEtudiantBaccalaureat);
	return *this;
}

Bibliotheque& Bibliotheque::operator+=(Professeur* ptrProfesseur){
	ajouterAbonne(*ptrProfesseur);
	return *this;
}

// L’opérateur += qui est défini 3 fois, avec un paramètre d’entrée différent :
//	o	L’autre définition prend en paramètre un pointeur Livre.Son comportement est similaire à ajouterLivre().
Bibliotheque& Bibliotheque::operator+=(Livre* ptrLivre){
	ajouterLivre(*ptrLivre);
	return *this;
}

// L’opérateur += qui est défini 3 fois, avec un paramètre d’entrée différent :
//	o	L’autre définition prend en paramètre un pointeur DVD.Son comportement est similaire à ajouterDVD().
Bibliotheque& Bibliotheque::operator+=(Dvd* ptrDVD){
	ajouterDVD(*ptrDVD);
	return *this;
}


// L’opérateur -= qui est défini 2 fois, avec un paramètre d’entrée différent
//	o	Une définition prend en paramètre un pointeur Abonne. Son comportement est similaire à retirerAbonne().
Bibliotheque& Bibliotheque::operator-=(Abonne* ptrAbonne){
	retirerAbonne(ptrAbonne->obtenirMatricule());
	return *this;
}

// L’opérateur -= qui est défini 2 fois, avec un paramètre d’entrée différent
//	o	L’autre définition prend en paramètre un pointeur ObjetEmpruntable. Son comportement est similaire à retirerObjetEmpruntable().
Bibliotheque& Bibliotheque::operator-=(ObjetEmpruntable* ptrObjet){
	retirerObjetEmpruntable(ptrObjet->obtenirCote());
	return *this;
}
