/****************************************************************************
* Fichier: ExceptionEchecRetour.h
* Auteur: PolySensei & Associates
* Date: 2 avril 2016
* Mise a jour : 10 avril 2016
* Description: Définition de la classe ExceptionEchecRetour
****************************************************************************/
#ifndef EXCEPTIONECHECRETOUR_H
#define EXCEPTIONECHECRETOUR_H

#include <stdexcept>
#include <string>

class ExceptionEchecRetour : public std::runtime_error
{
public:
    ExceptionEchecRetour::ExceptionEchecRetour(const std::string & descriptionErreur)
        : runtime_error(descriptionErreur){}

};

#endif // EXCEPTIONECHECRETOUR_H
