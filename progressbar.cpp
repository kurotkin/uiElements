#include "progressbar.h"
#include <QPainter>
#include <QPixmapCache>

ProgressBar::ProgressBar(QWidget *parent) :
    QWidget(parent),
    mInnerRadius(0.6),
    mOuterRadius(1.0),
    mColor(12,255,102),
    mInfiniteAnimation(this, "infiniteAnimationValue"),
    mInfiniteAnimationValue(0.0)
{
  mInfiniteAnimation.setLoopCount(-1);
  mInfiniteAnimation.setDuration(1000);
  mInfiniteAnimation.setStartValue(0.0);
  mInfiniteAnimation.setEndValue(1.0);
  mInfiniteAnimation.start();
}

qreal ProgressBar::innerRadius() const
{
  return mInnerRadius;
}

qreal ProgressBar::outerRadius() const
{
  return mOuterRadius;
}

QColor ProgressBar::color() const
{
  return mColor;
}

void ProgressBar::setInnerRadius(qreal innerRadius)
{
  if(innerRadius > 1.0) innerRadius = 1.0;
  if(innerRadius < 0.0) innerRadius = 0.0;

  if(mInnerRadius != innerRadius)
  {
      mInnerRadius = innerRadius;
      update();
  }
}

void ProgressBar::setOuterRadius(qreal outerRadius)
{
  if(outerRadius > 1.0) outerRadius = 1.0;
  if(outerRadius < 0.0) outerRadius = 0.0;

  if(mOuterRadius != outerRadius)
  {
      mOuterRadius = outerRadius;
      update();
  }
}

void ProgressBar::setColor(QColor color)
{
  if(color != mColor)
  {
      mColor = color;
      update();
  }
}

QRectF squared(QRectF rect)
{
  if(rect.width() > rect.height())
  {
      qreal diff = rect.width() - rect.height();
      return rect.adjusted(diff/2, 0, -diff/2, 0);
  }
  else
  {
      qreal diff = rect.height() - rect.width();
      return rect.adjusted(0, diff/2, 0, -diff/2);
  }
}

void ProgressBar::paintEvent(QPaintEvent *)
{
  QPixmap pixmap;
  pixmap = generatePixmap();
  QPainter painter(this);
  painter.drawPixmap( 0.5 * ( width() - pixmap.width() ), 0.5 * ( height() - pixmap.height() ), pixmap );
}

void ProgressBar::setInfiniteAnimationValue(qreal value)
{
  mInfiniteAnimationValue = value;
  update();
}

QPixmap ProgressBar::generatePixmap() const
{
  QPixmap pixmap(squared(rect()).size().toSize());
  pixmap.fill(QColor(0,0,0,0));
  QPainter painter(&pixmap);

  painter.setRenderHint(QPainter::Antialiasing, true);

  QRectF rect = pixmap.rect().adjusted(1,1,-1,-1);
  qreal margin = rect.width()*(1.0 - mOuterRadius)/2.0;
  rect.adjust(margin,margin,-margin,-margin);
  qreal innerRadius = mInnerRadius*rect.width()/2.0;

  painter.setBrush(QColor(225,225,225));
  painter.setPen(QColor(225,225,225));
  painter.drawPie(rect, 0, 360*16);

  painter.setBrush(mColor);
  painter.setPen(mColor);

  int startAngle = -mInfiniteAnimationValue * 360 * 16;
  int spanAngle = 0.15 * 360 * 16;
  painter.drawPie(rect, startAngle, spanAngle);

  painter.setBrush(QColor(255,255,255));
  painter.setPen(QColor(0,0,0, 60));
  painter.drawEllipse(rect.center(), innerRadius, innerRadius);

  painter.drawArc(rect, 0, 360*16);

  return pixmap;
}

qreal ProgressBar::infiniteAnimationValue() const
{
  return mInfiniteAnimationValue;
}
