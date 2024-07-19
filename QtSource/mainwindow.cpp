#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->actionnew->setIcon(QIcon("D:/喜欢/罗小黑&其他/001VEnKKgy1gsu6mbym6vj60t41dan4j02.jpg"));

    //使用添加QT资源    ": + 前缀名 + 文件名"
    ui->actionnew->setIcon(QIcon(":/image/001VEnKKgy1gsu6mbym6vj60t41dan4j02.jpg"));
    ui->actionopen->setIcon(QIcon(":/image/005y0Ylbly1hhdrfsc6pbj32p51pinpe.jpg"));


}

MainWindow::~MainWindow()
{
    delete ui;
}
