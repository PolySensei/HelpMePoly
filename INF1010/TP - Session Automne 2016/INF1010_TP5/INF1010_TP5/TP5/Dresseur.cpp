/*
Fichier: Dresseur.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 6 septembre 2016 par Maude Carrier
*/

#include "Dresseur.h"
#include "Foncteur.h"

using namespace std;

Dresseur::Dresseur() :nom_(""), equipe_("") {};

Dresseur::Dresseur(const std::string& nom, const std::string& equipe) : nom_(nom), equipe_(equipe) {};

Dresseur::~Dresseur()
{
}

std::string Dresseur::obtenirNom() const
{
	return nom_;
}

void Dresseur::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

unsigned int Dresseur::obtenirNombreCreatures() const
{
	return listeCreatures_.size();
}

std::list<Creature*> Dresseur::obtenirCreatures()
{
	return listeCreatures_;
}

//obtenirUneCreature, utilisez find_if de la STL avec un foncteur approprié pour tester la
//présence de la créature. Si la créature est absente renvoyez nullptr
Creature* Dresseur::obtenirUneCreature(const std::string& nom) const 
{
	FoncteurCreaturesDeMemeNom comparaison(nom);
	auto it = std::find_if(listeCreatures_.begin(), listeCreatures_.end(), comparaison);
	if (it != listeCreatures_.end())
		return *it;
	return nullptr;
}

void Dresseur::modifierCreature(std::list<Creature*> creatures) 
{
	listeCreatures_ = creatures;
}

bool Dresseur::ajouterCreature(Creature* creature) 
{
    FoncteurEgalCreatures comparaison(creature);
	auto it = std::find_if(listeCreatures_.begin(), listeCreatures_.end(), comparaison);
    if (it != listeCreatures_.end())
        return false;

	listeCreatures_.push_back(creature);
	return true;
}

bool Dresseur::enleverCreature(const std::string& nom) 
{
    FoncteurCreaturesDeMemeNom foncteurComparaison(nom);
	std::list<Creature*>::iterator it = std::find_if(listeCreatures_.begin(), listeCreatures_.end(), foncteurComparaison);
	if (it == listeCreatures_.end())
        return false;

    listeCreatures_.erase(it);

	return true;
}

ObjetMagique Dresseur::obtenirObjetMagique() const
{
	return objetMagique_;
}

void Dresseur::modifierObjetMagique(const ObjetMagique & objetMagique)
{
	objetMagique_ = objetMagique;
}

void Dresseur::utiliserObjetMagique(Creature* creature)
{

	if ((creature->obtenirPointDeVieTotal() - creature->obtenirPointDeVie()) >= objetMagique_.obtenirBonus()) {
		creature->modifierPointDeVie(creature->obtenirPointDeVie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierPointDeVie(creature->obtenirPointDeVieTotal());
	}
	if ((creature->obtenirEnergieTotale() - creature->obtenirEnergie()) > objetMagique_.obtenirBonus()) {
		creature->modifierEnergie(creature->obtenirEnergie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierEnergie(creature->obtenirEnergieTotale());
	}
}

std::string Dresseur::obtenirEquipe() const
{
	return equipe_;
}

void Dresseur::modifierEquipe(const std::string& equipe)
{
	equipe_ = equipe;
}

//operator==, doit utiliser find_if et un foncteur pour déterminer si les dresseurs ont les
//mêmes créatures (elles peuvent être dans un ordre différent).
bool Dresseur::operator==(const Dresseur& dresseur) //A compléter
{
    if (listeCreatures_.size() == 0 && dresseur.listeCreatures_.size() == 0)
        return true;
    else if (listeCreatures_.size() != dresseur.listeCreatures_.size())
        return false;

    /*Complétez moi! Vérifiez l'égalité entre les créatures via
    find_if*/
	auto it2 = dresseur.listeCreatures_.begin();
	
	while (it2 != dresseur.listeCreatures_.end()) {
		FoncteurEgalCreatures comparaison(*it2);
		std::list<Creature*>::iterator it = std::find_if(listeCreatures_.begin(), listeCreatures_.end(), comparaison);
		if (it != listeCreatures_.end())
			it2++;
		else
			return false;
	}
	return true;
}

bool Dresseur::operator==(const std::string& nom) const
{
	return (nom_ == nom);
}

bool operator==(const std::string& nom, const Dresseur& dresseur)
{
	return dresseur == nom;
}

std::ostream& operator<<(std::ostream& os, const Dresseur& dresseur)
{
    return os << dresseur.nom_ << " possede " << dresseur.listeCreatures_.size() 
        << " creature(s) et appartient a l'equipe " << dresseur.equipe_ << std::endl;
}


