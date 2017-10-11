/****************************************************************************
* Fichier: DVD.cpp
* Auteur: PolySensei & Associates
* Date: 6 mars 2016
* Mise a jour : 28 mars 2016
* Description: Implémentation de la classe DVD
****************************************************************************/
#include "Dvd.h"
#include <algorithm>

using namespace std;

Dvd::Dvd()
{
}

Dvd::Dvd(const std::string & cote, const std::string & titre, unsigned int annee, unsigned int ageMin, unsigned int nbExemplaires, std::string const & realisateur, std::list<std::string> acteurs) :
	ObjetEmpruntable(cote, titre, annee, ageMin, nbExemplaires), realisateur_(realisateur), listeActeurs_(acteurs)

{

}


Dvd::~Dvd()
{
}

std::string Dvd::obtenirRealisateur() const
{
	return realisateur_;
}

std::list<std::string> Dvd::obtenirActeur() const
{
	return listeActeurs_;
}

void Dvd::modifierRealisateur(std::string const & realisateur)
{
	realisateur_ = realisateur;
}

void Dvd::ajouterActeur(std::string const & acteur)
{
	listeActeurs_.push_back(acteur);
}

void Dvd::retirerActeur(std::string const & acteur)
{
	listeActeurs_.remove(acteur);
}


bool Dvd::recherche(const std::string & motsCle) const
{
	bool present = false;

	std::size_t trouverRealisateur = convertirMinuscule(realisateur_).find(convertirMinuscule(motsCle));

	for (auto it = listeActeurs_.begin(); it != listeActeurs_.end(); it++)
	{
		std::size_t trouveActeur = convertirMinuscule(*it).find(convertirMinuscule(motsCle));
		present = present || (trouveActeur != string::npos);
	}

	bool trouve = ObjetEmpruntable::recherche(motsCle) || present || (trouverRealisateur != string::npos);

	return trouve;
}

ostream & operator<<(ostream & o, const Dvd & dvd)
{
	const ObjetEmpruntable* obj = (&dvd);
	o << "Information sur le Dvd :" << endl;
	o << *obj
		<< " Realisateur : " << dvd.realisateur_
		<< "; Acteurs : ";

	list<string> listeActeur = dvd.obtenirActeur();
	listeActeur.sort(greater<string>());

		copy(listeActeur.begin(), listeActeur.end(), ostream_iterator<string>(o, "; "));

	return o << endl;
}
