/****************************************************************************
* Fichier: LivreNumerique.cpp
* Auteur: PolySensei & Associates
* Date: 22 février 2016
* Mise a jour : 3 mars 2016
* Description: Implémentation de la classe LivreNumerique
****************************************************************************/
#include "LivreNumerique.h"

#include "LivreNumerique.h"
using namespace std;


// Un constructeur par défaut.
LivreNumerique::LivreNumerique()
{

}

// Un constructeur par paramètre pour tous les attributs de cette classe et de ses 2 classes mères.
LivreNumerique::LivreNumerique(FORMAT_DOCUMENT format, unsigned int tailleOctet, const std::string& lien, const std::string& cote, const std::string& titre, unsigned int annee, unsigned int ageMin, unsigned int nbExemplaires, const std::string& auteur, const std::string& genre)
	: Livre(cote, titre, annee, ageMin, nbExemplaires, auteur, genre), format_(format), tailleOctet_(tailleOctet), lien_(lien)
{

}

// Un destructeur.
LivreNumerique::~LivreNumerique()
{

}

// Des méthodes d’accès et de modification aux attributs.  Les autres méthodes d’accès et de modification aux attributs sont hérité via la classe Livre.
unsigned int LivreNumerique::obtenirTaille() const
{
	return tailleOctet_;
}

std::string LivreNumerique::obtenirLienInternet() const
{
	return lien_;
}

FORMAT_DOCUMENT LivreNumerique::obtenirFormat() const
{
	return format_;
}

void LivreNumerique::modifierTaille(unsigned int taille)
{
	tailleOctet_ = taille;
}

void LivreNumerique::modifierLien(const std::string& lien)
{
	lien_ = lien;
}

void LivreNumerique::modifierFormat(const FORMAT_DOCUMENT& format)
{
	format_ = format;
}



// Une méthode obtenirFormatStr() qui permet de retourner un string associé au format du document.Par exemple, si le format est FORMAT_PDF, alors la valeur retournée sera « pdf ».
std::string LivreNumerique::obtenirFormatStr() const
{
	string typeDeFormat = "";

	switch (format_)
	{
	case FORMAT_PDF:
		typeDeFormat = "pdf";
		break;
	case FORMAT_EPUB:
		typeDeFormat = "epub";
		break;
	case FORMAT_DOCX:
		typeDeFormat = "docx";
		break;
	case FORMAT_TXT:
		typeDeFormat = "txt";
		break;
	case FORMAT_INCONNU:
		typeDeFormat = "inconnu";
		break;
	default:
		break;
	}

	return typeDeFormat;
}


// Une redéfinition de la méthode Livre::recherche() pour que la méthode recherche aussi si le mot-clé est identique au format du livre.
bool LivreNumerique::recherche(const std::string& motsCle) const
{
	std::size_t trouveFormat = convertirMinuscule(obtenirFormatStr()).find(convertirMinuscule(motsCle));

	//Utilisation du demasquage pour appeler la méthode de la classe mère
	bool trouve = Livre::recherche(motsCle)
		|| (trouveFormat != string::npos);

	return trouve;
}




//Un opérateur << qui affiche que c’est un objet numérique, affiche la taille du document, puis affiche le lien internet.Ensuite, il appelle l’opérateur << de la classe Livre; tel que présenté dans l’exemple à la fin du document.
std::ostream& operator<<(std::ostream& o, const LivreNumerique& livreNumerique)
{
	o << "Objet Numerique!  Taille : " << livreNumerique.tailleOctet_ << "oct.  "
		<< livreNumerique.lien_
		<< "  Format : " << livreNumerique.obtenirFormatStr() << endl
		<< (Livre)livreNumerique;
	return o;
}