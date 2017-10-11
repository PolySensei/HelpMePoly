/****************************************************************************
* Fichier: Livre.cpp
* Auteur: PolySensei & Associates
* Date: 4 février 2016
* Mise a jour : 6 février 2016
* Description: Implémentation de la classe livre
****************************************************************************/
#include <iostream>
#include <algorithm>
#include "Livre.h"

using namespace std;

Livre::Livre()
//initialisation des variables
	: nbExemplaires_(0), nbDisponibles_(0), ageMinimal_(0)
{

}

Livre::Livre(const Livre& unLivre)
	: cote_(unLivre.cote_), titre_(unLivre.titre_), annee_(unLivre.annee_), ageMinimal_(unLivre.ageMinimal_), nbExemplaires_(unLivre.nbExemplaires_), nbDisponibles_(unLivre.nbExemplaires_)
{

}

Livre::Livre(const string& cote, const string& titre, unsigned int annee, unsigned int ageMin, unsigned int nbExemplaires)
	: cote_(cote), titre_(titre), annee_(annee), ageMinimal_(ageMin), nbExemplaires_(nbExemplaires), nbDisponibles_(nbExemplaires)
{

}

Livre::~Livre()
{

}

string Livre::obtenirCote() const
{
	return cote_;
}

string Livre::obtenirTitre() const
{
	return titre_;
}

unsigned int Livre::obtenirAnnee() const
{
	return annee_;
}

unsigned int Livre::obtenirAgeMinimal() const
{
	return ageMinimal_;
}

unsigned int Livre::obtenirNbExemplaires() const
{
	return nbExemplaires_;
}

unsigned int Livre::obtenirNbDisponibles() const
{
	return nbDisponibles_;
}

void Livre::modifierNbExemplaires(unsigned int nbExemplaires)
{
	nbExemplaires_ = nbExemplaires;
}

void Livre::modifierNbDisponibles(unsigned int nbDisponibles)
{
	nbDisponibles_ = nbDisponibles;
}

void Livre::modifierTitre(const std::string & titre)
{
	titre_ = titre;
}

void Livre::modifierCote(const std::string & cote)
{
	cote_ = cote;
}

void Livre::modifierAnnee(unsigned int annee)
{
	annee_ = annee;
}

// Converti une phrase en minuscule
std::string Livre::convertirMinuscule(const std::string & phrase) const
{
	string phraseRetour = phrase;
	std::transform(phrase.begin(), phrase.end(), phraseRetour.begin(), ::tolower);
	return phraseRetour;
}

// Recherche les informations d'un livre à partir d'un mot clé
bool Livre::recherche(const std::string & motsCle) const
{
	std::size_t trouveTitre		= convertirMinuscule(titre_).find(convertirMinuscule(motsCle));
	std::size_t trouveCote		= convertirMinuscule(cote_).find(convertirMinuscule(motsCle));
	
	bool estTrouve = 
		(trouveTitre != string::npos) || 
		(trouveCote != string::npos);

	return estTrouve;
}


/// ____________________ TP2 _____________________________



//L’opérateur == qui prend un Livre en paramètre et permet de comparer 2 livres en considérant à la fois le titre et la cote d’un livre.
//L’opérateur retourne true si les livres sont identiques.Ainsi, cet opérateur va pouvoir faire l’opération livre1 == livre2.
bool Livre::operator==(Livre& unLivre) const{
	bool estEgal = false;
	if (titre_ == unLivre.obtenirTitre()){
		if (cote_ == unLivre.obtenirCote()){
			estEgal = true;
		}
	}
	return estEgal;
}


//L’opérateur == qui prend une cote en paramètre et permet de comparer 2 livres en considérant seulement la cote.
//L’opérateur retourne true si les cotes sont identiques.Ainsi, cet opérateur va pouvoir faire l’opération livre == cote.
bool Livre::operator==(std::string uneCote) const{
	bool estEgal = false;
	if (cote_ == uneCote)
		estEgal = true;
	return estEgal;
}

//L’opérateur == de type friend qui permet d’inverser l’ordre de l’opérateur == précédent.Ainsi, cet opérateur va pouvoir faire l’opération cote == livre.
bool operator==(std::string uneCote, Livre& unLivre){
	bool estEgal = false;
	if (unLivre == uneCote)
		estEgal = true;
	return estEgal;
}

//L’opérateur < qui prend en paramètre un Livre et permet de comparer les titres des livres en ordre alphabétique.
bool Livre::operator<(Livre& livre2) const{
	return (titre_ < livre2.obtenirTitre());
}

//L’opérateur << (remplace la méthode d’affichage) qui affiche les informations qui concernent un Livre, tel que présenté dans l’exemple à la fin du document.
ostream& operator<<(ostream& out, const Livre& unLivre){
	out << unLivre.cote_ << ". " << unLivre.titre_ << ". " << unLivre.annee_ << ". " << unLivre.ageMinimal_ << " ans et plus.";
	return out;
}

//Un opérateur = qui écrase les attributs de l’objet de gauche par les attributs l’objet passés en paramètre.
const Livre& Livre::operator=(const Livre& unLivre){
	if (this != &unLivre){
		cote_ = unLivre.cote_;
		titre_ = unLivre.titre_;
		annee_ = unLivre.annee_;
		ageMinimal_ = unLivre.ageMinimal_;
		nbExemplaires_ = unLivre.nbExemplaires_;
		nbDisponibles_ = unLivre.nbDisponibles_;
	}
	return *this;
}