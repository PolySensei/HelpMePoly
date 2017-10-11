/****************************************************************************
* Fichier: Professeur.cpp
* Auteur: PolySensei and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Implémentation de la classe Professeur
****************************************************************************/
#include <iostream>
#include "Professeur.h"

using namespace std;

// Un constructeur par défaut.
Professeur::Professeur() {

}

// Un constructeur par paramètres qui initialise les attributs en fonction des paramètres.
Professeur::Professeur(const std::string& nom, const std::string& equipe)
	: Dresseur(nom, equipe), outilScientifique_ (nullptr)
{

}

Professeur::Professeur(const Professeur& professeur)
{
	modifierNom(professeur.obtenirNom());
	modifierEquipe(professeur.obtenirEquipe());
}


// Le destructeur pour cette classe.
Professeur::~Professeur()
{

}

// Les méthodes d’accès de modification au nouvel attribut.

OutilScientifique* Professeur::obtenirOutilScientifique() const 
{
	return outilScientifique_;
}

void Professeur::modifierOutil(OutilScientifique outilScientifique)
{
	outilScientifique_ = &outilScientifique;
}



// Une méthode utiliserOutil qui s’applique à une créature.
void Professeur::utiliserOutil(Creature creature)
{
	outilScientifique_->utiliser(creature);
}


// Une méthode soigner qui rétablit les points de vie et l’énergie de la créature(passée en
//	argument) à leur valeur maximale

void Professeur::soigner(Creature& creature)
{
	creature.modifierEnergie(creature.obtenirEnergieTotale());
	creature.modifierPointDeVie(creature.obtenirPointDeVieTotal());
}


// L’opérateur << , qui affiche les informations du Professeur, tel que présenté dans
// l’exemple à la fin du document. Il doit appeler l’opérateur << de la classe Abonne.
Professeur& Professeur::operator=(Professeur& professeur)
{
	if (this != &professeur)
	{
		modifierNom(professeur.obtenirNom());
		modifierEquipe(professeur.obtenirEquipe());
		outilScientifique_ = professeur.outilScientifique_;
	}

	return *this;
}
