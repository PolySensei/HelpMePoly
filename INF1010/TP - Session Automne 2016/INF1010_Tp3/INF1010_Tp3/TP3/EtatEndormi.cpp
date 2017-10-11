/****************************************************************************
* Fichier: EtatEndormis.cpp
* Auteur: PolySensei 091111 and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Implémentation de la classe EtatEndormis
****************************************************************************/

#include "EtatEndormis.h"


//Un constructeur qui prend le nom en argument
EtatEndormi::EtatEndormi(const std::string & nom) : EtatCreature(nom)  
{
	type_ = TypeEtat::TypeEtat_endormi;
}
//Un constructeur qui prend le nom et la durée de l’état en argument
EtatEndormi::EtatEndormi(const std::string & nom, unsigned int duree) : EtatCreature(nom, duree)  
{
	type_ = TypeEtat::TypeEtat_endormi;
}
//Un destructeur
EtatEndormi::~EtatEndormi()
{
}
//La méthode appliquerEtat décrémente la durée si la durée est positive
void EtatEndormi::appliquerEtat(Creature & creature)
{
	if (duree_ > 0) {
		duree_--;
	}
}
// La méthode peutAttaquer qui renvoie false
bool EtatEndormi::peutAttaquer() const
{
	return false;
}
//La méthode estFini renvoie true si durée est inférieur ou égal à 0

bool EtatEndormi::estFini() const
{
	if (duree_ <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//Fonction d'affichage
std::ostream & operator<<(std::ostream & o, const EtatEndormi & EtatEndormi)
{
	o << "etat" << EtatEndormi.obtenirNom() << " durera " << EtatEndormi.duree_ << std::endl;

	return o;
}