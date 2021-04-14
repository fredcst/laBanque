#include "mainwindow.h"
#include "requete.h"
#include <iostream>
#include <QApplication>


//Fonction Random
int ventes_50(){
    return rand()%51;
}

/*
 * Villes:
 * * 1. Paris
 * * 2. Lyon
 * * 3. Strasbourg
 * * 4. Marseille
 *
 * Canaux:
 * * 1. Canal Bancaire
 * * 2. Canal Assurance
 * * 3. Canal Boursier
 *
 * Familles:
 * * 1. Prêts
 * * 2. Comptes
 * * 3. Cheques
 * * 4. Cartes
 *
 * Produits:
 * * 1. Habitation
 * * 2. Auto
 * * 3. Courant
 * * 4. Epargne
 * * 5. Vert
 * * 6. Bleu
 * * 7. Debit
 * * 8. Credit
 * * 9. Velo
 * * 10. Assurance
 * * 11. Notre action
 */


int main(int argc, char *argv[])
{
    Requete (1,1,1,1,1,1);

    std::cout << "";
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
