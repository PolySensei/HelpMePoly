/****************************************************************************
* Fichier: Objetmagique.h
* Auteur: Poly Sensei 091111 & Associates
* Date: 14 septembre 2016
* Mise a jour :  26 septembre 2016
* Description: Définiton de la classe ObjetMagique
****************************************************************************/

#ifndef OBJETMAGIQUE_H
#define OBJETMAGIQUE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class ObjetMagique
{
public:
	ObjetMagique();
	ObjetMagique(const std::string& nom, unsigned int bonus);
	~ObjetMagique();

	std::string obtenirNom() const;
	unsigned int obtenirBonus() const;

	void modifierNom(const std::string& nom);
	void modifierBonus(unsigned int bonus);

	void affichage() const;



private:

	std::string nom_;
	unsigned int bonus_;
};


#endif

