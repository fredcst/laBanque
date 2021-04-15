#include "charts.h"
#include "ui_charts.h"
#include <iostream>
#include <string>
#include <QString>

vector<Requete> creation_de_requetes(){
    vector<Requete> vec;
    for (int ville=1; ville<5; ville++){
        for (int canal=1; canal<4; canal++){
            for (int famille=1; famille<7; famille++){
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

vector<int> charts::whichCitiesAreChecked(){
    vector<int> villes;
    if (ui->check_paris->isChecked())
        villes.push_back(1);
    if (ui->check_lyon->isChecked())
        villes.push_back(2);
    if (ui->check_strasbourg->isChecked())
        villes.push_back(3);
    if (ui->check_marseille->isChecked())
        villes.push_back(4);
    /*
    for (int i = 0; i < (int)villes.size(); i++){
        cout << villes[i] << endl;
    }
    */
    return villes;
}

// ////////////OVERVIEW///////////////

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

// ////////////CANAUX///////////////

int totaldeProduitsparVille(vector <Requete> rq, int ville, int produit){
    int total=0;
    for (int i = 0; i<(int)rq.size(); i++){
        if((rq[i].getProduit()==produit && rq[i].getVille()==ville))
            total+=rq[i].getTotal_ventes();
    }
     return total;
}


QChartView * chartGenerator_2prod_famille(QString prod1, int id_prod1, QString prod2, int id_prod2, QString nom_famille, vector<int> villes){

    vector<Requete> rq;
    rq=creation_de_requetes();

    //![1]
        QBarSet *set0 = new QBarSet(prod1);
        QBarSet *set1 = new QBarSet(prod2);

        //Famille prets¡
        for (int i=1; i <= (int)villes.size(); i++){
            *set0 << totaldeProduitsparVille(rq,i,id_prod1);
        }
        for (int i=1; i <= (int)villes.size(); i++){
            *set1 << totaldeProduitsparVille(rq,i,id_prod2);
        }

    //![2]
        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);

    //![3]
        QChart *chart = new QChart();
        //afiche les barres
        chart->addSeries(series);
        chart->setTitle("Famille: " + nom_famille);
        chart->setAnimationOptions(QChart::SeriesAnimations);


    //![4]
        QStringList categories;

        if ( std::find(villes.begin(),villes.end(),1) != villes.end()){
            categories << "Paris";
        }
        if ( std::find(villes.begin(),villes.end(),2) != villes.end()){
            categories << "Lyon";
        }
        if ( std::find(villes.begin(),villes.end(),3) != villes.end()){
            categories << "Strasbourg";
        }
        if ( std::find(villes.begin(),villes.end(),4) != villes.end()){
            categories << "Marseille";
        }

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

QChartView * chartGenerator_1prod_famille(QString prod1, int id_prod1, QString nom_famille, vector<int> villes){

    vector<Requete> rq;
    rq=creation_de_requetes();

    //![1]
        QBarSet *set0 = new QBarSet(prod1);

        //Famille prets¡
        for (int i=1; i <= (int)villes.size(); i++){
            *set0 << totaldeProduitsparVille(rq,i,id_prod1);
        }

    //![2]
        QBarSeries *series = new QBarSeries();
        series->append(set0);

    //![3]
        QChart *chart = new QChart();
        //afiche les barres
        chart->addSeries(series);
        chart->setTitle("Famille: " + nom_famille);
        chart->setAnimationOptions(QChart::SeriesAnimations);


    //![4]
        QStringList categories;

        if ( std::find(villes.begin(),villes.end(),1) != villes.end()){
            categories << "Paris";
        }
        if ( std::find(villes.begin(),villes.end(),2) != villes.end()){
            categories << "Lyon";
        }
        if ( std::find(villes.begin(),villes.end(),3) != villes.end()){
            categories << "Strasbourg";
        }
        if ( std::find(villes.begin(),villes.end(),4) != villes.end()){
            categories << "Marseille";
        }

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

//Cases des villes en fonction de l'utilisateur choisi dans le MainWindow
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


    vector<int> villes = whichCitiesAreChecked();

    //Canal Bancaire
    ui->cBancLayout->addWidget(chartGenerator_2prod_famille("Habitation",1,"Auto",2,"Prêts",villes));
    ui->cBancLayout->addWidget(chartGenerator_2prod_famille("Courant",3,"Epargne",4,"Comptes",villes));
    ui->cBancLayout->addWidget(chartGenerator_2prod_famille("Vert",5,"Bleu",6,"Chèques",villes));
    ui->cBancLayout->addWidget(chartGenerator_2prod_famille("Débit",7,"Credit",8,"Cartes",villes));

    //Canal Assurance
    ui->cAssuLayout->addWidget(chartGenerator_2prod_famille("Vélo",9,"Ordi",10,"Assurances",villes));

    //Canal Notre Action
    ui->cBoursLayout->addWidget(chartGenerator_1prod_famille("La BanQ Action",11,"Notre Action",villes));

    //OVERVIEW
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


void clearLayout(QLayout* layout, bool deleteWidgets = true)
{
    while (QLayoutItem* item = layout->takeAt(0))
    {
        if (deleteWidgets)
        {
            if (QWidget* widget = item->widget())
                widget->deleteLater();
        }
        if (QLayout* childLayout = item->layout())
            clearLayout(childLayout, deleteWidgets);
        delete item;
    }
}


void charts::on_pushButton_clicked()
{
    clearLayout(ui->cBancLayout);
    ui->cBancaire->update();
    vector<int> villes = whichCitiesAreChecked();

    //Canal Bancaire
    ui->cBancLayout->addWidget(chartGenerator_2prod_famille("Habitation",1,"Auto",2,"Prêts",villes));
    ui->cBancLayout->addWidget(chartGenerator_2prod_famille("Courant",3,"Epargne",4,"Comptes",villes));
    ui->cBancLayout->addWidget(chartGenerator_2prod_famille("Vert",5,"Bleu",6,"Chèques",villes));
    ui->cBancLayout->addWidget(chartGenerator_2prod_famille("Débit",7,"Credit",8,"Cartes",villes));
    ui->cBancaire->update();

}
