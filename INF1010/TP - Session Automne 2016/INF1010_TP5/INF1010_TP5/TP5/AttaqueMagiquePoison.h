/*
Fichier: AttaqueMagiquePoison.h
Auteur(s): Maude Carrier
Date de creation: 11 octobre 2016
Description: La créature qui reçoit cette attaque perd de l'énergie due au poison
*/
#ifndef ETAT_EMPOISONNE_H
#define ETAT_EMPOISONNE_H

#include "AttaqueMagique.h"
#include "Foncteur.h"

#define MIN_DUREE_POISON 2

class AttaqueMagiquePoison : public AttaqueMagique
{
public:
    AttaqueMagiquePoison(); // À MODIFIER
	AttaqueMagiquePoison(unsigned int duree); 
    virtual ~AttaqueMagiquePoison();

    virtual void appliquerAttaque(Creature& Creature); 

    virtual bool estFini() const;
	
	virtual std::string obtenirTypeAttaque() const;

private:

//Un FoncteurGenerateurNombresAlea
	FoncteurGenerateurNombresAlea foncteurPoison_;
};
#endif // !ETAT_EMPOISONNE_H

