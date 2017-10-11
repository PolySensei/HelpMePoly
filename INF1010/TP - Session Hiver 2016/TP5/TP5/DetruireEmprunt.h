/****************************************************************************
* Fichier: DetruireEmprunt.h
* Auteur: PolySensei & Associates
* Date: 7 mars 2016
* Mise a jour : 28 mars 2016
* Description: Définition et implémentation du foncteur DetruireEmprunt
****************************************************************************/
#ifndef DETRUIREEMPRUNT_H
#define DETRUIREEMPRUNT_H

#include "Emprunt.h"

using namespace std;

class DetruireEmprunt{

public:
	DetruireEmprunt(){}

	bool operator()(Emprunt* ptrEmprunt){
		delete ptrEmprunt;
		return true;
	}
};

#endif