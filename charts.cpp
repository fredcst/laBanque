#include "charts.h"
#include "ui_charts.h"


charts::charts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::charts)
{
    ui->setupUi(this);
    ui->radioButton_volume->setChecked(1);
}

charts::~charts()
{
    delete ui;
}
