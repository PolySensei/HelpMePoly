/****************************************************************************
* Fichier: GreenBull.cpp
* Auteur: PolySensei 091111 and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Implémentation de la classe GreenBull
****************************************************************************/

#include "GreenBull.h"
#include <iostream>

GreenBull::GreenBull()
{
}

GreenBull::GreenBull(const std::string & nom, int bonus) :
	ObjetMagique(nom, bonus)
{
}


GreenBull::~GreenBull()
{
}

void GreenBull::utiliserSur(Creature & creature) const
{
	if ((creature.obtenirEnergieTotale() - creature.obtenirEnergie()) > obtenirBonus()) {
		creature.modifierEnergie(creature.obtenirEnergie() + obtenirBonus());
	}
	else {
		creature.modifierEnergie(creature.obtenirEnergieTotale());
	}
}

std::ostream& operator<<(std::ostream& os, const GreenBull& greenBull)
{
	return os << "l'objet " << greenBull.obtenirNom() << " fournit un bonus de " << greenBull.obtenirBonus() << std::endl;
}
