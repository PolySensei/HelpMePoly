/***************************************************************************
* Fichier: Livre.h
* Auteur: PolySensei & Associates
* Date: 4 février 2016
* Mise a jour : 6 février 2016
* Description: Définition de la classe Livre
****************************************************************************/
#ifndef LIVRE_H
#define LIVRE_H

#include <string>
#include <iostream>

class Livre
{
public:
	Livre();
	Livre(const Livre& unLivre);
	Livre(const std::string& cote, const std::string& titre, unsigned int annee, 
		unsigned int ageMin, unsigned int nbExemplaires);
	~Livre();

	std::string obtenirCote() const;
	std::string obtenirTitre() const;
	unsigned int obtenirAnnee() const;
	unsigned int obtenirAgeMinimal() const;
	unsigned int obtenirNbExemplaires() const;
	unsigned int obtenirNbDisponibles() const;

	std::string convertirMinuscule(const std::string& phrase) const;

	void modifierNbExemplaires(unsigned int nbExemplaires);
	void modifierNbDisponibles(unsigned int nbDisponibles);
	void modifierTitre(const std::string& titre);
	void modifierCote(const std::string& cote);
	void modifierAnnee(unsigned int annee);
	bool recherche(const std::string& motsCle) const;

	friend std::ostream& operator<<(std::ostream&, const Livre&);
	bool operator==(Livre&) const;
	bool operator==(std::string uneCote) const;
	friend bool operator==(std::string uneCote, Livre&);
	bool operator<(Livre&) const;
	const Livre& operator=(const Livre& unLivre);


private:
	std::string cote_;
	std::string titre_;
	unsigned int annee_;
	unsigned int ageMinimal_;
	unsigned int nbExemplaires_;
	unsigned int nbDisponibles_;
	
};


#endif