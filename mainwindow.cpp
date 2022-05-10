#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHeaderView>
#include <QListWidget>
#include <QListWidgetItem>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QWidget>
QTextStream cin(stdin);
QTextStream cout(stdout);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
    //Elements
    ui->listWidget_1->addItem("Ann");
    ui->listWidget_1->addItem("Bob");
    ui->listWidget_1->addItem("Rob");
    //ui->listWidget_1->addItem("Mary");
    ui->listWidget_2->addItem("Jason");
    ui->listWidget_2->addItem("Tom");
    ui->listWidget_2->addItem("Liz");
    //ui->listWidget_2->addItem("Kim");
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_pushButton_2_clicked() //to right
{
    moving(ui->listWidget_1, ui->listWidget_2);
}

void MainWindow::on_pushButton_1_clicked()  //to left
{
     moving(ui->listWidget_2, ui->listWidget_1);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->listWidget_1->sortItems(Qt::AscendingOrder);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->listWidget_2->sortItems(Qt::DescendingOrder);
}

void MainWindow::moving(QListWidget* From, QListWidget* To){
    if (From->count()==0){
        QMessageBox error;
        error.setText("There is no elements in the list");
        error.exec();
        return;
    }
    QListWidgetItem *ItemFr = From->takeItem(From->currentRow());
    To->insertItem(0,ItemFr);
    From->setCurrentRow(-1);
}
