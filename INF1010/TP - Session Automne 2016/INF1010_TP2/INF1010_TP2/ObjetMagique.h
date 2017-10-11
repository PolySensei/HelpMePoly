/****************************************************************************
* Fichier: ObjetMagique.h
* Auteur: Poly Sensei 091111 & Associates
* Date: 28 septembre 2016
* Mise a jour :  03 octobre 2016
* Description: Definition de la classe ObjetMagique
****************************************************************************/

#ifndef OBJETMAGIQUE_H
#define OBJETMAGIQUE_H

#include <string>

class ObjetMagique
{
public:
	ObjetMagique();
	ObjetMagique(const std::string &nom, int bonus);
	~ObjetMagique();

	std::string obtenirNom() const;
	int obtenirBonus() const;

	void modifierNom(const std::string& nom);
	void modifierBonus(int bonus);

	friend std::ostream& operator<< (std::ostream& out, const ObjetMagique& objetMagique);

private:
	std::string nom_;
	int bonus_;
};

#endif
