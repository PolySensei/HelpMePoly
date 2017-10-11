#ifndef ETUDIANT_H
#define ETUDIANT_H
#include "Abonne.h"

class Etudiant :
	public Abonne
{
public:
	Etudiant();
	Etudiant(const std::string& matricule, const std::string& nom, const std::string& prenom, unsigned int age, const std::string& ecole);
	~Etudiant();

	std::string obtenirEcole() const;
	void modifierEcole(const std::string& ecole);
	virtual unsigned int obtenirLimiteEmprunt() const;

	friend std::ostream & operator<<(std::ostream & o, const Etudiant & etudiant);

private :
	std::string ecole_;
};

#endif