#include "widget.h"
#include "./ui_widget.h"
#include <QPushButton>

//Teacher 类 老师类
//Student 类 学生类
//下课后，老师会触发一个信号，饿了，学生相应信号，请客吃饭

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建老师对象
    this->cc = new Teacher(this);

    //创建学生对象
    this->ll = new Student(this);

    // //老师饿了 学生请老师吃饭
    // connect(cc, &Teacher::hungry, ll, &Student::treat);

    // //调用下课函数
    // classIsOver();


    //连接带参数的信号和槽
    //指针->地址
    //函数指针->函数地址
    void(Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
    void(Student:: *studentSlot)(QString) = &Student::treat;
    connect(cc, teacherSignal, ll, studentSlot);

    //classIsOver();


    //点击一个下课的按钮再触发下课
    QPushButton * btn = new QPushButton("class over", this);

    //重置窗口大小
    resize(600,400);

    //点击按钮出发下课
    //connect(btn, &QPushButton::clicked, this, &Widget::classIsOver);


    //无参信号和槽连接
    void(Teacher:: *teacherSignal2)(void) = &Teacher::hungry;
    void(Student:: *studentSlot2)(void) = &Student::treat;
    connect(cc, teacherSignal2, ll, studentSlot2);

    //信号连接信号
    connect(btn, &QPushButton::clicked, cc, teacherSignal2);

    //断开信号
    //disconnect(cc, teacherSignal2, ll, studentSlot2)

    // QPushButton * btn2 = new QPushButton;

    // [btn](){
    //     btn->setText("aaa");
    //     btn2->setText("bbb");//btn2看不到
    // }();


    //利用lambda表达式实现点击按钮关闭窗口
    QPushButton * btn2 = new QPushButton;
    btn2->setText("close");
    btn2->move(100,0);
    btn2->setParent(this);

    connect(btn2, &QPushButton::clicked, this, [=](){
        this->close();
        emit cc->hungry("sandwich");

        //btn2->setText("aaa");
    });

}

void Widget::classIsOver()
{
    //下课函数 调用后 触发老师饿了的信号
    //emit cc->hungry();
    emit cc->hungry("sandwich");
}

Widget::~Widget()
{
    delete ui;
}
