/****************************************************************************
* Fichier: Emprunt.cpp
* Auteur: PolySensei & Associates
* Date: 6 mars 2016
* Mise a jour : 28 mars 2016
* Description: Implémentation de la classe Emprunt
****************************************************************************/
#include <iostream>
#include "Emprunt.h"

using namespace std;


Emprunt::~Emprunt()
{

}

string Emprunt::obtenirMatricule() const
{
	return matricule_;
}



unsigned int Emprunt::obtenirDateRetour() const
{
	return dateRetour_;
}

void Emprunt::modifierMatricule(const string &matricule)
{
	matricule_ = matricule;
}

void Emprunt::modifierDateRetour(unsigned int date)
{
	dateRetour_ = date;
}


/// TP4
Emprunt::Emprunt(std::string matricule, ObjetEmpruntable * objEmprunt, unsigned int date)
	: matricule_(matricule), objEmprunt_(objEmprunt), dateRetour_(date)
{
}

ObjetEmpruntable * Emprunt::obtenirObjetEmpruntable() const
{
	return objEmprunt_;
}



bool Emprunt::operator==(const Emprunt& emprunt) const {
	return ((matricule_ == emprunt.matricule_) &&
		(*objEmprunt_ == *emprunt.objEmprunt_) &&
		(dateRetour_ == emprunt.dateRetour_));
};
bool Emprunt::operator==(const std::string& str) const
{
	return ((matricule_ == str) || (*objEmprunt_ == str));
}
bool Emprunt::operator==(const  pair<std::string, std::string>& pair) const
{
	return ((matricule_ == pair.first) && (objEmprunt_->obtenirCote() == pair.second));
}
bool operator==(const std::string& str, const Emprunt& emprunt)
{
	return (emprunt == str);
}
bool operator==(const  pair<string, string>& pair, const Emprunt& emprunt)
{
	return ((emprunt.obtenirMatricule() == pair.first) && (emprunt.obtenirObjetEmpruntable()->obtenirCote() == pair.second));
}

ostream & operator<<(std::ostream & o, const Emprunt & emprunt)
{	

	o << "Usager #" <<
		emprunt.matricule_;
	if (emprunt.objEmprunt_ != nullptr)
	{
		o << ". " << emprunt.objEmprunt_->obtenirNomClasse() << ". ";
	}
	emprunt.objEmprunt_->afficherObjetEmpruntable(o);
	o <<
		"Retour prevu : " << emprunt.dateRetour_ <<
		endl;

	return o;
}
