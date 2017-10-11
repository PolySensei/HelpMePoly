/****************************************************************************
* Fichier: Emprunt.h
* Auteur: PolySensei & Associates
* Date: 22 février 2016
* Mise a jour : 3 mars 2016
* Description: Définition de la classe Emprunt
****************************************************************************/
#ifndef EMPRUNT_H
#define EMPRUNT_H

#include <string>
#include "Livre.h"
#include "Dvd.h"

class Emprunt
{
public:

	~Emprunt();

	std::string obtenirMatricule() const;
	unsigned int obtenirDateRetour() const;

	void modifierMatricule(const std::string& matricule);
	void modifierDateRetour(unsigned int date);



	/// _____ TP4 _____
	Emprunt(const std::string& matricule, ObjetEmpruntable* objEmprunt, unsigned int dateRetour);
	ObjetEmpruntable* obtenirObjEmprunt() const;
	void modifierObjEmprunt(ObjetEmpruntable* objEmprunt);	

	friend std::ostream& operator<<(std::ostream& out, const Emprunt& emprunt); 




private:
	std::string matricule_;
	unsigned int dateRetour_;

	/// _____ TP4 _____
	//Ajout de l'attribut du pointeur de type ObjetEmpruntable
	ObjetEmpruntable* objEmprunt_;

};

#endif