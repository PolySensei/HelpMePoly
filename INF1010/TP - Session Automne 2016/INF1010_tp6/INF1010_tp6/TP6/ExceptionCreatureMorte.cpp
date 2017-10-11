/****************************************************************************
* Fichier: ExceptionCreatureMorte.cpp
* Auteur: PolySensei and Associates
* Date: 23 novembre 2016
* Mise a jour : 10 décembre 2016
* Description: Implémentation de la classe ExceptionCreatureMorte
****************************************************************************/
#include "ExceptionCreatureMorte.h"
#include <string>
using namespace std;


int ExceptionCreatureMorte::compteur_ = 0; //Initialisation

//Un constructeur par paramètre recevant une chaîne de caractères (string) contenant le message
//de l’erreur. Le constructeur doit incrémenter la valeur du compteur.

ExceptionCreatureMorte::ExceptionCreatureMorte(const std::string & descriptionErreur): runtime_error(descriptionErreur)
{
	compteur_++;
}

//La méthode statique public obtenirValeurCompteur() qui retourne la valeur de compteur_.
int ExceptionCreatureMorte::obtenirValeurCompteur()
{ 
	return compteur_; 
}
