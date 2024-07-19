#include "widget.h"
#include "./ui_widget.h"
#include <QMovie>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //栈控件的使用---------------------------------------------------------

    //设置默认定位Button

    //Button按钮
    connect(ui->Button, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    //buttonTabBox按钮
    connect(ui->buttonTabBox, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    //ButtonTabWidget按钮
    connect(ui->ButtonTabWidget, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    //--------------------------------------------------------------------

    //下拉框
    ui->comboBox->addItem("杜鹃");
    ui->comboBox->addItem("樱花");
    ui->comboBox->addItem("海棠");

    //点击按钮 选中海棠
    connect(ui->btnSelect, &QPushButton::clicked, [=](){
        //ui->comboBox->setCurrentIndex(2);
        ui->comboBox->setCurrentText("海棠");
    });


    //-------------------------------------------------------------------

    //利用QLabel显示图片
    ui->labelImage->setPixmap(QPixmap(":/image/005y0Ylbly1hj9kxm09i0j31kw1kw1ky.jpg"));

    //利用QLabel显示gif动态图片
    QMovie * movie = new QMovie(":/image/小太阳gif.jpg");
    ui->labelMovie->setMovie(movie);
    //播放动图
    movie->start();

}

Widget::~Widget()
{
    delete ui;
}
