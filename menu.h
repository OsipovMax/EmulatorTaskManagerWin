#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "mainwindow.h"
#include "ui_menu.h"
//#include "allprocess.h"
//#include "proces.h"
//#include <fstream>

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu( QWidget *parent = 0);
    ~Menu();

private slots:
    void on_pushButton_clicked();


private:
    Ui::Menu *ui;
    MainWindow *UiM;

};

#endif // MENU_H
