#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPainter>
#include <QImage>
#include <QPicture>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // //pixmap绘图设备   专门为平台做了显示的优化/////////////////////////
    // QPixmap pix(300,300);

    // //填充颜色
    // pix.fill(Qt::white);

    // //声明画家
    // QPainter painter(&pix);

    // painter.setPen(QPen(Qt::blue));

    // painter.drawEllipse(QPoint(150,150),100,100);

    // //保存
    // pix.save("D:\\cpp\\QT\\pix.png");



    // //qimage 绘图设备  可以对像素进行访问//////////////////////////////
    // QImage img(300,300,QImage::Format_RGB32);

    // //填充颜色
    // img.fill(Qt::white);

    // //声明画家
    // QPainter painter(&img);

    // painter.setPen(QPen(Qt::blue));

    // painter.drawEllipse(QPoint(150,150),100,100);

    // //保存
    // img.save("D:\\cpp\\QT\\img.png");



    //qpicture 绘图设备  可以记录和重现绘图指令//////////////////////////

    QPicture pic;

    QPainter painter;
    //开始往pic上画
    painter.begin(&pic);

    painter.setPen(QPen(Qt::cyan));

    painter.drawEllipse(QPoint(150,150),100,100);

    //结束画画
    painter.end();

    //保存到磁盘
    pic.save("D:\\cpp\\QT\\pic.zt");



}


//绘图事件
void Widget::paintEvent(QPaintEvent *)
{
    // QPainter painter(this);

    // //利用qimage 对像素进行修改///////////////////////////////////
    // QImage img;

    // img.load(":/image/005y0Ylbly1hgh1g861whj30u00u00w5.jpg");

    // img = img.scaled(400, 400, Qt::KeepAspectRatio);

    // //修改像素点
    // for (int i = 50; i < 100; i++)
    // {
    //     for (int j = 50; j < 100; j++)
    //     {
    //         QRgb value = qRgb(200,0,0);
    //         img.setPixel(i, j, value);
    //     }
    // }

    // painter.drawImage(0,0,img);



    //重现qpicture的绘图指令/////////////////////////////////////

    QPainter painter(this);

    QPicture pic;

    pic.load("D:\\cpp\\QT\\pic.zt");

    painter.drawPicture(0,0,pic);
}



Widget::~Widget()
{
    delete ui;
}
