/****************************************************************************
* Fichier: PouvoirHallucinogene.cpp
* Auteur: PolySensei and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Implémentation de la classe PouvoirHallucinogene
****************************************************************************/

#include "PouvoirHallucinogene.h"
#include <iostream>


PouvoirHallucinogene::PouvoirHallucinogene()
{
}
//Un constructeur par paramètres ayant les mêmes paramètres que celui de la
//classe mère
PouvoirHallucinogene::PouvoirHallucinogene(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire) :
	Pouvoir(nom, nombreDeDegat, energieNecessaire)
{
	type_ = TypeEtat_confus;
}
//Un constructeur comprenant les mêmes paramètres que ceux du constructeur
//précédent ainsi qu’une durée
PouvoirHallucinogene::PouvoirHallucinogene(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree) :
	Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_ (duree)
{
	type_ = TypeEtat_confus;
}
//Un destructeur
PouvoirHallucinogene::~PouvoirHallucinogene()
{
}
//appliquerEffetOffensif modifie l’état de la créature cible vers l’état confus
void PouvoirHallucinogene::appliquerEffetOffensif(Creature & creatureEnnemie)
{
	EtatConfus* etatConfus = new EtatConfus("Confus", duree_);
	creatureEnnemie.modifierEtat(etatConfus);
}

//Affichage
std::ostream& operator<<(std::ostream& os, const PouvoirHallucinogene& PouvoirHallucinogene)
{
	return os << PouvoirHallucinogene.obtenirNom() << " possede un nombre de dégat de " << PouvoirHallucinogene.obtenirNombreDeDegat() <<
		" et une energie necessaire de " << PouvoirHallucinogene.obtenirEnergieNecessaire() << std::endl << " il peut rendre confus la cible" << std::endl;
}
