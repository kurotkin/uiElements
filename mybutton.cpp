#include "mybutton.h"
#include <QPainter>
#include <QMouseEvent>

MyButton::MyButton(QWidget *parent) : QWidget(parent), str("")
{

}

void MyButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QLinearGradient linearGradient(0, 0, 100, 100);
    linearGradient.setColorAt(0.0, Qt::white);
    linearGradient.setColorAt(0.2, Qt::green);
    linearGradient.setColorAt(1.0, Qt::black);
    painter.setBrush(linearGradient);

    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(rect(), 10, 10);

    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 12));
    painter.drawText(rect().adjusted(0, 0, 0, 0), Qt::AlignVCenter | Qt::AlignCenter, str);
}

QString MyButton::text() const
{
    return str;
}

void MyButton::setText(QString text)
{
    str = text;
    update();
}

void MyButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        click();
    }
}
