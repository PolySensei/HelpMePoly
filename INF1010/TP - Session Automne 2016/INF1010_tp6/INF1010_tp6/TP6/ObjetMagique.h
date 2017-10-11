/*
Fichier: ObjetMagique.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description: La classe ObjetMagique correspond aux differents objets utilisables
			par le dresseur sur ses creatures
*/
#ifndef OBJETMAGIQUE_H
#define OBJETMAGIQUE_H

#include <string>
#include <iostream>


class ObjetMagique
{
public:
	ObjetMagique();
	ObjetMagique(const std::string &nom, int bonus);
	~ObjetMagique();

	std::string obtenirNom() const;
	int obtenirBonus() const;

	void modifierNom(const std::string& nom);
	void modifierBonus(int bonus);

	friend std::ostream& operator<<(std::ostream& os, const ObjetMagique& objet);

private:
	std::string nom_;
	int bonus_;
};

#endif
