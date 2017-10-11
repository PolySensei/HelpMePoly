/****************************************************************************
* Fichier: Dresseur.h
* Auteur: Poly Sensei 091111 & Associates
* Date: 28 septembre 2016
* Mise a jour :  03 octobre 2016
* Description: Definition de la classe Dresseur
****************************************************************************/

#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include <vector>
#include "Creature.h"

#define MAX_NOMBRE_CREATURES 2


class Dresseur
{
public:
	Dresseur();
	Dresseur(const std::string& nom, const std::string& equipe);
	~Dresseur();

	std::string obtenirNom() const;
	void modifierNom(const std::string& nom);

	std::string obtenirEquipe() const;
	void modifierEquipe(const std::string& equipe);

	std::vector<Creature*> obtenirVecteurCreatures() const;
	void modifierCreature(Creature* creatures);

	ObjetMagique obtenirObjetMagique() const;
	void modifierObjetMagique(const ObjetMagique& objetMagique);

	void utiliserObjetMagique(Creature* creature);
	
	bool ajouterCreature(Creature* creature);
	bool enleverCreature(const std::string& nom);

	Creature* obtenirUneCreature(const std::string& nom) const;

	friend std::ostream& operator<< (std::ostream& out, const Dresseur& dresseur);
	bool operator==(Dresseur& dresseur);
	bool operator==(const std::string& nom) const;

	friend bool operator==(const std::string& nom, const Dresseur& dresseur);

private:
	std::string nom_;
	ObjetMagique objetMagique_;

	// ___TP2____

	std::vector<Creature*> vecCreatures_;
	std::string equipe_;


};

#endif