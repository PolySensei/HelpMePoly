/****************************************************************************
* Fichier: Professeur.cpp
* Auteur: PolySensei & Associates
* Date: 11 février 2016
* Mise a jour : 20 février 2016
* Description: Implémentation de la classe Professeur
****************************************************************************/
#include <iostream>
#include "Professeur.h"

using namespace std;

// Un constructeur par défaut.
Professeur::Professeur(){

}

// Un constructeur par paramètres qui initialise les attributs en fonction des paramètres.
Professeur::Professeur(const std::string& matricule, const std::string& nom, const std::string& prenom, unsigned int age, std::vector<std::string> vecEcoles)
	: Abonne(matricule, nom, prenom, age), vecEcoles_(vecEcoles)
{

}

// Le destructeur pour cette classe.
Professeur::~Professeur()
{

}

// La méthode d’accès au nouvel attribut.
vector<string> Professeur::obtenirVecEcoles() const
{
	return vecEcoles_;
}


// Une méthode ajouterEcole() qui prend en paramètre un string, et l’ajoute au vecteur.
void Professeur::ajouterEcole(const std::string& ecole)
{
	vecEcoles_.push_back(ecole);
}


// Une méthode retirerEcole () qui prend en paramètre un string. La méthode enlève
// l’école associée à ce string du vecteur.La méthode retourne un booléen true si l’école
// est retirée et false sinon.
bool Professeur::retirerEcole(const std::string& ecole)
{
	bool estRetire = false;
	for (unsigned int i = 0; i < vecEcoles_.size(); i++){
		if ((vecEcoles_[i] == ecole) && (!estRetire)){
			estRetire = true;
			vecEcoles_[i] = vecEcoles_[vecEcoles_.size() - 1];
			vecEcoles_.pop_back();
		}
	}
	return estRetire;
}


// La redéfinition de la méthode obtenir limiteEmprunts() en tenant compte du fait qu’un
// enseignant peut emprunter un nombre limité de livre définie comme suit limiteEmprunt
// = nombre Ecole x limite Emprunt Classique
unsigned int Professeur::obtenirLimiteEmprunts() const
{
	return vecEcoles_.size() * Abonne::obtenirLimiteEmprunts();
}


// L’opérateur << , qui affiche les informations du Professeur, tel que présenté dans
// l’exemple à la fin du document. Il doit appeler l’opérateur << de la classe Abonne.
std::ostream& operator<<(std::ostream& out, const Professeur& professeur){
	out << (Abonne)professeur
		<< "Limite d'emprunts : " << professeur.obtenirLimiteEmprunts() << endl
		<< "LISTE DES ECOLES : ";
	for (unsigned int i = 0; i < professeur.vecEcoles_.size(); i++){
		out << professeur.vecEcoles_[i] << "; ";
	}
	out << endl;

	return out;
}