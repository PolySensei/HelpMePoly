/****************************************************************************
* Fichier: Etudiant.cpp
* Auteur: PolySensei & Associates
* Date: 11 février 2016
* Mise a jour : 20 février 2016
* Description: Implémentation de la classe Etudiant
****************************************************************************/
#include <iostream>
#include "Etudiant.h"
#include <string>

using namespace std;

// Un constructeur par défaut qui initialise en plus l’attribut Ecole à la chaîne vide
Etudiant::Etudiant() : Abonne(), ecole_("")
{

}


// Un constructeur par paramètres qui initialise les attributs selon les paramètres.
Etudiant::Etudiant(const std::string& matricule, const std::string& nom, const std::string& prenom, unsigned int age, const std::string& ecole)
	: Abonne(matricule, nom, prenom, age), ecole_(ecole)
{

}

// Le destructeur pour cette classe.
Etudiant::~Etudiant()
{

}


// Les méthodes d’accès et de modification du nouvel attribut
string Etudiant::obtenirEcole() const
{
	return ecole_;
}

void Etudiant::modifierEcole(const std::string& ecole){
	ecole_ = ecole;
}



// Une redéfinition de la méthode pour obtenir le nombre d’emprunts, en tenant compte du
// fait qu’un étudiant à une limite d’emprunt 2 fois plus élevée qu’un abonné classique
unsigned int Etudiant::obtenirLimiteEmprunts() const
{    
	return Abonne::obtenirLimiteEmprunts()*2;
}


// L’opérateur << , qui affiche les informations de l’étudiant, tel que présenté dans l’exemple
// à la fin du document.Il doit utiliser l’opérateur << de la classe de base
ostream& operator<<(ostream& out, const Etudiant& etudiant){
	out << (Abonne)etudiant << "Ecole de provenance : " << etudiant.ecole_ << "; Limite d'emprunts : " << etudiant.obtenirLimiteEmprunts() << endl;   //Etudiant est un abonne
	return out;
}