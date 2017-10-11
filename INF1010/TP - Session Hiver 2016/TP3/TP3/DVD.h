/****************************************************************************
* Fichier: DVD.h
* Auteur: PolySensei & Associates
* Date: 11 février 2016
* Mise a jour : 20 février 2016
* Description: Définition de la classe DVD
****************************************************************************/
#ifndef DVD_H
#define DVD_H

#include <string>
#include <vector>
#include <iostream>
#include "ObjetEmpruntable.h"

//Héritage de la classe ObjetEmpruntable
class Dvd : public ObjetEmpruntable{

public:

	Dvd(const std::string& cote, const std::string& titre, unsigned int annee, unsigned int ageMin, unsigned int nbExemplaires, const std::string& realisateur, std::vector<std::string> vecActeurs);
	
	~Dvd();

	std::string obtenirRealisateur() const;
	std::vector<std::string> obternirActeurs() const;

	
	void modifierRealisateur(const std::string& unRealisateur);
	void ajouterActeur(const std::string& acteur);
	bool retirerActeur(const std::string& acteur);


	bool recherche(const std::string& motsCle) const;

	friend std::ostream& operator<<(std::ostream& out, const Dvd& dvd);

private:
	// Realisateur(string)
	std::string realisateur_;

	// Un vecteur de string qui correspond aux acteurs
	std::vector<std::string> vecActeurs_;

};

#endif