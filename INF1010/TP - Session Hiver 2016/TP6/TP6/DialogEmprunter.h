#ifndef DIALOGEMPRUNTER_H
#define DIALOGEMPRUNTER_H

#include <QDialog>
#include <QListWidget>
#include <QPushButton>
#include <QDialogButtonBox>
#include <list>
#include "ObjetEmpruntable.h"

class DialogEmprunter : public QDialog
{
    Q_OBJECT
public:
    explicit DialogEmprunter(std::list<ObjetEmpruntable*> objets, QWidget *parent = 0);

    ObjetEmpruntable* obtenirObjetSelectionne() const;

private:
    QListWidget* listeObjets_;
    QPushButton* boutonEmprunter_;
    QDialogButtonBox* boutons_;

    void setUI();

public slots:
    void activerBoutonEmprunter();

};

#endif // DIALOGEMPRUNTER_H
