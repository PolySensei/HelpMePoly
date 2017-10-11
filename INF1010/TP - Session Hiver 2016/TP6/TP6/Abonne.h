/*
Fichier: Abonne.h
Auteur(s): Karim Keddam
			Mohamed Amine Kibiche
Date de creation: 8 janvier 2016
Date de modification: 25 février 2016
Description: Description de la classe Abonne
*/

#ifndef ABONNE_H
#define ABONNE_H

#include <string>
#include "Emprunt.h"
#include "ObjetEmpruntable.h"
#include <iostream>

#define LIMITE_EMPRUNTS 2

class Abonne
{
public:

	/// TP4
	virtual std::string Abonne::obtenirNomClasse() const;


	/// TP3
	Abonne();
	Abonne(const std::string& matricule, const std::string& nom, const std::string& prenom, unsigned int age);

	~Abonne();

	std::string obtenirMatricule() const;	
	std::string obtenirNom() const;
	std::string obtenirPrenom() const;
	unsigned int obtenirAge() const;

	void modifierMatricule(const std::string& matricule);
	void modifierNom(const std::string& nom);
	void modifierPrenom(const std::string& prenom);
	void modifierAge(unsigned int age);

	virtual unsigned int obtenirLimiteEmprunt() const;
	friend std::ostream& operator<<(std::ostream& o, const Abonne& abonne);
	bool operator==(const Abonne& abonne) const;
	bool operator==(const std::string& matricule) const;
	friend bool operator==(const std::string& matricule, const Abonne& abonne);


private:
	std::string matricule_;
	std::string nom_;
	std::string prenom_;
	unsigned int age_;

	/// ____TP3_____
	unsigned int limiteEmprunt_;

};

	
#endif
