/****************************************************************************
* Fichier: GreenBull.h
* Auteur: PolySensei 091111 and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Définition de la classe GreenBull
****************************************************************************/
#ifndef GreenBull_H
#define GreenBull_H

#include <string>
#include <iostream>
#include "ObjetMagique.h"

class GreenBull: public ObjetMagique
{
public:
	GreenBull();
	GreenBull(const std::string &nom, int bonus);
	~GreenBull();

	void utiliserSur(Creature& creature) const;

	friend std::ostream& operator<<(std::ostream& os, const GreenBull& objet);

private:
	std::string nom_;
	int bonus_;
};

#endif
#pragma once
