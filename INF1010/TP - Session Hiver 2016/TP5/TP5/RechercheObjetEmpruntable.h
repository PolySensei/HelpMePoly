/****************************************************************************
* Fichier: RechercheObjetEmpruntable.h
* Auteur: PolySensei & Associates
* Date: 7 mars 2016
* Mise a jour : 28 mars 2016
* Description: Définition et implémentation du foncteur RechercheObjetEmpruntable
****************************************************************************/


#ifndef RECHERCHEOBJETEMPRUNTABLE_H
#define RECHERCHEOBJETEMPRUNTABLE_H
#include "ObjetEmpruntable.h"


//Écrire un foncteur prédicat unaire pour un algorithme de la librairie STL qui permet de chercher un string dans les objets empruntables.Il va rechercher les différents éléments empruntables dans le gestionnaire d’objet de la bibliothèque qui contiennent l’information désirée.Il retourne true si l’information a été trouvée, false sinon.
class RechercheObjetEmpruntable
{
public:

	RechercheObjetEmpruntable(const std::string& str) :motCle_(str) {};

	bool operator()(ObjetEmpruntable* ptrObjet)
	{
		return ptrObjet->recherche(motCle_);
	}

private:
	std::string motCle_;


};

#endif


