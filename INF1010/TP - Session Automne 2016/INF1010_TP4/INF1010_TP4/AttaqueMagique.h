

#ifndef ATTAQUEMAGIQUE_H
#define ATTAQUEMAGIQUE_H

#include "Creature.h"
#include <string>
#include <vector>
#define DUREE_MIN 2
using namespace std;

class AttaqueMagique
{
public:
	AttaqueMagique();
	AttaqueMagique(int duree);
	virtual ~AttaqueMagique();

	unsigned int obtenirDuree();
	void modifierDuree(int duree);
	string obtenirTypeAttaque();
	virtual void appliquerAttaque(Creature& creature) = 0;
	virtual bool estFini();

	friend std::ostream& operator<<(std::ostream& os, AttaqueMagique& AttaqueMagique);

protected:
	int duree_;
};

#endif