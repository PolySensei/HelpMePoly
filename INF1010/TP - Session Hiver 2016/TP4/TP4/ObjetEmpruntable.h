/****************************************************************************
* Fichier: ObjetEmpruntable.h
* Auteur: PolySensei & Associates
* Date: 22 février 2016
* Mise a jour : 3 mars 2016
* Description: Définition de la classe ObjetEmrpuntable
****************************************************************************/
#ifndef OBJETEMPRUNTABLE_H
#define OBJETEMPRUNTABLE_H

#include <string>
#include <iostream>
#include <typeinfo>


class ObjetEmpruntable
{
public :

	/// TP4

	std::string ObjetEmpruntable::obtenirNomClasse() const;
	void afficherObjetEmpruntable(std::ostream& o) const;
	virtual ~ObjetEmpruntable();
	
	/// Anciens TP
	ObjetEmpruntable();
	ObjetEmpruntable(const std::string& cote, const std::string& titre, unsigned int annee, unsigned int ageMin, unsigned int nbExemplaires);
	
	std::string obtenirCote() const;
	std::string obtenirTitre() const;
	unsigned int obtenirAnnee() const;
	unsigned int obtenirAgeMinimal() const;
	unsigned int obtenirNbExemplaires() const;
	unsigned int obtenirNbDisponibles() const;

	//convertirMinuscule permet de convertir une phrase en minuscule
	std::string convertirMinuscule(const std::string& phrase) const;

	void modifierNbExemplaires(unsigned int nbExemplaires);
	void modifierNbDisponibles(unsigned int nbDisponibles);
	void modifierTitre(const std::string& titre);
	void modifierCote(const std::string& cote);
	void modifierAnnee(unsigned int annee);
	//recherche renvoie un true si le motsCle est présent dans le titre ou dans la cote; false sinon
	virtual bool recherche(const std::string& motsCle) const; // TP4 : Ajout de virtual


	friend std::ostream& operator<<(std::ostream& o, const ObjetEmpruntable& objetEmpruntable);
	bool operator==(const ObjetEmpruntable& objetEmpruntable) const;
	bool operator==(const std::string& cote) const;
	friend bool operator==(const std::string& cote,  const ObjetEmpruntable& objetEmpruntable);
	bool operator< (const ObjetEmpruntable& objetEmpruntable) const;



	
protected:
	std::string cote_;
	std::string titre_;
	unsigned int annee_;
	unsigned int ageMinimal_;
	unsigned int nbExemplaires_;
	unsigned int nbDisponibles_;
};

#endif
