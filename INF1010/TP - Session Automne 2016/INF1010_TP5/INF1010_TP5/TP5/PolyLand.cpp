/*
Fichier: Dresseur.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description:
*/
#include "PolyLand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Foncteur.h"

using namespace std;

bool PolyLand::attraperCreature(Dresseur* dresseur, Creature* creature)
{
	return dresseur->ajouterCreature(creature);
}

bool PolyLand::relacherCreature(Dresseur* dresseur, const std::string& nomCreature)
{
	return dresseur->enleverCreature(nomCreature);
}

ostream& operator<<(std::ostream& os, const PolyLand& polyLand)
{
	FoncteurComparerDresseurs nom;
	FoncteurComparerCreatures attaque;
	list<Dresseur*> listTemp1 = polyLand.obtenirListeMaitre();
	list<Creature*> listTemp2 = polyLand.obtenirListeCompagnon();
	listTemp1.sort(nom);
	
	//std::sort(listTemp1.begin(), listTemp1.end(), nom);

	for (auto it = listTemp1.begin(); it != listTemp1.end(); it++)
		os << *(*it) << endl;

	//std::sort(listTemp2.begin(), listTemp2.end(), nom);
	listTemp2.sort(attaque);

	for (auto it = listTemp2.begin(); it != listTemp2.end(); it++)
		os << *(*it) << endl;
	return os;
}
