/****************************************************************************
* Fichier: Emprunt.h
* Auteur: PolySensei & Associates
* Date: 11 février 2016
* Mise a jour : 21 février 2016
* Description: Définition de la classe Emprunt
****************************************************************************/
#ifndef EMPRUNT_H
#define EMPRUNT_H

#include <string>
#include "Livre.h"
#include "DVD.h"

class Emprunt
{
public:
	Emprunt();
	Emprunt(const std::string& matricule, Livre* livre, unsigned int dateRetour);
	Emprunt(const std::string& matricule, Dvd* dvd, unsigned int dateRetour);
	~Emprunt();

	std::string obtenirMatricule() const;
	Livre* obtenirLivre() const;		
	unsigned int obtenirDateRetour() const;
	void modifierMatricule(const std::string& matricule);
	void modifierLivre(Livre *livre);
	void modifierDateRetour(unsigned int date);


	//_______TP3_______
	Dvd* obtenirDVD() const;
	void modifierDVD(Dvd *dvd);
	ObjetEmpruntable* obtenirObjetEmpruntable() const; 
	friend std::ostream& operator<<(std::ostream& out, const Emprunt& emprunt);


private:
	std::string matricule_;
	Livre* livre_;
	unsigned int dateRetour_;

	// Pointeur de DVD
	Dvd* dvd_;
};

#endif
