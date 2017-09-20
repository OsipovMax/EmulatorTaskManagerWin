#include "dialog1.h"
#include "ui_dialog1.h"
#include "allprocess.h"
#include "mainwindow.h"


Dialog1::Dialog1(MainWindow *ui1, AllProcess *arr,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1),
    ui1(ui1),
    arr(arr)
{
    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_pushButton_2_clicked()
{
    if(arr->size()){
    arr->remove(ui->lineEdit->text().toInt()-1);
    ui->lineEdit->clear();
    ui1->showProces();}
}
