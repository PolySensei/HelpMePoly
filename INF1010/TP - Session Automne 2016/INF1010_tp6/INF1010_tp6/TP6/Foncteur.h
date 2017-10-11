#ifndef  FRONTEUR
#define  FRONTEUR

#include "Dresseur.h"
#include <string>
#include <stdlib.h>

#define RAND_MIN_DEFAUT 0
#define RAND_MAX_DEFAUT 6

class FoncteurObtenirAttaqueCreature
{
public:
    FoncteurObtenirAttaqueCreature() {}
    ~FoncteurObtenirAttaqueCreature() {}

    unsigned int operator() (const Creature* creature) const {
        return creature->obtenirAttaque();
    }
};

class FoncteurComparerCreature
{
public:
	FoncteurComparerCreature() {}
	~FoncteurComparerCreature() {}

	bool operator() (const Creature* comparant, const Creature* compare) const {
		return comparant->obtenirAttaque() < compare->obtenirAttaque();
	}
};

class FoncteurComparerDresseur
{
public:
	FoncteurComparerDresseur() {}
	~FoncteurComparerDresseur() {}

	bool operator() (const Dresseur* comparant, const Dresseur* compare) const {
		return comparant->obtenirNom() < compare->obtenirNom();
	}
};

class FoncteurComparerPouvoir
{
public:
	FoncteurComparerPouvoir() {}
	~FoncteurComparerPouvoir() {}

	bool operator() (const Pouvoir* comparant, const Pouvoir* compare) const {
		return comparant->obtenirNombreDeDegat() < compare->obtenirNombreDeDegat();
	}
};

class FoncteurCreatureVie
{
public:
	FoncteurCreatureVie(unsigned int vieMin, unsigned int vieMAx) {
		vieMax_ = vieMAx;
		vieMin_ = vieMin;
		compteur_ = 0;
	}
	~FoncteurCreatureVie() {}

	unsigned int obtenirCompteur() const {
		return compteur_;
	}

	void operator() (const Creature* creaure) {
		if (creaure->obtenirPointDeVie() >= vieMin_ && creaure->obtenirPointDeVie() <= vieMax_)
			compteur_++;
	}

private:
	unsigned int vieMin_;
	unsigned int vieMax_;
	unsigned int compteur_;
};

class FoncteurCreaturesDeMemeNom
{
public:
	FoncteurCreaturesDeMemeNom(const std::string& nom) {
		nom_ = nom;
	}
	~FoncteurCreaturesDeMemeNom() {};

	bool operator() (const Creature* creature) const {
		return *creature == nom_;
	}

private:
	std::string nom_;
};

class FoncteurEgalCreatures
{
public:
	FoncteurEgalCreatures(Creature* creature) {
		creature_ = creature;
	}
	~FoncteurEgalCreatures() {}

	bool FoncteurEgalCreatures::operator() (const Creature* creatureAComparer) const {
		return *creatureAComparer == *creature_;
	}

private:
	Creature* creature_;
};

class FoncteurGenerateurNombresAlea
{
public:
	FoncteurGenerateurNombresAlea() {
		min_ = RAND_MIN_DEFAUT;
		max_ = RAND_MAX_DEFAUT;
	}

	FoncteurGenerateurNombresAlea(unsigned int min, unsigned int max) {
		min_ = min;
		max_ = max;
	}

	~FoncteurGenerateurNombresAlea() {}

	unsigned int operator() () const {
		return rand() % (max_ - min_ + 1) + min_;
	}

private:
	unsigned int min_;
	unsigned int max_;
};


#endif;