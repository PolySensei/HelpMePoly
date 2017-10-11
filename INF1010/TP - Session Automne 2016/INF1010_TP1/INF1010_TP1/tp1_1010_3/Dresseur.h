/****************************************************************************
* Fichier: Dresseur.h
* Auteur: Poly Sensei 091111 & Associates
* Date: 14 septembre 2016
* Mise a jour :  26 septembre 2016
* Description: Définiton de la classe Dresseur
****************************************************************************/

#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include "Creature.h"
#include "ObjetMagique.h"

using namespace std;

const int MAX_NOMBRE_CREATURES = 2;

class Dresseur
{
public:
    Dresseur();
	Dresseur(const std::string& nom);
    ~Dresseur();

    std::string obtenirNom() const;
    void modifierNom(const std::string& nom);

    ObjetMagique obtenirObjetMagique() const;
    void modifierObjetMagique(const ObjetMagique& objetMagique);

    void utiliserObjetMagique(Creature* creature);

    unsigned int obtenirNombreCreatures() const;

    Creature** obtenirCreatures() const;
    void modifierCreature(Creature** creatures);
	void modifierNombreCreatures(unsigned int nombreCreatures);
	void modifierNombreCreaturesMax(unsigned int nombreCreaturesMax);

    bool ajouterCreature(Creature& creature);
    bool retirerCreature(Creature& creature);

    void affichage() const;

private:
    std::string nom_;
    Creature** creatures_;
    unsigned int nombreCreatures_;
    unsigned int nombreCreaturesMax_;
    ObjetMagique objetMagique_;

};

#endif