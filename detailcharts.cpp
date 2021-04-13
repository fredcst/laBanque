#include "detailcharts.h"
#include "ui_detailcharts.h"
#include "charts.h"

detailCharts::detailCharts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::detailCharts)
{
    ui->setupUi(this);
}

detailCharts::~detailCharts()
{
    delete ui;
}

void detailCharts::on_pushButton_clicked()
{
    this->hide();
}
