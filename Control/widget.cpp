#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置单选按钮 男默认选中
    ui->radioButtonMan->setChecked(true);

    //选中女后打印信息
    connect(ui->radioButtonWoman, &QRadioButton::clicked, [=](){
        qDebug() << "select woman!";
    });


    //多选按钮   2是选中  0是未选中
    connect(ui->checkBox_4, &QCheckBox::stateChanged, [=](int state){
        qDebug() << state;
    });



    // //利用listWidget写诗
    // QListWidgetItem * item = new QListWidgetItem("人生天地间");

    // //将一行诗放入到listWidget控件中
    // ui->listWidget->addItem(item);

    // item->setTextAlignment(Qt::AlignCenter);


    //QStringList  QList<QString>
    QStringList list;
    list << "人生天地间" << "忽如远行客" << "斗酒相娱乐" << "聊厚不为薄";
    ui->listWidget->addItems(list);


}

Widget::~Widget()
{
    delete ui;
}
