/****************************************************************************
* Fichier: MemeObjet.h
* Auteur: PolySensei & Associates
* Date: 7 mars 2016
* Mise a jour : 28 mars 2016
* Description: Définition et implémentation du foncteur MemeObjet
****************************************************************************/

#ifndef MEMEOBJET_H
#define MEMEOBJET_H

#include <algorithm>

// un foncteur générique binaire <T,P> pour les algorithmes de la librairie STL qui permet de trouver un objet identique dans le conteneur. Ce foncteur est un prédicat générique qui contient un attribut pointeur de type P et qui retourne true si l’objet de type T en paramètre est équivalent à l’attribut de pointeur type P.
template <typename T, typename P>
class MemeObjet
{
public:
	MemeObjet(P* ptrObjetP) : ptrObjetP_(ptrObjetP) {}


	bool operator()(T* ptrObjetT)
	{
		return *ptrObjetT == *ptrObjetP_;
	}


private:
	P* ptrObjetP_;
};


#endif //MEMEOBJET_H