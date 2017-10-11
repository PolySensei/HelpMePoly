/****************************************************************************
* Fichier: Creature.h
* Auteur: Poly Sensei 091111 & Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Définition de la classe Creature
****************************************************************************/

#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <vector>

#include "ObjetMagique.h"
#include "Pouvoir.h"
#include "EtatCreature.h"

//Décarations anticipées pour que la compilation soit possible
class Pouvoir;

class EtatCreature;

class Creature
{
public:
	Creature();
	Creature(const std::string& nom, unsigned int attaque, 
		unsigned int defense, unsigned int pointDeVie, unsigned int energie);
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
    EtatCreature* obtenirEtat();
	void attaquer(const Pouvoir& pouvoir, Creature& creature);
	int experienceGagnee(const Creature& creature);

	bool apprendrePouvoir(Pouvoir* pouvoir);
	bool oublierPouvoir(Pouvoir* pouvoir);
	
	void modifierNom(const std::string& nom);
	void modifierAttaque(unsigned int attaque);
	void modifierDefense(unsigned int defense);
	void modifierPointDeVie(unsigned int pointDeVie);
	void modifierEnergie(unsigned int energie);
	void modifierExperience(unsigned int experience);
	void modifierNiveau(unsigned int niveau);
	void modifierPouvoirs(std::vector<Pouvoir*> pouvoirs);
    void modifierEtat(EtatCreature* etat);

	Creature(const Creature& creature);
	Creature& operator=(const Creature& creature);

	bool operator==(const Creature& creature) const;
	bool operator==(const std::string& nom) const;
	friend bool operator==(const std::string& nom, const Creature& creature);

	friend std::ostream& operator<<(std::ostream& os, const Creature& creature);

protected:

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
	std::vector<Pouvoir*> pouvoirs_;
   
	//Etat un pointeur vers la classe EtatCreature
	EtatCreature* etat_;

    void revenirEtatNormal();
};

#endif