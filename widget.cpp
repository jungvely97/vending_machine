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
    this->money_ += 500;
    ui->lcdNumber->display(this->money_);
    button();
}
void Widget::on_pb100_clicked()
{
    this->money_ += 100;
    ui->lcdNumber->display(this->money_);
    button();
}
void Widget::on_pb50_clicked(){
    this->money_ += 50;
    ui->lcdNumber->display(this->money_);
    button();
}
void Widget::on_pb10_clicked(){
    this->money_ += 10;
    ui->lcdNumber->display(this->money_);
    button();
}
void Widget::on_pbCoffee_clicked(){
    this->money_ -= 100;
    ui->lcdNumber->display(this->money_);
    button();
}
void Widget::on_pb_Tea_clicked(){
    this->money_ -= 150;
    ui->lcdNumber->display(this->money_);
    button();
}
void Widget::on_pbCola_clicked(){
    this->money_ -=200;
    ui->lcdNumber->display(this->money_);
    button();
}

void Widget::button(){
    if(this->money_ >= 200) ui->pbCola->setEnabled(true);
    else ui->pbCola->setEnabled(0);
    if(this->money_ >= 150) ui->pb_Tea->setEnabled(true);
    else ui->pb_Tea->setEnabled(0);
    if(this->money_ >= 100) ui->pbCoffee->setEnabled(true);
    else ui->pbCoffee->setEnabled(0);
}

void Widget::on_pbReset_clicked(){
    QString str;
    int num500, num100, num50, num10;

    num500 = this->money_ / 500;
    this->money_ %= 500;
    num100 = this->money_ / 100;
    this->money_ %= 100;
    num50 = this->money_ / 50;
    this->money_ %= 50;
    num10 = this->money_ / 10;
    this->money_ %= 10;

    str = QString("500: %1, 100: %2, 50: %3, 10: %4").arg(num500).arg(num100).arg(num50).arg(num10);
    QMessageBox::information(this, "show", str);
    ui->lcdNumber->display(this->money_);
}

