/*
Fichier: RechercheObjetEmpruntable.h
Auteur(s): Mohamed Amine Kibiche
Date de creation: 25 février 2016
Date de modification: 25 février 2016
Description: Foncteur permet de chercher un str dans un ObjetEmpruntable
*/
#ifndef RECHERCHEOBJETEMPRUNTABLE_H
#define RECHERCHEOBJETEMPRUNTABLE_H

#include "ObjetEmpruntable.h"
#include <string>
class RechercheObjetEmpruntable
{
public:

	RechercheObjetEmpruntable(const std::string& cote) : cote_(cote) {};
	bool operator() (ObjetEmpruntable *element)
	{
		if (element != nullptr)
			return element->recherche(cote_);
		return false;
	};

private:
	std::string cote_;

};

#endif // RECHERCHEOBJETEMPRUNTABLE_H