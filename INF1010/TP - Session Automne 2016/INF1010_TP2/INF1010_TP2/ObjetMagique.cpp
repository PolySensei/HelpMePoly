/****************************************************************************
* Fichier: ObjetMagique.cpp
* Auteur: Poly Sensei 091111 & Associates
* Date: 28 septembre 2016
* Mise a jour :  03 octobre 2016
* Description: Implémentation de la classe ObjetMagique
****************************************************************************/

#include "ObjetMagique.h"
#include <iostream>

using namespace std;

ObjetMagique::ObjetMagique()
{
}

ObjetMagique::ObjetMagique(const std::string & nom, int bonus):
	nom_(nom), bonus_(bonus)
{
}


ObjetMagique::~ObjetMagique()
{
}

std::string ObjetMagique::obtenirNom() const
{
	return nom_;
}

int ObjetMagique::obtenirBonus() const
{
	return bonus_;
}

void ObjetMagique::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

void ObjetMagique::modifierBonus(int bonus)
{
	bonus_ = bonus;
}

//Surcharge de l'opérateur <<

ostream& operator<<(ostream& out, const ObjetMagique& objetMagique)
{
	out << "l'objet " << objetMagique.nom_ << "fournit un bonus de " << objetMagique.bonus_ << endl;
	return out;
}