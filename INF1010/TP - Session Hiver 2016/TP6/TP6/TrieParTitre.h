/*
Fichier: TrieParTitre.h
Auteur(s): Mohamed Amine Kibiche
Date de creation: 25 février 2016
Date de modification: 25 février 2016
Description: Foncteur permet de vérifier si les objets sont ordre alphabétique
*/
#ifndef TRIEPARTITRE_H
#define TRIEPARTITRE_H

#include "ObjetEmpruntable.h"

class TrieParTitre
{
public:
	bool operator() (ObjetEmpruntable* element1 , ObjetEmpruntable* element2) 
	{
		if (*element1 < *element2) 
			return true; 
		return false;
	};
};

#endif // TRIEPARTITRE_H