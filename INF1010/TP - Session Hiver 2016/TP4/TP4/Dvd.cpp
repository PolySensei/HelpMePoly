/****************************************************************************
* Fichier: DVD.cpp
* Auteur: PolySensei & Associates
* Date: 22 février 2016
* Mise a jour : 3 mars 2016
* Description: Implémentation de la classe Etudiant DVD
****************************************************************************/
#include "Dvd.h"

using namespace std;

Dvd::Dvd()
{
}

Dvd::Dvd(const std::string & cote, const std::string & titre, unsigned int annee, unsigned int ageMin, unsigned int nbExemplaires, std::string const & realisateur, std::vector<std::string> acteurs) :
	ObjetEmpruntable(cote, titre, annee, ageMin, nbExemplaires), realisateur_(realisateur), vecActeurs_(acteurs)

{

}


Dvd::~Dvd()
{
}

std::string Dvd::obtenirRealisateur() const
{
	return realisateur_;
}

std::vector<std::string> Dvd::obtenirActeur() const
{
	return vecActeurs_;
}

void Dvd::modifierRealisateur(std::string const & realisateur)
{
	realisateur_ = realisateur;
}

void Dvd::ajouterActeur(std::string const & acteur)
{
	vecActeurs_.push_back(acteur);
}

void Dvd::retirerActeur(std::string const & acteur)
{
	for (int i = 0; i < vecActeurs_.size(); i++)
	{
		if (vecActeurs_[i] == acteur)
		{
			vecActeurs_[i] = vecActeurs_.back();
			vecActeurs_.pop_back();
		}
	}
}


bool Dvd::recherche(const std::string & motsCle) const
{
	bool present = false;
	std::size_t trouverRealisateur = convertirMinuscule(realisateur_).find(convertirMinuscule(motsCle));
	for (int i = 0; i < vecActeurs_.size(); i++)
	{
		std::size_t trouveActeur = convertirMinuscule(vecActeurs_[i]).find(convertirMinuscule(motsCle));
		present = present || (trouveActeur != string::npos);
	}
	//Utilisation du demasquage pour appeler la méthode de la classe mère
	bool trouve = ObjetEmpruntable::recherche(motsCle) 
		|| present
		|| (trouverRealisateur != string::npos);

	return trouve;
}

ostream & operator<<(ostream & o, const Dvd & dvd)
{
	const ObjetEmpruntable* obj = (&dvd);
	o << "Information sur le Dvd :" << endl;
	o << *obj
		<< " Realisateur : " << dvd.realisateur_
		<< "; Acteurs : ";
	//affichage des acteurs
	for (int i = 0; i < dvd.vecActeurs_.size(); i++)
		{
			o << dvd.vecActeurs_[i] << "; ";
		}

	return o << endl;
}
