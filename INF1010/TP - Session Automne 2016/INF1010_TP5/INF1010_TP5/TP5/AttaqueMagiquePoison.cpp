/****************************************************************************
* Fichier: AttaqueMagiquePoison.cpp
* Auteur: PolySensei and Associates
* Date: 7 novembre 2016 Mise a jour : 21 novembre 2016
* Description: Implémentation de la classe AttaqueMagiquePoison
****************************************************************************/
#include "AttaqueMagiquePoison.h"

 //Le constructeur doit initialiser le nouvel attribut pour que le tirage soit fait dans l’intervalle
//[1,6].
AttaqueMagiquePoison::AttaqueMagiquePoison() : AttaqueMagique(MIN_DUREE_POISON) 
{
	FoncteurGenerateurNombresAlea foncteurPoison_(1, 6);
}

AttaqueMagiquePoison::AttaqueMagiquePoison(unsigned int duree) : AttaqueMagique(duree) 
{
	FoncteurGenerateurNombresAlea foncteurPoison_(1, 6);
}

AttaqueMagiquePoison::~AttaqueMagiquePoison()
{
}

//appliquerAttaque doit utiliser le foncteur pour les tirages aléatoires
void AttaqueMagiquePoison::appliquerAttaque(Creature & creature) 
{
	if (duree_ > 0 && creature.obtenirEnergie() >= 5)
	{
		unsigned int energie = creature.obtenirEnergie();
		if (foncteurPoison_() == 1)
		{
			creature.modifierEnergie(energie - 2);
		}
		duree_--;
	}
}

bool AttaqueMagiquePoison::estFini() const
{
    return (duree_ <= 0);
}

std::string AttaqueMagiquePoison::obtenirTypeAttaque() const
{
	return (typeid(*this).name());
}
