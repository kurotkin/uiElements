#include "myswitch.h"
#include <QPainter>
#include <QMouseEvent>

MySwitch::MySwitch(QWidget *parent): QAbstractButton(parent),
    h(16),
    mOpacity(0.000),
    mSwitch(false),
    m(3),
    thumbBrush("#d5d5d5")
{
    mAnim = new QPropertyAnimation(this, "offset", this);
    setOffset(h / 2);
    y = h / 2;
    setBrush(QColor(12,204,102));
}

MySwitch::MySwitch(const QBrush &brush, QWidget *parent) : QAbstractButton(parent),
    h(16),
    mSwitch(false),
    mOpacity(0.000),
    m(3),
    thumbBrush("#d5d5d5")
{
    mAnim = new QPropertyAnimation(this, "offset", this);
    setOffset(h / 2);
    y = h / 2;
    setBrush(brush);
}

void MySwitch::paintEvent(QPaintEvent *e) {
    QPainter p(this);
    p.setPen(Qt::NoPen);
    if (isEnabled()) {
        p.setBrush(mSwitch ? brush() : Qt::black);
        p.setOpacity(mSwitch ? 0.5 : 0.38);
        p.setRenderHint(QPainter::Antialiasing, true);
        p.drawRoundedRect(QRect(m, m, width() - 2 * m, height() - 2 * m), 8.0, 8.0);
        p.setBrush(thumbBrush);
        p.setOpacity(1.0);
        p.drawEllipse(QRectF(offset() - (h / 2), y - (h / 2), height(), height()));
    } else {
        p.setBrush(Qt::black);
        p.setOpacity(0.12);
        p.drawRoundedRect(QRect(m, m, width() - 2 * m, height() - 2 * m), 8.0, 8.0);
        p.setOpacity(1.0);
        p.setBrush(QColor("#BDBDBD"));
        p.drawEllipse(QRectF(offset() - (h / 2), y - (h / 2), height(), height()));
    }
}

void MySwitch::mouseReleaseEvent(QMouseEvent *e) {
    if (e -> button() & Qt::LeftButton) {
        mSwitch = mSwitch ? false : true;
        thumbBrush = mSwitch ? mBrush : QBrush("#d5d5d5");
        if (mSwitch) {
            switchOff();
            mAnim->setStartValue(h / 2);
            mAnim->setEndValue(width() - h);
            mAnim->setDuration(120);
            mAnim->start();
        } else {
            switchOn();
            mAnim->setStartValue(offset());
            mAnim->setEndValue(h / 2);
            mAnim->setDuration(120);
            mAnim->start();
        }
    }
    QAbstractButton::mouseReleaseEvent(e);
}

QSize MySwitch::sizeHint() const {
    return QSize(2 * (h + m), h + 2 * m);
}
