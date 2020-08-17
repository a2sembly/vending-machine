#include "widget.h"
#include "ui_widget.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->Coffee->setEnabled(false);
    ui->Tea->setEnabled(false);
    ui->Milk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::moneyChange(int input)
{
    this->Current_Money += input;
    ui->Money->display(this->Current_Money);
    if(this->Current_Money<100)
    {
        ui->Coffee->setEnabled(false);
        ui->Tea->setEnabled(false);
        ui->Milk->setEnabled(false);
    }
    if(this->Current_Money>=100)
    {
        ui->Coffee->setEnabled(true);
    }
    if(this->Current_Money>=200)
    {
        ui->Milk->setEnabled(true);
    }
    if(this->Current_Money<150)
    {
        ui->Tea->setEnabled(false);
    }
    if(this->Current_Money>=150)
    {
        ui->Tea->setEnabled(true);
    }
    if(this->Current_Money<200)
    {
        ui->Milk->setEnabled(false);
    }
}

void Widget::on_Reset_clicked()
{
    char Changes[100];
    sprintf(Changes,"%d원",Current_Money);
    this->Current_Money = 0;
    ui->Money->display(this->Current_Money);
    QMessageBox::information(this,"Changes",Changes);
}

void Widget::on_pb_10_clicked()
{
    moneyChange(10);
}

void Widget::on_pb_50_clicked()
{
    moneyChange(50);
}

void Widget::on_pb_100_clicked()
{
    moneyChange(100);
}

void Widget::on_pb_500_clicked()
{
    moneyChange(500);
}

void Widget::on_Coffee_clicked()
{
    moneyChange(-100);
}

void Widget::on_Milk_clicked()
{
    moneyChange(-200);
}

void Widget::on_Tea_clicked()
{
    moneyChange(-150);
}
