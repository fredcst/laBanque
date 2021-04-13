#include "charts.h"
#include "ui_charts.h"



charts::charts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::charts)
{
    ui->setupUi(this);
}

charts::~charts()
{
    delete ui;
}

void charts::on_pushButton_clicked()
{
    dtch.show();
}

void charts::on_pushButton_2_clicked()
{
    dtch.show();
}

void charts::on_pushButton_3_clicked()
{
    dtch.show();
}
