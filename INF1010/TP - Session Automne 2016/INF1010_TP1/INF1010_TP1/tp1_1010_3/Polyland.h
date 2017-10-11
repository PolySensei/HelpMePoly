/****************************************************************************
* Fichier: Polyland.h
* Auteur: Poly Sensei 091111 & Associates
* Date: 14 septembre 2016
* Mise a jour :  26 septembre 2016
* Description: Définiton de la classe Polyland
****************************************************************************/

#ifndef POLYLAND_H
#define POLYLAND_H

#include <string>
#include <vector>
#include <iostream>
#include "Dresseur.h"
using namespace std;

class PolyLand
{
public:
	PolyLand();
	~PolyLand();

	void ajouterDresseur(Dresseur* dresseur);
	bool retirerDresseur(string& dresseur);
	void ajouterCreature(Creature& creature);
	void retirerCreature(string& creature);

	Dresseur* choisirDresseurAleatoire();
	Creature* choisirCreatureAleatoire();

	bool attraperCreature(Dresseur* dresseur, Creature& unCreature);
	bool relacherCreature(Dresseur* dresseur, string& unCreature);

	void infoDresseur(const string unDresseur);

private:

	Dresseur** dresseurs_;
	Creature** creatures_;
	unsigned int nbrCreatures_;
	unsigned int nbrDresseurs_;
};


#endif


