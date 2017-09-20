#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "allprocess.h"

Dialog::Dialog(MainWindow *ui1, AllProcess *arr, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    ui1(ui1),
    arr(arr)
{


}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_2_clicked()
{
    if(arr->size()){
    arr->remove(1);
    std::cerr << "!!!" << arr->size()<< std::endl;
    ui1->showProces();}
}
