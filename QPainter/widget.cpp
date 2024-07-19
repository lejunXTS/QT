#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton,&QPushButton::clicked,[=](){
        posX += 20;
        //如果要手动调用绘图事件 用update更新
        update();
    });
}


//绘图事件
void Widget::paintEvent(QPaintEvent *)
{
    // //实例化画家类  this指定的是绘图的设备
    // QPainter painter(this);

    // //设置画笔
    // QPen pen(QColor(122,168,200));

    // //设置画笔宽度
    // pen.setWidth(6);

    // //设置画笔风格
    // pen.setStyle(Qt::DotLine);

    // //让画家使用这个笔
    // painter.setPen(pen);

    // //设置画刷
    // QBrush brush(QColor(222,222,222));

    // //设置画刷风格
    // brush.setStyle(Qt::Dense3Pattern);

    // //让画家使用画刷
    // painter.setBrush(brush);

    // //画线
    // painter.drawLine(QPoint(0,0), QPoint(100,100));

    // //画圆 椭圆
    // painter.drawEllipse(QPoint(100,100),36,66);

    // //画矩形
    // painter.drawRect(QRect(20,20,50,50));

    // //画文字
    // painter.drawText(QRect(10,200,100,50),"晴天与猫");


    /////////////////高级设置/////////////////////////////////////////

    //QPainter painter(this);

    // painter.drawEllipse(QPoint(100,100),50,50);

    // //设置抗锯齿能力  效率低
    // painter.setRenderHint(QPainter::Antialiasing);

    // painter.drawEllipse(QPoint(200,200),50,50);


    // //画矩形
    // painter.drawRect(QRect(20,20,50,50));

    // //移动画家
    // painter.translate(100,0);

    // //保存画家状态
    // painter.save();

    // painter.drawRect(QRect(20,20,50,50));

    // painter.translate(100,0);

    // //还原画家保存状态
    // painter.restore();

    // painter.drawRect(QRect(20,20,50,50));


    ///////////////利用画家画资源图片//////////////////////

    QPainter painter(this);

    //如果超出屏幕 从0开始
    if (posX > this->width())
    {
        posX = 0;
    }

    QPixmap pixmap(":/image/le.jpg");

    QPixmap scaledPixmap = pixmap.scaled(200, 200, Qt::KeepAspectRatio);

    painter.drawPixmap(posX,10,scaledPixmap);
}

Widget::~Widget()
{
    delete ui;
}
