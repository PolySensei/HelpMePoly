/****************************************************************************
* Fichier: Pouvoir.h
* Auteur: Poly Sensei 091111 & Associates
* Date: 14 septembre 2016
* Mise a jour : 26 septembre 2016
* Description: Définiton de la classe Pouvoir
****************************************************************************/

#ifndef POUVOIR_H
#define POUVOIR_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Pouvoir
{
public:
	Pouvoir();
	Pouvoir(const std::string& nom, unsigned int degat, unsigned int energieNecessaire);
	~Pouvoir();

	std::string obtenirNom() const;
	unsigned int obtenirDegat() const;
	unsigned int obtenirEnergieNecessaire() const;

	void modifierNom(const std::string& nom);
	void modifierDegat(unsigned int& degat);
	void modifierEnergieNecessaire(unsigned int& energieNecessaire);

	void description() const;

private:

	std::string nom_;
	unsigned int degat_;
	unsigned int energieNecessaire_;
};


#endif

