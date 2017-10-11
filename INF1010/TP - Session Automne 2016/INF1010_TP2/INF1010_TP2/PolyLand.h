/****************************************************************************
* Fichier: PolyLand.h
* Auteur: Poly Sensei 091111 & Associates
* Date: 28 septembre 2016
* Mise a jour :  03 octobre 2016
* Description: Definition de la classe PolyLand
****************************************************************************/

#ifndef POLYLAND_H
#define POLYLAND_H

#include <string>
#include <vector>
#include <iostream>
#include "Dresseur.h"
#include "Creature.h"
#define MAX_DRESSEURS 100
#define MAX_CREATURES 1000
#define MAX_OBJET_MAGIQUE 100
#define MAX_POUVOIRS 10

class PolyLand
{
public:
	PolyLand();
	~PolyLand();
	
	std::vector<Dresseur*> obtenirDresseurs() const;

	bool ajouterDresseur(Dresseur* dresseur);
	bool ajouterCreature(Creature* creature); // A MODIFIER... (si necessaire)

	bool retirerDresseur(const std::string& nom); // A MODIFIER... (si necessaire)
	bool retirerCreature(const std::string& nom); // A MODIFIER... (si necessaire)

	Dresseur* choisirDresseurAleatoire(); // A MODIFIER... (si necessaire)
	Creature* choisirCreatureAleatoire(); // A MODIFIER... (si necessaire)

	bool attraperCreature(Dresseur* dresseur, Creature* creature); // A MODIFIER... (si necessaire)
	bool relacherCreature(Dresseur* dresseur, const std::string& nomCreature); // A MODIFIER... (si necessaire)
	
	friend std::ostream& operator<<(std::ostream& out, const PolyLand& polyland);
	void operator+=(Dresseur* dresseur);
	void operator-=(Dresseur* dresseur);
	void operator+=(Creature* creature);
	void operator-=(Creature* creature);
	//________TP2_______

private:
	//________TP2_______
	std::vector<Dresseur*> dresseurs_;
	std::vector<Creature*> creatures_;
};
#endif