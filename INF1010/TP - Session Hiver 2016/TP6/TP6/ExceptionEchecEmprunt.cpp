/****************************************************************************
* Fichier: ExceptionEchecEmprunt.cpp
* Auteur: PolySensei & Associates
* Date: 2 avril 2016
* Mise a jour : 11 avril 2016
* Description: Implémentation de la classe ExceptionEchecEmprunt
****************************************************************************/
#include "ExceptionEchecEmprunt.h"
#include <string>
using namespace std;


int ExceptionEchecEmprunt::compteur_ = 0; //Initialisation

ExceptionEchecEmprunt::ExceptionEchecEmprunt(const std::string & descriptionErreur)
    : runtime_error(descriptionErreur){compteur_++;}


int ExceptionEchecEmprunt::obtenirValeurCompteur(){return compteur_;}

