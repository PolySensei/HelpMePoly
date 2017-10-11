/****************************************************************************
* Fichier: Pouvoir.cpp
* Auteur: Poly Sensei 091111 & Associates
* Date: 28 septembre 2016
* Mise a jour :  03 octobre 2016
* Description: Implémentation de la classe Pouvoir
****************************************************************************/

#include "Pouvoir.h"
#include <iostream>

using namespace std;

//Un constructeur par défaut

Pouvoir::Pouvoir()
{
}

//Un constructeur par paramètre

Pouvoir::Pouvoir(const std::string& nom, 
	unsigned int nombreDeDegat,	unsigned int energieNecessaire):
	nom_(nom), nombreDeDegat_(nombreDeDegat), energieNecessaire_(energieNecessaire)
{
}

//Un constructeur par copie qui va copier tous les attributs.

Pouvoir::Pouvoir(const Pouvoir& pouvoir) 
	:nom_(pouvoir.nom_), nombreDeDegat_(pouvoir.nombreDeDegat_), energieNecessaire_(pouvoir.energieNecessaire_)
{
}

Pouvoir::~Pouvoir()
{
}

unsigned int Pouvoir::obtenirEnergieNecessaire() const
{
	return energieNecessaire_;
}

std::string Pouvoir::obtenirNom() const
{
	return nom_;
}

unsigned int Pouvoir::obtenirNombreDeDegat() const
{
	return nombreDeDegat_;
}

void Pouvoir::modifierNombreDeDegat(unsigned int nombreDegat)
{
	nombreDeDegat_ = nombreDegat;
}

void Pouvoir::modifierEnergieNecessarie(unsigned int energieNecessaire)
{
	energieNecessaire_ = energieNecessaire;
}

void Pouvoir::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

//Surcharge de l'opérateur <<

ostream& operator<<(ostream& out, const Pouvoir& pouvoir) {

	out << pouvoir.nom_ << " necessite " << pouvoir.energieNecessaire_ << " energie et inflige " << pouvoir.nombreDeDegat_ << " degats" << endl << endl;
	return out;
}

//Un opérateur = qui écrase les attributs de l’objet de gauche par les attributs l’objet passés
//en paramètre.
void Pouvoir::operator=(Pouvoir& pouvoir) {

	modifierNom(pouvoir.nom_);
	modifierNombreDeDegat(pouvoir.nombreDeDegat_);
	modifierEnergieNecessarie(pouvoir.energieNecessaire_);

}

//L’opérateur == qui prend un Pouvoir en paramètre et permet de comparer 2 pouvoirs en
//considérant seulement le nom.L’opérateur retourne true si les pouvoirs ont le même nom,
//false sinon.Ainsi, cet opérateur va pouvoir faire l’opération pouvoir1 == pouvoir2.

bool Pouvoir::operator==(string& nom) const {
	bool estEgal = false;

	if (nom_ == nom) {
		estEgal = true;
	}
	return estEgal;
}