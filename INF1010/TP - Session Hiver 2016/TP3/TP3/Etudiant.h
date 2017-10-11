/****************************************************************************
* Fichier: Etudiant.h
* Auteur: PolySensei & Associates
* Date: 11 février 2016
* Mise a jour : 20 février 2016
* Description: Définition de la classe Etudiant
****************************************************************************/
#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <string>
#include <vector>
#include <iostream>
#include "Abonne.h"

//héritage de la calsse Abonne
class Etudiant : public Abonne {
	public:

		Etudiant();
		Etudiant(const std::string& matricule, const std::string& nom, const std::string& prenom, unsigned int age, const std::string& ecole);
		~Etudiant();

		std::string obtenirEcole() const;
		void modifierEcole(const std::string& ecole);
		unsigned int obtenirLimiteEmprunts() const;
		friend std::ostream& operator<<(std::ostream& out, const Etudiant& etudiant);

	
	protected:
		// Ecole (string), qui correspond à l’école de provenance de l’étudiant
		std::string ecole_;


};

#endif