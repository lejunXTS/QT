#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

    //早起版本槽函数写在public slots下，5.4版本后写在public或者全局下
    //返回值void 需要声明 需要实现
    //可以有参数 可以重载
    void treat();

    void treat(QString foodName);

signals:

};

#endif // STUDENT_H
