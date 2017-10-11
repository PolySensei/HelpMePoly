
#ifndef ATTAQUEMAGIQUEPOISON_H
#define ATTAQUEMAGIQUEPOISON_H

#include <string>
#include "Creature.h"
#include "AttaqueMagique.h"
#include <vector>

using namespace std;

class AttaqueMagiquePoison: public AttaqueMagique
{
public:
	AttaqueMagiquePoison();
	AttaqueMagiquePoison(int duree);
	virtual ~AttaqueMagiquePoison();

	virtual void appliquerAttaque(Creature& creature);
	virtual bool estFini();
};

#endif