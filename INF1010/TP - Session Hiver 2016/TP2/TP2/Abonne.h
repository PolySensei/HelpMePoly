
/****************************************************************************
* Fichier: Abonne.h
* Auteur : PolySensei & Associates
* Date : 4 février 2016
* Mise a jour : 6 février 2016
* Description : Définition de la classe Abonne
****************************************************************************/

#ifndef ABONNE_H
#define ABONNE_H

#include "Emprunt.h"
#include "Livre.h"
#include <string>
#include <vector>
#include <iostream>

class Abonne
{
public:
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

	std::vector<Emprunt*> obtenirListeEmprunt() const;
	int obtenirNombreEmprunte() const;
	bool estEmprunte(const Livre& unLivre) const;
	void ajouterEmprunt(Emprunt* unEmprunt);
	bool retirerEmprunt(Livre& unLivre); 

	friend std::ostream& operator<< (std::ostream& out, const Abonne& unAbonne);
	bool operator==(Abonne&) const;
	bool operator==(std::string unMatricule) const;
	friend bool operator==(std::string unMatricule, Abonne&);
	
private:
	std::string matricule_;
	std::string nom_;
	std::string prenom_;
	unsigned int age_;
	std::vector<Emprunt*> listeEmprunt_;

};


#endif