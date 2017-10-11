/****************************************************************************
* Fichier: Livre.cpp
* Auteur: PolySensei & Associates
* Date: 6 mars 2016
* Mise a jour : 28 mars 2016
* Description: Implémentation de la classe Livre
****************************************************************************/
#include "Livre.h"

using namespace std;

Livre::Livre()
{

}

Livre::Livre(const std::string & cote, const std::string & titre, unsigned int annee, unsigned int ageMin, unsigned int nbExemplaires, const string & auteur, const string & genre) : 
	ObjetEmpruntable(cote, titre, annee, ageMin, nbExemplaires), auteur_(auteur), genre_(genre)
{

}


Livre::~Livre()
{

}

std::string Livre::obtenirAuteur() const
{
	return auteur_;
}

std::string Livre::obtenirGenre() const
{
	return genre_;
}

void Livre::modifierAuteur(std::string const & auteur)
{
	auteur_ = auteur;
}

void Livre::modifierGenre(std::string const & genre)
{
	genre_ = genre;
}

bool Livre::recherche(const std::string & motsCle) const
{
	std::size_t trouveAuteur = convertirMinuscule(auteur_).find(convertirMinuscule(motsCle));
	std::size_t trouveGenre = convertirMinuscule(genre_).find(convertirMinuscule(motsCle));
	//Utilisation du demasquage pour appeler la méthode de la classe mère
	bool trouve = ObjetEmpruntable::recherche(motsCle)
			|| (trouveAuteur != string::npos)
			|| (trouveGenre !=string::npos);

	return trouve;
}

ostream & operator<<(ostream & o, Livre const& livre)
{
	const ObjetEmpruntable* obj = &livre;
	o << "Information sur le livre :" << endl;
	o << *obj
		<< " Auteur : " << livre.auteur_
		<< "; Genre : " << livre.genre_ << endl;

	return o;
}
