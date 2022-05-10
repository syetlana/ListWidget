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
    if (ui->listWidget_1->count()==0){
        QMessageBox error;
        error.setText("There is no elements in the 1st list");
        error.exec();
        return;
    }
    ui->listWidget_2->insertItem(0, ui->listWidget_1->takeItem(ui->listWidget_1->currentRow()));
    ui->listWidget_1->setCurrentRow(-1);
}

void MainWindow::on_pushButton_1_clicked()  //to left
{
    if (ui->listWidget_2->count()==0){
        QMessageBox error;
        error.setText("There is no elements in the 2nd list");
        error.exec();
        return;
    }
    ui->listWidget_1->insertItem(0, ui->listWidget_2->takeItem(ui->listWidget_2->currentRow()));
    ui->listWidget_2->setCurrentRow(-1);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->listWidget_1->sortItems(Qt::AscendingOrder);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->listWidget_2->sortItems(Qt::DescendingOrder);
}
