#include "mainwindow.h"
#include "requete.h"
#include <iostream>
#include <QApplication>
#include <vector>
#include <random>

using std::vector;
using namespace std;

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
 * * 5. Assurances
 * * 6. Action
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
 * * 10. Ordi
 * * 11. Notre action
*/

/*
void affichage(vector<Requete> rq){
    for (int i = 0; i<(int)rq.size(); i++){

        cout << "Ville: ";
        cout << rq[i].getVille() << endl;
        cout << "Canal: ";
        cout << rq[i].getCanal() << endl;
        cout << "Produit: ";
        cout << rq[i].getProduit() << endl;
        cout << "Total Ventes: ";
        cout << rq[i].getTotal_ventes() << endl;
        cout << "--\n";
    }
}
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //CB1_toutes(argc,argv);
    //CA_toutes(argc,argv);

    //CB_toutes();
    MainWindow w;

    w.show();
    return a.exec();
}
