/****************************************************************************
* Fichier: Pouvoir.h
* Auteur:Poly Sensei 091111 & Associates
* Date: 28 septembre 2016
* Mise a jour :  03 octobre 2016
* Description: Definition de la classe Pouvoir
****************************************************************************/

#ifndef POUVOIR_H
#define POUVOIR_H

#include <string>
class Pouvoir
{
public:
	Pouvoir();
	Pouvoir(const std::string& nom, 
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	Pouvoir::Pouvoir(const Pouvoir& pouvoir);
	~Pouvoir();

	unsigned int obtenirNombreDeDegat() const;
	unsigned int obtenirEnergieNecessaire() const;
	std::string obtenirNom() const;

	void modifierNombreDeDegat(unsigned int nombreDegat);
	void modifierEnergieNecessarie(unsigned int energieNecessaire);
	void modifierNom(const std::string& nom);

	void operator=(Pouvoir& pouvoir);
	bool operator==(std::string& nom) const;
	friend std::ostream& operator<< (std::ostream& out, const Pouvoir& pouvoir);


	//________TP2________

private:
	std::string nom_;
	unsigned int nombreDeDegat_ ;
	unsigned int energieNecessaire_;

};

#endif