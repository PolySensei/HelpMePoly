/*
Fichier: MemeElement.h
Auteur(s): Mohamed Amine Kibiche
Date de creation: 25 février 2016
Date de modification: 25 février 2016
Description: Foncteur permet de vérifier si l'élément existe déjèa
*/
#ifndef MEMEELEMENT_H
#define MEMEELEMENT_H


#include <string>
template<typename T, typename P>
class MemeElement
{
public:
	
	MemeElement(P* element) : element_(element) {};
	bool operator() (T *element);

private:
	P* element_;
};

template<typename T, typename P>
bool  MemeElement<T,P>::operator() (T *element)
{
	if (element_ != nullptr)
		return (*element) == (*element_);
	return false;
}

#endif // MEMEELEMENT_H