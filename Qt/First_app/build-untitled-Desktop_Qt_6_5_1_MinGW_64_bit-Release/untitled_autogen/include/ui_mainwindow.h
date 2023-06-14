/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *comboBoxEnergyLosses;
    QDoubleSpinBox *doubleSpinBox_0;
    QDoubleSpinBox *doubleSpinBox_1;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_1;
    QLabel *label_0;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_4;
    QPushButton *pushButtonCalc;
    QDoubleSpinBox *doubleSpinBox_5;
    QLabel *label_5;
    QComboBox *comboBoxFlow;
    QLabel *label_6;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(425, 403);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        comboBoxEnergyLosses = new QComboBox(centralwidget);
        comboBoxEnergyLosses->addItem(QString());
        comboBoxEnergyLosses->addItem(QString());
        comboBoxEnergyLosses->addItem(QString());
        comboBoxEnergyLosses->setObjectName("comboBoxEnergyLosses");
        comboBoxEnergyLosses->setGeometry(QRect(30, 10, 301, 28));
        doubleSpinBox_0 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_0->setObjectName("doubleSpinBox_0");
        doubleSpinBox_0->setGeometry(QRect(30, 50, 141, 29));
        doubleSpinBox_0->setDecimals(6);
        doubleSpinBox_0->setMinimum(-1000000.000000000000000);
        doubleSpinBox_0->setMaximum(1000000.000000000000000);
        doubleSpinBox_1 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_1->setObjectName("doubleSpinBox_1");
        doubleSpinBox_1->setGeometry(QRect(30, 90, 141, 29));
        doubleSpinBox_1->setDecimals(6);
        doubleSpinBox_1->setMinimum(-1000000.000000000000000);
        doubleSpinBox_1->setMaximum(1000000.000000000000000);
        doubleSpinBox_2 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_2->setObjectName("doubleSpinBox_2");
        doubleSpinBox_2->setGeometry(QRect(30, 130, 141, 29));
        doubleSpinBox_2->setDecimals(6);
        doubleSpinBox_2->setMinimum(-1000000.000000000000000);
        doubleSpinBox_2->setMaximum(1000000.000000000000000);
        doubleSpinBox_3 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_3->setObjectName("doubleSpinBox_3");
        doubleSpinBox_3->setGeometry(QRect(30, 170, 141, 29));
        doubleSpinBox_3->setDecimals(6);
        doubleSpinBox_3->setMinimum(-1000000.000000000000000);
        doubleSpinBox_3->setMaximum(1000000.000000000000000);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(190, 169, 201, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(190, 130, 201, 31));
        label_1 = new QLabel(centralwidget);
        label_1->setObjectName("label_1");
        label_1->setGeometry(QRect(190, 90, 201, 31));
        label_0 = new QLabel(centralwidget);
        label_0->setObjectName("label_0");
        label_0->setGeometry(QRect(190, 50, 201, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(190, 210, 201, 31));
        doubleSpinBox_4 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_4->setObjectName("doubleSpinBox_4");
        doubleSpinBox_4->setGeometry(QRect(30, 210, 141, 29));
        doubleSpinBox_4->setReadOnly(false);
        doubleSpinBox_4->setDecimals(6);
        doubleSpinBox_4->setMinimum(-1000000.000000000000000);
        doubleSpinBox_4->setMaximum(1000000.000000000000000);
        pushButtonCalc = new QPushButton(centralwidget);
        pushButtonCalc->setObjectName("pushButtonCalc");
        pushButtonCalc->setGeometry(QRect(30, 330, 141, 29));
        doubleSpinBox_5 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_5->setObjectName("doubleSpinBox_5");
        doubleSpinBox_5->setGeometry(QRect(30, 290, 141, 29));
        doubleSpinBox_5->setReadOnly(true);
        doubleSpinBox_5->setDecimals(6);
        doubleSpinBox_5->setMinimum(-1000000.000000000000000);
        doubleSpinBox_5->setMaximum(1000000.000000000000000);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(190, 290, 201, 31));
        comboBoxFlow = new QComboBox(centralwidget);
        comboBoxFlow->addItem(QString());
        comboBoxFlow->addItem(QString());
        comboBoxFlow->setObjectName("comboBoxFlow");
        comboBoxFlow->setGeometry(QRect(30, 250, 141, 28));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(190, 250, 201, 31));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        comboBoxEnergyLosses->setItemText(0, QCoreApplication::translate("MainWindow", "Friction Losses", nullptr));
        comboBoxEnergyLosses->setItemText(1, QCoreApplication::translate("MainWindow", "Exit Losses", nullptr));
        comboBoxEnergyLosses->setItemText(2, QCoreApplication::translate("MainWindow", "Bend Losses", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_0->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButtonCalc->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        comboBoxFlow->setItemText(0, QCoreApplication::translate("MainWindow", "Full flow", nullptr));
        comboBoxFlow->setItemText(1, QCoreApplication::translate("MainWindow", "Part full flow", nullptr));

        label_6->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
