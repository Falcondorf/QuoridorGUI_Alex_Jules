#include "gameWindow.h"
#include <iostream>
using namespace std;
gameWindow::gameWindow(Game *myGame, QWidget *parent) :QWidget(parent),gameGUI_(myGame){


    root_ = new QHBoxLayout();
    boardGUI_ = new QGridLayout();
    listInfo_ = new QVBoxLayout();


        cout<< gameGUI_->getSizeGame() << endl;
        double sizeCase= 1000/(3*gameGUI_->getSizeGame()-1);
        int width = (gameGUI_->getSizeGame()*2)-1;

        QPixmap woodenFrame("pic/woodenFrame.jpg");
        QPixmap wall("pic/wallFrame.jpg");
        QPixmap frameNoPlayer("pic/woodenFrame_Player.jpg");
        QPixmap wallE("pic/woodBackground.jpg");

        for (int i=0;i<width;i++){
            for(int j=0;j<width;j++){

                /*-------------label rempli ---------------*/
                 QLabel *label  = new QLabel();
                 label->setPixmap(woodenFrame);
                 label->setMaximumSize(QSize(sizeCase,sizeCase));

                 QLabel *label2  = new QLabel();
                 label2->setPixmap(wall);
                 label2->setMaximumSize(QSize(sizeCase/3,sizeCase/3));

                 QLabel *label3  = new QLabel();
                 label3->setPixmap(wall);
                 label3->setMaximumSize(QSize(sizeCase,sizeCase/3));

                 QLabel *label4  = new QLabel();
                 label4->setPixmap(wall);
                 label4->setMaximumSize(QSize(sizeCase/3,sizeCase));

                 /*-------------label vide ---------------*/

                 QLabel *labelP = new QLabel();
                 labelP->setPixmap(frameNoPlayer);
                 labelP->setMaximumSize(sizeCase, sizeCase);


                 QLabel *label5  = new QLabel();
                 label5->setPixmap(wallE);
                 label5->setMaximumSize(QSize(sizeCase/3,sizeCase/3));

                 QLabel *label6  = new QLabel();
                 label6->setPixmap(wallE);
                 label6->setMaximumSize(QSize(sizeCase,sizeCase/3));

                 QLabel *label7  = new QLabel();
                 label7->setPixmap(wallE);
                 label7->setMaximumSize(QSize(sizeCase/3,sizeCase));

                if (gameGUI_->filledPos(i,j)){
                     if(i%2==0 && j%2==0){
                         boardGUI_->addWidget(labelP,i,j);
                     }
                     if(i%2!=0 && j%2!=0){
                         boardGUI_->addWidget(label2,i,j);
                     }
                     if(i%2==0 && j%2!=0){
                         boardGUI_->addWidget(label4,i,j);
                     }
                     if(i%2!=0 && j%2==0){
                         boardGUI_->addWidget(label3,i,j);
                     }
                }else{
                    if(i%2==0 && j%2==0){
                        boardGUI_->addWidget(label,i,j);
                    }
                    if(i%2!=0 && j%2!=0){
                        boardGUI_->addWidget(label5,i,j);
                    }
                    if(i%2==0 && j%2!=0){
                        boardGUI_->addWidget(label7,i,j);
                    }
                    if(i%2!=0 && j%2==0){
                        boardGUI_->addWidget(label6,i,j);
                    }
                }

            }
        }
        boardGUI_->setSizeConstraint(QLayout::SetFixedSize);
        boardGUI_->setSpacing(0);
        root_->addLayout(boardGUI_);
        root_->addLayout(listInfo_);

}


