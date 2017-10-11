/****************************************************************************
* Fichier: ObjetNumerique.h
* Auteur: PolySensei & Associates
* Date: 22 février 2016
* Mise a jour : 3 mars 2016
* Description: Définition de la classe ObjetNumerique
****************************************************************************/
#ifndef	OBJETNUMERIQUE_H
#define OBJETNUMERIQUE_H

#include <string>

class ObjetNumerique
{
public:

	// Un destructeur.
	virtual ~ObjetNumerique() {}

	// Bien que la classe ne contienne aucun attribut, il est tout de même demandé de faire des méthodes 
	// d’accès et de modifications. Ceci va forcer les classes dérivées à implémenter les attributs nécessaires. 
	// Ainsi, on demande de faire les méthodes d’accès et de modification virtuelles pures pour : 
	//	o La taille du document numérique(entier positif), en octets. 
	//	o Le lien internet(string) vers l’objet numérique.
	virtual unsigned int obtenirTaille() const = 0;
	virtual std::string obtenirLienInternet() const = 0;
	virtual void modifierTaille(unsigned int taille) = 0;
	virtual void modifierLien(const std::string& lien) = 0;

		
};



#endif

