/****************************************************************************
* Fichier: ObjetMagique.cpp
* Auteur: Poly Sensei 091111 & Associates
* Date: 14 septembre 2016
* Mise a jour :  26 septembre 2016
* Description: Implémentation de la classe ObjetMagique
****************************************************************************/
#include <iostream>
#include "ObjetMagique.h"

using namespace std;

ObjetMagique::ObjetMagique()
	: nom_(""), bonus_(0)
{
}

ObjetMagique::ObjetMagique(const std::string& nom, unsigned int bonus)
	: nom_(nom), bonus_(bonus)
{
}

ObjetMagique::~ObjetMagique()
{
}

string ObjetMagique::obtenirNom() const
{
	return nom_;
}

unsigned int ObjetMagique::obtenirBonus() const
{
	return bonus_;
}

void ObjetMagique::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

void ObjetMagique::modifierBonus(unsigned int bonus)
{
	bonus_= bonus;
}

/*Une méthode d’affichage des informations, nommée affichage(), qui affichera les
différentes informations contenus dans les attributs*/

void ObjetMagique::affichage() const
{
	cout << "L'objet " << nom_
		<< " fournit un bonus de " << bonus_ << endl;
}
