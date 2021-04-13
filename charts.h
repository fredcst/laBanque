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
    explicit charts(QWidget *parent = nullptr);
    ~charts();

private slots:
    void on_lcdNumber_overflow();

private:
    Ui::charts *ui;
};

#endif // CHARTS_H
