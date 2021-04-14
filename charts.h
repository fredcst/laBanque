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

    void on_radioButton_clicked();

private:
    Ui::charts *ui;
};

#endif // CHARTS_H
