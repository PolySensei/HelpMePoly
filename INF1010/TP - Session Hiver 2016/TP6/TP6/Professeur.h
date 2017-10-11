#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include <vector>
#include <list>
#include "Abonne.h"
class Professeur :
	public Abonne
{
public:
	Professeur();
	Professeur(const std::string& matricule, const std::string& nom, const std::string& prenom, unsigned int age, std::vector<std::string> ecoles);
	~Professeur();

	std::list<std::string> obtenirEcole() const;
	void ajouterEcole(std::string const& ecole);
	bool retirerEcole(std::string const& ecole);
	virtual unsigned int obtenirLimiteEmprunt() const;
	
	friend std::ostream & operator<<(std::ostream & o, const Professeur & professeur);

private:
	std::list<std::string> listEcoles_;
};
#endif // !PROFESSEUR_H
