/****************************************************************************
* Fichier: PolyLand.h
* Auteur: PolySensei 091111 and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Définition de la classe PolyLand
****************************************************************************/
#ifndef POLYLAND_H
#define POLYLAND_H

#include <vector>
#include <iostream>

#include "Dresseur.h"
#include "Creature.h"

class PolyLand
{
public:
	PolyLand();
	~PolyLand();
	
	bool ajouterDresseur(Dresseur* dresseur);
	bool retirerDresseur(const std::string& nom);

	bool ajouterCreature(Creature* creature);
	bool retirerCreature(const std::string& nom);

	Dresseur* choisirDresseurAleatoire();
	Creature* choisirCreatureAleatoire();

	bool attraperCreature(Dresseur* dresseur, Creature* creature);
	bool relacherCreature(Dresseur* dresseur, const std::string nomCreature);

	PolyLand& operator+=(Dresseur* dresseur);
	PolyLand& operator-=(Dresseur* dresseur);
	PolyLand& operator+=(Creature* creature);
	PolyLand& operator-=(Creature* creature);

	friend std::ostream& operator<<(std::ostream& os, const PolyLand& poly);

private:
	std::vector<Dresseur*> dresseurs_;
	std::vector<Creature*> creatures_;
};
#endif