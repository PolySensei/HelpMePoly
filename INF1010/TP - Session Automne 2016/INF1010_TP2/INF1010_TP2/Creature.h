/****************************************************************************
* Fichier: Creature.h
* Auteur: Poly Sensei 091111 & Associates
* Date: 28 septembre 2016
* Mise a jour :  03 octobre 2016
* Description: Definition de la classe Creature
****************************************************************************/

#ifndef CREATURE_H
#define CREATURE_H

#include <vector>
#include <string>
#include "ObjetMagique.h"
#include "Pouvoir.h"

class Creature
{
public:
	Creature();
	Creature(const std::string& nom, unsigned int attaque, 
		unsigned int defense, unsigned int pointDeVie, unsigned int energie);
	Creature(const Creature& creature);
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
	std::vector<Pouvoir*> obtenirPouvoirs() const;

	void attaquer(Pouvoir& pouvoir, Creature& creature);
	int experienceGagnee(const Creature& creature);
	
	void modifierNom(std::string nom);
	void modifierAttaque(unsigned int attaque);
	void modifierDefense(unsigned int defense);
	void modifierPointDeVie(unsigned int pointDeVie);
	void modifierPointDeVieTotal(unsigned int pointDeVieTotal);
	void modifierEnergie(unsigned int energie);
	void modifierEnergieTotal(unsigned int energieTotal);
	void modifierExperience(unsigned int experience);
	void modifierExperienceNecessaire(unsigned int experienceNecessaire);
	void modifierNiveau(unsigned int niveau);
	void modifierPouvoirs(Pouvoir* pouvoirs);

	bool operator==(const std::string& nom) const;
	friend std::ostream& operator<< (std::ostream& out, const Creature& creature);
	void operator=(Creature creature);
	bool operator==(Creature& creature) const;
	friend bool operator==(const std::string& nom, const Creature& creature);

	void apprendrePouvoir(Pouvoir* pouvoir);
	void oublierPouvoir(std::string pouvoir);

	// _________TP2___________

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
	
	// _________TP2___________

	std::vector<Pouvoir*> vecPouvoir_;
};

#endif