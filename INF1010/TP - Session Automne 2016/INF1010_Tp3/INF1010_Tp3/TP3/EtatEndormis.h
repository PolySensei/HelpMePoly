/****************************************************************************
* Fichier: EtatEndormis.h
* Auteur: PolySensei 091111 and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Définition de la classe EtatEndormis
****************************************************************************/
#ifndef ETATENDORMIS_H
#define ETATENDORMIS_H

#include <string>
#include "EtatCreature.h"
#include <vector>
#include <iostream>


class EtatEndormi : public EtatCreature
{
public:
	EtatEndormi(const std::string& nom);
	EtatEndormi(const std::string& nom, unsigned int duree);
	~EtatEndormi();

	friend std::ostream& operator<<(std::ostream& o, const EtatEndormi& etatEndormi);

	bool peutAttaquer() const;
	void appliquerEtat(Creature& creature);
	bool estFini() const;
};


#endif
