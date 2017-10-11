/****************************************************************************
* Fichier: Livre.cpp
* Auteur: PolySensei & Associates
* Date: 11 février 2016
* Mise a jour : 20 février 2016
* Description: Implémentation de la classe Livre
****************************************************************************/
#include <iostream>
#include "Livre.h"

using namespace std;


Livre::Livre()
{

}

// Un constructeur par paramètres qui initialise en plus les nouveaux attributs.
Livre::Livre(const std::string &cote, const std::string &titre, unsigned int annee, unsigned int ageMin, unsigned int nbExemplaires, const std::string &auteur, const std::string &genre) : ObjetEmpruntable(cote, titre, annee, ageMin, nbExemplaires), auteur_(auteur), genre_(genre)
{

}

Livre::~Livre()
{

}


// La méthodes d’accès et de modifications pour les nouveaux attributs : obtenirAuteur(), obtenirGenre(), modifierAuteur(), modifierGenre()
std::string Livre::obtenirAuteur() const							
{
	return auteur_;
}

std::string Livre::obtenirGenre() const
{
	return genre_;
}

void Livre::modifierAuteur(const std::string& unAuteur){
	auteur_ = unAuteur;
}

void Livre::modifierGenre(const std::string& unGenre){
	genre_ = unGenre;
}




// Une redéfinition de la méthode rechercher() qui va aussi vérifier si la chaîne de
// caractères est présente dans les nouveaux attributs de type string
bool Livre::recherche(const std::string& motsCle) const{		

	bool estTrouve = false;

	std::size_t trouveAuteur = convertirMinuscule(auteur_).find(convertirMinuscule(motsCle));
	std::size_t trouveGenre = convertirMinuscule(genre_).find(convertirMinuscule(motsCle));

	estTrouve = ObjetEmpruntable::recherche(motsCle) || 
		(trouveAuteur != string::npos) ||
		(trouveGenre != string::npos);

	return estTrouve;

}



// L’opérateur << qui affiche les informations du Livre, tel que présenté dans l’exemple à la
// fin du document. Il doit appeler l’opérateur << de la classe ObjetEmpruntable.
ostream& operator<<(ostream& out, const Livre& livre){
	out << "Information sur le livre :" << endl
		<< (ObjetEmpruntable)livre
		<< " Auteur : " << livre.auteur_
		<< "; Genre : " << livre.genre_ << endl;
	return out;
}