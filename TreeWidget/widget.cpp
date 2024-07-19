#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //treeWidget控件的使用

    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList()<< "一" << "内容");

    //创建顶层节点
    QTreeWidgetItem * liTtem = new QTreeWidgetItem(QStringList()<< "一");
    QTreeWidgetItem * liTtem2 = new QTreeWidgetItem(QStringList()<< "二");

    //加载顶层节点
    ui->treeWidget->addTopLevelItem(liTtem);
    ui->treeWidget->addTopLevelItem(liTtem2);

    //追加子节点
    //QTreeWidgetItem * ll = new QTreeWidgetItem(QStringList()<< "一帆一江一渔舟"<<"一个渔翁一个钩");
    // QStringList first;
    // first << "一帆一江一渔舟，一个渔翁一个钩";
    // QTreeWidgetItem * ll = new QTreeWidgetItem(first);
    // liTtem->addChild(ll);


    // QStringList second;
    // second << "一俯一仰一场笑，一江明月一江秋";
    // QTreeWidgetItem * ll2 = new QTreeWidgetItem(second);
    // liTtem2->addChild(ll2);

    QTreeWidgetItem *childItem1 = new QTreeWidgetItem(QStringList() <<""<<"一帆一江一渔舟，一个渔翁一个钩");
    QTreeWidgetItem *childItem2 = new QTreeWidgetItem(QStringList() << ""<<"一俯一仰一场笑，一江明月一江秋");
    liTtem->addChild(childItem1);
    liTtem2->addChild(childItem2);



}

Widget::~Widget()
{
    delete ui;
}
