/****************************************************************************
* Fichier: Abonne.cpp
* Auteur: PolySensei & Associates
* Date: 22 février 2016
* Mise a jour : 3 mars 2016
* Description: Implémentation de la classe Abonne
****************************************************************************/
#include <iostream>
#include "Abonne.h"

using namespace std;

//Une méthode obtenirNomClasse() qui permet de retourner le nom de la classe d’un
//pointeur, qu’il soit de type Abonne ou de ses classes dérivés.

std::string Abonne::obtenirNomClasse() const
{
	if (this != nullptr)
	{
		return typeid(*this).name();
	}
	else
	{
		return "nullptr";
	}

}



Abonne::Abonne()
	:age_(0)
{

}

Abonne::Abonne(const std::string & matricule, const std::string & nom, const std::string & prenom, unsigned int age) 
	: matricule_(matricule), nom_(nom), prenom_(prenom), age_(age), limiteEmprunt_(LIMITE_EMPRUNTS)
{

}

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

std::vector<Emprunt*> Abonne::obtenirEmprunts() const
{
	return vecEmprunts_;
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


unsigned int Abonne::obtenirNombreEmprunte() const
{
	return vecEmprunts_.size();
}


ostream & operator<<(ostream & o, const Abonne & abonne)
{
	// Affichage des informations de base
	o << abonne.prenom_ << ", " <<
		abonne.nom_ << ". " <<
		abonne.age_ << " ans. #" <<
		abonne.matricule_ << endl;

	o << "LISTE DE LIVRES :" << endl;

	// Affichage de la liste de objetEmpruntables

	for (unsigned int i = 0; i < abonne.vecEmprunts_.size(); i++)
	{
		o << i + 1 << " - " << *(abonne.vecEmprunts_[i]) << endl;
	}

	return o;

}

bool Abonne::operator==(const Abonne & abonne) const
{
	return
		(matricule_ == abonne.matricule_) &&
		(nom_ == abonne.nom_) &&
		(prenom_ == abonne.prenom_) &&
		(age_ == abonne.age_);
}

bool Abonne::operator==(const std::string & matricule) const
{
	return matricule_ == matricule;
}

bool operator==(const std::string & matricule, const Abonne & abonne)
{
	return abonne == matricule;
}

/// _____________TP3__________________

bool Abonne::estEmprunte(const ObjetEmpruntable & objetEmpruntable) const
{
	// vérifier si le objetEmpruntable est déjà emprunté
	for (unsigned int i = 0; i < vecEmprunts_.size(); i++)
	{
		if ((*(vecEmprunts_[i]->obtenirObjEmprunt())) == objetEmpruntable)
		{
			return true;
		}
	}
	return false;
}

void Abonne::ajouterEmprunt(Emprunt * emprunt)
{
	vecEmprunts_.push_back(emprunt);
}

bool Abonne::retirerEmprunt(ObjetEmpruntable * objetEmpruntable)
{
	bool estRetire = false;
	for (unsigned int i = 0; i < vecEmprunts_.size(); i++)
	{
		if (*(vecEmprunts_[i]->obtenirObjEmprunt()) == *objetEmpruntable)
		{
			vecEmprunts_[i] = vecEmprunts_.back();
			vecEmprunts_.pop_back();
			estRetire = true;
		}
	}

	return estRetire;
}

unsigned int Abonne::obtenirLimiteEmprunt() const
{
	return limiteEmprunt_;
}
