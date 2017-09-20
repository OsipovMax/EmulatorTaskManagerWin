#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include "allprocess.h"

namespace Ui {
class Dialog1;
}
class MainWindow;

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(MainWindow* ,AllProcess *arr, QWidget *parent = 0);
    ~Dialog1();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Dialog1 *ui;
    MainWindow *ui1;
    AllProcess *arr;
};

#endif // DIALOG1_H
