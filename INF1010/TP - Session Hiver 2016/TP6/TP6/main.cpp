#include "MainWindow.h"
#include <QApplication>


#include <vector>
#include <iostream>
#include <stdexcept>
#include "Bibliotheque.h"
#include "Abonne.h"
#include "EtudiantBaccalaureat.h"
#include "LivreNumerique.h"
#include "Professeur.h"
#include <typeinfo>

int main(int argc, char *argv[])
{
    // Creation des abonnes, des etudiants et des professeurs
    Abonne john("1839456", "Doe", "John", 23);
    Abonne nicolas("1630236", "Gagnon", "Nicolas", 8);
    Abonne martin("1269348", "Tremblay", "Martin", 18);
    Etudiant harry("1782965", "Potter", "Harry", 21, "Pourdlard");
    Etudiant hermione("1876458", "Granger", "Hermione", 20, "Pourdlard");
    EtudiantBaccalaureat tony("1865487", "Stark", "Tony", 42);
    Professeur albus("p878546", "Dumbledore", "Albus", 78, { "Polytechnique", "UdM", "Poudlard" });

    // Création des livres et DVD
    Livre livre1("BD302", "Harry Potter et le prisionier d'Azkaban", 1999, 3, 17, "JK ROWLING", "Science-Fiction");
    Livre livre2("QA204", "Calcul a plusieurs variables partie 2", 2011, 3, 1, "Cay HORTSTMANN", "Informatique");
    Livre livre3("GA403", "Big C++", 2009, 8, 2, "Cay HORTSTMANN", "Informatique");
    Livre livre4("AC409", "Le chateau d'Ortrante", 1764, 16, 2, "Cay HORTSTMANN", "Informatique");
    Livre livre5("QA203", "Calcul a plusieurs variables partie 1", 2011, 3, 1, "Cay HORTSTMANN", "Informatique");
    Livre livre6("GA404", "Big C++", 2016, 8, 2, "Cay HORTSTMANN", "Informatique");

    Dvd dvd1("D8403", "Rush Hour", 1998, 2, 13, "Al", { "Jackie Chan", "Chris Tucker" });
    Dvd dvd2("D7203", "Avenger", 2012, 3, 5, "Nick Fury", { "Iron Man", "Thor","Hulk", "Captain America", "Black Window" });

    // Creation de la bibliotheque, et ajout des elements
    Bibliotheque biblio;

    //Ajout des Abonnes
    biblio += &john;	biblio += &nicolas;	biblio += &martin;
    biblio += &harry;	biblio += &tony;	biblio += &hermione;
    biblio += &albus;

    // Ajout des livres et DVD
    biblio += &livre1;	biblio += &livre2;	biblio += &livre3;
    biblio += &livre4;	biblio += &livre5;	biblio += &livre6;
    biblio += &dvd1;	biblio += &dvd2;

    // Creation des objets numeriques et ajout à la bibliotheque
    LivreNumerique livNum1(FORMAT_EPUB, 1270, "vvv.3Mousquetaire.com", "NUM392",
                           "Les 3 mousquetaires", 1844, 11, 5, "A. Dumas", "Roman");
    LivreNumerique livNum2(FORMAT_EPUB, 1270, "vvv.3Mousquetaire.com", "NUM393",
                           "Les 3 mousquetaires 2", 1846, 11, 5, "A. Dumas", "Roman");
    biblio += &livNum1;
    biblio += &livNum2;

    // Création du vecteur pour effectuer les emprunts
    vector<pair<string,string> > vecEmp {make_pair("1630236","BD302"), make_pair("1630236","D7203"),
                                         make_pair("1782965","AC409"), make_pair("1782965","BD302"),
                                         make_pair("1782965","D7203"), make_pair("1782965","QA203"),
                                         make_pair("1865487","AC409"), make_pair("1865487","BD302"),
                                         make_pair("1865487","D7203"), make_pair("1865487","QA204"),
                                         make_pair("1865487","NUM392"), make_pair("p878546","BD302"),
                                         make_pair("p878546","D7203"), make_pair("p878546","NUM392")};
	// Effectue les emprunts
    for (size_t i = 0; i < vecEmp.size(); i++) {
        try {
            biblio.emprunter(vecEmp[i].first, vecEmp[i].second, 160204);
        } catch (exception&) {}
    }


    QApplication a(argc, argv);
    MainWindow w(&biblio);
    w.show();

    return a.exec();
}
