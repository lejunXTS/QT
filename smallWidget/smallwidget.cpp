#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SmallWidget)
{
    ui->setupUi(this);

    //QStringBox数字改变 QSlider跟着移动
    connect(ui->spinBox, &QSpinBox::valueChanged, ui->horizontalSlider, &QSlider::setValue);

    //QSlider滑动 QStringBox数字跟着改变
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}


//设置数字
void SmallWidget::setNumber(int num)
{
    ui->spinBox->setValue(num);
}

//获取数字
int SmallWidget::getNumber()
{
    return ui->spinBox->value();
}


SmallWidget::~SmallWidget()
{
    delete ui;
}
