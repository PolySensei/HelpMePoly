/****************************************************************************
* Fichier: Emprunt.h
* Auteur: PolySensei & Associates
* Date: 4 février 2016
* Mise a jour : 6 février 2016
* Description: Définition de la classe Emprunt
****************************************************************************/

#ifndef EMPRUNT_H
#define EMPRUNT_H

#include <string>
#include "Livre.h"

class Emprunt
{
public:
	Emprunt(std::string matricule, Livre* livre, unsigned int date);
	~Emprunt();

	std::string obtenirMatricule() const;
	Livre* obtenirLivre() const;
	unsigned int obtenirDateRetour() const;

	void modifierMatricule(const std::string& matricule);
	void modifierLivre(Livre *livre);
	void modifierDateRetour(unsigned int date);

	friend std::ostream& operator<< (std::ostream&, const Emprunt&);


private:
	std::string matricule_;
	Livre *livre_;
	unsigned int dateRetour_;
};


#endif