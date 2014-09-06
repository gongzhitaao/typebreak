#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    countdown = QTime(0, 10, 0);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);

    showTime();

    setWindowState(Qt::WindowFullScreen);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showTime()
{
    countdown = countdown.addSecs(-1);
    QString text = countdown.toString("mm:ss");
    if ((countdown.second() % 2) == 0)
        text[2] = ' ';
    ui->lcdNumber->display(text);

    if (QTime(0, 0) == countdown) {
        timer->stop();
        close();
    }
}
