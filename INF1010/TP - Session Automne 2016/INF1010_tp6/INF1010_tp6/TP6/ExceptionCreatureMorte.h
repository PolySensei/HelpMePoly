/****************************************************************************
* Fichier: ExceptionCreatureMorte.h
* Auteur: PolySensei and Associates
* Date: 23 novembre 2016
* Mise a jour : 10 d�cembre 2016
* Description: D�finition de la classe ExceptionCreatureMorte
****************************************************************************/
#ifndef EXCEPTIONCREATUREMORTE_H
#define EXCEPTIONCREATUREMORTE_H

#include <stdexcept>
#include <string>

class ExceptionCreatureMorte : public std::runtime_error
{
public:
    ExceptionCreatureMorte::ExceptionCreatureMorte(const std::string & descriptionErreur);
    static int obtenirValeurCompteur();

private:

    //compteur_ : un entier (int) statique privé permettant de compter le nombre de fois que
    //l’exception ExceptioCreatureMorte est lancée.
	static int compteur_;
};

#endif // EXCEPTIONCREATUREMORTE_H

