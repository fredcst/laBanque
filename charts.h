#ifndef CHARTS_H
#define CHARTS_H

#include <QWidget>
#include <QDateTime>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <iostream>
#include <vector>
#include <random>
#include "requete.h"
#include <QBoxLayout>

using std::vector;
using namespace std;

QT_CHARTS_USE_NAMESPACE


namespace Ui {
class charts;
}

/*

//Fonction Random
int ventes_50(){
    return rand()%51;
}


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
}*/


class charts : public QWidget
{
    Q_OBJECT

public:
    explicit charts(int, QWidget *parent = nullptr);
    ~charts();

private slots:

    void on_check_toutes_toggled(bool checked);

    //void on_check_toutes_stateChanged(int arg1);
    vector<int> whichCitiesAreChecked();
    void on_check_toutes_clicked(bool checked);


    void on_pushButton_clicked();

private:
    Ui::charts *ui;
};

#endif // CHARTS_H
