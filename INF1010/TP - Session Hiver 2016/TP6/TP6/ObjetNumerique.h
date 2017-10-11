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

