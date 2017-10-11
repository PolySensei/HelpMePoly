/****************************************************************************
* Fichier: Elixir.h
* Auteur: Poly Sensei 091111 & Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Définition de la classe Elixir
****************************************************************************/

#ifndef Elixir_H
#define Elixir_H

#include <string>
#include <iostream>
#include "PotionMagique.h"

#include "Creature.h"

class Elixir: public PotionMagique
{
public:
	Elixir();
	Elixir(const std::string &nom, int bonus);
	~Elixir();

	void utiliserSur(Creature& creature) const;

	friend std::ostream& operator<<(std::ostream& os, const Elixir& objet);

private:
	std::string nom_;
	int bonus_;
};

#endif
