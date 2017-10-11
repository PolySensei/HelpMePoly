
#include "EtudiantBaccalaureat.h"

using namespace std;

EtudiantBaccalaureat::EtudiantBaccalaureat(const std::string& matricule, const std::string& nom, const std::string& prenom, unsigned int age)
	: Etudiant(matricule, nom, prenom, age, "Polytechnique Montreal")
{

}

unsigned int EtudiantBaccalaureat::obtenirLimiteEmprunt() const
{
	return (Etudiant::obtenirLimiteEmprunt()) * 2;
}

