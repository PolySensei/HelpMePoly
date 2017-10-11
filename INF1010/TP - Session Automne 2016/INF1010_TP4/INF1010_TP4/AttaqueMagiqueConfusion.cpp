

#include "AttaqueMagiqueConfusion.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

//Un constructeur par défaut qui initialise la durée à 2

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion() : AttaqueMagique(DUREE_MIN)
{

}
//Un constructeur qui prend en paramètre une durée

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(int duree) : AttaqueMagique(duree)
{

}
//Un destructeur
AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion()
{

}
//Une méthode appliquerAttaque(). L’attaque magique poison permet, dans le tiers
//des cas, de réduire les points de vie de la créature adverse de 2 points, dans le
//cas où celle - ci à au moins 5 points de vie(si bien - sûr la durée de l’attaque magique
//	n’est pas nulle).Dans les autres cas, rien ne se passe.
void AttaqueMagiqueConfusion::appliquerAttaque(Creature& creature)
{
	if (rand() % 3 < 1 && creature.obtenirPointDeVie() >= 5 && duree_ != 0)
	{
		creature.modifierPointDeVie(creature.obtenirPointDeVie() - 2);
	}
}
//Une méthode estFini() qui retourne vraie si la durée est nulle 
bool AttaqueMagiqueConfusion::estFini()
{
	if (duree_ == 0)
	{
		return true;
	}
	return false;
}
