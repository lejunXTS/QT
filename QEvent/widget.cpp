#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动定时器
    //参数1 间隔(单位 毫秒)
    id1 = startTimer(1000);

    id2 = startTimer(2000);

    //定时器的第二种方式
    QTimer * timer = new QTimer(this);
    //启动定时器
    timer->start(500);

    connect(timer, &QTimer::timeout, [=](){
        static int num = 1;

        //label_4每隔0.5秒+1
        ui->label_4->setText(QString::number(num++));
    });

    //点击暂停按钮 实现停止定时器
    connect(ui->dtn, &QPushButton::clicked, [=](){
        timer->stop();
    });



    //步骤一 安转事件过滤器
    //label 安装事件过滤器
    ui->label->installEventFilter(this);

}

//步骤二 重写事件过滤器的事件
bool Widget::eventFilter(QObject *obj, QEvent *e)
{
    if (obj == ui->label)
    {
        if (e->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent * ev = static_cast<QMouseEvent *>(e);
            QString str = QString("事件过滤器中 鼠标按下了 x = %1  y = %2  "
                                  "globalx = %3  globaly = %4").arg(ev->x()).arg(ev->y())
                              .arg(ev->globalX()).arg(ev->globalY());
            qDebug()<< str;

            return true;
        }
    }

    //其他默认处理
    return QWidget::eventFilter(obj,e);
}


//重写定时器的事件
void Widget::timerEvent(QTimerEvent *ev)
{
    if (ev->timerId() == id1)
    {
        static int num = 1;

        //label_2每隔1秒+1
        ui->label_2->setText(QString::number(num++));
    }

    if (ev->timerId() == id2)
    {
        //label_2每隔2秒+1
        static int num2 = 1;
        ui->label_3->setText(QString::number(num2++));
    }

}



Widget::~Widget()
{
    delete ui;
}
