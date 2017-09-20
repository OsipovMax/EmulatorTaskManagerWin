#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "proces.h"
#include "allprocess.h"


namespace Ui {
class Dialog;
}

class MainWindow;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(MainWindow* ,AllProcess *arr, QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    MainWindow *ui1;
    AllProcess *arr;

};

#endif // DIALOG_H
