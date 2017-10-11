/****************************************************************************
* Fichier: PouvoirHallucinogene.h
* Auteur: PolySensei and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Définition de la classe PouvoirHallucinogene
****************************************************************************/
#ifndef POUVOIRHALLUCINOGENE_H
#define POUVOIRHALLUCINOGENE_H

#include <string>
#include <iostream>
#include "EtatConfus.h"
#include "Pouvoir.h"


class PouvoirHallucinogene : public Pouvoir
{
public:
	PouvoirHallucinogene();
	PouvoirHallucinogene(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	PouvoirHallucinogene(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);
	~PouvoirHallucinogene();

	void appliquerEffetOffensif(Creature& creatureEnnemie);
	friend std::ostream& operator<<(std::ostream& os, const PouvoirHallucinogene& pouvoir);
private:
	int duree_;

};

#endif
