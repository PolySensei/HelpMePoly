/****************************************************************************
* Fichier: EtudiantBaccalaureat.cpp
* Auteur: PolySensei & Associates
* Date: 11 février 2016
* Mise a jour : 20 février 2016
* Description: Implémentation de la classe EtudiantBaccalaureat
****************************************************************************/
#include <iostream>
#include "Etudiant.h"
#include "EtudiantBaccalaureat.h"

using namespace std;


// Un constructeur prenant en paramètre un matricule, un nom, un prénom et un âge et qui
// initialise l’attribut Ecole à « Polytechnique Montreal ».
EtudiantBaccalaureat::EtudiantBaccalaureat(const std::string & matricule, const std::string & nom, const std::string & prenom, unsigned int age)
	: Etudiant(matricule, nom, prenom, age, "Polytechnique Montreal")
{

}


EtudiantBaccalaureat::~EtudiantBaccalaureat()
{

}


// Une redéfinition de la méthode pour obtenir le nombre d’emprunts, en tenant compte du
// fait qu’un étudiant au baccalauréat à une limite d’emprunts 2 fois plus élevé qu’un
// étudiant classique
unsigned int EtudiantBaccalaureat::obtenirLimiteEmprunts() const
{    
	return Etudiant::obtenirLimiteEmprunts()*2;
}
