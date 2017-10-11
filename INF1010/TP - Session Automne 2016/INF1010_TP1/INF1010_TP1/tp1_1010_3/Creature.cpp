/****************************************************************************
* Fichier: Creature.cpp
* Auteur: Poly Sensei 091111 & Associates
* Date: 14 septembre 2016
* Mise a jour :  26 septembre 2016
* Description: Implémentation de la classe Creature
****************************************************************************/

#include "Creature.h"
#include <string>
#include <iostream>

using namespace std;

Creature::Creature()
	: nom_(""), attaque_(0), defense_(0), pointDeVie_(0), pointDeVieTotal_(0), energie_(0), energieTotal_(0), experience_(0), experienceNecessaire_(0), niveau_(0), pouvoir_()
{
}

Creature::Creature(const string& nom, unsigned int attaque, unsigned int defense, unsigned int pointDeVie, unsigned int energie, const Pouvoir pouvoir)
	: nom_(nom), attaque_(attaque), defense_(defense), pointDeVie_(pointDeVie), pointDeVieTotal_(pointDeVie), energie_(energie), energieTotal_(energie), experience_(0), experienceNecessaire_(100), niveau_(1), pouvoir_(pouvoir)
{
}

string Creature::obtenirNom() const
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
Pouvoir Creature::obtenirPouvoir() const
{
	return pouvoir_;
}

void Creature::modifierNom(const std::string& nom)
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
void Creature::modifierEnergieTotale(unsigned int energieTotale)
{
	energieTotal_ = energieTotale;
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
void Creature::modifierPouvoir(const Pouvoir& pouvoir)
{
	pouvoir_ = pouvoir;
}

Creature::~Creature()
{
}
	
//Une méthode attaquer() qui prend en paramètre une créature qui va subir l’attaque
void Creature::attaquer(Creature& creature)
{
	//L'attaque est possible si votre créature a assez d'energie
	//Et que la creature adverse a encore des points de vie
	if (energie_ >= pouvoir_.obtenirEnergieNecessaire() && creature.pointDeVie_ > 0) {

		//Calcul du nombre de degat selon une formule
		unsigned int degat = (pouvoir_.obtenirDegat())* (attaque_ / 2 - creature.defense_);
		//On choisit un nombre aléatoire entre 1 et 6
		int tentative = rand() % 6;
		//l'attaque rate une fois sur 6
		if (tentative != 3) {
			//Afficher le nom de la créature qui lance l'attaque, le nom de l'attaque,
			//le nombre de dégat infligé, et la créature qui est attaquée
			cout << nom_ << " lance " << pouvoir_.obtenirNom() << " qui inflige " << pouvoir_.obtenirDegat() << " degat a " << creature.nom_ << endl;

			//Afficher le nombre d'XP gagné si c'est approprié, n'oubliez pas de faire
			//les modifications adéquates
			if (int(creature.obtenirPointDeVie() - degat) < 0) {
				creature.modifierPointDeVie(0);
				unsigned int experienceGagnee = experienceGagner(creature);
				cout << nom_ << " a gagné " << experienceGagnee << " XP" << endl;
			}
			else {
				creature.modifierPointDeVie(creature.obtenirPointDeVie() - degat);
			}

			//Afficher le nombre de point de vie restant de la créature attaquée
			//Faites attention aux requis d'une attaque
			cout << creature.nom_ << " a encore " << creature.pointDeVie_ << " PV" << endl;
		}
		else {
			//La créature adverse est déjà vaincue
			cout << "Attaque " << pouvoir_.obtenirNom() << " a échouée" << endl;
		}
	}
	else {
		cout << "La creature n'a plus de vie" << endl;
	}

}

int Creature::experienceGagner(const Creature& creature)
{
	if (creature.obtenirPointDeVie() <= 0) {
		//Calcul de l'experience selon une formule mystérieuse
		int experience = (creature.obtenirNiveau() + 1 - niveau_) * ((creature.obtenirAttaque() + 5 - attaque_) *
		 (creature.obtenirDefense() + 3 - defense_)) + (pointDeVie_ / 2);
		if (experience > (experienceNecessaire_ - experience_)) {
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
		else {
			experience_ += experience;
		}
		return experience;
	}
	return 0;
}

void Creature::information() const {

	cout << nom_ << " a " << attaque_ <<
		" en attaque et " << defense_ << " en defense," << endl <<
		"Il a " << pointDeVie_ << "/" << pointDeVieTotal_ << " PV et " << energie_ << "/" << energieTotal_ << " Energie " << endl <<
		"Il est au niveau " << niveau_ << " avec " << experience_ << " d'XP" << endl <<
		"Il lui manque " << experienceNecessaire_ << " jusqu'au prochain niveau" << endl;
	pouvoir_.description();

}