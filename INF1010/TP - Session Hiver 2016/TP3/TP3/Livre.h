/****************************************************************************
* Fichier: Livre.h
* Auteur: PolySensei & Associates
* Date: 11 février 2016
* Mise a jour : 20 février 2016
* Description: Définition de la classe livre
****************************************************************************/
#ifndef LIVRE_H
#define LIVRE_H

#include <string>
#include <vector>
#include <iostream>
#include "ObjetEmpruntable.h"

//Héritage de la classe ObjetEmpruntable
class Livre : public ObjetEmpruntable {

public:
	Livre();
	Livre(const std::string &cote, const std::string &titre, unsigned int annee, unsigned int ageMin, unsigned int nbExemplaires, const std::string &auteur, const std::string &genre);

	~Livre();

	std::string obtenirAuteur() const;
	std::string obtenirGenre() const;

	
	void modifierAuteur(const std::string& unAuteur);
	void modifierGenre(const std::string& unGenre);

	bool recherche(const std::string& motsCle) const;
	friend std::ostream& operator<<(std::ostream& out, const Livre& livre);


private:
	// Auteur(string)
	std::string auteur_;

	// Genre(string), qui représente la catégorie à laquelle appartient le livre.
	std::string genre_;
};

#endif