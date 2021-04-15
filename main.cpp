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

int totalParFamilleEtVille(vector <Requete> rq, int ville, int produit_1, int produit_2){
    int total=0;
    for (int i = 0; i<(int)rq.size(); i++){
        if((rq[i].getProduit()==produit_1 || rq[i].getProduit()==produit_2) && rq[i].getVille()==ville)
            total+=rq[i].getTotal_ventes();
    }
     return total;
}


void CB1_toutes(int argc, char *argv[]){
    vector<Requete> rq;
    rq=creation_de_requetes();
    //affichage(rq);

    QApplication a(argc, argv);

//![1]
    //légende
    QBarSet *set0 = new QBarSet("Prêts");
    QBarSet *set1 = new QBarSet("Comptes");
    QBarSet *set2 = new QBarSet("Chèques");
    QBarSet *set3 = new QBarSet("Cartes");

    //valeurs random FAMILLES
    // paris << lyon << strasbourg << marseille

    //Famille prets
    for (int i=1; i<5; i++){
        *set0 << totalParFamilleEtVille(rq,i,1,2);
    }
    //Famille comptes
    for (int i=1; i<5; i++){
        *set1 << totalParFamilleEtVille(rq,i,3,4);
    }
    //Famille cheques
    for (int i=1; i<5; i++){
        *set2 << totalParFamilleEtVille(rq,i,5,6);
    }
    //Famille cartes
    for (int i=1; i<5; i++){
        *set3 << totalParFamilleEtVille(rq,i,7,8);
    }


//![1]

//![2]
//! chaque append affiche les familles dans les 4 graphes
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);

//![2]

//![3]
    QChart *chart = new QChart();
    //afiche les barres
    chart->addSeries(series);
    chart->setTitle("Canal Bancaire");
    chart->setAnimationOptions(QChart::SeriesAnimations);
//![3]

//![4]
    QStringList categories;
    categories << "Paris" << "Lyon" << "Strasbourg" << "Marseille";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,100);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
//![4]

//![5]
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
//![5]

//![6]
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
//![6]

//![7]
    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(420, 300);
    window.show();
//![7]

    return a.exec();
}


void CA_toutes(int argc, char *argv[]){
    vector<Requete> rq;
    rq=creation_de_requetes();
    //affichage(rq);

    QApplication a(argc, argv);

//![1]
    //légende
    QBarSet *set0 = new QBarSet("Total Assurances");

    //valeurs random FAMILLES
    // paris << lyon << strasbourg << marseille


    //Famille assurance
    for (int i=1; i<5; i++){
        *set0 << totalParFamilleEtVille(rq,i,9,10);
    }


//![1]

//![2]
//! chaque append affiche les familles dans les 4 graphes
    QBarSeries *series = new QBarSeries();
    series->append(set0);

//![2]

//![3]
    QChart *chart = new QChart();
    //afiche les barres
    chart->addSeries(series);
    chart->setTitle("Canal Assurance");
    chart->setAnimationOptions(QChart::SeriesAnimations);
//![3]

//![4]
    QStringList categories;
    categories << "Paris" << "Lyon" << "Strasbourg" << "Marseille";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,100);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
//![4]

//![5]
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
//![5]

//![6]
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
//![6]

//![7]
    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(420, 300);
    window.show();
//![7]

    return a.exec();
}

void CB_toutes(){

    vector<Requete> rq;
    rq=creation_de_requetes();


//![1]
    QBarSet *set0 = new QBarSet("Total Assurances");

    //Famille notre action
    for (int i=1; i<5; i++){
        *set0 << totalParFamilleEtVille(rq,i,11,0);
    }


//![2]
    QBarSeries *series = new QBarSeries();
    series->append(set0);


//![3]
    QChart *chart = new QChart();
    //afiche les barres
    chart->addSeries(series);
    chart->setTitle("Canal Assurance");
    chart->setAnimationOptions(QChart::SeriesAnimations);
//![3]

//![4]
    QStringList categories;
    categories << "Paris" << "Lyon" << "Strasbourg" << "Marseille";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,100);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
//![4]

//![5]
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
//![5]

//![6]
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
//![6]


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
