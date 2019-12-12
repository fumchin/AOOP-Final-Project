/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *Testdata_1;
    QLineEdit *Submitdata_1;
    QLineEdit *Spend_time_1;
    QLineEdit *Correct_1;
    QPushButton *pushButton;
    QComboBox *OptionComboBox;
    QLineEdit *PeopleNum;
    QLineEdit *Destination;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(791, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 20, 61, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(330, 80, 47, 12));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(330, 110, 41, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(330, 170, 71, 20));
        Testdata_1 = new QLineEdit(centralWidget);
        Testdata_1->setObjectName(QString::fromUtf8("Testdata_1"));
        Testdata_1->setGeometry(QRect(410, 20, 281, 20));
        Submitdata_1 = new QLineEdit(centralWidget);
        Submitdata_1->setObjectName(QString::fromUtf8("Submitdata_1"));
        Submitdata_1->setGeometry(QRect(410, 70, 281, 20));
        Spend_time_1 = new QLineEdit(centralWidget);
        Spend_time_1->setObjectName(QString::fromUtf8("Spend_time_1"));
        Spend_time_1->setGeometry(QRect(412, 110, 241, 20));
        Correct_1 = new QLineEdit(centralWidget);
        Correct_1->setObjectName(QString::fromUtf8("Correct_1"));
        Correct_1->setGeometry(QRect(410, 170, 251, 20));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 220, 75, 23));
        OptionComboBox = new QComboBox(centralWidget);
        OptionComboBox->addItem(QString());
        OptionComboBox->addItem(QString());
        OptionComboBox->addItem(QString());
        OptionComboBox->addItem(QString());
        OptionComboBox->addItem(QString());
        OptionComboBox->addItem(QString());
        OptionComboBox->addItem(QString());
        OptionComboBox->addItem(QString());
        OptionComboBox->addItem(QString());
        OptionComboBox->addItem(QString());
        OptionComboBox->addItem(QString());
        OptionComboBox->setObjectName(QString::fromUtf8("OptionComboBox"));
        OptionComboBox->setGeometry(QRect(170, 70, 69, 22));
        PeopleNum = new QLineEdit(centralWidget);
        PeopleNum->setObjectName(QString::fromUtf8("PeopleNum"));
        PeopleNum->setGeometry(QRect(410, 210, 251, 20));
        Destination = new QLineEdit(centralWidget);
        Destination->setObjectName(QString::fromUtf8("Destination"));
        Destination->setGeometry(QRect(410, 230, 251, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(330, 200, 61, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(330, 230, 61, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 791, 17));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Testdata", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Submitdata", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Spend time", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Correct or not", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        OptionComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        OptionComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        OptionComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        OptionComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));
        OptionComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "5", nullptr));
        OptionComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "6", nullptr));
        OptionComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "7", nullptr));
        OptionComboBox->setItemText(7, QCoreApplication::translate("MainWindow", "8", nullptr));
        OptionComboBox->setItemText(8, QCoreApplication::translate("MainWindow", "9", nullptr));
        OptionComboBox->setItemText(9, QCoreApplication::translate("MainWindow", "10", nullptr));
        OptionComboBox->setItemText(10, QCoreApplication::translate("MainWindow", "11", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "PeopleNum", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Destination", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
