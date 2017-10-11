#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <QTableView>
#include <QStandardItemModel>
#include <QPushButton>

#include "Bibliotheque.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Bibliotheque * biblio, QWidget *parent = 0);
    ~MainWindow();

private:
    Bibliotheque * biblio_;

    QListWidget* listeAbonnes_;
    QTableView* tabEmprunts_;
    QStandardItemModel* model_;

    QPushButton* boutonAjoutEmprunt_;
    QPushButton* boutonRetourner_;

    void setUI();
    void setConnections();
    void chargerAbonnes();
    QListWidgetItem* obtenirAbonneSelectionne();


signals:
    void empruntAjoute(QListWidgetItem* item);


private slots:
    void afficherEmpruntsAbonne(QListWidgetItem* item);
    void ajouterEmprunt();
    void retirerEmprunt();


};

#endif // MAINWINDOW_H
