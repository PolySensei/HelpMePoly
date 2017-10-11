#ifndef EXCEPTIONECHECEMPRUNT_H
#define EXCEPTIONECHECEMPRUNT_H

#include <stdexcept>
#include <string>

class ExceptionEchecEmprunt : public std::runtime_error
{
public:

    ExceptionEchecEmprunt(const std::string & descriptionErreur);

    static int obtenirValeurCompteur();

private:
    static int compteur_;
};
#endif // EXCEPTIONECHECEMPRUNT_H
