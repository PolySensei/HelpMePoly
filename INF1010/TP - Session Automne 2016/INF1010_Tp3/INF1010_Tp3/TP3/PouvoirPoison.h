/****************************************************************************
* Fichier: PouvoirPoison.h
* Auteur: PolySensei and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Définition de la classe PouvoirPoison
****************************************************************************/
#ifndef POUVOIRPOISON_H
#define POUVOIRPOISON_H

#include <string>
#include <iostream>
#include "Creature.h"
#include "Pouvoir.h"
#include "EtatEmpoisonne.h"
class Creature;

class PouvoirPoison: public Pouvoir
{
public:
	PouvoirPoison();
	PouvoirPoison(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	PouvoirPoison(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);
	~PouvoirPoison();

	void appliquerEffetOffensif(Creature& creatureEnnemie);
	friend std::ostream& operator<<(std::ostream& os, const PouvoirPoison& pouvoir);
private:
	//tp3
	int duree_;
	
};

#endif