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
#include "Abonne.h"
#include "Livre.h"
#include "Emprunt.h"
#include <iostream>

#define LIMITE_EMPRUNTS 2


class Bibliotheque
{
public:

	Bibliotheque();
	~Bibliotheque();

	bool estEmpruntable(const Abonne& abonne, const Livre& livre) const;

	Abonne* trouverAbonne(std::string const unMatricule) const;
	Livre* trouverLivre(std::string const unCote) const;
	void ajouterAbonne(Abonne&);
	void retirerAbonne(std::string const unMatricule);
	void ajouterLivre(Livre&);
	bool retirerLivre(std::string const uneCote);
	void rechercherLivre(std::string chaineCaracteres) const;
	bool emprunter(const std::string unMatricule, const std::string uneCote, unsigned int dateRetour);
	bool retourner(const std::string matricule, const std::string cote);
	void infoAbonne(const std::string matricule) const;
	friend void operator>>(std::istream&, Bibliotheque&);
	void operator+=(Abonne*);
	void operator+=(Livre*);
	void operator-=(Abonne*);
	void operator-=(Livre*);



private:
	std::vector<Abonne*> listeAbonnes_;
	std::vector<Livre*> listeLivres_;
	std::vector<Emprunt*> listeEmprunts_;
};

#endif