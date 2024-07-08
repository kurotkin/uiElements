#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>

class MyButton : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText)

public:
    MyButton(QWidget *parent = nullptr);
    QString text() const;

public slots:
    void setText(QString text);

signals:
    void click();

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

private:
    QString str;

};

#endif // MYBUTTON_H
