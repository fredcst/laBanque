#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "charts.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setDisabled(1);
    ui->comboBox->setDisabled(1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ch = new charts(ui->comboBox->currentIndex());
    ch->show();
    this->hide();
}

void MainWindow::on_radioButton_clicked()
{
    ui->pushButton->setDisabled(0);
    ui->comboBox->setDisabled(1);
}

void MainWindow::on_radioButton_2_clicked()
{
    //verifie si comboBox Index=0 et si boutton est deja pressé
    if(ui->radioButton->isEnabled() && ui->comboBox->currentIndex()==0) ui->pushButton->setDisabled(1);
    ui->comboBox->setDisabled(0);
}


void MainWindow::on_comboBox_activated(int index)
{
    //verifie si le push button est deja activé pour le desactiver et verifie si l'index et correct
    if(index!=0) ui->pushButton->setDisabled(0);
    else ui->pushButton->setDisabled(1);
}
