/****************************************************************************
* Fichier: PouvoirSoporifique.h
* Auteur: PolySensei and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Définition de la classe PouvoirSoporifique
****************************************************************************/
#ifndef POUVOIRSOPORIFIQUE_H
#define POUVOIRSOPORIFIQUE_H

#include <string>
#include <iostream>
#include "EtatEndormis.h"
#include "Pouvoir.h"


class PouvoirSoporifique : public Pouvoir
{
public:
	PouvoirSoporifique();
	PouvoirSoporifique(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	PouvoirSoporifique(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);
	~PouvoirSoporifique();

	void appliquerEffetOffensif(Creature& creatureEnnemie);
	friend std::ostream& operator<<(std::ostream& os, const PouvoirSoporifique& pouvoir);
private:
	int duree_;

};

#endif
