/****************************************************************************
* Fichier: EtudiantBaccalaureat.h
* Auteur: PolySensei & Associates
* Date: 22 février 2016
* Mise a jour : 3 mars 2016
* Description: Définition de la classe EtudiantBaccalaureat
****************************************************************************/
#ifndef ETUDIANTBACCALAUREAT_H
#define ETUDIANTBACCALAUREAT_H
#include "Etudiant.h"

class EtudiantBaccalaureat : public Etudiant
{
public:

	EtudiantBaccalaureat(const std::string& matricule, const std::string& nom, const std::string& prenom, unsigned int age);
	unsigned int obtenirLimiteEmprunt() const;

};
#endif