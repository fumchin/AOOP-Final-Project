#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <QSqlResult>
#include <QSqlDatabase>
#include "building.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void connectDB();

private slots:
    void on_pushButton_clicked();

    void on_People_Infomation_clicked();

private:
    Ui::MainWindow *ui;
    Building building;
};

#endif // MAINWINDOW_H
