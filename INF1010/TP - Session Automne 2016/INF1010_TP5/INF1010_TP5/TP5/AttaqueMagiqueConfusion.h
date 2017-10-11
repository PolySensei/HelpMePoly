/*
Fichier: AttaqueMagiqueConfusion.h
Auteur(s): Maude Carrier
Date de creation: 11 octobre 2016
Description: Cette attaque magique rend la créature qui la reçoit tellement confuse qu'elle en perd des points de vie
*/
#ifndef ETAT_CONFUS_H
#define ETAT_CONFUS_H

#include <stdlib.h>

#include "Foncteur.h"
#include "AttaqueMagique.h"

#define MIN_DUREE_CONFUSION 3

class AttaqueMagiqueConfusion : public AttaqueMagique
{
public:
    AttaqueMagiqueConfusion();
	AttaqueMagiqueConfusion(unsigned int duree); 
    virtual ~AttaqueMagiqueConfusion(); 

    virtual void appliquerAttaque(Creature& Creature); 

    virtual bool estFini() const;

	virtual std::string obtenirTypeAttaque() const;

private:
	FoncteurGenerateurNombresAlea foncteurConfusion_;
};
#endif 




