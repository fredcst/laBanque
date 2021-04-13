#ifndef DETAILCHARTS_H
#define DETAILCHARTS_H

#include <QWidget>

namespace Ui {
class detailCharts;
}

class detailCharts : public QWidget
{
    Q_OBJECT

public:
    explicit detailCharts(QWidget *parent = nullptr);
    ~detailCharts();

private slots:
    void on_pushButton_clicked();

private:
    Ui::detailCharts *ui;
};

#endif // DETAILCHARTS_H
