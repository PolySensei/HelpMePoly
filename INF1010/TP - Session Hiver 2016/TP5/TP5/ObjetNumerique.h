/****************************************************************************
* Fichier: ObjetNumerique.h
* Auteur: PolySensei & Associates
* Date: 6 mars 2016
* Mise a jour : 28 mars 2016
* Description: Définition de la classe ObjetNumerique
****************************************************************************/
#ifndef	OBJETNUMERIQUE_H
#define OBJETNUMERIQUE_H



#include <string>
#include <iostream>


class ObjetNumerique
{
public:

	virtual ~ObjetNumerique() = 0 {};

	virtual void modifierTaille(unsigned int tailleOctet) = 0;
	virtual unsigned int obtenirTaille( ) const = 0;
	virtual void modifierLien(std::string lien) = 0;
	virtual std::string obtenirLien() const = 0;
	
};



#endif

