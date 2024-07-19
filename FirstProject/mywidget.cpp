#include "mywidget.h"
#include <QPushButton>//按钮控件的头文件
#include "mypushbutton.h"
#include <QDebug>

//命名规范
//类名：首字母大写，单词和单词之间首字母大写（大驼峰）
//函数名 变量名称，首字母小写，单词和单词之间字母大写（小驼峰）

//快捷键
//注释  ctrl+/
//运行  ctrl+r
//编译  ctrl+b
//字体缩放 Ctrl+鼠标滚轮
//查找 Ctrl+f
//整行移动  Ctrl+shift+上或者下
//帮助文档 F1
//自动对齐  Ctrl+i
//同名之间的.h和.cpp切换  F4



myWidget::myWidget(QWidget *parent)
    : QWidget(parent)//初始化列表
{
    //创建一个按钮
    QPushButton * btn = new QPushButton;
    //btn->show();//show以顶层方式单出窗口控件
    //让btn对象依赖在myWidget窗口中
    btn->setParent(this);
    //显示文本
    btn->setText("the first button");



    //创建第二个按钮  按照控件的大小创建窗口
    QPushButton * btn2 = new QPushButton("the second button",this);

    //移动btn2按钮
    btn2->move(100,100);

    // //重置按钮大小
    // btn2->resize(60,60);

    //重置窗口大小
    resize(500,300);

    //设置固定窗口大小
    setFixedSize(500,300);

    //设置窗口标题
    setWindowTitle("the first window");


    //创建一个自己的按钮对象
    MyPushButton * myBtn = new MyPushButton;
    myBtn->setText("my own button");

    myBtn->move(100,200);
    myBtn->setParent(this);//设置到对象树中


    //需求——点击我的按钮，关闭窗口
    //参数1 信号的发送者 参数二 发送的信号(函数的地址)
    //参数3 信号的接受者 参数4 处理的槽函数(函数的地址)
    //connect(myBtn, &MyPushButton::clicked, this, &myWidget::close);
    connect(myBtn, &QPushButton::clicked, this, &QWidget::close);

}

myWidget::~myWidget() {
    qDebug() << "myWidget析构";
}
