/*
Fichier: Dresseur.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include <iostream>
#include <list>
#include <algorithm>

#include "Creature.h"
#include "ObjetMagique.h"
#include "ExceptionAttaqueEchouee.h"

class Dresseur
{
public:
	Dresseur();
	Dresseur(const std::string& nom, const std::string& equipe);
	~Dresseur();

	std::string obtenirNom() const;
	void modifierNom(const std::string& nom);

	unsigned int obtenirNombreCreatures() const;

	std::vector<Creature*> obtenirCreatures() const;
	Creature* obtenirUneCreature(const std::string& nom) const;
	void modifierCreature(std::vector<Creature*>  creatures);

	void ajouterCreature(Creature* creature);
	bool enleverCreature(const std::string& nom);

	ObjetMagique obtenirObjetMagique() const;
	void modifierObjetMagique(const ObjetMagique& objetMagique);

	void utiliserObjetMagique(Creature* creature);

	std::string obtenirEquipe() const;
	void modifierEquipe(const std::string& equipe);

	friend std::ostream& operator<<(std::ostream& os, const Dresseur& dresseur);

	bool operator==(const Dresseur& dresseur) const;
	bool operator==(const std::string& nom) const;
	friend bool operator==(const std::string& nom, const Dresseur& dresseur);

    //TODO : M�thodes TP3
    template<typename PredicatUnaire>
    void appliquerFoncteurUnaire(PredicatUnaire& froncteur) const;
    template<typename PredicatUnaire>
    void supprimerElements(PredicatUnaire& froncteur);

    template<typename PredicatBinaire>
    Creature* obtenirCreatureMax(const PredicatBinaire& predicat);

private:
	std::string nom_;
	std::vector<Creature*> creatures_;
	std::string equipe_;
	ObjetMagique objetMagique_;

};

template<typename PredicatUnaire>
void Dresseur::appliquerFoncteurUnaire(PredicatUnaire & froncteur) const
{
    for each (Creature* creature in creatures_)
    {
        froncteur(creature);
    }
}

template<typename PredicatUnaire>
void Dresseur::supprimerElements(PredicatUnaire & foncteur)
{
    creatures_.remove_if(foncteur);
}

template<typename PredicatBinaire>
Creature* Dresseur::obtenirCreatureMax(const PredicatBinaire & predicat)
{
    auto max_it = std::max_element(creatures_.begin(), creatures_.end(), predicat);
    if (max_it != creatures_.end())
        return *max_it;

    return nullptr;
}

#endif
