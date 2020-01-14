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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JudgeWindow
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *overWeightLabel;
    QLabel *TotalPeopleLabel;
    QLabel *TotalPathLabel;
    QLabel *TotalScoreLabel;

    void setupUi(QWidget *JudgeWindow)
    {
        if (JudgeWindow->objectName().isEmpty())
            JudgeWindow->setObjectName(QString::fromUtf8("JudgeWindow"));
        JudgeWindow->resize(1085, 721);
        gridLayoutWidget = new QWidget(JudgeWindow);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 10, 421, 681));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(JudgeWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(620, 570, 75, 23));
        layoutWidget = new QWidget(JudgeWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(510, 80, 271, 411));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        overWeightLabel = new QLabel(layoutWidget);
        overWeightLabel->setObjectName(QString::fromUtf8("overWeightLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Franklin Gothic Demi"));
        font.setPointSize(20);
        overWeightLabel->setFont(font);

        verticalLayout->addWidget(overWeightLabel);

        TotalPeopleLabel = new QLabel(layoutWidget);
        TotalPeopleLabel->setObjectName(QString::fromUtf8("TotalPeopleLabel"));
        TotalPeopleLabel->setFont(font);

        verticalLayout->addWidget(TotalPeopleLabel);

        TotalPathLabel = new QLabel(layoutWidget);
        TotalPathLabel->setObjectName(QString::fromUtf8("TotalPathLabel"));
        TotalPathLabel->setFont(font);

        verticalLayout->addWidget(TotalPathLabel);

        TotalScoreLabel = new QLabel(layoutWidget);
        TotalScoreLabel->setObjectName(QString::fromUtf8("TotalScoreLabel"));
        TotalScoreLabel->setFont(font);

        verticalLayout->addWidget(TotalScoreLabel);


        retranslateUi(JudgeWindow);

        QMetaObject::connectSlotsByName(JudgeWindow);
    } // setupUi

    void retranslateUi(QWidget *JudgeWindow)
    {
        JudgeWindow->setWindowTitle(QCoreApplication::translate("JudgeWindow", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("JudgeWindow", "PushButton", nullptr));
        overWeightLabel->setText(QString());
        TotalPeopleLabel->setText(QString());
        TotalPathLabel->setText(QString());
        TotalScoreLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class JudgeWindow: public Ui_JudgeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JUDGEWINDOW_H
