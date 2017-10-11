/****************************************************************************
* Fichier: Professeur.cpp
* Auteur: PolySensei & Associates
* Date: 6 mars 2016
* Mise a jour : 28 mars 2016
* Description: Implémentation de la classe Professeur
****************************************************************************/
#include "Professeur.h"


using namespace std;

Professeur::Professeur() : Abonne()
{

}

Professeur::Professeur(const string& matricule, const string& nom, const string& prenom, unsigned int age, list<string> ecoles) :
	Abonne(matricule, nom, prenom, age), listeEcole_(ecoles)
{

}
Professeur::~Professeur()
{

}

list<string> Professeur::obtenirEcole() const
{
	return listeEcole_;
}

void Professeur::ajouterEcole(std::string const & ecole)
{
	bool present = false;

	if (binary_search(listeEcole_.begin(), listeEcole_.end(), ecole))
	{
		present = true;
	}

	if (!present)
		listeEcole_.push_back(ecole);
}

bool Professeur::retirerEcole(std::string const & ecole)
{
	bool estRetire = false;

	int tailleInitial = listeEcole_.size(); 

	listeEcole_.remove(ecole);

	if (tailleInitial > listeEcole_.size())
	{
		estRetire = true;
	}

	return estRetire;
}

unsigned int Professeur::obtenirLimiteEmprunt() const
{
	return Abonne::obtenirLimiteEmprunt()*listeEcole_.size();
}


ostream & operator<<(ostream & o, const Professeur & professeur)
{
	const Abonne* ab = &professeur;
	o << *ab 
	<< "Limite d'emprunts : " << professeur.obtenirLimiteEmprunt() << endl;;
		
	o << "LISTE DES ECOLES : " ;

	// Affichage de la liste des ecoles
	list<string> listeEcole = professeur.obtenirEcole();
	listeEcole.sort(greater<string>());
	copy(listeEcole.begin(), listeEcole.end(), ostream_iterator<string>(o, "; "));

	o << endl;

	return o;
}