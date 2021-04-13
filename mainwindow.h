#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "charts.h"
#include "detailcharts.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_comboBox_activated(int index);

private:
    Ui::MainWindow *ui;
    charts charts1;
};

#endif // MAINWINDOW_H
