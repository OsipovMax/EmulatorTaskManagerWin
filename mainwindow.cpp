#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <cstdlib>


MainWindow::MainWindow( QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    arr(new AllProcess)

{
    ui->setupUi(this);
    ProcesTableWidget = new QTableWidgetItem[100];
    UserTableWidget = new QTableWidgetItem[100];
    JournalTableWidget = new QTableWidgetItem[100];
    MyDialog1 = new Dialog1(this,arr);
    timer = new QTimer(this);
    std::string ProcesName;
    float ProcesCenPr, ProcesMemory,ProcesDisk, ProcesNetW;
    std::string filename = "Kurs.txt";
    std::ifstream f(filename.c_str());
    if (f.is_open()) {
        while (f) {
            std::getline(f, ProcesName);
            f >> ProcesCenPr >> ProcesMemory >> ProcesDisk >> ProcesNetW;
            while (f && f.get( ) != '\n');
            arr->Add(Proces(ProcesName, ProcesCenPr, ProcesMemory, ProcesDisk, ProcesNetW));
        }
    } else {
        std::cerr << "Ошибка! не открыт файл!" << std::endl;
    }
    this->showProces();
    this->showUser();
    this->showJournal();
    connect(ui->action_4, SIGNAL(triggered(bool)), this, SLOT(quit()));
    connect(ui->pushButton, SIGNAL(clicked(bool)),MyDialog1, SLOT(show()));
    if(arr->size()<=10 && arr->size()>=8){
    connect(timer, SIGNAL(timeout()),this,SLOT(changes()));
    timer->start(10000);
    connect(timer, SIGNAL(timeout()),this,SLOT(changes1()));
    timer->start(9000);
    connect(timer, SIGNAL(timeout()),this,SLOT(changes2()));
    timer->start(8500);}
    if(arr->size()<8 && arr->size()>5 )
    {connect(timer, SIGNAL(timeout()),this,SLOT(changes()));
        timer->start(8000);
        connect(timer, SIGNAL(timeout()),this,SLOT(changes1()));
        timer->start(7500);
        connect(timer, SIGNAL(timeout()),this,SLOT(changes2()));
        timer->start(6500);}
    if(arr->size()<5){
        connect(timer, SIGNAL(timeout()),this,SLOT(changes()));
                timer->start(6000);
                connect(timer, SIGNAL(timeout()),this,SLOT(changes1()));
                timer->start(5000);
                connect(timer, SIGNAL(timeout()),this,SLOT(changes2()));
                timer->start(4000);}
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showProces( ){
    ui->tableWidget->clear( );
    float summa=0;
    int i=0;
    int j=0;
    QStringList name_table;
        name_table << "Name"  << "CentralProces" << "Memory" << "Disc" << "NetWork";
        ui->tableWidget->setHorizontalHeaderLabels(name_table);
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget->setRowCount(arr->size());
        ui->tableWidget->setColumnCount(5);
        ProcesTableWidget = new QTableWidgetItem[5 * (arr->size()+1)];
            for (vector <Proces>::iterator it = arr->begin() ; it!=arr->end() ; ++it){
                ProcesTableWidget[0+i].setText(QString::fromStdString(it->getName()));
                ProcesTableWidget[1+i].setText(QString::number(it->getCentralProcess())+"%");
                ProcesTableWidget[2+i].setText(QString::number(it->getMemory())+"MB");
                ProcesTableWidget[3+i].setText(QString::number(it->getDisc())+"MB/c");
                ProcesTableWidget[4+i].setText(QString::number(it->getNetwork())+"Mbit/c");

                ui->tableWidget->setItem( j,  0, &ProcesTableWidget[0+i]);
                ui->tableWidget->setItem( j , 1, &ProcesTableWidget[1+i]);
                ui->tableWidget->setItem( j , 2, &ProcesTableWidget[2+i]);
                ui->tableWidget->setItem( j , 3, &ProcesTableWidget[3+i]);
                ui->tableWidget->setItem( j , 4, &ProcesTableWidget[4+i]);
                i=i+5;
                j=j+1;
                summa=summa+it->getCentralProcess();
            }
            ui->label->setText(QString::number(summa));
            }

void MainWindow::showUser( ){
   float Cp=0, Mem=0, Ds=0, Nt=0;
    ui->tableWidget_2->clear( );
        ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget_2->setRowCount(1);
        ui->tableWidget_2->setColumnCount(5);
        UserTableWidget = new QTableWidgetItem[5];
for (vector <Proces>::iterator it = arr->begin() ; it!=arr->end() ; ++it){
    Cp=Cp+it->getCentralProcess();
    Mem=Mem+it->getMemory();
    Ds=Ds+it->getDisc();
    Nt=Nt+it->getNetwork();}
                  UserTableWidget[0].setText(QString::fromStdString("User"));
                  UserTableWidget[1].setText(QString::number(Cp)+"%");
                  UserTableWidget[2].setText(QString::number(Mem)+"MB");
                  UserTableWidget[3].setText(QString::number(Ds)+"MB/s");
                  UserTableWidget[4].setText(QString::number(Nt)+"Mbit/s");
                  for (int i = 0; i < 5; ++i)
                      ui->tableWidget_2->setItem(0, i, &UserTableWidget[i]);
            }
void MainWindow::showJournal( ){
    ui->tableWidget_3->clear( );
    int i=0;
    int j=0,b=1;
    QStringList name_table;
        name_table << "Name" << "Time";
        ui->tableWidget_3->setHorizontalHeaderLabels(name_table);
        ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget_3->setRowCount(10);
        ui->tableWidget_3->setColumnCount(2);
        JournalTableWidget = new QTableWidgetItem[20];
            for (vector <Proces>::iterator it = arr->begin() ; it!=arr->end() ; ++it){
                JournalTableWidget[0+i].setText(QString::fromStdString(it->getName()));
                ui->tableWidget_3->setItem( j,  0, &JournalTableWidget[0+i]);
                i=i+2;
                j=j+1;
            }
                JournalTableWidget[1].setText(QString::fromStdString("0:12:31"));
                JournalTableWidget[3].setText(QString::fromStdString("0:00:00"));
                JournalTableWidget[5].setText(QString::fromStdString("0:03:11"));
                JournalTableWidget[7].setText(QString::fromStdString("0:15:09"));
                JournalTableWidget[9].setText(QString::fromStdString("0:00:00"));
                JournalTableWidget[11].setText(QString::fromStdString("0:00:00"));
                JournalTableWidget[13].setText(QString::fromStdString("0:00:00"));
                JournalTableWidget[15].setText(QString::fromStdString("0:00:00"));
                JournalTableWidget[17].setText(QString::fromStdString("0:00:00"));
                JournalTableWidget[19].setText(QString::fromStdString("0:00:00"));

                for (int a = 0; a<10 ;a++){
                ui->tableWidget_3->setItem( a,  1, &JournalTableWidget[b]);
                b=b+2;}
            }





void MainWindow::changes()
{
   Proces& OneProces = *(arr->begin()) ;
   OneProces.setCentralProcess(rand()% 3 +1);
   OneProces.setNetwork(rand() % 9 +3.7 );
   Proces& OneProces3 = *(arr->begin()+2) ;
   OneProces3.setCentralProcess(rand()% 8 +3.5);
   OneProces3.setDisc(rand() % 3 +1.9);
   Proces& OneProces10 = *(arr->begin()+9);
   OneProces10.setCentralProcess(rand()% 7 + 5.5);
   OneProces10.setMemory(rand() % 1 + 0.4);
   Proces& OneProces6 = *(arr->begin()+5);
   OneProces6.setMemory(rand() %11 +7.7);
  this->showProces();
  this->showUser();
}
void MainWindow::changes1()
{
    Proces& OneProces = *(arr->begin()) ;
    OneProces.setMemory(rand() % 44+5 );
    Proces& OneProces2 = *(arr->begin()+1);
    OneProces2.setNetwork(rand() % 7+7);
    Proces& OneProces5 = *(arr->begin()+4);
    OneProces5.setMemory(rand() % 14 +21);
    OneProces5.setNetwork(rand() % 19 +7);
    Proces& OneProces8 = *(arr->begin()+7);
    OneProces8.setNetwork(rand() % 3 +0.7);
    this->showProces();
    this->showUser();
}
void MainWindow:: changes2(){
    Proces& OneProces4 = *(arr->begin()+3) ;
    OneProces4.setCentralProcess(rand() % 21+9);
    OneProces4.setDisc(rand()% 33+5);
    OneProces4.setMemory(rand()% 29+11);
    Proces& OneProces2 = *(arr->begin()+1) ;
    OneProces2.setDisc(rand() % 3+7);
    Proces& OneProces7 = *(arr->begin()+6);
    OneProces7.setMemory(rand()% 2+ 1.2);
    OneProces7.setNetwork(rand()% 1 +0.1);
    this->showProces();
    this->showUser();
}
void MainWindow::on_pushButton_clicked()
{

}
