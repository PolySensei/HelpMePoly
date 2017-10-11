/****************************************************************************
* Fichier: Creature.h
* Auteur: Poly Sensei 091111 & Associates
* Date: 14 septembre 2016
* Mise a jour :  26 septembre 2016
* Description: Implémentation de la classe Creature
****************************************************************************/

#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <vector>
#include <iostream>
#include "Pouvoir.h" 

using namespace std;

class Creature
{
public:
	Creature();
	Creature(const string& nom, unsigned int attaque, unsigned int defense, unsigned int pointDeVie, unsigned int energie, const Pouvoir pouvoir);
	~Creature();

	std::string obtenirNom() const;
	unsigned int obtenirAttaque() const;
	unsigned int obtenirDefense() const;
	unsigned int obtenirPointDeVie() const;
	unsigned int obtenirPointDeVieTotal() const;
	unsigned int obtenirEnergie() const;
	unsigned int obtenirEnergieTotale() const;
	unsigned int obtenirExperience() const;
	unsigned int obtenirExperienceNecessaire() const;
	unsigned int obtenirNiveau() const;
	Pouvoir obtenirPouvoir() const;

	void modifierNom(const std::string& nom);
	void modifierAttaque(unsigned int attaque);
	void modifierDefense(unsigned int defense);
	void modifierPointDeVie(unsigned int pointDeVie);
	void modifierPointDeVieTotal(unsigned int pointDeVieTotal);
	void modifierEnergie(unsigned int energie);
	void modifierEnergieTotale(unsigned int energieTotal);
	void modifierExperience(unsigned int experience);
	void modifierExperienceNecessaire(unsigned int experienceNecessaire);
	void modifierNiveau(unsigned int niveau);
	void modifierPouvoir(const Pouvoir& pouvoir);

	void attaquer(Creature& creature);
	int experienceGagner(const Creature& creature);

	void information() const;

private:

	std::string nom_;
	unsigned int attaque_;
	unsigned int defense_;
	unsigned int pointDeVie_;
	unsigned int pointDeVieTotal_;
	unsigned int energie_;
	unsigned int energieTotal_;
	unsigned int experience_;
	unsigned int experienceNecessaire_;
	unsigned int niveau_;
	Pouvoir pouvoir_;

};


#endif
