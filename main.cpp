#include "mainwindow.h"

#include <QApplication>
#include <QVBoxLayout>
#include "mybutton.h"
#include "progressbar.h"
#include "myswitch.h"
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget window;

    QVBoxLayout layout(&window);

    // Button
    MyButton* myButton = new MyButton();
    myButton -> setFixedSize(100, 50);
    myButton -> setText("My Button");
    QApplication::connect(myButton, &MyButton::click, [](){ qDebug()<<"clicked"; });
    layout.addWidget(myButton);

    // Progress Bar
    ProgressBar* progressBar = new ProgressBar();
    progressBar -> setFixedSize(50, 50);
    layout.addWidget(progressBar);

    // Switch
    MySwitch* mySwitch = new MySwitch();
    mySwitch -> setFixedSize(50, 25);
    QApplication::connect(mySwitch, &MySwitch::switchOn, [](){ qDebug()<<"switch on"; });
    QApplication::connect(mySwitch, &MySwitch::switchOff, [](){ qDebug()<<"switch off"; });
    layout.addWidget(mySwitch);


    window.show();

    return a.exec();
}
