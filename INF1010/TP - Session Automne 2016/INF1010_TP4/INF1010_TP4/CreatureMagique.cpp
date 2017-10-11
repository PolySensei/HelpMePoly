/****************************************************************************
* Fichier: CreatureMagique.cpp
* Auteur: PolySensei 091111 and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Implémentation de la classe CreatureMagique
****************************************************************************/


#include "CreatureMagique.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

//Le constructeur par défaut
CreatureMagique::CreatureMagique()
{
	attaqueMagique_ = nullptr;
}
//le constructeur par paramètres qui recois un bonus
//et une Créature
CreatureMagique::CreatureMagique(int bonus, Creature creature) :
	Creature(creature), bonus_(bonus)
{
	attaqueMagique_ = nullptr;
}
//Destructeur
CreatureMagique::~CreatureMagique()
{

}
// l’opérateur =
CreatureMagique& CreatureMagique::operator=(const CreatureMagique& creatureMagique)
{
	if (this != &creatureMagique)
	{
		nom_ = creatureMagique.obtenirNom();
		attaque_ = creatureMagique.attaque_;
		defense_ = creatureMagique.defense_;
		pointDeVie_ = creatureMagique.pointDeVie_;
		pointDeVieTotal_ = creatureMagique.pointDeVieTotal_;
		energie_ = creatureMagique.energie_;
		energieTotal_ = creatureMagique.energieTotal_;
		experience_ = creatureMagique.experience_;
		experienceNecessaire_ = creatureMagique.experienceNecessaire_;
		niveau_ = creatureMagique.niveau_;
		pouvoirs_ = creatureMagique.pouvoirs_;
		bonus_ = creatureMagique.bonus_;
		if (typeid(*attaqueMagique_).name() == typeid(AttaqueMagiquePoison).name())
		{
			attaqueMagique_ = new AttaqueMagiquePoison;
		}
		else
		{
			attaqueMagique_ = new AttaqueMagiqueConfusion;
		}
	}
	return *this;
}
//Le constructeur de copie
CreatureMagique::CreatureMagique(const CreatureMagique& creatureMagique)
{
	nom_ = creatureMagique.obtenirNom();
	attaque_ = creatureMagique.attaque_;
	defense_ = creatureMagique.defense_;
	pointDeVie_ = creatureMagique.pointDeVie_;
	pointDeVieTotal_ = creatureMagique.pointDeVieTotal_;
	energie_ = creatureMagique.energie_;
	energieTotal_ = creatureMagique.energieTotal_;
	experience_ = creatureMagique.experience_;
	experienceNecessaire_ = creatureMagique.experienceNecessaire_;
	niveau_ = creatureMagique.niveau_;
	pouvoirs_ = creatureMagique.pouvoirs_;
	bonus_ = creatureMagique.bonus_;
	if (typeid(*attaqueMagique_).name() == typeid(AttaqueMagiquePoison).name())
	{
		attaqueMagique_ = new AttaqueMagiquePoison;
	}
	else
	{
		attaqueMagique_ = new AttaqueMagiqueConfusion;
	}
}
//affichage
std::ostream& operator<<(std::ostream& os, CreatureMagique& creature)
{
	os << "La creature magique " << creature.nom_ << " a " << creature.attaque_ << " en attaque et " << creature.defense_ << " en defense, " << std::endl
		<< "Il a " << creature.pointDeVie_ << "/" << creature.pointDeVieTotal_ << " PV et " << creature.energie_ << "/" << creature.energieTotal_ << " Energie" << std::endl
		<< "Il est au niveau " << creature.niveau_ << " avec " << creature.experience_ << "d'XP" << std::endl
		<< "Il lui manque " << creature.experienceNecessaire_ - creature.experience_ << " jusqu'au prochain niveau " << std::endl;
	os << "Pouvoirs : " << std::endl;
	if (!creature.pouvoirs_.empty()) {
		for (unsigned int i = 0; i < creature.pouvoirs_.size(); i++) {
			os << *(creature.pouvoirs_[i]);
		}
	}
	else
		os << creature.nom_ << " ne connait aucun pouvoir";
	os << std::endl;
	os << *(creature.obtenirAttaqueMagique()) << std::endl;
	return os;
}
//Une méthode attaquer() qui prend en paramètre les mêmes attributs que pour une
//attaque régulière entre Creatures, soit le pouvoir à utiliser et une créature à
//attaquer. Ajoute le bonus qu’elle possède en attribut à ses points de vie si le total du
//bonus et de ses points de vie est inférieur au nombre de points de vie total.//L’effet du pointeur d’AttaqueMagique est appliqué sur son adversaire
//avant l’attaque, seulement si l’attaque magique n’est pas encore terminée.
//Finalement, une attaque régulière est faite.
void CreatureMagique::attaquer(const Pouvoir & pouvoir, Creature & creature)
{
	if (attaqueMagique_->obtenirDuree() != 0)
	{
		attaqueMagique_->appliquerAttaque(creature);
	}
	Creature::attaquer(pouvoir, creature);
	modifierPointDeVie(obtenirPointDeVie() + bonus_);
	if (obtenirPointDeVie() > obtenirPointDeVieTotal())
	{
		modifierPointDeVie(pointDeVieTotal_);
	}
}
//Les accesseurs et les modificateurs des deux attributs
int CreatureMagique::obtenirBonus()
{
	return bonus_;
}
//Les accesseurs et les modificateurs des deux attributs
void CreatureMagique::modifierBonus(int bonus)
{
	bonus_ = bonus;
}
//Les accesseurs et les modificateurs des deux attributs
AttaqueMagique* CreatureMagique::obtenirAttaqueMagique()
{
	return attaqueMagique_;
}
//Les accesseurs et les modificateurs des deux attributs
void CreatureMagique::modifierAttaqueMagique(AttaqueMagique* attaque)
{
	attaqueMagique_ = attaque;
}

//Les accesseurs et les modificateurs des deux attributs
string CreatureMagique::obtenirTypeCreature()
{
	return typeid(*this).name();
}
//Les méthodes apprendreAttaqueMagique et oublierAttaqueMagique qui
//ajoutent / changent ou effacent l’attribut pointeur d’attaque magique
bool CreatureMagique::apprendreAttaqueMagique(AttaqueMagique* attaque)
{
	if (attaqueMagique_ == nullptr) {
		attaqueMagique_ = attaque;
	}
	else if (typeid(*attaqueMagique_).name() == typeid(*attaque).name())
	{
		delete attaqueMagique_;
		attaqueMagique_ = new AttaqueMagiquePoison;
	}
	else
	{
		delete attaqueMagique_;
		attaqueMagique_ = new AttaqueMagiqueConfusion;
	}
	return true;
}
//Les méthodes apprendreAttaqueMagique et oublierAttaqueMagique qui
//ajoutent / changent ou effacent l’attribut pointeur d’attaque magique
bool CreatureMagique::oublierAttaqueMagique()
{
	delete attaqueMagique_;
	attaqueMagique_ = nullptr;
	return true;
}