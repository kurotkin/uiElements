#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <QObject>
#include <QWidget>
#include <QPropertyAnimation>

class ProgressBar : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(qreal innerRadius READ innerRadius WRITE setInnerRadius)
    Q_PROPERTY(qreal outerRadius READ outerRadius WRITE setOuterRadius)
    Q_PROPERTY(QColor color READ color WRITE setColor)
    Q_PROPERTY(qreal infiniteAnimationValue READ infiniteAnimationValue WRITE setInfiniteAnimationValue)

public:
    explicit ProgressBar(QWidget *parent = nullptr);
    qreal innerRadius() const;
    qreal outerRadius() const;
    QColor color() const;

public slots:
    void setInnerRadius(qreal innerRadius);
    void setOuterRadius(qreal outerRadius);
    void setColor(QColor color);

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void setInfiniteAnimationValue(qreal value);

private:
    QPixmap generatePixmap() const;
    qreal infiniteAnimationValue() const;

private:
    qreal mInnerRadius;
    qreal mOuterRadius;
    QColor mColor;

    QPropertyAnimation mInfiniteAnimation;
    qreal mInfiniteAnimationValue = 0.0;

};

#endif // PROGRESSBAR_H
