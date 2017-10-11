/****************************************************************************
* Fichier: OutilScientifique.h
* Auteur: PolySensei 091111 and Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Définition de la classe OutilScientifique
****************************************************************************/
#ifndef OUTIL_SCIENTIFIQUE_H
#define OUTIL_SCIENTIFIQUE_H

#include <string>

#include "Creature.h"

class OutilScientifique
{
public:
    OutilScientifique(const std::string& nom, const std::string& description);
    ~OutilScientifique();

    std::string obtenirNom() const;
    std::string obtenirDesciption() const;

    void utiliser(Creature& creature);

    friend std::ostream& operator<<(std::ostream& os, const OutilScientifique& outil);
private:
    std::string nom_;
    std::string description_;
};
#endif // !OUTIL_SCIENTIFIQUE_H


