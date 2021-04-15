#include "charts.h"
#include "ui_charts.h"
#include <iostream>

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
                    vec.push_back(Requete(ville,canal,famille,produit,rand()%51));
                }
            }
        }
    }
    return vec;
}

int totalParFamilleEtVille(vector <Requete> rq, int ville, int produit_1, int produit_2){
    int total=0;
    for (int i = 0; i<(int)rq.size(); i++){
        if((rq[i].getProduit()==produit_1 || rq[i].getProduit()==produit_2) && rq[i].getVille()==ville)
            total+=rq[i].getTotal_ventes();
    }
     return total;
}

QChartView * chartGenerator_banc(int nb_villes){

    vector<Requete> rq;
    rq=creation_de_requetes();

    //![1]
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

    //![2]
        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);

    //![3]
        QChart *chart = new QChart();
        //afiche les barres
        chart->addSeries(series);
        chart->setTitle("Canal Bancaire");
        chart->setAnimationOptions(QChart::SeriesAnimations);


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

    //![5]
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

    //![6]
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}

QChartView * chartGenerator_assu(int nb_villes){

    vector<Requete> rq;
    rq=creation_de_requetes();

    //![1]
        QBarSet *set0 = new QBarSet("Assurances");
        //Famille notre action
        for (int i=1; i<5; i++){
            *set0 << totalParFamilleEtVille(rq,i,9,10);
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

    //![5]
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

    //![6]
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}

QChartView * chartGenerator_bours(int nb_villes){

    vector<Requete> rq;
    rq=creation_de_requetes();

    //![1]
        QBarSet *set0 = new QBarSet("Notre Action");
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

    //![5]
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

    //![6]
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}


charts::charts(int nb, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::charts)
{
    ui->setupUi(this);

//Volume selectionné par défaut
    ui->radioButton_volume->setChecked(1);

//Option d'utilisateur choisie dans le MainWindow
    switch (nb) {
    case 1:
        ui->check_paris->setChecked(1);
        break;
    case 2:
        ui->check_lyon->setChecked(1);
        break;
    case 3:
        ui->check_strasbourg->setChecked(1);
        break;
    case 4:
        ui->check_marseille->setChecked(1);
        break;
    default:
        ui->check_toutes->setChecked(1);
        charts::on_check_toutes_clicked(1);
        break;
    }

    ui->overviewLayout->addWidget(chartGenerator_banc(1));
    ui->overviewLayout->addWidget(chartGenerator_assu(1));
    ui->overviewLayout->addWidget(chartGenerator_bours(1));
}





charts::~charts()
{
    delete ui;
}

//interaction checkboxes villes
void charts::on_check_toutes_toggled(bool checked)
{
    if (checked){
        ui->check_marseille->setDisabled(1);
        ui->check_strasbourg->setDisabled(1);
        ui->check_lyon->setDisabled(1);
        ui->check_paris->setDisabled(1);
    }
}

//interaction checkboxes villes
void charts::on_check_toutes_clicked(bool checked)
{
    if (checked){
        ui->check_marseille->setChecked(1);
        ui->check_strasbourg->setChecked(1);
        ui->check_lyon->setChecked(1);
        ui->check_paris->setChecked(1);
        ui->check_marseille->setDisabled(1);
        ui->check_strasbourg->setDisabled(1);
        ui->check_lyon->setDisabled(1);
        ui->check_paris->setDisabled(1);
    }
    else{
        ui->check_marseille->setEnabled(1);
        ui->check_strasbourg->setEnabled(1);
        ui->check_lyon->setEnabled(1);
        ui->check_paris->setEnabled(1);
    }
}
