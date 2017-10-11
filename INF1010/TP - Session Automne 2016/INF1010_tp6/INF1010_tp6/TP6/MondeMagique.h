#ifndef MONDE_MAGIQUE_H
#define MONDE_MAGIQUE_H

#include <list>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

template<typename T, typename S> //T = maitre, S = compagnon
class MondeMagique
{
public:
	MondeMagique();
	~MondeMagique();

	list<T*> obtenirListMaitre() const;
	list<S*> obtenirListCompagnon() const;

	void ajouter(T* t);
	void ajouter(S* s);

	//T* obtenirPlusPetitElementMaitre() const;
	//S* obtenirPlusPetitElementCompagnon() const;

	//T* obtenirPlusGrandElementMaitre() const;
	//S* obtenirPlusGrandElementCompagnon() const;

	bool supprimer(const T* t);
	bool supprimer(const S* s);

	template<typename Predicate>
	bool supprimerCompagnon(const Predicate& predicate);

	template<typename Predicate>
	bool supprimerMaitre(const Predicate& predicate);

	void vider();

	MondeMagique& operator+=(T* t) {
		ajouter(t);
		return *this;
	}

	MondeMagique& operator+=(S* s) {
		ajouter(s);
		return *this;
	}

	MondeMagique& operator-=(T* t) {
		supprimer(t);
		return *this;
	}

	MondeMagique& operator-=(S* s) {
		supprimer(s);
		return *this;
	}

protected:
	list<T*> listMaitre_;
	list<S*> listCompagnon_;
};


template<typename T, typename S>
MondeMagique<T, S>::MondeMagique() 
{}


template<typename T, typename S>
MondeMagique<T, S>::~MondeMagique()
{}


template<typename T, typename S>
list<T*> MondeMagique<T, S>::obtenirListMaitre() const 
{
	return listMaitre_;
}

template<typename T, typename S>
list<S*> MondeMagique<T, S>::obtenirListCompagnon() const
{
	return listCompagnon_;
}

template<typename T, typename S>
void MondeMagique<T, S>::ajouter(T* t) 
{
	listMaitre_.push_back(t);
}

template<typename T, typename S>
void MondeMagique<T, S>::ajouter(S* s)
{
	listCompagnon_.push_back(s);
}

//template<typename T, typename S>
//T* MondeMagique<T, S>::obtenirPlusPetitElementMaitre() const 
//{
//	auto minListeMaitre = [](const T* a1, const T* a2) 
//	{
//		return a1 > a2;
//	};
//	return (*min_element(listMaitre_.begin(), listMaitre_.end(), minListeMaitre));
//}

//template<typename T, typename S>
//S* MondeMagique<T, S>::obtenirPlusPetitElementCompagnon() const 
//{
//	auto minListeCompagnon = [](const S* a1, const S* a2)
//	{
//		return a1 > a2;
//	};
//	return (*min_element(listCompagnon_.begin(), listCompagnon_.end(), minListeCompagnon));
//}

//template<typename T, typename S>
//T* MondeMagique<T, S>::obtenirPlusGrandElementMaitre() const 
//{
//	auto maxListeMaitre = [](const T* a1, const T* a2)
//	{
//		return a1 > a2;
//	};
//	return (*min_element(listMaitre_.begin(), listMaitre_.end(), maxListeMaitre));
//}

//template<typename T, typename S>
//S* MondeMagique<T, S>::obtenirPlusGrandElementCompagnon() const 
//{
//	auto maxListeCompagnon = [](const S* a1, const S* a2)
//	{
//		return a1 > a2;
//	};
//	return (*min_element(listCompagnon_.begin(), listCompagnon_.end(), maxListeCompagnon));
//}


template<typename T, typename S>
void MondeMagique<T, S>::vider() 
{
	listMaitre_.clear();
	listCompagnon_.clear();
}


template<typename T, typename S>
bool MondeMagique<T, S>::supprimer(const T* t) 
{
	list<T*>::iterator pos = find(listMaitre_.begin(), listMaitre_.end(), t);
	if (pos != listMaitre_.end()) 
	{
		listMaitre_.erase(pos);
		return true;
	}
	else 
	{
		return false;
	}
}

template<typename T, typename S>
bool MondeMagique<T, S>::supprimer(const S* s)
{
	list<S*>::iterator pos = find(listCompagnon_.begin(), listCompagnon_.end(), s);
	if (pos != listCompagnon_.end())
	{
		listCompagnon_.erase(pos);
		return true;
	}
	else 
	{
		return false;
	}
}


template<typename T, typename S>
template<typename Predicate>
bool MondeMagique<T, S>::supprimerMaitre(const Predicate& predicate) {
	size_t tailleAvant = listMaitre_.size();
	listMaitre_.remove_if(predicate);
	if (tailleAvant != listMaitre_.size()) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T, typename S>
template<typename Predicate>
bool MondeMagique<T, S>::supprimerCompagnon(const Predicate& predicate) {
	size_t tailleAvant = listCompagnon_.size();
	list<S*>::iterator pos = find_if(listCompagnon_.begin(), listCompagnon_.end(), predicate);
	listCompagnon_.remove_if(predicate);
	if (tailleAvant != listCompagnon_.size()) {
		return true;
	}
	else {
		return false;
	}
}

//template<typename T, typename S>
//MondeMagique& MondeMagique<T, S>::operator+=(T* t) 
//{
//	ajouter(t);
//	return *this;
//}
//
//template<typename T, typename S>
//MondeMagique& MondeMagique<T, S>::operator+=(S* s)
//{
//	ajouter(s);
//	return *this;
//}
//
//template<typename T, typename S>
//MondeMagique& MondeMagique<T, S>::operator-=(T* t)
//{
//	supprimer(t);
//	return *this;
//}
//
//template<typename T, typename S>
//MondeMagique& MondeMagique<T, S>::operator-=(S* s)
//{
//	supprimer(s);
//	return *this;
//}

#endif
