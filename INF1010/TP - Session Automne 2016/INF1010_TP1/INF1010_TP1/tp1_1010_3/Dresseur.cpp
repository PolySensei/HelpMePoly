/****************************************************************************
* Fichier: Dresseur.cpp
* Auteur: Poly Sensei 091111 & Associates
* Date: 14 septembre 2016
* Mise a jour :  26 septembre 2016
* Description: Implémentation de la classe Dresseur
****************************************************************************/
#include <iostream>
#include <string>
#include "Dresseur.h"
#include "Creature.h"
#include "ObjetMagique.h"

using namespace std;


Dresseur::Dresseur()
	: nom_(""), nombreCreatures_(0), creatures_(nullptr), nombreCreaturesMax_(MAX_NOMBRE_CREATURES), objetMagique_()
{
	creatures_ = new Creature*[MAX_NOMBRE_CREATURES];
	for (int i = 1; i < MAX_NOMBRE_CREATURES; i++)
		creatures_[i] = nullptr;
}

Dresseur::Dresseur(const string& nom)
	: nom_(nom), nombreCreatures_(0), creatures_(nullptr), nombreCreaturesMax_(MAX_NOMBRE_CREATURES), objetMagique_()
{
	creatures_ = new Creature*[MAX_NOMBRE_CREATURES];
	for (int i = 1; i < MAX_NOMBRE_CREATURES; i++)
		creatures_[i] = nullptr;
}

Dresseur::~Dresseur()
{
	for (int i = 1; i < nombreCreatures_; i++) {
		delete creatures_[i];
		creatures_[i] = nullptr;
	}
}


string Dresseur::obtenirNom() const
{
	return nom_;
}

ObjetMagique Dresseur::obtenirObjetMagique() const
{
	return objetMagique_;
}

unsigned int Dresseur::obtenirNombreCreatures() const
{
	return nombreCreatures_;
}

Creature** Dresseur::obtenirCreatures() const
{
	return creatures_;
}

void Dresseur::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Dresseur::modifierObjetMagique(const ObjetMagique& objetMagique)
{
	objetMagique_ = objetMagique;
}

void Dresseur::modifierCreature(Creature** creatures)
{
	creatures_ = creatures;
}

void Dresseur::modifierNombreCreatures(unsigned int nombreCreatures)
{
	nombreCreatures_ = nombreCreatures;
}

void Dresseur::modifierNombreCreaturesMax(unsigned int nombreCreaturesMax)
{
	nombreCreaturesMax_ = nombreCreaturesMax;
}
/*Une méthode ajouterCreature() qui prend en paramètre une créature et qui l’ajoute au
tableau de créatures du dresseur. L’ajout de la créature ne se
fait que si le dresseur ne la possède pas encore.Cette méthode doit renvoyer true si
l’opération est un succès, false sinon */

bool Dresseur::ajouterCreature(Creature& creature) {
	bool estAjoute = true;
/*Si la taille des créatures atteint est égale à la taille
maximale, le nombre de créatures maximal va être doublé */
	if (nombreCreatures_ == nombreCreaturesMax_) {
		Creature** tableauTemp = new Creature* [nombreCreaturesMax_ * 2];
		for (int i = 0; i < nombreCreatures_; i++) {
			tableauTemp[i] = creatures_[i];
		}
		delete[] creatures_;
		creatures_ = tableauTemp;
		modifierNombreCreaturesMax(nombreCreaturesMax_ * 2);
	}
	for (unsigned int i = 0; i < nombreCreatures_ ; i++) {
		if (creatures_[i] == &creature) {
			estAjoute = false;
		}
	}
	if (estAjoute == true){
			creatures_[nombreCreatures_] = &creature;
			nombreCreatures_++;
	}
	return estAjoute;
}



	


/*Une méthode retirerCreature() qui prend en paramètre un nom et retire la créature
avec le nom associé si le dresseur la possède.Cette méthode doit renvoyer true si
l’opération est un succès, false sinon */

bool Dresseur::retirerCreature(Creature& creature) {
	bool estRetire = false;
	for (unsigned int i = 0; i < nombreCreatures_; i++) {
		if (creatures_[i] == &creature) {	
			creatures_[i] = nullptr;
			estRetire = true;
		}
	}
	return estRetire;
}

void Dresseur::utiliserObjetMagique(Creature* creature)
{
	creature->modifierPointDeVie((creature->obtenirPointDeVie()) + (objetMagique_.obtenirBonus())) ;
	creature->modifierEnergie((creature->obtenirEnergie()) + (objetMagique_.obtenirBonus())) ;
}


void Dresseur::affichage() const {

	cout << nom_ << " possede " << nombreCreatures_ << " creature(s)" << endl;
}
