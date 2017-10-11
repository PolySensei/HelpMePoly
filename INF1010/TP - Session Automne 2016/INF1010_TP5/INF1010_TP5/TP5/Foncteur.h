/****************************************************************************
* Fichier: Foncteur.h
* Auteur: PolySensei and Associates
* Date: 5 novembre 2016 Mise a jour : 19 novembre 2016
* Description: Implémentation des différents foncteurs
****************************************************************************/
#ifndef  FONCTEUR
#define  FONCTEUR

#include <functional>
#include "Dresseur.h"
#include <string>
#include <string>
#include <stdlib.h>

using namespace std;

#define RAND_MIN_DEFAUT 0
#define RAND_MAX_DEFAUT 6

//Froncteur permettant d'obtenir l'attaque de la créature passée en argument
class FoncteurObtenirAttaqueCreature
{
public:
    FoncteurObtenirAttaqueCreature() {}
    ~FoncteurObtenirAttaqueCreature() {}

    unsigned int operator() (const Creature* creature) const {
        return creature->obtenirAttaque();
    }
};

//Ce foncteur prend en argument deux pointeurs de créature et renvoie true si la première créature
//a une attaque inférieure à celle de la deuxième
class FoncteurComparerCreatures
{
public:
	FoncteurComparerCreatures() {}
	~FoncteurComparerCreatures() {}

	bool operator()(const Creature* creature1, const Creature* creature2) const {
		return (creature1->obtenirAttaque() < creature2->obtenirAttaque());
	}
};

//Ce foncteur prend en argument deux pointeurs de dresseurs et renvoie true si le premier a un
//nom strictement inférieur au nom du second. Cette comparaison se fera selon l’ordre
//alphanumérique.
class FoncteurComparerDresseurs
{
public:
	FoncteurComparerDresseurs() {}
	~FoncteurComparerDresseurs() {}
	
	bool operator()(const Dresseur* dresseur1, const Dresseur* dresseur2) const {
		return (dresseur1->obtenirNom() < dresseur2->obtenirNom());
	}
};

//Ce foncteur prend en argument deux pointeurs de pouvoir et renvoie true si le premier pouvoir a
//un nombre de dégâts inférieur à celui du deuxième.
class FoncteurComparerPouvoirs
{
public:
	FoncteurComparerPouvoirs() {}
	~FoncteurComparerPouvoirs() {}

	bool operator()(const Pouvoir* pouvoir1, const Pouvoir* pouvoir2) const {
		if (pouvoir1->obtenirNombreDeDegat() < pouvoir2->obtenirNombreDeDegat()) {
			return true;
		}
		else {
			return false;
		}
	}
};

//Ce foncteur prend en argument un pointeur de créature et renvoie true si cette créature a le même
//nom que l’attribut de la classe correspondant
class FoncteurCreaturesDeMemeNom
{
public:
	FoncteurCreaturesDeMemeNom(const std::string& creature) : creature_(creature) {}
	~FoncteurCreaturesDeMemeNom() {}
	
	bool operator()(const Creature* creature) const {
		return (creature->obtenirNom() == creature_);
		}
private:
	string creature_;
};

//Ce foncteur prend en argument un pointeur de créature et renvoie true si cette créatures est égale
//à l’attribut creature du foncteur (au sens de leur opérateur ==).
class FoncteurEgalCreatures
{
public:
	FoncteurEgalCreatures()
	{
	}

	FoncteurEgalCreatures(Creature* creature): creature_(creature)
	{
	}

	~FoncteurEgalCreatures() {}

	bool operator()(Creature* creature) {
		return creature->obtenirNom() == creature_->obtenirNom();
	}
private:
	Creature* creature_;
};

//Ce foncteur prend en argument un pointeur vers une créature et incrémente une variable interne
//si les points de vie de la créature sont entre ces bornes
class FoncteurCreatureVie
{
public:
	FoncteurCreatureVie(unsigned int vieMin, unsigned int vieMax) : vieMin_(vieMin), vieMax_(vieMax), compteur_(0)
	{
		
	}
	~FoncteurCreatureVie() {}

	unsigned int obtenirCompteur() const
	{
		return compteur_;
	}

	void operator()(const Creature* creature) {
		if (creature->obtenirPointDeVie() <= vieMax_ && creature->obtenirPointDeVie() >= vieMin_)
		{
			compteur_++;
		}
	}
private:
	unsigned int vieMin_;
	unsigned int vieMax_;
	unsigned int compteur_;
};

//Ce foncteur permet de générer un nombre aléatoire compris dans un intervalle
class FoncteurGenerateurNombresAlea
{
public:
	FoncteurGenerateurNombresAlea() 
	{
		borneMin_ = RAND_MIN_DEFAUT;
		borneMax_ = RAND_MAX_DEFAUT;
	}
	FoncteurGenerateurNombresAlea(unsigned int borneMin, unsigned int borneMax) : borneMin_(borneMin), borneMax_(borneMax)
	{

	}
	~FoncteurGenerateurNombresAlea() {}
	unsigned int operator() (){
		return (borneMin_ + (rand()%(borneMax_ - borneMin_ + 1)));
	}

private:
	unsigned int borneMin_;
	unsigned int borneMax_;
};

#endif;