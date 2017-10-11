/****************************************************************************
* Fichier: Emprunt.cpp
* Auteur: PolySensei & Associates
* Date: 11 février 2016
* Mise a jour : 21 février 2016
* Description: Implémentation de la classe Emprunt
****************************************************************************/
#include <iostream>
#include "Emprunt.h"
#include "Abonne.h"

using namespace std;

Emprunt::Emprunt(){
}


//Constructeur par paramètre pour un livre initialisant un pointeur nullptr a dvd_
Emprunt::Emprunt(const std::string& matricule, Livre* livre, unsigned int dateRetour)
	: matricule_(matricule), livre_(livre), dateRetour_(dateRetour), dvd_(nullptr)
{
}

//Constructeur par paramètre pour un livre initialisant un pointeur nullptr a livre_
Emprunt::Emprunt(const std::string& matricule, Dvd* dvd, unsigned int dateRetour)
	: matricule_(matricule), dvd_(dvd), dateRetour_(dateRetour), livre_(nullptr)
{
}

Emprunt::~Emprunt()
{

}

string Emprunt::obtenirMatricule() const
{
	return matricule_;
}

Livre* Emprunt::obtenirLivre() const
{
	return livre_;
}

unsigned int Emprunt::obtenirDateRetour() const
{
	return dateRetour_;
}


void Emprunt::modifierMatricule(const string &matricule)
{
	matricule_ = matricule;
}

void Emprunt::modifierLivre(Livre* livre)
{
	livre_ = livre;
}


void Emprunt::modifierDateRetour(unsigned int date)
{
	dateRetour_ = date;
}


// Les méthodes d’accès et de modification des nouveaux attributs : obtenirDVD(), modifierDVD().
Dvd* Emprunt::obtenirDVD() const{
	return dvd_;
}

void Emprunt::modifierDVD(Dvd *dvd){
	dvd_ = dvd;
}



// Une redéfinition de la méthode obtenirLivre() en obtenirObjetEmpruntable() qui va
// renvoyer le pointeur non nul s’il y a, le pointeur nul sinon
ObjetEmpruntable* Emprunt::obtenirObjetEmpruntable() const{

	ObjetEmpruntable* ptrObjet = nullptr;

	if (livre_ != nullptr)
		ptrObjet = livre_;
	else if (dvd_ != nullptr)
		ptrObjet = dvd_;

	return ptrObjet;
}


// Un opérateur <<, qui affiche le matricule de l’abonné, puis appelle l’opérateur << de
// l’objet empruntable approprié; tel que présenté dans l’exemple à la fin du document.
ostream& operator<<(ostream& out, const Emprunt& emprunt){

	out << "Usager #" << emprunt.matricule_;

	if (emprunt.livre_ == nullptr){  //Si nous n'avons pas de livre, il s'agit d'un DVD
		out << ". DVD " << *emprunt.dvd_;
	}
	else if (emprunt.dvd_ == nullptr){
		out << ". Livre " << *emprunt.livre_;
	} 

		out << "Retour prevu : " << emprunt.dateRetour_ << endl;

	return out;
}
