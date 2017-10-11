/****************************************************************************
* Fichier: Creature.cpp
* Auteur: Poly Sensei 091111 & Associates
* Date: 28 septembre 2016
* Mise a jour :  03 octobre 2016
* Description: Implémentation de la classe Creature
****************************************************************************/

#include "Creature.h"
#include "Pouvoir.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

//Un constructeur par défaut qui initialise les attributs aux valeurs par défaut.

Creature::Creature():nom_(""), attaque_(0), defense_(0), pointDeVie_(0),
	energie_(0), experience_(0), niveau_(1), vecPouvoir_()
{
	energieTotal_ = 0;
	experienceNecessaire_ = 0;
	pointDeVieTotal_ = 0;
}

//Un constructeur par paramètres qui initialise les attributs nom, attaque, defense, point de
//vie, et énergie selon les paramètres correspondants.Les autres paramètres sont
//initialisés à des valeurs par défaut

Creature::Creature(const string& nom, unsigned int attaque,
	unsigned int defense, unsigned int pointDeVie, unsigned int energie):
	nom_(nom), attaque_(attaque), defense_(defense), pointDeVie_(pointDeVie),
	energie_(energie), experience_(0), niveau_(1), vecPouvoir_()
{
	energieTotal_ = energie;
	experienceNecessaire_ = 100;
	pointDeVieTotal_ = pointDeVie;
}

//Un constructeur par copie qui va copier tous les attributs.

Creature::Creature(const Creature& creature)
	: nom_(creature.nom_), attaque_(creature.attaque_), defense_(creature.defense_), pointDeVie_(creature.pointDeVie_),
		energie_(creature.energie_), experience_(creature.experience_), niveau_(creature.niveau_), vecPouvoir_(creature.vecPouvoir_)
{
	energieTotal_ = creature.energieTotal_;
	experienceNecessaire_ = creature.experienceNecessaire_;
	pointDeVieTotal_ = creature.pointDeVieTotal_;
}

//destructeur

Creature::~Creature()
{

}

std::string Creature::obtenirNom() const
{
	return nom_;
}

unsigned int Creature::obtenirAttaque() const
{
	return attaque_;
}

unsigned int Creature::obtenirDefense() const
{
	return defense_;
}

unsigned int Creature::obtenirPointDeVie() const
{
	return pointDeVie_;
}

unsigned int Creature::obtenirPointDeVieTotal() const
{
	return pointDeVieTotal_;
}

unsigned int Creature::obtenirEnergie() const
{
	return energie_;
}

unsigned int Creature::obtenirEnergieTotale() const
{
	return energieTotal_;
}

unsigned int Creature::obtenirExperience() const
{
	return experience_;
}

unsigned int Creature::obtenirExperienceNecessaire() const
{
	return experienceNecessaire_;
}

unsigned int Creature::obtenirNiveau() const
{
	return niveau_;
}

vector<Pouvoir*> Creature::obtenirPouvoirs() const
{
	return vecPouvoir_;
}


void Creature::attaquer(Pouvoir& pouvoir, Creature& creature)
{
	for (int i = 0; i < vecPouvoir_.size(); i++) {
		if (vecPouvoir_[i]->obtenirNom() == pouvoir.obtenirNom()) {
			if (energie_ >= vecPouvoir_[i]->obtenirEnergieNecessaire())
			{
				if (creature.obtenirPointDeVie() >= 0)
				{
					//Calcul du nombre de degat selon une formule 
					unsigned int degat = (vecPouvoir_[i]->obtenirNombreDeDegat())* (attaque_ / 2 - creature.defense_);
					int tentative = rand() % 6;
					//l'attaque rate une fois sur 6
					if (tentative != 3) {
						std::cout << nom_ << " lance " << vecPouvoir_[i]->obtenirNom() << " qui inflige " << degat << " degat a " << creature.obtenirNom() << endl;
						if (degat > creature.obtenirPointDeVie()) {
							creature.modifierPointDeVie(0);
							int xp = experienceGagnee(creature);
							cout << nom_ << " a gagné " << xp << " XP" << endl;
						}
						else
						creature.modifierPointDeVie(creature.obtenirPointDeVie() - degat);
						cout << creature.obtenirNom() << " a encore " << creature.obtenirPointDeVie() << " PV" << endl;
						energie_ -= vecPouvoir_[i]->obtenirEnergieNecessaire();
					}
					else {
						std::cout << "Attaque " << vecPouvoir_[i]->obtenirNom() << " a échouée" << endl;
					}
				}
				else
					std::cout << "Vous deja avez vaincu " << creature.obtenirNom() << endl;
			}
		}
	}
}

int Creature::experienceGagnee(const Creature& creature)
{
	if (creature.obtenirPointDeVie() <= 0) 
    {
		//Calcul de l'experience selon une formule mystérieuse
		int experience = (creature.obtenirNiveau() + 1 - niveau_) * ((creature.obtenirAttaque() + 5 - attaque_) * (creature.obtenirDefense() + 3 - defense_)) + (pointDeVie_ / 2);
		if (experience > (experienceNecessaire_ - experience_)) 
        {
			//Cas ou la creature va monter d'un niveau
			int experienceRestante = experience - (experienceNecessaire_ - experience_);
			niveau_++;
			attaque_ += 1;
			defense_ += 1;
			pointDeVie_ += 5;
			energie_ += 5;
			energieTotal_ += 5;
			pointDeVieTotal_ += 5;
			experience_ = experienceRestante;
			experienceNecessaire_ = experienceNecessaire_ * 15 / 10;
		}
		else 
        {
			//Sinon elle recupère juste de l'expérience
			experience_ += experience;
		}
		return experience;
	}
	return 0;
}

void Creature::modifierNom(string nom)
{
	nom_ = nom;
}

void Creature::modifierAttaque(unsigned int attaque)
{
	attaque_ = attaque;
}

void Creature::modifierDefense(unsigned int defense)
{
	defense_ = defense;
}

void Creature::modifierPointDeVie(unsigned int pointDeVie)
{
	pointDeVie_ = pointDeVie;
}

void Creature::modifierPointDeVieTotal(unsigned int pointDeVieTotal)
{
	pointDeVieTotal_ = pointDeVieTotal;
}

void Creature::modifierEnergie(unsigned int energie)
{
	energie_ = energie;
}

void Creature::modifierEnergieTotal(unsigned int energieTotal)
{
	energieTotal_ = energieTotal;
}

void Creature::modifierExperience(unsigned int experience)
{
	experience_ = experience;
}

void Creature::modifierExperienceNecessaire(unsigned int experienceNecessaire)
{
	experienceNecessaire_ = experienceNecessaire;
}

void Creature::modifierNiveau(unsigned int niveau)
{
	niveau_ = niveau;
}

void Creature::modifierPouvoirs(Pouvoir* pouvoirs){
	for (int i = 0; i < vecPouvoir_.size(); i++) {
		if (vecPouvoir_[i] == pouvoirs) {
			vecPouvoir_[i] = pouvoirs;
		}
	}
}

//implémentation de apprendrePouvoir

void Creature::apprendrePouvoir(Pouvoir* pouvoir) {
	if (vecPouvoir_.size() == 0) {
		vecPouvoir_.push_back(pouvoir);
	}
	else {
		for (int i = 0; i < vecPouvoir_.size(); i++) {
			if (vecPouvoir_[i] != pouvoir) {
				vecPouvoir_.push_back(pouvoir);
			}
		}
	}
}

//implémentation de oublierPouvoir

void Creature::oublierPouvoir(string pouvoir) {
	for (int i = 0; i < vecPouvoir_.size(); i++) {
		if (*vecPouvoir_[i] == pouvoir) {
			vecPouvoir_[i] = vecPouvoir_[vecPouvoir_.size() - 1];
			vecPouvoir_.pop_back();
			cout << "Le pouvoir " << pouvoir << " a bien ete retire" << endl;
		}
		else {
			cout << "Le pouvoir " << pouvoir << " n'a pas ete retire" << endl;
		}
	}
}

//surchage de l'opérateur <<

ostream& operator<<(ostream& out, const Creature& creature) {
	out << creature.nom_ << " a " << creature.attaque_ << " en attaque et " << creature.defense_ << " en defense," << endl <<
		"Il a " << creature.pointDeVie_ << "/" << creature.pointDeVieTotal_ << " PV et " << creature.energie_ <<
		"/" << creature.energieTotal_ << " Energie " << endl <<
		"Il est au niveau " << creature.niveau_ << " avec " << creature.experience_ << " d'XP" << endl <<
		"Il lui manque " << creature.experienceNecessaire_ << " jusqu'au prochain niveau" << endl
		<< "Pouvoirs :" << endl;
	if (creature.vecPouvoir_.size() > 0){
		for (int unsigned i = 0; i < creature.vecPouvoir_.size(); i++) {
			out << creature.vecPouvoir_[i]->obtenirNom();
		}
	}
	else
		out << creature.nom_ << "ne connait aucun pouvoir" << endl << endl;

	return out;
}

// _______TP2________

//Un opérateur = qui écrase les attributs de l’objet de gauche par les attributs l’objet passés
//en paramètre.


void Creature::operator=(Creature creature) {

	modifierAttaque(creature.attaque_);
	modifierDefense(creature.defense_);
	modifierPointDeVie(creature.pointDeVie_);
	modifierPointDeVieTotal(creature.pointDeVieTotal_);
	modifierEnergie(creature.energie_);
	modifierEnergieTotal(creature.energieTotal_);
	modifierExperience(creature.experience_);
	experienceNecessaire_ = creature.experienceNecessaire_;
	modifierNiveau(creature.niveau_);
	vecPouvoir_ = creature.vecPouvoir_;

}

//L’opérateur == qui prend une Creature en paramètre et permet de comparer 2 créatures
//en considérant tous les attributs sauf le vecteur de Pouvoir et le nombre de pouvoir.
//L’opérateur retourne true si les créatures ont les mêmes attributs, false sinon.Ainsi, cet
//opérateur va pouvoir faire l’opération creature1 == creature2.

bool Creature::operator==(Creature& creature) const {
	bool estEgal = false;

	if (attaque_ == creature.obtenirAttaque()) {
		if (defense_ == creature.obtenirDefense()) {
			if (pointDeVie_ == creature.obtenirPointDeVie()) {
				if (pointDeVieTotal_ == creature.obtenirPointDeVieTotal()) {
					if (energie_ == creature.obtenirEnergie()) {
						if (energieTotal_ == creature.obtenirEnergieTotale()) {
							if (experience_ == creature.obtenirExperience()) {
								if (experienceNecessaire_ == creature.obtenirExperienceNecessaire()) {
									if (niveau_ == creature.obtenirNiveau()) {
					estEgal = true;
				}
			}
		}
	}
					}
				}
			}
		}
	}
	return estEgal;
}

//L’opérateur == qui prend un nom en paramètre et permet de comparer 2 créatures en
//considérant seulement le nom.L’opérateur retourne true si les noms sont identiques, false
//sinon.Ainsi, cet opérateur va pouvoir faire l’opération créature == nom.

bool Creature::operator==(const string& nom) const {
	bool estEgal = false;

	if (nom_ == nom) {
		estEgal = true;
	}
	return estEgal;
}

//L’opérateur == de type friend qui permet d’inverser l’ordre de l’opérateur== précédent.
//Ainsi, cet opérateur va pouvoir faire l’opération nom == créature.

bool operator==(const string& nom, const Creature& creature) {
	bool estEgal = false;

	if (creature == nom) {
		estEgal = true;
	}
	return estEgal;
}