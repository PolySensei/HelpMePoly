/****************************************************************************
* Fichier: PolyLand.cpp
* Auteur: Poly Sensei 091111 & Associates
* Date: 14 septembre 2016
* Mise a jour :  26 septembre 2016
* Description: Implémentation de la classe PolyLand
****************************************************************************/

#include "PolyLand.h"
#include <string>
#include <iostream>
#include "Creature.h"
#include "Dresseur.h"
#include "PolyLand.h"
#include "Pouvoir.h"
#include <time.h>

using namespace std;

PolyLand::PolyLand()
	: nbrDresseurs_(0), nbrCreatures_(0), dresseurs_(nullptr), creatures_(nullptr)
{
	dresseurs_ = new Dresseur*[100];
	for (int i = 1; i < 100; i++)
		dresseurs_[i] = nullptr;

	creatures_ = new Creature*[1000];
	for (int i = 1; i < 1000; i++)
		creatures_[i] = nullptr;
}

PolyLand::~PolyLand()
{
	for (int i = 0; i < nbrCreatures_; i++) {
		delete creatures_[i];
		creatures_[i] = nullptr;
	}
	for (int i = 0; i < nbrDresseurs_; i++) {
		delete dresseurs_[i];
		dresseurs_[i] = nullptr;
	}
}

/*La méthode ajouterDresseur() qui permet d’ajouter dresseur reçu en paramètre , deux
dresseurs ne peuvent pas avoir le même nom */

void PolyLand::ajouterDresseur(Dresseur* dresseur)
{
	bool estDejaUtilise = false;
	for (unsigned int i = 0; i < nbrDresseurs_; i++) {
		if (dresseurs_[i] == dresseur) {
			estDejaUtilise = true;
		}
	}
	if (!estDejaUtilise) {
		dresseurs_[nbrDresseurs_] = dresseur;
		nbrDresseurs_++;
		cout << dresseur->obtenirNom() << " a été ajouté !" << endl;
	}
}

bool PolyLand::retirerDresseur(string& dresseur)
{
	bool flag = false;
	for (unsigned int i = 0; i < nbrDresseurs_; i++) {
		if (dresseurs_[i]->obtenirNom() == dresseur) {
			flag = true;
		}
		if (flag) {
			dresseurs_[i] = dresseurs_[i + 1];
		}
	}
	if (flag) {
		dresseurs_[nbrDresseurs_] = nullptr;
		nbrDresseurs_--;
	}
	return flag;
}


void PolyLand::ajouterCreature(Creature& creature)
{
	bool estDejaUtilise = false;
	for (unsigned int i = 0; i < nbrCreatures_; i++) {
		if (creatures_[i] == &creature) {
			estDejaUtilise = true;
		}
	}
	if (!estDejaUtilise) {
		creatures_[nbrCreatures_] = &creature;
		nbrCreatures_++;
		cout << creature.obtenirNom() << " a été ajouté !" << endl;
	}
}

void PolyLand::retirerCreature(string& creature)
{
	bool flag = false;
	for (unsigned int i = 0; i < nbrCreatures_; i++) {
		if (creatures_[i]->obtenirNom() == creature) {
			flag = true;
		}
		if (flag) {
			creatures_[i] = creatures_[i + 1];
		}
	}
	if (flag) {
		creatures_[nbrCreatures_] = nullptr;
		nbrCreatures_--;
	}
}

Dresseur* PolyLand::choisirDresseurAleatoire()
{
	srand(time(NULL));
	return dresseurs_[rand() % nbrDresseurs_];
}
Creature* PolyLand::choisirCreatureAleatoire()
{
	srand(time(NULL));
	return creatures_[rand() % nbrCreatures_];
}

bool PolyLand::relacherCreature(Dresseur* dresseur, string& unCreature)
{
	bool estRelache = false;
	for (unsigned int i = 0; i < dresseur->obtenirNombreCreatures(); i++) {
		if (dresseur->obtenirCreatures()[i]->obtenirNom() == unCreature) {
			estRelache = true;
		}
		if (estRelache) {
			dresseur->obtenirCreatures()[i] = dresseur->obtenirCreatures()[i + 1];
		}
	}
	if (estRelache) {
		dresseur->obtenirCreatures()[dresseur->obtenirNombreCreatures()] = nullptr;
		dresseur->modifierNombreCreatures(dresseur->obtenirNombreCreatures() - 1);
	}
	return estRelache;
}
bool PolyLand::attraperCreature(Dresseur* dresseur, Creature& unCreature)
{
	bool estAttrape = true;
	for (unsigned int i = 0; i < (*dresseur).obtenirNombreCreatures(); i++) {
		if ((*dresseur).obtenirCreatures()[i] == &unCreature) {
			estAttrape = false;
		}
	}
	if (estAttrape) {
		(*dresseur).ajouterCreature(unCreature);
	}
	return estAttrape;
}

void PolyLand::infoDresseur(const string unDresseur)
{
	for (int i = 0; i < nbrDresseurs_; i++) {
		if (dresseurs_[i]->obtenirNom() == unDresseur)
		{
			cout << "Informations sur le dresseur:" << endl;
				dresseurs_[i]->affichage();
				for (int j = 0; j < dresseurs_[i]->obtenirNombreCreatures(); j++) {
					cout << "-" << j + 1 << "- ";
					dresseurs_[i]->obtenirCreatures()[j]->information();
				}
		}
	}
}
