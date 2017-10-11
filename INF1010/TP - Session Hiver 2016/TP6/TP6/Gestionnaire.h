/*
Fichier: Gestionnaire.h
Auteur(s): Mohamed Amine Kibiche
Date de creation: 25 février 2016
Date de modification: 25 février 2016
Description: Classe template permet de gérer l'Ajout, le retrait  la recherche des objets
*/
#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <list>
#include <algorithm>
#include <iostream>
#include <iterator>

template <typename T>
class Gestionnaire 
{
public:
	// Constructeurs et destructeurs
	Gestionnaire() {};
	~Gestionnaire() {};

	bool ajouterElement(T* element);
	bool retirerElement(T* element);
	template<typename Predicate>
	bool retirerContenu(const Predicate& p);
	bool trouverElement(const T& element)const;
	template<typename Predicate>
	T* trouverElement(const Predicate& p)const;
	template<typename Predicate>
	std::list<T*> trouverContenu(Predicate& p)const;
private:
	// Attributs
	std::list<T*> listeContenu_;
};

using namespace std;

// Ajouter le contenu
template<typename T>
bool Gestionnaire<T>::ajouterElement(T* element)
{
	if (trouverElement(*element))
		return false;
	listeContenu_.push_back(element);
	return true;
}
// retirer le contenu
template<typename T>
bool Gestionnaire<T>::retirerElement(T* element)
{
	size_t sizeAvant = listeContenu_.size();
	listeContenu_.remove(element);
	return  (sizeAvant != listeContenu_.size());
}

template<typename T>
template<typename Predicate>
bool Gestionnaire<T>::retirerContenu(const Predicate &p)
{
	size_t sizeAvant = listeContenu_.size();
	listeContenu_.remove_if(p);
	return  (sizeAvant != listeContenu_.size());
}
// trouver le contenu
template<typename T>
bool Gestionnaire<T>::trouverElement(const T& element) const
{
	return (find(listeContenu_.begin(), listeContenu_.end(), &element) != listeContenu_.end());
}

template<typename T>
template<typename Predicate>
T* Gestionnaire<T>::trouverElement(const Predicate& p) const
{
	list <T*>::const_iterator trouve = find_if(listeContenu_.begin(), listeContenu_.end(), p);
	if (trouve != listeContenu_.end())
		return (*trouve);
	return nullptr;
}

template<typename T>
template<typename Predicate>
list<T*> Gestionnaire<T>::trouverContenu( Predicate& p) const
{
	list<T*> local;
	copy_if(listeContenu_.begin(), listeContenu_.end(), back_inserter(local), p);
	return local;
}
#endif //GESTIONNAIRE_H
