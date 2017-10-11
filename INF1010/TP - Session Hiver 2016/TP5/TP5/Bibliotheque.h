/****************************************************************************
* Fichier: Bibliotheque.h
* Auteur: PolySensei & Associates
* Date: 6 mars 2016
* Mise a jour : 28 mars 2016
* Description: Définition de la classe Bibliotheque
****************************************************************************/
#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <string>
#include <map>
#include <iostream>
#include "gestionnaire.h"
#include "Emprunt.h"
#include "Abonne.h"
#include "Etudiant.h"
#include "EtudiantBaccalaureat.h"
#include "Professeur.h"
#include "ObjetNumerique.h"
#include "ObjetEmpruntable.h"
#include "Livre.h"
#include "LivreNumerique.h"
#include "Dvd.h"
#include "DetruireEmprunt.h"
#include "MemeObjet.h"
#include "RechercheObjetEmpruntable.h"
#include "TrieParTitre.h"
#include "Empruntable.h"

class Bibliotheque
{
public:

	Bibliotheque();
	~Bibliotheque();

	Abonne* trouverAbonne(const std::string& matricule) const;

	ObjetEmpruntable* trouverObjetEmpruntable(const std::string& cote) const;

	std::string obtenirClasseObjet(std::string const& cote) const;

	bool ajouterAbonne(Abonne& abonne);
	bool retirerAbonne(const std::string& matricule);	

	bool ajouterObjetEmpruntable(ObjetEmpruntable* objet);
	
	bool retirerObjetEmpruntable(const std::string& cote);
	void rechercherObjetEmpruntable(const std::string& str) const;

	
	bool emprunter(const std::string& matricule, const std::string& cote, unsigned int date);
	bool retourner(const std::string& matricule, const std::string& cote);

	void infoAbonne(const std::string& matricule) const;

	Bibliotheque& operator+=(Abonne* abonne);
	Bibliotheque& operator+=(ObjetEmpruntable* obj);
	Bibliotheque& operator-=(Abonne* abonne);
	Bibliotheque& operator-=(ObjetEmpruntable* obj);

	friend std::istream& operator>>(std::istream& in, const Bibliotheque& biblio);

	/// ____ TP5 ___
	map<string, Emprunt*> Bibliotheque::trierEmprunt(Abonne * abonne) const;

private:

	/// ____ TP5 ___
	Gestionnaire<Abonne> gestAbonnes_;
	Gestionnaire<Emprunt> gestEmprunts_;
	Gestionnaire<ObjetEmpruntable>gestObj_;
};

#endif