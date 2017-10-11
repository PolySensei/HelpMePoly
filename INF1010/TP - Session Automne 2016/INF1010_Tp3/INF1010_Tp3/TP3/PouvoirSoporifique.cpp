/****************************************************************************
* Fichier: PouvoirSoporifique.cpp
* Auteur: PolySensei and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Implémentation de la classe PouvoirSoporifique
****************************************************************************/

#include "PouvoirSoporifique.h"
#include <iostream>


PouvoirSoporifique::PouvoirSoporifique()
{
}
//Un constructeur par paramètres ayant les mêmes paramètres que celui de la
//classe mère
PouvoirSoporifique::PouvoirSoporifique(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire) :
	Pouvoir(nom, nombreDeDegat, energieNecessaire)
{
	type_ = TypeEtat_endormi;
}
//Un constructeur comprenant les mêmes paramètres que ceux du constructeur
//précédent ainsi qu’une durée
PouvoirSoporifique::PouvoirSoporifique(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree) :
	Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_(duree)
{
	type_ = TypeEtat_endormi;
}
//Un destructeur
PouvoirSoporifique::~PouvoirSoporifique()
{
}
//appliquerEffetOffensif modifie l’état de la créature cible vers l’état endormi
void PouvoirSoporifique::appliquerEffetOffensif(Creature & creatureEnnemie)
{
	EtatEndormi* etatEndormi = new EtatEndormi("Endormi", duree_);
	creatureEnnemie.modifierEtat(etatEndormi);
}

//Affichage
std::ostream& operator<<(std::ostream& os, const PouvoirSoporifique& PouvoirSoporifique)
{
	return os << PouvoirSoporifique.obtenirNom() << " possede un nombre de dégat de " << PouvoirSoporifique.obtenirNombreDeDegat() <<
		" et une energie necessaire de " << PouvoirSoporifique.obtenirEnergieNecessaire() << std::endl << "il peut endormir la cible" << std::endl;
}
