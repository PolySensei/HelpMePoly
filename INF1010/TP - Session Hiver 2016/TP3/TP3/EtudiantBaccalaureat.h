/****************************************************************************
* Fichier: EtudiantBaccalaureat.h
* Auteur: PolySensei & Associates
* Date: 11 février 2016
* Mise a jour : 20 février 2016
* Description: Définition de la classe EtudiantBaccalaureat
****************************************************************************/
#ifndef ETUDIANTBACCALAUREAT_H
#define ETUDIANTBACCALAUREAT_H


#include <string>
#include <vector>
#include <iostream>
#include "Etudiant.h"

//Héritage de la classe Etudiant
class EtudiantBaccalaureat : public Etudiant{

public:

	EtudiantBaccalaureat(const std::string& matricule, const std::string& nom, const std::string& prenom, unsigned int age);

	~EtudiantBaccalaureat();

	unsigned int obtenirLimiteEmprunts() const;

};

#endif