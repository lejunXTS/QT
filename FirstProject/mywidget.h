#ifndef MYWIDGET_H //防止头文件重复包含
#define MYWIDGET_H

#include <QWidget>//包含QWidget 窗口类

class myWidget : public QWidget
{
    Q_OBJECT //Q_OBJECT宏，允许类中使用信号和槽的机制

public:
    myWidget(QWidget *parent = nullptr);//构造函数
    ~myWidget();//析构函数
};
#endif // MYWIDGET_H
