/****************************************************************************
* Fichier: EtatCreature.cpp
* Auteur: Poly Sensei 091111 & Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Implémentation de la classe EtatCreature
****************************************************************************/

#include "EtatCreature.h"

#include "Creature.h"


//Un constructeur par paramètre qui prend comme argument le nom de l’état,
EtatCreature::EtatCreature(const std::string & nom) : nom_(nom), duree_(0), type_(TypeEtat::TypeEtat_normal)
{
}
//Un constructeur par paramètre qui prend comme argument le nom de l’état et une durée
EtatCreature::EtatCreature(const std::string & nom, unsigned int duree) : nom_(nom), duree_(duree), type_(TypeEtat::TypeEtat_normal)
{
}
//Destructeur
EtatCreature::~EtatCreature()
{
}
//Une méthode appliquerEtat qui sera surchargée dans les classes dérivées
void EtatCreature::appliquerEtat(Creature & creature)
{
}
//Une méthode peutAttaquer qui détermine si une créature peut attaquer à ce tour. 
bool EtatCreature::peutAttaquer() const
{
    return rand() % 6 != 0;
}
//Une méthode estFini qui caractérise si la créature peut revenir à un état normal. 
bool EtatCreature::estFini() const
{
    return false;
}
//Deux accesseurs pour le nom et l’attribut type
std::string EtatCreature::obtenirNom() const
{
    return nom_;
}

TypeEtat EtatCreature::obtenirType() const
{
    return type_;
}
//La fonction friend : operateur<< , pour afficher le nom de l’état.
std::ostream & operator<<(std::ostream & o, const EtatCreature & etatCreature)
{
    o << "etat" << etatCreature.nom_ << std::endl;

    return o;
}
