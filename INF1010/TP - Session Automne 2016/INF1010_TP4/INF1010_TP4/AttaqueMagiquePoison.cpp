

#include "AttaqueMagiquePoison.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
//Un constructeur par défaut qui initialise la durée à 2

AttaqueMagiquePoison::AttaqueMagiquePoison() : AttaqueMagique(DUREE_MIN)
{

}
//Un constructeur qui prend en paramètre une durée
AttaqueMagiquePoison::AttaqueMagiquePoison(int duree) : AttaqueMagique(duree)
{

}
//Un destructeur
AttaqueMagiquePoison::~AttaqueMagiquePoison()
{

}
//Une méthode appliquerAttaque(). L’attaque magique poison permet, dans le tiers
//des cas, de réduire l’énergie de la créature adverse de 2 points, dans le cas où
//celle - ci à au moins 5 points d’énergie(si bien - sûr la durée de l’attaque magique
//n’est pas nulle).Dans les autres cas, rien ne se passe.

void AttaqueMagiquePoison::appliquerAttaque(Creature& creature)
{
	if (rand() % 3 < 1 && creature.obtenirEnergie() >= 5 && duree_ != 0)
	{
		creature.modifierEnergie(creature.obtenirEnergie() - 2);
	}
}
//Une méthode estFini() qui retourne vraie si la durée est nulle
bool AttaqueMagiquePoison::estFini()
{
	if (duree_ == 0)
	{
		return true;
	}
	return false;
}
