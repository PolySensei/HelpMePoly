/****************************************************************************
* Fichier: EtudiantBaccalaureat.cpp
* Auteur: PolySensei & Associates
* Date: 22 février 2016
* Mise a jour : 3 mars 2016
* Description: Implémentation de la classe EtudiantBaccalaureat
****************************************************************************/
#include "EtudiantBaccalaureat.h"

using namespace std;

EtudiantBaccalaureat::EtudiantBaccalaureat(const std::string& matricule, const std::string& nom, const std::string& prenom, unsigned int age)
	: Etudiant(matricule, nom, prenom, age, "Polytechnique Montreal")
{

}

unsigned int EtudiantBaccalaureat::obtenirLimiteEmprunt() const
{
	return (Etudiant::obtenirLimiteEmprunt()) * 2;
}

