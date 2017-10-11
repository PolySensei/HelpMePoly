/****************************************************************************
* Fichier: ExceptionEchecCapture.h
* Auteur: PolySensei and Associates
* Date: 23 novembre 2016
* Mise a jour : 10 décembre 2016
* Description: Définition de la classe ExceptionEchecCapture
****************************************************************************/
#ifndef EXCEPTIONECHECCAPTURE_H
#define EXCEPTIONECHECCAPTURE_H

#include <stdexcept>
#include <string>

class ExceptionEchecCapture : public std::runtime_error
{
public:
	ExceptionEchecCapture::ExceptionEchecCapture(const std::string & descriptionErreur)
		: runtime_error(descriptionErreur) {}

};

#endif // EXCEPTIONECHECCAPTURE_H
