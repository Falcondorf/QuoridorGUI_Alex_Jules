#include "mainwindow.h"
#include "game.h"
#include <QApplication>
#include <qgridlayout.h>
#include <qlabel.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Game myGame ("name1","name2",5);
    int width = 5;

    QPixmap Image;
    Image.load("rire.jpg");

    QLabel i_label;
    i_label.setPixmap(Image);
    QLabel* label  = new QLabel("Image Size:");

    QGridLayout* gl = new QGridLayout(&w);
    gl->addWidget(label);

    w.setLayout(gl);
    w.show();

    return a.exec();
}
