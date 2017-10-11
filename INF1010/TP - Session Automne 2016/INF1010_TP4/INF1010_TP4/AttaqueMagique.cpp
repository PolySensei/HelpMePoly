#include "AttaqueMagique.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
;

AttaqueMagique::AttaqueMagique(): duree_(0)
{

}
//Un constructeur qui prend en paramètre une durée
AttaqueMagique::AttaqueMagique(int duree): duree_(duree)
{

}
//Un destructeur
AttaqueMagique::~AttaqueMagique()
{

}
//Un accesseur et un modificateur de l’attribut
unsigned int AttaqueMagique::obtenirDuree()
{
	return duree_;
}
void AttaqueMagique::modifierDuree(int duree)
{
	duree_ = duree;
}
//Une méthode obtenirTypeAttaque() qui retourne le type de l’attaque.
string AttaqueMagique::obtenirTypeAttaque()
{
	return typeid(*this).name();
}
//La méthode estFini() qui retourne toujours true
bool AttaqueMagique::estFini()
{
	return true;
}
//Affichage
std::ostream& operator<<(std::ostream& os, AttaqueMagique& attaque)
{
	os << "Cette creature de la classe CreatureMagique a aussi une attaque magique de type classe "
		<< attaque.obtenirTypeAttaque() << " qui a une duree de " << attaque.obtenirDuree() << endl;
	return os;
}