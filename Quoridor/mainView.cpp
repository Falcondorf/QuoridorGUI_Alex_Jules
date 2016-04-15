#include "mainwindow.h"
#include "game.h"
#include <QApplication>
#include <qgridlayout.h>
#include <qlabel.h>
#include <qpainter.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    int nbCase = 19;
    Game myGame ("name1","name2",nbCase);
    double sizeCase= 1000/(3*nbCase-1);
    int width = (nbCase*2)-1;

    QGridLayout* gl = new QGridLayout();
    for (int i=0;i<width;i++){

        for(int j=0;j<width;j++){
             QPixmap woodenFrame("C:/Users/Pierre/Pictures/caseBois.jpg");
             QLabel *label  = new QLabel();
             label->setPixmap(woodenFrame);
             label->setMaximumSize(QSize(sizeCase,sizeCase));
             QPixmap wall("C:/Users/Pierre/Pictures/mur.jpg");
             QLabel *label2  = new QLabel();
             label2->setPixmap(wall);
             label2->setMaximumSize(QSize(sizeCase/3,sizeCase/3));

             QPixmap wallH("C:/Users/Pierre/Pictures/mur.jpg");
             QLabel *label3  = new QLabel();
             label3->setPixmap(wall);
             label3->setMaximumSize(QSize(sizeCase,sizeCase/3));

             QPixmap wallV("C:/Users/Pierre/Pictures/mur.jpg");
             QLabel *label4  = new QLabel();
             label4->setPixmap(wall);
             label4->setMaximumSize(QSize(sizeCase/3,sizeCase));


             if(i%2==0 && j%2==0){
                 gl->addWidget(label,i,j);
             }
             if(i%2!=0 && j%2!=0){
                 gl->addWidget(label2,i,j);
             }
             if(i%2==0 && j%2!=0){
                 gl->addWidget(label4,i,j);
             }
             if(i%2!=0 && j%2==0){
                 gl->addWidget(label3,i,j);
             }



        }
    }


    QWidget *widget=new QWidget();
    gl->setSizeConstraint(QLayout::SetFixedSize);
    gl->setSpacing(0);
    widget->setLayout(gl);




   // w.setCentralWidget(label);
    //w.setCentralWidget(label2);
    widget->show();

    return a.exec();
}
