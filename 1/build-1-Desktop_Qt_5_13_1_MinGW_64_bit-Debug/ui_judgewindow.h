/********************************************************************************
** Form generated from reading UI file 'judgewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JUDGEWINDOW_H
#define UI_JUDGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JudgeWindow
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_checkbox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_label;
    QPushButton *export_to_database;
    QLineEdit *name1;
    QLineEdit *id1;
    QLineEdit *name2;
    QLineEdit *id2;

    void setupUi(QWidget *JudgeWindow)
    {
        if (JudgeWindow->objectName().isEmpty())
            JudgeWindow->setObjectName(QString::fromUtf8("JudgeWindow"));
        JudgeWindow->resize(1216, 1068);
        gridLayoutWidget = new QWidget(JudgeWindow);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 30, 911, 911));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_2 = new QWidget(JudgeWindow);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(960, 29, 31, 931));
        gridLayout_checkbox = new QGridLayout(gridLayoutWidget_2);
        gridLayout_checkbox->setObjectName(QString::fromUtf8("gridLayout_checkbox"));
        gridLayout_checkbox->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(JudgeWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 10, 191, 20));
        label_2 = new QLabel(JudgeWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(290, 10, 211, 20));
        label_3 = new QLabel(JudgeWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(550, 10, 181, 20));
        label_4 = new QLabel(JudgeWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(780, 10, 181, 20));
        gridLayoutWidget_3 = new QWidget(JudgeWindow);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(1010, 30, 31, 911));
        gridLayout_label = new QGridLayout(gridLayoutWidget_3);
        gridLayout_label->setObjectName(QString::fromUtf8("gridLayout_label"));
        gridLayout_label->setContentsMargins(0, 0, 0, 0);
        export_to_database = new QPushButton(JudgeWindow);
        export_to_database->setObjectName(QString::fromUtf8("export_to_database"));
        export_to_database->setGeometry(QRect(1060, 650, 121, 41));
        name1 = new QLineEdit(JudgeWindow);
        name1->setObjectName(QString::fromUtf8("name1"));
        name1->setGeometry(QRect(1080, 80, 113, 20));
        id1 = new QLineEdit(JudgeWindow);
        id1->setObjectName(QString::fromUtf8("id1"));
        id1->setGeometry(QRect(1080, 120, 113, 20));
        name2 = new QLineEdit(JudgeWindow);
        name2->setObjectName(QString::fromUtf8("name2"));
        name2->setGeometry(QRect(1080, 170, 113, 20));
        id2 = new QLineEdit(JudgeWindow);
        id2->setObjectName(QString::fromUtf8("id2"));
        id2->setGeometry(QRect(1080, 220, 113, 20));

        retranslateUi(JudgeWindow);

        QMetaObject::connectSlotsByName(JudgeWindow);
    } // setupUi

    void retranslateUi(QWidget *JudgeWindow)
    {
        JudgeWindow->setWindowTitle(QCoreApplication::translate("JudgeWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("JudgeWindow", "Wait To Leave", nullptr));
        label_2->setText(QCoreApplication::translate("JudgeWindow", "Arrive people", nullptr));
        label_3->setText(QCoreApplication::translate("JudgeWindow", "TotalCost", nullptr));
        label_4->setText(QCoreApplication::translate("JudgeWindow", "WinOrLost", nullptr));
        export_to_database->setText(QCoreApplication::translate("JudgeWindow", "export", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JudgeWindow: public Ui_JudgeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JUDGEWINDOW_H
