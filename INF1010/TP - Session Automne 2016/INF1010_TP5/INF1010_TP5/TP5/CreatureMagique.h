/*
Fichier: CreatureMagique.h
Auteur(s): Philippe Troclet
Date de creation: 30 septembre 2016
Révision: Maude Carrier (11 octobre 2016)
Description: Les creatures magiques peuvent bénificier d'une attaque magique
*/
#ifndef CREATURE_MAGIQUE_H
#define CREATURE_MAGIQUE_H

#include "AttaqueMagiqueConfusion.h"
#include "AttaqueMagiquePoison.h"

class CreatureMagique : public Creature
{
public:
	CreatureMagique();
	CreatureMagique(const Creature& creature, unsigned int bonus);

    CreatureMagique(const CreatureMagique& creatureMagique);
	CreatureMagique& operator=(const CreatureMagique& creatureMagique);

    virtual ~CreatureMagique(); // À MODIFIER (si nécessaire...)

    virtual void attaquer(const Pouvoir& pouvoir, Creature& creature); // À MODIFIER (si nécessaire...)

    friend std::ostream& operator<<(std::ostream& os, const CreatureMagique& creature); // À MODIFIER (si nécessaire...)
	
	virtual std::string obtenirTypeCreature() const;

	AttaqueMagique* obtenirAttaque() const;
	unsigned int obtenirBonus() const;
	void modifierBonus(unsigned int bonus);

	void apprendreAttaqueMagique(const AttaqueMagique* attaqueMagique);
	void oublierAttaqueMagique(const AttaqueMagique* attaqueMagique);

private:
    unsigned int bonus_;
	AttaqueMagique* attaqueMagique_;
};

#endif