/****************************************************************************
* Fichier: PotionMagique.h
* Auteur: PolySensei and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Définition de la classe PotionMagique
****************************************************************************/
#ifndef PotionMagique_H
#define PotionMagique_H

#include <string>
#include <iostream>
#include "ObjetMagique.h"

class PotionMagique: public ObjetMagique
{
public:
	PotionMagique();
	PotionMagique(const std::string &nom, int bonus);
	~PotionMagique();

	void utiliserSur(Creature& creature) const;

	friend std::ostream& operator<<(std::ostream& os, const PotionMagique& objet);

private:
	std::string nom_;
	int bonus_;
};

#endif
#pragma once
