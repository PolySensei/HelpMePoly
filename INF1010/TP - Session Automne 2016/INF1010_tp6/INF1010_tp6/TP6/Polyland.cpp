/*
Fichier: Dresseur.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description:
*/
#include "PolyLand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

PolyLand::PolyLand(Dresseur& dresseur):hero_(dresseur) {};
//
//
//PolyLand::~PolyLand()
//{
//	while (creatures_.size() != 0)
//	{
//		delete creatures_.back();
//		creatures_.back() = nullptr;
//		creatures_.pop_back();
//	}
//	while (dresseurs_.size() != 0)
//	{
//		dresseurs_.back() = nullptr;
//		dresseurs_.pop_back();
//	}
//}


//bool PolyLand::ajouterDresseur(Dresseur* dresseur)
//{
//	for (unsigned int i = 0; i < dresseurs_.size(); i++)
//	{
//		if (dresseur->obtenirNom() == *(dresseurs_[i]))
//		{
//			std::cout << dresseur->obtenirNom() << " n'a pas ete ajoute" << std::endl;
//			return false;
//		}
//	}
//	dresseurs_.push_back(dresseur);
//	std::cout << dresseur->obtenirNom() << " a bien �t� ajout� !" << std::endl;
//	return true;
//}
//
//bool PolyLand::retirerDresseur(const std::string& nom)
//{
//	for (unsigned int i = 0; i < dresseurs_.size(); i++)
//	{
//		if (*(dresseurs_[i]) == nom)
//		{
//			dresseurs_[i] = dresseurs_.back();
//			dresseurs_.pop_back();
//			std::cout << nom << " a bien �t� retire !" << std::endl;
//			return true;
//		}
//	}
//	return false;
//}
//
//bool PolyLand::ajouterCreature(Creature* creature)
//{
//	creatures_.push_back(new Creature(*creature));
//	std::cout << creature->obtenirNom() << " a bien �t� ajout� !" << std::endl;
//	return true;
//}
//
//bool PolyLand::retirerCreature(const std::string& nom)
//{
//	for (unsigned int i = 0; i < creatures_.size(); i++)
//	{
//		if (creatures_[i]->obtenirNom() == nom)
//		{
//			delete creatures_[i];
//			creatures_[i] = creatures_.back();
//			creatures_.pop_back();
//			std::cout << nom << " a bien �t� retire !" << std::endl;
//			return true;
//		}
//	}
//	return false;
//}

//Dresseur* PolyLand::choisirDresseurAleatoire()
//{
//	if (listMaitre_.size() > 0) {
//		unsigned int indice = rand() % listMaitre_.size();
//		return listMaitre_[indice];
//	}
//	else {
//		return nullptr;
//	}
//}
//
//Creature* PolyLand::choisirCreatureAleatoire()
//{
//	if (listCompagnon_.size() > 0) {
//		unsigned int indice = rand() % listCompagnon_.size();
//		return listCompagnon_[indice];
//	}
//	else {
//		return nullptr;
//	}
//}


Dresseur& PolyLand::obtenirHero() const{
	return hero_;
}


void PolyLand::attraperCreature(Dresseur* dresseur, Creature* creature)
{
    dresseur->ajouterCreature(creature);
}

bool PolyLand::relacherCreature(Dresseur* dresseur, const std::string& nomCreature)
{
	return dresseur->enleverCreature(nomCreature);
}

//PolyLand& PolyLand::operator+= (Dresseur* dresseur)
//{
//	ajouterDresseur(dresseur);
//	return *this;
//}
//
//PolyLand& PolyLand::operator-=(Dresseur* dresseur)
//{
//	retirerDresseur(dresseur->obtenirNom());
//	return *this;
//}
//
//PolyLand& PolyLand::operator+= (Creature* creature)
//{
//	ajouterCreature(creature);
//	return *this;
//}
//
//PolyLand& PolyLand::operator-=(Creature* creature)
//{
//	retirerCreature(creature->obtenirNom());
//	return *this;
//}



std::ostream& operator<<(std::ostream& os, const PolyLand& poly)
{
	if (!poly.listMaitre_.empty())
	{
		list<Dresseur*> listDresseurTemp = poly.obtenirListMaitre();
		listDresseurTemp.sort(FoncteurComparerDresseur());
		for each (Dresseur* dresseur in listDresseurTemp)
		{
			os << *dresseur << std::endl;
		}
	}

	if (!poly.listCompagnon_.empty())
	{
		list<Creature*> listCreatureTemp = poly.obtenirListCompagnon();
		listCreatureTemp.sort(FoncteurComparerCreature());
		for each (Creature* creature in listCreatureTemp)
		{
			os << *creature << std::endl;
		}
	}

	return os;
}
