/****************************************************************************
* Fichier: Bibliotheque.h
* Auteur: PolySensei & Associates
* Date: 4 février 2016
* Mise a jour : 6 février 2016
* Description: Définition de la classe Bibliotheque
****************************************************************************/
#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <string>
#include <vector>
#include "EtudiantBaccalaureat.h"
#include "Professeur.h"
#include "Livre.h"
#include "DVD.h"
#include "Emprunt.h"
#include <iostream>

#define LIMITE_EMPRUNTS 2


class Bibliotheque
{
public:

	Bibliotheque();
	~Bibliotheque();

	Abonne* trouveAbonne(const std::string& unMatricule) const;
	ObjetEmpruntable* trouverObjetEmpruntable(const std::string& unCote) const;
	std::string obtenirClasseObjet(const std::string& unCote) const;

	bool ajouterAbonne(Abonne&);
	bool retourner(const std::string & matricule, const std::string & cote);
	bool retirerAbonne(const std::string & unMatricule);					
	bool ajouterLivre(Livre& livre);
	bool ajouterDVD(Dvd& dvd);
	bool retirerObjetEmpruntable(const std::string& uneCote);

	void rechercher(const std::string& chaineCaracteres) const;
	bool estEmpruntable(const std::string & matricule, const ObjetEmpruntable & objetEmpruntable) const;
	bool emprunter(const std::string& unMatricule, const std::string uneCote, unsigned int dateRetour);
	void infoAbonne(const std::string & matricule) const;
	
	friend std::istream& operator>>(std::istream&, Bibliotheque&);
	Bibliotheque& operator+=(Abonne*);
	Bibliotheque& operator+=(Etudiant* ptrEtudiant);
	Bibliotheque& operator+=(EtudiantBaccalaureat* ptrEtudiantBaccalaureat);
	Bibliotheque& operator+=(Professeur* ptrProfesseur);
	Bibliotheque& operator+=(Livre*);
	Bibliotheque& operator+=(Dvd*);
	Bibliotheque& operator-=(Abonne*);
	Bibliotheque& operator-=(ObjetEmpruntable*);


private:
	// Vecteur de pointeurs d’abonnés.
	std::vector<Abonne*> vecAbonnes_;

	// Vecteur de pointeurs de livres.
	std::vector<Livre*> vecLivres_;

	// Vecteur de pointeurs de DVD.
	std::vector<Dvd*> vecDVD_;

	// Vecteur de pointeurs d’emprunt.
	std::vector<Emprunt*> vecEmprunts_;


};

#endif