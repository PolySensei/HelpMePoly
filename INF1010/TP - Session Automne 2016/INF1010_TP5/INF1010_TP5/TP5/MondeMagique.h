/****************************************************************************
* Fichier: MondeMagique.cpp
* Auteur: PolySensei and Associates
* Date: 7 novembre 2016 Mise a jour : 21 novembre 2016
* Description: Définition et implémentation de la classe template de la classe MondeMagique
****************************************************************************/
#include <list>
#include <string>
#include <algorithm>

using namespace std;

#ifndef MONDE_MAGIQUE_H
#define MONDE_MAGIQUE_H

template <typename T,typename S>

class MondeMagique
{
public:
	MondeMagique();
	~MondeMagique();

	list<T*> obtenirListeMaitre() const;
	list<S*> obtenirListeCompagnon() const;

	void ajouter(T* pointeurMaitre);
	void ajouter(S* pointeurCompagnon);

	void supprimer(T* pointeurMaitre);
	void supprimer(S* pointeurCompagnon);

	template <typename P>
	void supprimerMaitre(const P& prédicat);
	template <typename P>
	void supprimerCompagnon(const P& prédicat);

	void vider();

	void operator+=(T* pointeurMaitre);
	void operator-=(T* pointeurMaitre);

	void operator+=(S* pointeurCompagnon);
	void operator-=(S* pointeurCompagnon);


protected:

//Une list de pointeurs d’instances T listMaitre_ (utiliser le conteneur de la librairie STL).
	std::list<T*> listMaitre_;
//Une list de pointeurs d’instances S listCompagnon_ 
	std::list<S*> listCompagnon_;
};

#endif

//Un constructeur par défaut.
template <typename T, typename S>
MondeMagique<T, S>::MondeMagique()
{

}

//Un destructeur
template <typename T, typename S>
MondeMagique<T, S>::~MondeMagique()
{

}

//Des accesseurs pour chacun des conteneurs T et S du MondeMagique.
template <typename T, typename S>
list<T*> MondeMagique<T,S>::obtenirListeMaitre() const
{
	return listMaitre_;
}

template <typename T, typename S>
list<S*> MondeMagique<T, S>::obtenirListeCompagnon() const
{
	return listCompagnon_;
}

//Une méthode ajouter
template <typename T, typename S>
void MondeMagique<T, S>::ajouter(T* pointeurMaitre)
{
	listMaitre_.push_back(pointeurMaitre);
}
template <typename T, typename S>
void MondeMagique<T, S>::ajouter(S* pointeurCompagnon)
{
	listCompagnon_.push_back(pointeurCompagnon);
}

//Une méthode supprimer
template <typename T, typename S>
void MondeMagique<T, S>::supprimer(T* pointeurMaitre)
{
	std::list<T*>::iterator it = find(listMaitre_.begin(), listMaitre_.end(), pointeurMaitre);
	listMaitre_.erase(it);
}
template <typename T, typename S>
void MondeMagique<T, S>::supprimer(S* pointeurCompagnon)
{
	std::list<S*>::iterator it = find(listCompagnon_.begin(), listCompagnon_.end(), pointeurCompagnon);
	listCompagnon_.erase(it);
}

//Une méthode supprimerMaitre
template <typename T, typename S>
template <typename P>
void MondeMagique<T, S>::supprimerMaitre(const P& prédicat)
{
	remove_if(listMaitre_.begin(), listMaitre_.end(), prédicat);
}
template <typename T, typename S>
template <typename P>
void MondeMagique<T, S>::supprimerCompagnon(const P& prédicat)
{
	remove_if(listCompagnon_.begin(), listCompagnon_.end(), prédicat);
}

//Une méthode vider qui vide les deux listes d’un coup
template <typename T, typename S>
void MondeMagique<T, S>::vider()
{
	listMaitre_.clear();
	listCompagnon_.clear();
}

//Les surcharges des opérateurs += et -= pour chaque type T et S qui ajoutent ou retirent
//une instance donnée dans la liste correspondante
template <typename T, typename S>
void MondeMagique<T, S>::operator+=(T* pointeurMaitre)
{
	ajouter(pointeurMaitre);
}
template <typename T, typename S>
void MondeMagique<T, S>::operator-=(T* pointeurMaitre)
{
	supprimer(pointeurMaitre);
}

template <typename T, typename S>
void MondeMagique<T, S>::operator+=(S* pointeurCompagnon)
{
	ajouter(pointeurCompagnon);
}

template <typename T, typename S>
void MondeMagique<T, S>::operator-=(S* pointeurCompagnon)
{
	supprimer(pointeurCompagnon);
}













