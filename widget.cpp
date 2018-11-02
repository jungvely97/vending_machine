#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pb500_clicked()
{
    this->money_ += 500;
}
void Widget::on_pb100_clicked()
{
    this->money_ += 100;
}
void Widget::on_pb50_clicked(){
    this->money_ += 50;
}
void Widget::on_pb10_clicked(){
    this->money_ += 10;
}
void Widget::on_coffee_clicked(){
    this->money_ -= 100;
}
void Widget::on_tea_clicked(){
    this->money_ -= 150;
}
void Widget::on_cola_cliced(){
    this->money_ -=200;
}

void Widget::button(){
    if(this->money_ >= 200) ui->pbCola->setEnabled(true);
    if(this->money_ >= 150) ui->pb_Tea->setEnabled(true);
    if(this->money_ >= 100) ui->pbCoffee->setEnabled(true);
}

