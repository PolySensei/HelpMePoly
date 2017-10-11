/****************************************************************************
* Fichier: Pouvoir.cpp
* Auteur: Poly Sensei 091111 & Associates
* Date: 14 septembre 2016
* Mise a jour :  26 septembre 2016
* Description: Implémentation de la classe Pouvoir
****************************************************************************/
#include <iostream>
#include "Pouvoir.h"

using namespace std;

Pouvoir::Pouvoir()
	: nom_(""), degat_(0), energieNecessaire_(0)
{
}

Pouvoir::Pouvoir(const std::string& nom, unsigned int degat, unsigned int energieNecessaire)
	: nom_(nom), degat_(degat), energieNecessaire_(energieNecessaire)
{
}

Pouvoir::~Pouvoir()
{
}

string Pouvoir::obtenirNom() const
{
	return nom_;
}

unsigned int Pouvoir::obtenirDegat() const
{
	return degat_;
}

unsigned int Pouvoir::obtenirEnergieNecessaire() const
{
	return energieNecessaire_;
}

void Pouvoir::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Pouvoir::modifierDegat(unsigned int& degat)
{
	degat_ = degat;
}

void Pouvoir::modifierEnergieNecessaire(unsigned int& energieNecessaire)
{
	energieNecessaire_ = energieNecessaire;
}

void Pouvoir::description() const {

	cout << "Son pouvoir est : " << nom_ << " necessite " << energieNecessaire_
		<< " d'energie et inflige " << degat_ << " degats" << endl << endl;
}
