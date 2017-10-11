
#ifndef ATTAQUEMAGIQUECONFUSION_H
#define ATTAQUEMAGIQUECONFUSION_H

#include <string>
#include "Creature.h"
#include "AttaqueMagique.h"
#include <vector>

using namespace std;

class AttaqueMagiqueConfusion : public AttaqueMagique
{
public:
	AttaqueMagiqueConfusion();
	AttaqueMagiqueConfusion(int duree);
	virtual ~AttaqueMagiqueConfusion();

	virtual void appliquerAttaque(Creature& creature);
	virtual bool estFini();
};

#endif
