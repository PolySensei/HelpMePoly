/****************************************************************************
* Fichier: Professeur.h
* Auteur: PolySensei & Associates
* Date: 11 février 2016
* Mise a jour : 20 février 2016
* Description: Définition de la classe Professeur
****************************************************************************/
#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include <string>
#include <vector>
#include <iostream>
#include "Abonne.h"

//Héritage de la classe Abonne
class Professeur : public Abonne {

	public:

		Professeur();

		Professeur(const std::string& matricule, const std::string& nom, const std::string& prenom, unsigned int age, std::vector<std::string> vecEcoles);

		~Professeur();

		std::vector<std::string> obtenirVecEcoles() const;

		void ajouterEcole(const std::string& ecole);
		bool retirerEcole(const std::string& ecole);

		unsigned int obtenirLimiteEmprunts() const;

		friend std::ostream& operator<<(std::ostream& out, const Professeur& professeur);

		
	private:
		// Un vecteur de string qui correspond aux différentes écoles où il enseigne.
		std::vector<std::string> vecEcoles_;

};

#endif
