/****************************************************************************
* Fichier: Professeur.h
* Auteur: PolySensei and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Définition de la classe Professeur
****************************************************************************/
#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include <string>
#include "Dresseur.h"
#include "OutilScientifique.h"
#include <vector>
#include <iostream>


class Professeur : public Dresseur
{
public:
	Professeur();
	Professeur(const std::string& nom, const std::string& equipe);
	Professeur(const Professeur& professeur);
	~Professeur();

	OutilScientifique* obtenirOutilScientifique() const;
	void modifierOutil(OutilScientifique outilScientifique);
	void utiliserOutil(Creature creature);

	void soigner(Creature& creature);

	Professeur& operator=(Professeur& professeur);

	//Attributs

private:
	//Un pointeur vers un OutilScientifique
	OutilScientifique* outilScientifique_;

};


#endif
