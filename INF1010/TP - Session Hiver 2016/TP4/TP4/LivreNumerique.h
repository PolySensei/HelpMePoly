/****************************************************************************
* Fichier: LivreNumerique.h
* Auteur: PolySensei & Associates
* Date: 22 février 2016
* Mise a jour : 3 mars 2016
* Description: Définition de la classe livreNumerique
****************************************************************************/

#ifndef LIVRENUMERIQUE_H
#define LIVRENUMERIQUE_H


#include "ObjetNumerique.h"
#include "Livre.h"
#include <string>
#include <iostream>


/* Enumeration pour les types de documents possibles
- FORMAT_PDF:		Le format du livre est en "pdf"
- FORMAT_EPUB:		Le format du livre est en "epub"
- FORMAT_DOCX:		Le format du livre est en "docx"
- FORMAT_TXT:		Le format du livre est en "txt"
- FORMAT_INCONNU :	Le format du livre est inconnu
*/
enum FORMAT_DOCUMENT
{
	FORMAT_PDF		= 0,
	FORMAT_EPUB		= 1,
	FORMAT_DOCX		= 2,
	FORMAT_TXT		= 3,
	FORMAT_INCONNU	= 4,
};



class LivreNumerique :	public ObjetNumerique, public Livre
{
public:
	
	LivreNumerique();
	LivreNumerique(FORMAT_DOCUMENT format, unsigned int tailleOctet, const std::string& lien, const std::string& cote, const std::string& titre, unsigned int annee, unsigned int ageMin, unsigned int nbExemplaires, const std::string& auteur, const std::string& genre);
	~LivreNumerique();

	// Les autres méthodes d’accès et de modification aux attributs sont hérités via la classe Livre.
	unsigned int obtenirTaille() const;
	std::string obtenirLienInternet() const;
	FORMAT_DOCUMENT obtenirFormat() const;
	void modifierTaille(unsigned int taille);
	void modifierLien(const std::string& lien);
	void modifierFormat(const FORMAT_DOCUMENT& format);

	std::string obtenirFormatStr() const;
	bool recherche(const std::string& motsCle) const;
	friend std::ostream& operator<<(std::ostream& o, const LivreNumerique& livreNumerique);


private:
	//Nouvel attribut format_ indiquant le format du document
	FORMAT_DOCUMENT format_;

	//tailleOctet_Taille du document en octet
	unsigned int tailleOctet_;

	//Lien internet vers l'objet numérique
	std::string lien_;

};


#endif
