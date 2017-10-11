/****************************************************************************
* Fichier: CreatureMagique.h
* Auteur: PolySensei 091111 and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Définition de la classe CreatureMagique
****************************************************************************/

#ifndef CREATUREMAGIQUE_H
#define CREATUREMAGIQUE_H

#include <string>
#include <iostream>
#include "AttaqueMagique.h"
#include "AttaqueMagiquePoison.h"
#include "AttaqueMagiqueConfusion.h"
#include "Creature.h"

class CreatureMagique : public Creature
{
public:
	CreatureMagique();
	CreatureMagique(int bonus, Creature creature);
	virtual ~CreatureMagique();
	CreatureMagique& operator=(const CreatureMagique& creatureMagique);
	CreatureMagique(const CreatureMagique& creatureMagique);

	int obtenirBonus();
	void modifierBonus(int bonus);

	AttaqueMagique* obtenirAttaqueMagique();
	void modifierAttaqueMagique(AttaqueMagique* attaque);

	string obtenirTypeCreature();

	bool apprendreAttaqueMagique(AttaqueMagique* attaque);
	bool oublierAttaqueMagique();
	friend std::ostream& operator<<(std::ostream& os, CreatureMagique& creatureMagique);

	void attaquer(const Pouvoir & pouvoir, Creature & creature);
private:
	int bonus_;
	//Un pointeur de type AttaqueMagique : attaqueMagique_
	AttaqueMagique* attaqueMagique_;
};

#endif
