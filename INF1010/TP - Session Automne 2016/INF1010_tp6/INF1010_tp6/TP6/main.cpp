/****************************************************************************
* Fichier: main.cpp
* Auteur: PolySensei and Associates
* Date: 23 novembre 2016
* Mise a jour : 10 décembre 2016
* Description: Main
****************************************************************************/

#include "Gamebay.h"
#include <QApplication>
#include <time.h>
#include <clocale>  // pour setlocale

int main(int argc, char *argv[])
{
    srand(time(NULL));
    setlocale(LC_ALL, "");
    // Dresseurs
    Dresseur vous("Vous", "PolyMtl");
    Dresseur sacha("Sacha", "UDEM");
    //Creatures
    Creature pokachu("Pokachu", 10, 20, 100, 50);
    Creature salimouche("Salimouche", 20, 15, 110, 50);
    Creature Carapouce("Carapouce", 10, 1, 55, 25);
    Creature Balbazar("Balbazar", 11, 2, 50, 22);

    //Pouvoirs
    Pouvoir bouleDeFeu("Boule de feu", 5, 5);
    Pouvoir eclair("Eclair", 10, 5);
    Pouvoir tonerre("Tonnerre", 15, 10);
    Pouvoir pistoletAEau("Pistolet a eau", 6, 6);
    Pouvoir lanceFeuille("Lance feuille", 5, 5);

    salimouche.apprendrePouvoir(&bouleDeFeu);
    pokachu.apprendrePouvoir(&tonerre);
    pokachu.apprendrePouvoir(&eclair);
    Carapouce.apprendrePouvoir(&pistoletAEau);
    Balbazar.apprendrePouvoir(&lanceFeuille);


    PolyLand polyland(vous);

    polyland += &vous;
    polyland += &sacha;
    polyland += &pokachu;
    polyland += &salimouche;
    polyland += &Carapouce;
    polyland += &Balbazar;
    // En vous promenant dans Polyland, vous attrappez un pokachu et Sacha attrappe un salimouche
    vous.ajouterCreature(&pokachu);
    sacha.ajouterCreature(&salimouche);
    sacha.ajouterCreature(&pokachu);
    vous.ajouterCreature(&salimouche);


    QApplication a(argc, argv);
    Gamebay w(&polyland);
    w.show();

    return a.exec();
}
