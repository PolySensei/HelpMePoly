/****************************************************************************
* Fichier: Professeur.h
* Auteur: PolySensei & Associates
* Date: 6 mars 2016
* Mise a jour : 28 mars 2016
* Description: Définition de la classe Professeur
****************************************************************************/
#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include <list>
#include <algorithm>
#include <string>
#include <functional>
#include "Abonne.h"

class Professeur :
	public Abonne
{
public:
	Professeur();
	Professeur(const std::string& matricule, const std::string& nom, const std::string& prenom, unsigned int age, std::list<std::string> ecoles);
	~Professeur();

	std::list<std::string> obtenirEcole() const;
	void ajouterEcole(std::string const& ecole);
	bool retirerEcole(std::string const& ecole);
	virtual unsigned int obtenirLimiteEmprunt() const;

	friend std::ostream & operator<<(std::ostream & o, const Professeur & professeur);

private:
	// liste qui contient les écoles
	std::list<std::string> listeEcole_;
};
#endif 
