#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


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
    sum(500);
}
void Widget::on_pb100_clicked()
{
    sum(100);
}
void Widget::on_pb50_clicked(){
    sum(50);
}
void Widget::on_pb10_clicked(){
    sum(10);
}
void Widget::on_pbCoffee_clicked(){
    sum(-100);
}
void Widget::on_pb_Tea_clicked(){
    sum(-150);
}
void Widget::on_pbCola_clicked(){
    sum(-200);
}

void Widget::button(){
    if(money_ >= 200) ui->pbCola->setEnabled(true);
    else ui->pbCola->setEnabled(0);
    if(money_ >= 150) ui->pb_Tea->setEnabled(true);
    else ui->pb_Tea->setEnabled(0);
    if(money_ >= 100) ui->pbCoffee->setEnabled(true);
    else ui->pbCoffee->setEnabled(0);
}

void Widget::sum(int num){
    money_ += num;
    ui->lcdNumber->display(this->money_);
    button();
}

void Widget::on_pbReset_clicked(){
    QString str;
    int num500, num100, num50, num10;

    if(money_ > 500) num500 = money_ / 500;
    money_ %= 500;
    if(money_ < 500)num100 = money_ / 100;
    money_ %= 100;
    if(money_ < 100)num50 = money_ / 50;
    money_ %= 50;
    if(money_ < 50)num10 = money_ / 10;
    money_ %= 10;

    str = QString("500: %1, 100: %2, 50: %3, 10: %4").arg(num500).arg(num100).arg(num50).arg(num10);
    QMessageBox::information(this, "show", str);
    ui->lcdNumber->display(this->money_);
}

