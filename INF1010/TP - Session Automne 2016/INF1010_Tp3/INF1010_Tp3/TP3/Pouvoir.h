
/****************************************************************************
* Fichier: Pouvoir.h
* Auteur: PolySensei and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Définition de la classe Pouvoir
****************************************************************************/
#ifndef POUVOIR_H
#define POUVOIR_H

#include <string>
#include <iostream>

#include "Creature.h"
#include "TypeEtat.h"

class Creature;

class Pouvoir
{
public:
	Pouvoir();
	Pouvoir(const std::string& nom, 
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	~Pouvoir();

	unsigned int obtenirNombreDeDegat() const;
	unsigned int obtenirEnergieNecessaire() const;
	std::string obtenirNom() const;
    TypeEtat obtenirType() const; //renvoie le type, qui caractérise l'effet du pouvoir (ex: empoisonner)

	void modifierNombreDeDegat(unsigned int nombreDegat);
	void modifierEnergieNecessarie(unsigned int energieNecessaire);
	void modifierNom(const std::string& nom);

	Pouvoir(const Pouvoir& pouvoir);
	Pouvoir& operator=(const Pouvoir& pouvoir);

	bool operator==(const Pouvoir& pouvoir) const;

	friend std::ostream& operator<<(std::ostream& os, const Pouvoir& pouvoir);

    void appliquerEffetOffensif(Creature& creatureEnnemie);
    void appliquerEffetDefensif(Creature& creatureAllie);
protected:
	std::string nom_;
	unsigned int nombreDeDegat_ ;
	unsigned int energieNecessaire_;
	//type caractérise les modification d’état que la créature attaque peut subir
	TypeEtat type_;
};

#endif