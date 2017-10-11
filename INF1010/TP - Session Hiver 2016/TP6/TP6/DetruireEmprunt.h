/*
Fichier: DetruireEmprunt.h
Auteur(s): Mohamed Amine Kibiche
Date de creation: 25 février 2016
Date de modification: 25 février 2016
Description: Foncteur permet de detruire les emprunts
*/
#ifndef DETRUIREEMPRUNT_H
#define DETRUIREEMPRUNT_H

#include "Emprunt.h"

class DetruireEmprunt
{
public:
	bool operator() (Emprunt* element) { delete element; return true; };

};

#endif // DETRUIREEMPRUNT_H