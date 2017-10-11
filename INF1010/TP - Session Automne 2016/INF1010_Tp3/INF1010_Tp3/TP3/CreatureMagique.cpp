/****************************************************************************
* Fichier: CreatureMagique.cpp
* Auteur: Poly Sensei 091111 & Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Implémentation de la classe CreatureMagique
****************************************************************************/


#include "CreatureMagique.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>


CreatureMagique::CreatureMagique()
{
}
//Constructeurs par paramètres ayant tous les paramètres du constructeur par défaut de
//la classe de base ainsi qu’un paramètre représentant le bonus

CreatureMagique::CreatureMagique(const std::string& nom, unsigned int attaque,
	unsigned int defense, unsigned int pointDeVie, unsigned int energie, unsigned int bonus) :
	Creature(nom, attaque, defense, pointDeVie, energie), bonus_(bonus)
{
}
//Un opérateur =
CreatureMagique& CreatureMagique::operator=(const CreatureMagique& creatureMagique)
{
	if (this != &creatureMagique)
	{
		nom_ = creatureMagique.obtenirNom();
		attaque_ = creatureMagique.attaque_;
		defense_ = creatureMagique.defense_;
		pointDeVie_ = creatureMagique.pointDeVie_;
		energie_ = creatureMagique.energie_;
		experience_ = creatureMagique.experience_;
		niveau_ = creatureMagique.niveau_;
		pouvoirs_ = creatureMagique.pouvoirs_;
		bonus_ = creatureMagique.bonus_;
	}
	return *this;
}
//Un constructeur par copie

CreatureMagique::CreatureMagique(const CreatureMagique& creatureMagique)
{
	nom_ = creatureMagique.nom_;
	attaque_ = creatureMagique.attaque_;
	defense_ = creatureMagique.defense_;
	pointDeVie_ = creatureMagique.pointDeVie_;
	energie_ = creatureMagique.energie_;
	experience_ = creatureMagique.experience_;
	niveau_ = creatureMagique.niveau_;
	pouvoirs_ = creatureMagique.pouvoirs_;
	bonus_ = creatureMagique.bonus_;
}
//Fonction d'affichage
std::ostream& operator<<(std::ostream& os, const CreatureMagique& creature)
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
	return os;
}
//Attaquer doit effectuer une attaque normale et augmenter sa vie de bonus point de
//vie
void CreatureMagique::attaquer(const Pouvoir & pouvoir, Creature & creature)
{
	Creature::attaquer(pouvoir, creature);
	modifierPointDeVie(obtenirPointDeVie() + bonus_);
	if (obtenirPointDeVie() > obtenirPointDeVieTotal())
	{
		modifierPointDeVie(pointDeVieTotal_);
	}
}