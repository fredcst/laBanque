#include "charts.h"
#include "ui_charts.h"
#include "mainwindow.h"
#include <iostream>


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
