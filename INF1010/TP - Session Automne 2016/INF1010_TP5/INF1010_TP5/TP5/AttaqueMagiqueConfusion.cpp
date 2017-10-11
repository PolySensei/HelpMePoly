/****************************************************************************
* Fichier: AttaqueMagiqueConfusion.cpp
* Auteur: PolySensei and Associates
* Date: 7 novembre 2016 Mise a jour : 21 novembre 2016
* Description: Implémentation de la classe AttaqueMagiqueConfusion
****************************************************************************/
#include "AttaqueMagiqueConfusion.h"

//Le constructeur doit initialiser le nouvel attribut pour que le tirage soit fait dans l’intervalle
//[1,6]..
AttaqueMagiqueConfusion::AttaqueMagiqueConfusion() :AttaqueMagique(MIN_DUREE_CONFUSION) // À MODIFIER
{
	FoncteurGenerateurNombresAlea foncteurConfusion_(1, 6);
}

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(unsigned int duree) :AttaqueMagique(duree) // À MODIFIER
{
	FoncteurGenerateurNombresAlea foncteurConfusion_(1, 6);
}

AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion()
{
}

//appliquerAttaque doit utiliser le foncteur pour les tirages aléatoires

void AttaqueMagiqueConfusion::appliquerAttaque(Creature & creature) 
{
    if (duree_ > 0 && creature.obtenirPointDeVie() >= 5) 
	{
        unsigned int pointDeVie = creature.obtenirPointDeVie();
        if (foncteurConfusion_() == 1) 
		{
            creature.modifierPointDeVie(pointDeVie - 2);
        }
        duree_--;
    }
}

bool AttaqueMagiqueConfusion::estFini() const
{
    return ( duree_ <= 0 );
}

std::string AttaqueMagiqueConfusion::obtenirTypeAttaque() const
{
	return (typeid(*this).name());
}
