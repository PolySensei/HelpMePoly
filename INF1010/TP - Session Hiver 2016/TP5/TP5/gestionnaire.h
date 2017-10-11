/****************************************************************************
* Fichier: Gestionnaire.h
* Auteur: PolySensei & Associates
* Date: 7 mars 2016
* Mise a jour : 28 mars 2016
* Description: Définition de la classe Gestionnaire
****************************************************************************/

#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <algorithm>
#include <list>
#include <string>
using namespace std;

template <typename T>
class Gestionnaire
{
public:
	Gestionnaire(){}
	~Gestionnaire(){}

	bool ajouterElement(T* ptrElement);
	bool retirerElement(T* ptrElement);

	template <typename P>
	bool retirerContenu(P& predicat);
	template <typename P>
	T* trouverElement(const P& predicat) const;

	bool trouverElement(const T& element) const;

	template <typename P>
	list<T*> trouverContenu(const P& predicat) const;

	
private:
	list<T*> conteneur_;

};
#endif //GESTIONNAIRE_H



//Une méthode ajouterElement() qui reçoit un pointeur de l’élément en paramètre et qui permet de l’ajouter seulement s’il n’est pas déjà dans le conteneur.Si l’ajout a été fait, la méthode renvoie true, false sinon.
template <typename T>
bool Gestionnaire<T>::ajouterElement(T* ptrElement)
{
	bool estAjoute = false;
	list<T*>::iterator it = find(conteneur_.begin(), conteneur_.end(), ptrElement);

	if (it == conteneur_.end())
	{
		estAjoute = true;
		conteneur_.push_back(ptrElement);
	}

	return estAjoute;
}


// Une méthode retirerElement () qui reçoit un pointeur de l’élément en paramètre et qui permet de le retirer du conteneur.Si le retrait a été fait, la méthode renvoie true, false sinon.
template <typename T>
bool Gestionnaire<T>::retirerElement(T* ptrElement)
{
	bool estRetire = false;
	int nElementInitial = conteneur_.size();

	conteneur_.remove(ptrElement);

	if (nElementInitial > conteneur_.size())
	{
		estRetire = true;
	}

	return estRetire;
}


// Une méthode générique sur le predicat, retirerContenu() qui prend un prédicat unaire(Predicate&) en paramètre, retire l’objet ou les objets dans le conteneur qui vérifie le prédicat et retourne true si au moins un élément est retiré, false sinon. Un prédicat unaire une fonction qui a un seul paramètre et retourne un booléen.
template <typename T>
template <typename P>
bool Gestionnaire<T>::retirerContenu(P& predicat)
{
	bool estRetire = false;
	int nElementInitiale = conteneur_.size();

	conteneur_.remove_if(predicat);

	if (nElementInitiale > conteneur_.size())
	{
		estRetire = true;
	}
	return estRetire;
}


// Une méthode générique sur le prédicat trouverElement() qui prend un prédicat unaire(Predicate&) en paramètre, recherche l’objet qui vérifie le prédicat et retourne un pointeur de type T.Si aucun objet n’est retrouvé, un pointeur nul est retourné sinon.
template <typename T>
template <typename P>
T* Gestionnaire<T>::trouverElement(const P& predicat) const
{
	auto it = find_if(conteneur_.begin(), conteneur_.end(), predicat);
	if (it != conteneur_.end())
	{
		return *it;
	}
	return nullptr;
}


// Une méthode trouverElement() qui est une surcharge de la méthode précédente, elle prend un élément de type T reçu en paramètre, recherche l’objet et retourne true si l’élément est trouvé, false sinon.
template <typename T>
bool Gestionnaire<T>::trouverElement(const T& element) const
{
	bool estTrouve = false;
	list<T*>::iterator it = find(conteneur_.begin(), conteneur_.end(), &element);

	if (it != conteneur_.end() || !(conteneur_.empty()))
	{
		estTrouve = true;
	}

	return estTrouve;
}


// Une méthode générique sur le prédicat, trouverContenu() qui prend un prédicat unaire(Predicate&) en paramètre, recherche tous les objets qui vérifient le prédicat et retourne une liste de pointeur de type T.Si aucun objet n’est retrouvé, une liste vide est retournée sinon.
template <typename T>
template <typename P> 
list<T*> Gestionnaire<T>::trouverContenu(const P& predicat) const
{
	list<T*> conteneurRetour(conteneur_.size());
	list<T*>::iterator it = copy_if(conteneur_.begin(), conteneur_.end(), conteneurRetour.begin(), predicat);
	conteneurRetour.resize(distance(conteneurRetour.begin(), it));
	return conteneurRetour;
}