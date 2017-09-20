#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog1.h"
#include <QTableWidgetItem>
#include <memory>
#include <vector>
#include "proces.h"
#include "allprocess.h"
#include <QTimer>
#include <fstream>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( QWidget *parent = 0);
    ~MainWindow();
    void showProces( );
    void showUser( );
    void showJournal();

private slots:

    void changes();
    void changes1();
    void changes2();
    void on_pushButton_clicked();

private:
    std::vector<QTableWidgetItem> items;
    Ui::MainWindow *ui;
    QTableWidgetItem *ProcesTableWidget;
    QTableWidgetItem *UserTableWidget;
    QTableWidgetItem *JournalTableWidget;
    Dialog1 *MyDialog1;
    AllProcess *arr;
    Proces *ProcesOne;
    Proces *OneProces;
    QTimer *timer;

};

#endif // MAINWINDOW_H
