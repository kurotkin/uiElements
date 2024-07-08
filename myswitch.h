#ifndef MYSWITCH_H
#define MYSWITCH_H

#include <QObject>
#include <QWidget>
#include <QAbstractButton>
#include <QPropertyAnimation>

class MySwitch: public QAbstractButton {
    Q_OBJECT
    Q_PROPERTY(int offset READ offset WRITE setOffset)
    Q_PROPERTY(QBrush brush READ brush WRITE setBrush)

public:
    MySwitch(QWidget* parent = nullptr);
    MySwitch(const QBrush& brush, QWidget* parent = nullptr);

    QSize sizeHint() const override;

    QBrush brush() const {
        return mBrush;
    }
    void setBrush(const QBrush &brsh) {
        mBrush = brsh;
    }

    int offset() const {
        return x;
    }
    void setOffset(int o) {
        x = o;
        update();
    }

signals:
    void switchOn();
    void switchOff();

protected:
    void paintEvent(QPaintEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;

private:
    bool mSwitch;
    qreal mOpacity;
    int x, y, h, m;
    QBrush thumbBrush, trackBrush, mBrush;
    QPropertyAnimation* mAnim = nullptr;
};

#endif // MYSWITCH_H
