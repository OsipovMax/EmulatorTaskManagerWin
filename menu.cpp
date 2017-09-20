#include "menu.h"
#include "ui_menu.h"


Menu::Menu( QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)

{
    ui->setupUi(this);
    UiM = new MainWindow();
    connect(ui->pushButton, SIGNAL(clicked( )), UiM , SLOT(show( )));
}

Menu::~Menu()
{
    delete ui;

}

void Menu::on_pushButton_clicked()
{

}


