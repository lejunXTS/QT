#include "student.h"
#include <QDebug>

Student::Student(QObject *parent)
    : QObject{parent}
{}

void Student::treat()
{
    qDebug() << "please eat teacher";
}


void Student::treat(QString foodName)
{
    //QString->char *  先转成QByteArray (.toUtf8())  再转成char * ()
    qDebug() << "please eat teacher: " << foodName.toUtf8().data();
}
