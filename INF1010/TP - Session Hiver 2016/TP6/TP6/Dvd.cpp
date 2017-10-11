#include "Dvd.h"
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;

Dvd::Dvd()
{
}

Dvd::Dvd(const string & cote, const string & titre, unsigned int annee, unsigned int ageMin,
	unsigned int nbExemplaires, string const & realisateur, vector<string> acteurs) :
	ObjetEmpruntable(cote, titre, annee, ageMin, nbExemplaires), realisateur_(realisateur)
{
	copy(acteurs.begin(),acteurs.end(), back_inserter(listActeurs_));
}

Dvd::~Dvd()
{
}

string Dvd::obtenirRealisateur() const
{
	return realisateur_;
}

list<string> Dvd::obtenirActeur() const
{
	return listActeurs_;
}

void Dvd::modifierRealisateur(string const & realisateur)
{
	realisateur_ = realisateur;
}

void Dvd::ajouterActeur(string const & acteur)
{
	listActeurs_.push_back(acteur);
}

void Dvd::retirerActeur(string const & acteur)
{
	listActeurs_.remove(acteur);
}


bool Dvd::recherche(const string & motsCle) const
{
	bool present = false;
	size_t trouverRealisateur = convertirMinuscule(realisateur_).find(convertirMinuscule(motsCle));
	for (list<string>::const_iterator it = listActeurs_.begin(); it != listActeurs_.end(); it++){
		size_t trouveActeur = convertirMinuscule((*it)).find(convertirMinuscule(motsCle));
		present = present || (trouveActeur != string::npos);
	}
	//Utilisation du demasquage pour appeler la méthode de la classe mère
	bool trouve = ObjetEmpruntable::recherche(motsCle) 
		|| present
		|| (trouverRealisateur != string::npos);

	return trouve;
}

ostream & operator<<(ostream & o, const Dvd&  dvd)
{
	const ObjetEmpruntable* obj = (&dvd);
	o << "Information sur le Dvd :" << endl;
	o << *obj
		<< " Realisateur : " << dvd.obtenirRealisateur()
		<< "; Acteurs : ";
	//affichage des acteurs
	list<string>  liste = dvd.obtenirActeur(); 
	liste.sort(greater<string>());
	for(list<string>::iterator it = liste.begin(); it != liste.end(); it++)
		o << (*it) << "; ";

	return o << endl;
}
