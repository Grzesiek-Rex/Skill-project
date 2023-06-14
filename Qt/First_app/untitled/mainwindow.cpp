#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    spinBoxArray[0] = ui->doubleSpinBox_0;
    spinBoxArray[1] = ui->doubleSpinBox_1;
    spinBoxArray[2] = ui->doubleSpinBox_2;
    spinBoxArray[3] = ui->doubleSpinBox_3;
    spinBoxArray[4] = ui->doubleSpinBox_4;
    spinBoxArray[5] = ui->doubleSpinBox_5;
    labelArray[0] = ui->label_0;
    labelArray[1] = ui->label_1;
    labelArray[2] = ui->label_2;
    labelArray[3] = ui->label_3;
    labelArray[4] = ui->label_4;
    labelArray[5] = ui->label_5;
    labelArray[6] = ui->label_6;
    on_comboBoxEnergyLosses_currentIndexChanged(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBoxEnergyLosses_currentIndexChanged(int index)
{
    for (int i = 0; i < 6; ++i)
        spinBoxArray[i]->setEnabled(true);

    switch(index)
    {
    default:
        break;
    case 0:
        labelArray[0]->setText("Pipe length (ft)");
        labelArray[1]->setText("Pipe slope (ft/ft)");
        labelArray[2]->setText("Rate of flow (cfs)");
        labelArray[3]->setText("Manning coefficient (-)");
        labelArray[4]->setText("Pipe diameter (ft)");
        labelArray[5]->setText("Output - friction losses (ft)");

        spinBoxArray[0]->setValue(0);
        spinBoxArray[1]->setValue(0);
        spinBoxArray[2]->setValue(0);
        spinBoxArray[3]->setValue(0);
        spinBoxArray[4]->setValue(0);
        spinBoxArray[5]->setValue(0);

        labelArray[6]->setText("Flow characteristics");
        ui->comboBoxFlow->setEnabled(true);
        ui->comboBoxFlow->setVisible(true);
        break;
    case 1:
        labelArray[0]->setText("Average outlet velocity (fps)");
        labelArray[1]->setText("Receiving channel velocity downstream of outlet (fps)");
        labelArray[2]->setText("Acceleration due to gravity (ft/s^2)");
        labelArray[3]->setText("Skew: 0˚-90˚ (deg)");
        labelArray[4]->setText("");
        labelArray[5]->setText("Output - exit losses (ft)");

        spinBoxArray[0]->setValue(0);
        spinBoxArray[1]->setValue(0);
        spinBoxArray[2]->setValue(32.2);
        spinBoxArray[2]->setDisabled(true);
        spinBoxArray[3]->setValue(0);
        spinBoxArray[4]->setValue(0);
        spinBoxArray[4]->setDisabled(true);
        spinBoxArray[5]->setValue(0);

        labelArray[6]->setText("");
        ui->comboBoxFlow->setDisabled(true);
        ui->comboBoxFlow->setVisible(false);
        break;
    case 2:
        labelArray[0]->setText("Angle curvature in degrees (deg)");
        labelArray[1]->setText("Channel flow velocity (fps)");
        labelArray[2]->setText("Acceleration due to gravity (ft/s^2)");
        labelArray[3]->setText("");
        labelArray[4]->setText("");
        labelArray[5]->setText("Output - bend loss (ft)");

        spinBoxArray[0]->setValue(0);
        spinBoxArray[1]->setValue(0);
        spinBoxArray[2]->setValue(32.2);
        spinBoxArray[2]->setDisabled(true);
        spinBoxArray[3]->setValue(0);
        spinBoxArray[3]->setDisabled(true);
        spinBoxArray[4]->setValue(0);
        spinBoxArray[4]->setDisabled(true);
        spinBoxArray[5]->setValue(0);

        labelArray[6]->setText("");
        ui->comboBoxFlow->setDisabled(true);
        ui->comboBoxFlow->setVisible(false);
        break;
    }
}


void MainWindow::on_pushButtonCalc_clicked()
{
    double result {};
    switch(ui->comboBoxEnergyLosses->currentIndex())
    {
    default:
        break;
    case 0:
        switch(ui->comboBoxFlow->currentIndex())
        {
        default:
            break;
        case 0:
            result = std::pow((spinBoxArray[2]->value() * spinBoxArray[3]->value()) / (0.46 * std::pow(spinBoxArray[4]->value(), 2.67)), 2);
            break;
        case 1:
            result = spinBoxArray[1]->value();
            break;
        }
        spinBoxArray[5]->setValue(result * spinBoxArray[0]->value());
        break;
    case 1:
        result = 1 * (((std::pow(spinBoxArray[0]->value(), 2) / (2 * spinBoxArray[2]->value())) - (((std::pow(spinBoxArray[1]->value() * cos(spinBoxArray[3]->value() / 180 * M_PI), 2)) / (2 * spinBoxArray[2]->value())))));
        if (result > 0)
            spinBoxArray[5]->setValue(result);
        else
            spinBoxArray[5]->setValue(0);
        break;
    case 2:
        result = (0.0033 * spinBoxArray[0]->value())*((spinBoxArray[1]->value() * spinBoxArray[1]->value()) / (2 * spinBoxArray[2]->value()));
        spinBoxArray[5]->setValue(result);
        break;
    }
}

