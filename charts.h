#ifndef CHARTS_H
#define CHARTS_H

#include <QWidget>
#include <QDateTime>

namespace Ui {
class charts;
}

class charts : public QWidget
{
    Q_OBJECT

public:
    explicit charts(int, QWidget *parent = nullptr);
    ~charts();

private slots:

    void on_check_toutes_toggled(bool checked);

    //void on_check_toutes_stateChanged(int arg1);

    void on_check_toutes_clicked(bool checked);

private:
    Ui::charts *ui;
};

#endif // CHARTS_H
