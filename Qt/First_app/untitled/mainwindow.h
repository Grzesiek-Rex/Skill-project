#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>
#include <QLabel>
#include <cmath>

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
    void on_comboBoxEnergyLosses_currentIndexChanged(int index);

    void on_pushButtonCalc_clicked();

private:
    Ui::MainWindow *ui;
    QDoubleSpinBox* spinBoxArray[6];
    QLabel* labelArray[7];
};
#endif // MAINWINDOW_H
