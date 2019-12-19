#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include <QDebug>
#include <QSqlResult>
#include <QSqlDatabase>
#include "building.h"
#include "data.h"
#include "scheduler.h"


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
    void slot_update_data();
    void on_startSimBtn_clicked();

private:
    Ui::MainWindow *ui;
    Data data;
    Building building;
    Scheduler scheduler;
};

#endif // MAINWINDOW_H
