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


#include "Creature.h"
#include "ObjetMagique.h"
#include <list>
#include <algorithm>



class Dresseur
{
public:
	Dresseur();
	Dresseur(const std::string& nom, const std::string& equipe);
	~Dresseur();

	std::string obtenirNom() const;
	void modifierNom(const std::string& nom);
	
	unsigned int obtenirNombreCreatures() const;

	std::list<Creature*> obtenirCreatures();
	Creature* obtenirUneCreature(const std::string& nom) const; //À MODIFIFIER !!
	void modifierCreature(std::list<Creature*>  creatures);
	
	bool ajouterCreature(Creature* creature);
	bool enleverCreature(const std::string& nom);

	ObjetMagique obtenirObjetMagique() const;
	void modifierObjetMagique(const ObjetMagique& objetMagique);

	void utiliserObjetMagique(Creature* creature);

	std::string obtenirEquipe() const;
	void modifierEquipe(const std::string& equipe);

	friend std::ostream& operator<<(std::ostream& os, const Dresseur& dresseur);

	bool operator==(const Dresseur& dresseur);
	bool operator==(const std::string& nom) const;
	friend bool operator==(const std::string& nom, const Dresseur& dresseur);

	template <typename P>
	void appliquerFoncteurUnaire(P& predicat);
	template <typename P>
	void supprimerElement(const P& predicat);
	template <typename P>
	Creature* obtenirCreatureMax(const P& predicat);

private:
	std::string nom_;
	std::string equipe_;
	ObjetMagique objetMagique_;
	std::list<Creature*> listeCreatures_;

};

//appliquerFoncteurUnaire, applique le foncteur à toutes les créatures du conteneur, notez
//que l’application du foncteur sur un élément peut modifier le foncteur
template <typename P>
void Dresseur::appliquerFoncteurUnaire(P& predicat)
{
	predicat = std::for_each(listeCreatures_.begin(), listeCreatures_.end(), predicat);
}

//supprimerElement, supprime tous les éléments du conteneur pour lesquels l’application
//du foncteur passé en argument retourne true. Pensez à utiliser la méthode remove_if
//appropriée
template <typename P>
void Dresseur::supprimerElement(const P& predicat)
{
	std::remove_if(listeCreatures_.begin(), listeCreatures_.end(), predicat);
}

//obtenirCreatureMax, prend un foncteur en argument, et retourne la créature max selon
//l’ordre induit par le foncteur
template <typename P>
Creature* Dresseur::obtenirCreatureMax(const P& predicat)
{
	auto i = std::max_element(listeCreatures_.begin(), listeCreatures_.end(), predicat);
	if (i != listeCreatures_.end())
		return *i;
	else
		return nullptr;
}

#endif
