/****************************************************************************
* Fichier: LivreNumerique.cpp
* Auteur: PolySensei & Associates
* Date: 6 mars 2016
* Mise a jour : 28 mars 2016
* Description: Implémentation de la classe LivreNumerique
****************************************************************************/
#include "LivreNumerique.h"


using namespace std;


LivreNumerique::LivreNumerique() : 
	format_(FORMAT_INCONNU),tailleOctet_(0), lien_(""), Livre()
{
}

LivreNumerique::LivreNumerique(
	FORMAT_DOCUMENT format, unsigned int tailleOctet, string lien,
	const string & cote, const string & titre, unsigned int annee,
	unsigned int ageMin, unsigned int nbExemplaires,
	const string & auteur, const string & genre) :
	format_(format),
	lien_(lien), tailleOctet_(tailleOctet),
	Livre(cote, titre, annee, ageMin, nbExemplaires, auteur, genre)
{

}


LivreNumerique::~LivreNumerique()
{
}

FORMAT_DOCUMENT LivreNumerique::obtenirFormat() const
{
	return format_;
}

void LivreNumerique::modifierFormat(FORMAT_DOCUMENT format)
{
	format_ = format;
}

std::string LivreNumerique::obtenirFormatStr() const
{
	string formatStr = "";
	switch (format_)
	{
	case FORMAT_PDF:
		formatStr = "pdf";
		break;
	case FORMAT_EPUB:
		formatStr = "epub";
		break;
	case FORMAT_DOCX:
		formatStr = "docx";
		break;
	case FORMAT_TXT:
		formatStr = "txt";
		break;
	case FORMAT_INCONNU:
		formatStr = "inconnu";
		break;
	default:
		formatStr = "inconnu";
		break;
	}

	return formatStr;
}


bool LivreNumerique::recherche(const std::string & motsCle) const
{
	size_t trouveAuteur = convertirMinuscule(auteur_).find(convertirMinuscule(motsCle));
	size_t trouveGenre = convertirMinuscule(genre_).find(convertirMinuscule(motsCle));
	size_t trouveFormat = convertirMinuscule(obtenirFormatStr()).find(convertirMinuscule(motsCle));

	//Utilisation du demasquage pour appeler la méthode de la classe mère
	bool trouve = ObjetEmpruntable::recherche(motsCle)
		|| (trouveAuteur != string::npos)
		|| (trouveGenre != string::npos)
		|| (trouveFormat != string::npos);

	return trouve;
}


std::ostream & operator<<(std::ostream & o, const LivreNumerique & objet)
{
	const Livre* liv = &objet;

	o << "Objet Numerique!  Taille : " <<
		objet.tailleOctet_ << " oct.  " <<
		objet.lien_ << "  Format : " 
		<< objet.obtenirFormatStr() << endl;

	o << *liv;
	return o;


}


void LivreNumerique::modifierTaille(unsigned int tailleOctet)
{
	tailleOctet_ = tailleOctet;
}

unsigned int LivreNumerique::obtenirTaille() const
{
	return tailleOctet_;
}

void LivreNumerique::modifierLien(std::string lien)
{
	lien_ = lien;
}

std::string LivreNumerique::obtenirLien() const
{
	return lien_;
}





