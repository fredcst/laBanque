#ifndef CHARTS_H
#define CHARTS_H

#include <QWidget>
#include <QDateTime>
#include "detailcharts.h"

namespace Ui {
class charts;
}

class charts : public QWidget
{
    Q_OBJECT

public:
    explicit charts(QWidget *parent = nullptr);
    ~charts();
    detailCharts dtch;

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::charts *ui;
};

#endif // CHARTS_H
