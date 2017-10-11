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
	LivreNumerique(FORMAT_DOCUMENT format,
		unsigned int tailleOctet, std::string lien,
		const std::string& cote, const std::string& titre, unsigned int annee,
		unsigned int ageMin, unsigned int nbExemplaires, 
		const std::string& auteur, const std::string& genre
		);
	virtual ~LivreNumerique();

	FORMAT_DOCUMENT obtenirFormat() const;
	void modifierFormat(FORMAT_DOCUMENT format);
	std::string obtenirFormatStr() const;

	virtual bool recherche(const std::string& motsCle) const;
	friend std::ostream & operator<<(std::ostream & o, const LivreNumerique & objet);



	// Redéfinition des méthodes de ObjetNumerique
	void modifierTaille(unsigned int tailleOctet);
	unsigned int obtenirTaille() const;
	void modifierLien(std::string lien);
	std::string obtenirLien() const;

private:
	FORMAT_DOCUMENT format_;
	unsigned int tailleOctet_;
	std::string lien_;

};


#endif // LIVRENUMERIQUE_H
