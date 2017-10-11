/****************************************************************************
* Fichier: EtatConfus.h
* Auteur: Poly Sensei 091111 & Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Définition de la classe EtatConfus
****************************************************************************/
#ifndef ETATCONFUS_H
#define ETATCONFUS_H

#include <string>
#include "EtatCreature.h"
#include <vector>
#include <iostream>

class EtatConfus : public EtatCreature
{
public:
	EtatConfus(const std::string& nom);
	EtatConfus(const std::string& nom, unsigned int duree);
	~EtatConfus();

	friend std::ostream& operator<<(std::ostream& o, const EtatConfus& etatConfus);

	bool peutAttaquer() const;
	void appliquerEtat(Creature& creature);
	bool estFini() const;
};


#endif
#pragma once
