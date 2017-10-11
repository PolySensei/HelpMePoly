/****************************************************************************
* Fichier: DVD.h
* Auteur: PolySensei & Associates
* Date: 22 février 2016
* Mise a jour : 3 mars 2016
* Description: Définition de la classe DVD
****************************************************************************/
#ifndef DVD_H
#define DVD_H
#include "ObjetEmpruntable.h"
#include <vector>

class Dvd :
	public ObjetEmpruntable
{
public:
	Dvd();
	Dvd(const std::string& cote, const std::string& titre, unsigned int annee,
		unsigned int ageMin, unsigned int nbExemplaires, std::string const& realisateur, std::vector<std::string> acteurs);

	~Dvd();

	std::string obtenirRealisateur() const;
	std::vector<std::string> obtenirActeur() const;

	void modifierRealisateur(std::string const& realisateur);
	void ajouterActeur(std::string const& acteur);
	void retirerActeur(std::string const& acteur);

	//recherche renvoie true si motsCle est présent dans les attributs de type string; false sinon
	bool recherche(const std::string& motsCle) const;

	friend std::ostream& operator<<(std::ostream& o, const Dvd& dvd);

private:
	std::string realisateur_;
	std::vector<std::string> vecActeurs_;

};
#endif

