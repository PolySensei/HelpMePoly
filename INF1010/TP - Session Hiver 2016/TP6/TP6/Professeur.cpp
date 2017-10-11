#include "Professeur.h"
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;

Professeur::Professeur() : Abonne()
{

}

Professeur::Professeur(const string& matricule, const string& nom, const string& prenom, unsigned int age, vector<string> ecoles) :
	Abonne(matricule, nom, prenom, age)
{
	copy(ecoles.begin(), ecoles.end(), back_inserter(listEcoles_));
}
Professeur::~Professeur()
{

}

list<string> Professeur::obtenirEcole() const
{
	return listEcoles_;
}

void Professeur::ajouterEcole(std::string const & ecole)
{
	if (find(listEcoles_.begin(), listEcoles_.end(), ecole) == listEcoles_.end())
		listEcoles_.push_back(ecole);		
}

bool Professeur::retirerEcole(std::string const & ecole)
{
	size_t sizeAvant = listEcoles_.size();
	listEcoles_.remove(ecole);
	return  (sizeAvant != listEcoles_.size());
}

unsigned int Professeur::obtenirLimiteEmprunt() const
{
	return Abonne::obtenirLimiteEmprunt()*listEcoles_.size();
}


ostream & operator<<(ostream & o, const Professeur & professeur)
{
	const Abonne* ab = &professeur;
	o << *ab 
	<< "Limite d'emprunts : " << professeur.obtenirLimiteEmprunt() << endl;;
		

	o << "LISTE DES ECOLES : " ;

	// Affichage de la liste des ecoles
	list<string>  liste = professeur.obtenirEcole();
	liste.sort(greater<string>());
	for each(string str in liste)
		o << str << "; ";

	o << endl;
	return o;
}