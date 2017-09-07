#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTime>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(int duration, QWidget *parent = 0);
    ~Widget();

private slots:
    void showTime();

private:
    Ui::Widget *ui;

    QTime countdown_;
    QTimer *timer_;

    int duration_;
};

#endif // WIDGET_H
