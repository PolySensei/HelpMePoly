/****************************************************************************
* Fichier: CreatureMagique.cpp
* Auteur: PolySensei and Associates
* Date: 7 novembre 2016 Mise a jour : 21 novembre 2016
* Description: Implémentation de la classe CreatureMagique
****************************************************************************/
#include "CreatureMagique.h"

CreatureMagique::CreatureMagique() : bonus_(0)
{
	attaqueMagique_ = nullptr;
}

CreatureMagique::CreatureMagique(const Creature& creature, unsigned int bonus) :bonus_(bonus), Creature(creature)
{
	attaqueMagique_ = nullptr;
}

CreatureMagique::CreatureMagique(const CreatureMagique & creatureMagique) : Creature(creatureMagique), bonus_(creatureMagique.bonus_)
{
	if (creatureMagique.obtenirAttaque()->obtenirTypeAttaque() == typeid(AttaqueMagiqueConfusion).name())
	{
		attaqueMagique_ = new AttaqueMagiqueConfusion(creatureMagique.obtenirAttaque()->obtenirDuree());
	}
	else
	{
		attaqueMagique_ = new AttaqueMagiquePoison(creatureMagique.obtenirAttaque()->obtenirDuree());
	}
}

CreatureMagique::~CreatureMagique()
{
	delete attaqueMagique_;
	attaqueMagique_ = nullptr;
}

CreatureMagique& CreatureMagique::operator=(const CreatureMagique& creatureMagique)
{
	if (this != &creatureMagique)
	{
		Creature c(creatureMagique);
		Creature::operator=(c);
		bonus_ = creatureMagique.bonus_;
		delete attaqueMagique_;
		if (creatureMagique.obtenirAttaque()->obtenirTypeAttaque() == typeid(AttaqueMagiqueConfusion).name())
		{
			attaqueMagique_ = new AttaqueMagiqueConfusion(creatureMagique.obtenirAttaque()->obtenirDuree());
		}
		else
		{
			attaqueMagique_ = new AttaqueMagiquePoison(creatureMagique.obtenirAttaque()->obtenirDuree());
		}
	}
	return *this;
}

void CreatureMagique::attaquer(const Pouvoir & pouvoir, Creature & creature)
{
    if (obtenirPointDeVie() + bonus_ <= obtenirPointDeVieTotal()) {
        modifierPointDeVie(obtenirPointDeVie() + bonus_);
    }
    else {
        modifierPointDeVie(obtenirPointDeVieTotal());
    }
	 
	if (!attaqueMagique_->estFini()) //Si l'État est encore applicable
	{
		attaqueMagique_->appliquerAttaque(creature);  //On applique l'état sur la créature adverse
	}
	Creature::attaquer(pouvoir, creature); //Ensuite on attaque la créature
}

std::ostream& operator<<(std::ostream & os, const CreatureMagique& creature)
{
	Creature c(creature);
	os << c << "Cette créature de la " << creature.obtenirTypeCreature() << "a aussi une attaque magique de type " << creature.obtenirAttaque()->obtenirTypeAttaque();
	os << " qui a une durée de " << creature.obtenirAttaque()->obtenirDuree() << std::endl;
    return os;
}

std::string CreatureMagique::obtenirTypeCreature() const
{
	return (typeid(*this).name());
}

AttaqueMagique* CreatureMagique::obtenirAttaque() const
{
	return attaqueMagique_;
}

unsigned int CreatureMagique::obtenirBonus() const
{
	return bonus_;
}

void CreatureMagique::modifierBonus(unsigned int bonus)
{
	bonus_ = bonus;
}

void CreatureMagique::apprendreAttaqueMagique(const AttaqueMagique* attaqueMagique)
{
	if (attaqueMagique != nullptr)
	{
		delete attaqueMagique_;
	}
	if (attaqueMagique->obtenirTypeAttaque() == typeid(AttaqueMagiqueConfusion).name())
	{
		attaqueMagique_ = new AttaqueMagiqueConfusion(attaqueMagique->obtenirDuree());
	}
	else
	{
		attaqueMagique_ = new AttaqueMagiquePoison(attaqueMagique->obtenirDuree());
	}
}

void CreatureMagique::oublierAttaqueMagique(const AttaqueMagique* attaqueMagique)
{
	if (attaqueMagique != nullptr)
	{
		delete attaqueMagique_;
		attaqueMagique_ = nullptr;
	}
}
