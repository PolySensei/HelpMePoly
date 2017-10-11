/****************************************************************************
* Fichier: ExceptionAttaqueEchouee.h
* Auteur: PolySensei and Associates
* Date: 23 novembre 2016
* Mise a jour : 10 décembre 2016
* Description: Définition de la classe ExceptionAttaqueEchouee
****************************************************************************/
#ifndef EXCEPTIONATTAQUEECHOUE_H
#define EXCEPTIONATTAQUEECHOUE_H

#include <stdexcept>
#include <string>

class ExceptionAttaqueEchouee : public std::runtime_error
{
public:
	ExceptionAttaqueEchouee::ExceptionAttaqueEchouee(const std::string & descriptionErreur)
		: runtime_error(descriptionErreur) {}

};

#endif // EXCEPTIONATTAQUEECHOUE_H
