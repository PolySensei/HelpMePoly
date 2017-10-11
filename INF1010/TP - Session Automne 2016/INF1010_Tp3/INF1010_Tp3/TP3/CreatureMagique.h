/****************************************************************************
* Fichier: CreatureMagique.h
* Auteur: Poly Sensei 091111 & Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Définition de la classe CreatureMagique
****************************************************************************/

#ifndef CREATUREMAGIQUE_H
#define CREATUREMAGIQUE_H

#include <string>
#include <iostream>

#include "Creature.h"

class CreatureMagique : public Creature
{
public:
	CreatureMagique();
	CreatureMagique(const std::string& nom, unsigned int attaque,
		unsigned int defense, unsigned int pointDeVie, unsigned int energie, unsigned int bonus);
	CreatureMagique& operator=(const CreatureMagique& creatureMagique);
	CreatureMagique(const CreatureMagique& creatureMagique);

	friend std::ostream& operator<<(std::ostream& os, const CreatureMagique& creatureMagique);

	void attaquer(const Pouvoir & pouvoir, Creature & creature);
private:
	//tp3
	int bonus_;

};

#endif
