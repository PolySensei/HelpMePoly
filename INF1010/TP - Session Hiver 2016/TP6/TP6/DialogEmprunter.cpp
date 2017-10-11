#include "DialogEmprunter.h"

#include <QDialogButtonBox>
#include <QLabel>
#include <QListWidgetItem>
#include <QVBoxLayout>
#include <QVariant>


Q_DECLARE_METATYPE(ObjetEmpruntable*)


DialogEmprunter::DialogEmprunter(std::list<ObjetEmpruntable *> objets, QWidget *parent) : QDialog(parent)
{
    setUI();

    // remplit la liste d'objets empruntables
    for (auto it = objets.begin(); it != objets.end(); it++) {
        QString s = ((*it)->obtenirTitre() + " (").c_str() + QString::number((*it)->obtenirNbDisponibles()) + QString(")");
        QListWidgetItem* item = new QListWidgetItem(s, listeObjets_);
        item->setData(Qt::UserRole, QVariant::fromValue<ObjetEmpruntable*>(*it));
    }

    // Connexions entre les signaux et les slots
    connect(listeObjets_, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(activerBoutonEmprunter()));
    connect(boutons_, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(boutons_, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

void DialogEmprunter::setUI()
{
    listeObjets_ = new QListWidget(this);
    listeObjets_->setSortingEnabled(true);

    QVBoxLayout* dialogLayout = new QVBoxLayout(this);
    dialogLayout->addWidget(new QLabel("Titre (disponibilité)"));
    dialogLayout->addWidget(listeObjets_);

    boutons_ = new QDialogButtonBox(this);
    boutons_->addButton("Annuler",QDialogButtonBox::RejectRole);
    boutonEmprunter_ = boutons_->addButton("Emprunter",QDialogButtonBox::AcceptRole);
    boutonEmprunter_->setEnabled(false);

    dialogLayout->addWidget(boutons_);
    this->setLayout(dialogLayout);

    setWindowTitle("Effectuer un emprunt");
}

// Fonction appelee lorsqu'un objet est selectionne dans la liste pour
// activer le bouton Emprunter
void DialogEmprunter::activerBoutonEmprunter()
{
    boutonEmprunter_->setEnabled(true);
}

// Fonction qui recupere et retourne le pointeur de l'objet selectionne
ObjetEmpruntable* DialogEmprunter::obtenirObjetSelectionne() const
{
    QList<QListWidgetItem*> selection = listeObjets_->selectedItems();
    QListWidgetItem* item = selection.back();
    return item->data(Qt::UserRole).value<ObjetEmpruntable*>();
}

