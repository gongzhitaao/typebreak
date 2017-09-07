#include "widget.h"
#include "ui_widget.h"

Widget::Widget(int duration, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    duration_(duration)
{
    ui->setupUi(this);

    countdown_ = QTime(0, duration_, 0);
    timer_ = new QTimer(this);
    connect(timer_, SIGNAL(timeout()), this, SLOT(showTime()));
    timer_->start(1000);

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
    countdown_ = countdown_.addSecs(-1);
    QString text = countdown_.toString("mm:ss");
    if ((countdown_.second() % 2) == 0)
        text[2] = ' ';
    ui->lcdNumber->display(text);

    if (QTime(0, 0) == countdown_) {
        timer_->stop();
        close();
    }
}
