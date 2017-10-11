/*
Fichier: Bibliotheque.h
Auteur(s): Mohamed Amine Kibiche
Date de creation:
Date de modification: 25 f?vrier 2016
Description: la classe qui fait le lien entre toutes les autres classes
*/
#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <string>
#include <list>
#include <map>
#include "Abonne.h"
#include "ObjetEmpruntable.h"
#include "Emprunt.h"
#include "Gestionnaire.h"
#include <iostream>


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

    void emprunter(const std::string& matricule, const std::string& cote, unsigned int date);
    void retourner(const std::string& matricule, const std::string& cote);

    void infoAbonne(const std::string& matricule) const;

    std::list<Abonne*> obtenirListeAbonnes() const;
    std::list<Emprunt*> obtenirListeEmprunts() const;
    std::list<ObjetEmpruntable*> obtenirListeObjets() const;

    Bibliotheque& operator+=(Abonne* abonne);
    Bibliotheque& operator+=(ObjetEmpruntable* obj);
    Bibliotheque& operator-=(Abonne* abonne);
    Bibliotheque& operator-=(ObjetEmpruntable* obj);

    friend std::istream& operator>>(std::istream& in, const Bibliotheque& biblio);

    /// ____ TP5 ___
    map<string, Emprunt*> trierEmprunt(Abonne * abonne) const;

private:

    /// ____ TP5 ___
    Gestionnaire<Abonne> gestAbonnes_;
    Gestionnaire<Emprunt> gestEmprunts_;
    Gestionnaire<ObjetEmpruntable>gestObj_;
};

#endif
