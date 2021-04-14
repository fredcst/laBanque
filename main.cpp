#include "mainwindow.h"
#include "requete.h"
#include <iostream>
#include <QApplication>
#include <vector>

using std::vector;
using namespace std;


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

vector<Requete> creation_de_requetes(){
    vector<Requete> vec;
    for (int ville=1; ville<5; ville++){
        for (int canal=1; canal<4; canal++){
            for(int famille=1; famille<7; famille++){
                for (int produit=1; produit<12; produit++){
                    if(
                            !(
                            ((produit==1 || produit==2) && famille==1 && canal==1) ||
                            ((produit==3 || produit==4) && famille==2 && canal==1) ||
                            ((produit==5 || produit==6) && famille==3 && canal==1) ||
                            ((produit==7 || produit==8) && famille==4 && canal==1) ||
                            ((produit==9 || produit==10) && famille==5 && canal==2)||
                            (produit==11 && famille==6 && canal==3)
                              )
                       ) continue;
                    vec.push_back(Requete(ville,canal,famille,produit,ventes_50()));
                }
            }
        }
    }
    return vec;
}

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

int main(int argc, char *argv[])
{
    vector<Requete> rq;
    rq=creation_de_requetes();
    affichage(rq);

    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //return a.exec();
}
