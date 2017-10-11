/*
Fichier: Empruntable.h
Auteur(s): Mohamed Amine Kibiche
Date de creation: 25 février 2016
Date de modification: 25 février 2016
Description: 
*/
#include "Empruntable.h"

Empruntable::Empruntable(const std::string& matricule, const std::string& cote, bool& estDejaEmprunte,unsigned int& nombreEmrunte) : matricule_(matricule), 
cote_(cote), estDejaEmprunte_(&estDejaEmprunte), nombreEmrunte_(&nombreEmrunte)
{}

bool  Empruntable::operator() (Emprunt *element)
{
	if (element->obtenirMatricule() == matricule_)
	{
		(*nombreEmrunte_)++;
		if ((*element->obtenirObjetEmpruntable()) == cote_)
			(*estDejaEmprunte_) = true;
		return true;
	}
	return false;
}
int Empruntable::obtenirNombreEmrunte() 
{ 
	return *nombreEmrunte_; 
}
bool Empruntable::estDejaEmrunte() 
{ 
	return *estDejaEmprunte_; 
}
