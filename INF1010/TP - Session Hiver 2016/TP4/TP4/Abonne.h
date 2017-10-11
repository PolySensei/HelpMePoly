/****************************************************************************
* Fichier: Abonne.h
* Auteur: PolySensei & Associates
* Date: 22 février 2016
* Mise a jour : 3 mars 2016
* Description: Définition de la classe Abonne
****************************************************************************/
#ifndef ABONNE_H
#define ABONNE_H

#include <string>
#include "Emprunt.h"
#include "ObjetEmpruntable.h"
#include <vector>
#include <iostream>

#define LIMITE_EMPRUNTS 2

class Abonne
{
public:

	/// TP4
	std::string Abonne::obtenirNomClasse() const;


	/// TP3
	Abonne();
	Abonne(const std::string& matricule, const std::string& nom, const std::string& prenom, unsigned int age);

	virtual ~Abonne();

	std::string obtenirMatricule() const;	
	std::string obtenirNom() const;
	std::string obtenirPrenom() const;
	unsigned int obtenirAge() const;

	void modifierMatricule(const std::string& matricule);
	void modifierNom(const std::string& nom);
	void modifierPrenom(const std::string& prenom);
	void modifierAge(unsigned int age);

	std::vector<Emprunt*> obtenirEmprunts() const;

	unsigned int obtenirNombreEmprunte() const;
	friend std::ostream& operator<<(std::ostream& o, const Abonne& abonne);
	bool operator==(const Abonne& abonne) const;
	bool operator==(const std::string& matricule) const;
	friend bool operator==(const std::string& matricule, const Abonne& abonne);


	virtual unsigned int obtenirLimiteEmprunt() const;
	bool estEmprunte(const ObjetEmpruntable& objetEmpruntable) const;
	void ajouterEmprunt(Emprunt * emprunt);
	bool retirerEmprunt(ObjetEmpruntable * objetEmpruntable);

private:
	std::string matricule_;
	std::string nom_;
	std::string prenom_;
	unsigned int age_;
	std::vector<Emprunt*> vecEmprunts_;
	unsigned int limiteEmprunt_;

};

	
#endif
