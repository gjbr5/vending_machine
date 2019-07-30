#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    update();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::changeMoney(int n)
{
    money += n;
    update();
}

void Widget::update()
{
    ui->lcdNumber->display(money);
    ui->pbCoke->setEnabled(money >= 200);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbCoffee->setEnabled(money >= 100);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbCoke_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    QString remain = "";
    remain.sprintf("500원: %d개\n100원: %d개\n50원: %d개\n10원: %d개",
                   money / 500,
                   (money % 500) / 100,
                   (money % 100) / 50,
                   (money % 50) / 10);
    //    remain += "500원: " + QString::number(money / 500) + "개\n";
    //    money %= 500;
    //    remain += "100원: " + QString::number(money / 100) + "개\n";
    //    money %= 100;
    //    remain += "50원: " + QString::number(money / 50) + "개\n";
    //    money %= 50;
    //    remain += "10원: " + QString::number(money / 10) + "개";
    //    money %= 10;
    money = 0;
    update();
    QMessageBox::information(nullptr, "반환", remain);
}
