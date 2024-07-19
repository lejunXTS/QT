#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击获取  获取控件当前的值
    connect(ui->btnGet, &QPushButton::clicked, [=](){
        qDebug() << ui->widget->getNumber();
    });

    //点击设置  设置到一半
    connect(ui->btnSet, &QPushButton::clicked, [=](){
        ui->widget->setNumber(50);
    });
}

Widget::~Widget()
{
    delete ui;
}
