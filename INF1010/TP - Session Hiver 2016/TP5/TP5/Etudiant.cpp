/****************************************************************************
* Fichier: Etudiant.cpp
* Auteur: PolySensei & Associates
* Date: 6 mars 2016
* Mise a jour : 28 mars 2016
* Description: Implémentation de la classe Etudiant
****************************************************************************/
#include "Etudiant.h"

using namespace std;

Etudiant::Etudiant() : Abonne(), ecole_("")
{

}

Etudiant::Etudiant(const string& matricule, const string& nom, const string& prenom, unsigned int age, const string& ecole) :
	Abonne(matricule, nom, prenom, age), ecole_(ecole)
{

}
Etudiant::~Etudiant()
{

}

string Etudiant::obtenirEcole() const
{
	return ecole_;
}

void Etudiant::modifierEcole(const string& ecole)
{
	ecole_ = ecole;
}

unsigned int Etudiant::obtenirLimiteEmprunt() const
{
	return Abonne::obtenirLimiteEmprunt() * 2;
}

ostream & operator<<(ostream & o, const Etudiant & etudiant)
{
	const Abonne* ab = &etudiant;
	return o << (*ab)
		<< "Ecole de provenance : "
		<< etudiant.ecole_ 
		<< "; Limite d'emprunts : " << etudiant.obtenirLimiteEmprunt() << endl;
}
