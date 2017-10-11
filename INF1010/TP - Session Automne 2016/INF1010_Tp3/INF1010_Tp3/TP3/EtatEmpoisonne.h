/****************************************************************************
* Fichier: EtatEmpoisonne.h
* Auteur: Poly Sensei 091111 & Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Définition de la classe EtatEmoisonne
****************************************************************************/
#ifndef ETATEMPOISONNE_H
#define ETATEMPOISONNE_H

#include <string>
#include "EtatCreature.h"
#include <vector>
#include <iostream>


class EtatEmpoisonne : public EtatCreature
{
public:
	EtatEmpoisonne(const std::string& nom);
	EtatEmpoisonne(const std::string& nom, unsigned int duree);
	~EtatEmpoisonne();

	friend std::ostream& operator<<(std::ostream& o, const EtatEmpoisonne& etatEmpoisonne);

	void appliquerEtat(Creature& creature);
	bool estFini() const;
};


#endif
