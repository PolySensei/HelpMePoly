/****************************************************************************
* Fichier: Abonne.cpp
* Auteur: PolySensei & Associates
* Date: 4 février 2016
* Mise a jour : 6 février 2016
* Description: Implémentation de la classe Abonne
****************************************************************************/
#include <iostream>
#include <string>
#include "Abonne.h"
using namespace std;

/****************************************************************************
* Fonction:	Abonne::Abonne
* Description: Constructeur par défaut
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
Abonne::Abonne()
	:age_(0)
{
}

/****************************************************************************
* Fonction:	Abonne::Abonne
* Description: Constructeur par paramètres
* Paramètres:	- const string& matricule: valeur du matricule
*				- const string& nom: valeur du nom
*				- const string& prenom: valeur du prenom
*				- unsigned int age: valeur de l age
* Retour:		aucun
****************************************************************************/
Abonne::Abonne(const string& matricule, const string& nom, const string& prenom, unsigned int age)
	: matricule_(matricule), nom_(nom), prenom_(prenom), age_(age)
{
}

/****************************************************************************
* Fonction:	Abonne::~Abonne
* Description: Destructeur
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
Abonne::~Abonne()
{
}


string Abonne::obtenirMatricule() const
{
	return matricule_;
}

string Abonne::obtenirNom() const
{
	return nom_;
}

string Abonne::obtenirPrenom() const
{
	return prenom_;
}

unsigned int Abonne::obtenirAge() const
{
	return age_;
}

void Abonne::modifierMatricule(const string& matricule)
{
	matricule_ = matricule;
}

void Abonne::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Abonne::modifierPrenom(const string& prenom)
{
	prenom_ = prenom;
}

void Abonne::modifierAge(unsigned int age)
{
	age_ = age;
}


// _____________TP2__________________
vector<Emprunt*> Abonne::obtenirListeEmprunt() const{
	return listeEmprunt_;
}


int Abonne::obtenirNombreEmprunte() const{
	return listeEmprunt_.size();
}


/****************************************************************************
* Fonction:	Abonne::estEmprunte
* Description: Prend en paramètre un Livre et vérifie si l'abonné possède un emprunt de ce livre. 
* Paramètres:	const Livre& unLivre
* Retour:		Booléen qui true, si l’abonné possède un emprunt associé à ce livre, sinon false.
****************************************************************************/
bool Abonne::estEmprunte(const Livre& unLivre) const
{
	bool estEmprunt = false;
	for (unsigned int i = 0; i < listeEmprunt_.size(); i++){
		if (listeEmprunt_[i]->obtenirLivre() == &unLivre){ 
			estEmprunt = true;
		}
	}
	return estEmprunt;
}


/****************************************************************************
* Fonction:	Abonne::ajouterEmprunt
* Description: Ajout d'un emprunt a la fin du vecteur d'emprunt de l'abonné
* Paramètres:	Emprunt* unEmprunt: un emprunt
* Retour:		Aucun
****************************************************************************/
void Abonne::ajouterEmprunt(Emprunt* unEmprunt){
	listeEmprunt_.push_back(unEmprunt);
}

/****************************************************************************
* Fonction:	Abonne::retireremprunt
* Description: Retirer un emprunt dans le vecteur d emprunt de l'abonne
* Paramètres:	Livre& unLivre; un livre
* Retour:		Un booléen true si le livre est retirer sinon false
****************************************************************************/
bool Abonne::retirerEmprunt(Livre& unLivre){
	bool estRetire = false;
	for (unsigned int i = 0; i < listeEmprunt_.size(); i++){
		if (listeEmprunt_[i]->obtenirLivre() == &unLivre){	//S'assure que l'abonné avait bel et bien emprunté le livre.
			estRetire = true;
			listeEmprunt_[i] = listeEmprunt_[listeEmprunt_.size() - 1];
			listeEmprunt_.pop_back();
		}
	}
	return estRetire;
}


/****************************************************************************
* Fonction:	operator<<
* Description:	Surcharge de l’opérateur << (remplace la méthode d’affichage), 
*				qui affiche les informations qui concernent un Abonne, tel 
*				que présenté dans l’exemple à la fin de l'énoncé du TP.
* Paramètres:	ostream& out, le stream de sortie
*				const Abonne& unAbonne, l'Abonné à afficher
* Retour:		ostream& out, le stream de sortie
****************************************************************************/
ostream& operator<<(ostream& out, const Abonne& unAbonne){
	out << unAbonne.prenom_ << ", " << unAbonne.nom_ << ". " << unAbonne.age_ << " ans. #" << unAbonne.matricule_ << endl << "LISTE DE LIVRES :";
	for (int unsigned i = 0; i < unAbonne.listeEmprunt_.size(); i++){
		out << endl << (i + 1) << " - " << *unAbonne.listeEmprunt_[i] << endl;
	}
	return out;
}




//L’opérateur == qui prend un Abonne en paramètre et permet de comparer 2 abonnés en considérant à la fois le matricule, le Nom, le Prénom et l’âge. L’opérateur retourne true si les abonnés sont identiques, false sinon. Ainsi, cet opérateur va pouvoir faire l’opération abonne1 == abonne2.
bool Abonne::operator==(Abonne& abonne2) const{
	bool estEgal = false;

	if (matricule_ == abonne2.obtenirMatricule()){
		if (nom_ == abonne2.obtenirNom()){
			if (prenom_ == abonne2.obtenirPrenom()){
				if (age_ == abonne2.obtenirAge()){
					estEgal = true;
				}
			}
		}
	}
	return estEgal;
}


//L’opérateur == qui prend un matricule en paramètre et permet de comparer 2 abonnés en considérant seulement le matricule.L’opérateur retourne true si les matricules sont identiques, false sinon.Ainsi, cet opérateur va pouvoir faire l’opération abonne == matricule.
bool Abonne::operator==(std::string unMatricule) const{
	bool estEgal = false;
	if (matricule_ == unMatricule)
		estEgal = true;
	return estEgal;
}



//L’opérateur == de type friend qui permet d’inverser l’ordre de l’opérateur == précédent.Ainsi, cet opérateur va pouvoir faire l’opération matricule == abonne.
bool operator==(std::string unMatricule, Abonne& unAbonne){
	bool estEgal = false;
	if (unAbonne == unMatricule)
		estEgal = true;
	return estEgal;
}