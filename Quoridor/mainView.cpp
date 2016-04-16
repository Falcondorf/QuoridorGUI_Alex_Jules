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
    int nbCase = 5;
    Game myGame ("name1","name2",nbCase);
    double sizeCase= 1000/(3*nbCase-1);
    int width = (nbCase*2)-1;

    QGridLayout* gl = new QGridLayout();
    for (int i=0;i<width;i++){

        for(int j=0;j<width;j++){
             QPixmap woodenFrame("pic/woodenFrame.jpg");
             QLabel *label  = new QLabel();
             label->setPixmap(woodenFrame);
             label->setMaximumSize(QSize(sizeCase,sizeCase));

             QPixmap wall("pic/wallFrame.jpg");
             QLabel *label2  = new QLabel();
             label2->setPixmap(wall);
             label2->setMaximumSize(QSize(sizeCase/3,sizeCase/3));

             QLabel *label3  = new QLabel();
             label3->setPixmap(wall);
             label3->setMaximumSize(QSize(sizeCase,sizeCase/3));

             QLabel *label4  = new QLabel();
             label4->setPixmap(wall);
             label4->setMaximumSize(QSize(sizeCase/3,sizeCase));

             /*----------------------------*/

             QPixmap frameNoPlayer("pic/woodenFrame_Player.jpg");
             QLabel *labelP = new QLabel();
             labelP->setPixmap(frameNoPlayer);
             labelP->setMaximumSize(sizeCase, sizeCase);

             QPixmap wallE("pic/woodBackground.jpg");
             QLabel *label5  = new QLabel();
             label5->setPixmap(wallE);
             label5->setMaximumSize(QSize(sizeCase/3,sizeCase/3));

             QLabel *label6  = new QLabel();
             label6->setPixmap(wallE);
             label6->setMaximumSize(QSize(sizeCase,sizeCase/3));

             QLabel *label7  = new QLabel();
             label7->setPixmap(wallE);
             label7->setMaximumSize(QSize(sizeCase/3,sizeCase));

            if (myGame.filledPos(i,j)){
                 if(i%2==0 && j%2==0){
                     gl->addWidget(labelP,i,j);
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
            }else{
                if(i%2==0 && j%2==0){
                    gl->addWidget(label,i,j);
                }
                if(i%2!=0 && j%2!=0){
                    gl->addWidget(label5,i,j);
                }
                if(i%2==0 && j%2!=0){
                    gl->addWidget(label7,i,j);
                }
                if(i%2!=0 && j%2==0){
                    gl->addWidget(label6,i,j);
                }
            }

        }
    }


    QWidget *widget=new QWidget();
    gl->setSizeConstraint(QLayout::SetFixedSize);
    gl->setSpacing(0);

    widget->setLayout(gl);
    //widget->setStyleSheet("background-image: pic/woodBackground.jpg");



   // w.setCentralWidget(label);
    //w.setCentralWidget(label2);

    widget->show();

    return a.exec();
}
