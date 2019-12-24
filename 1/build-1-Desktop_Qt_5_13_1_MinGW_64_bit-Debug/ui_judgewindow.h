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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JudgeWindow
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_checkbox;

    void setupUi(QWidget *JudgeWindow)
    {
        if (JudgeWindow->objectName().isEmpty())
            JudgeWindow->setObjectName(QString::fromUtf8("JudgeWindow"));
        JudgeWindow->resize(1216, 1068);
        gridLayoutWidget = new QWidget(JudgeWindow);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 30, 911, 941));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_2 = new QWidget(JudgeWindow);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(960, 29, 160, 951));
        gridLayout_checkbox = new QGridLayout(gridLayoutWidget_2);
        gridLayout_checkbox->setObjectName(QString::fromUtf8("gridLayout_checkbox"));
        gridLayout_checkbox->setContentsMargins(0, 0, 0, 0);

        retranslateUi(JudgeWindow);

        QMetaObject::connectSlotsByName(JudgeWindow);
    } // setupUi

    void retranslateUi(QWidget *JudgeWindow)
    {
        JudgeWindow->setWindowTitle(QCoreApplication::translate("JudgeWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JudgeWindow: public Ui_JudgeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JUDGEWINDOW_H
