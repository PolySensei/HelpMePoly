/****************************************************************************
* Fichier: EtatCreature.h
* Auteur: Poly Sensei 091111 & Associates
* Date: 5 octobre 2016 Mise a jour : 19 octobre 2016
* Description: Définition de la classe EtatCreature
****************************************************************************/

#ifndef ETAT_CREATURE_H
#define ETAT_CREATURE_H

#include <iostream>
#include <string>  
#include "Creature.h"
#include "TypeEtat.h"


//déclaration anticipée nécessaire à cause des inclusions circulaires
class Creature;

class EtatCreature
{
public:
    EtatCreature(const std::string& nom);
    EtatCreature(const std::string& nom, unsigned int duree);
    ~EtatCreature();

    void appliquerEtat(Creature& creature); //à appliquer sur la créature qui possède ce pouvoir
    bool peutAttaquer() const; //détermine si l'état de la créature lui permet d'attaquer
    bool estFini() const; //si vrai, informe la créature qu'elle peut retourner à l'état normal

    std::string obtenirNom() const;
    TypeEtat obtenirType() const;

    friend std::ostream& operator<<(std::ostream& o, const EtatCreature& etatCreature);
private:
    std::string nom_;

	//Attributs tp3
protected:
    unsigned int duree_;
    TypeEtat type_;
};
#endif // !ETAT_CREATURE_H




