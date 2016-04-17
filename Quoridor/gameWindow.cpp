#include "gameWindow.h"
#include <iostream>
using namespace std;
gameWindow::gameWindow(Game *myGame, QWidget *parent) :QWidget(parent),gameGUI_(myGame){


    root_ = new QHBoxLayout(this);
    boardGUI_ = new QGridLayout(this);
    listInfo_ = new QVBoxLayout(this);

    double sizeCase= 1000/(3*gameGUI_->getSizeGame()-1);
    int width = (gameGUI_->getSizeGame()*2)-1;

    QPixmap woodenFrame("pic/woodenFrame.jpg");
    woodenFrame = woodenFrame.scaled(sizeCase,sizeCase,Qt::KeepAspectRatio);
    QPixmap wall("pic/wallFrame.jpg");
    wall = wall.scaled(200,200,Qt::KeepAspectRatio);
    QPixmap frameNoPlayer("pic/woodenFrame_Player.jpg");
    frameNoPlayer = frameNoPlayer.scaled(sizeCase,sizeCase,Qt::KeepAspectRatio);
    QPixmap wallE("pic/woodBackground.jpg");
    wallE = wallE.scaled(200,200,Qt::KeepAspectRatio);

    for (int i=0;i<width;i++){
        for(int j=0;j<width;j++){

            /*-------------label rempli ---------------*/
             QLabel *label  = new QLabel();
             label->setPixmap(woodenFrame);
             label->setMaximumSize(QSize(sizeCase,sizeCase));
             label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

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
             labelP->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

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
    /*-------------Infos du joueurs(liste infos)-------------------*/
    //QString::fromStdString(str)

    nameP = new QLabel();
    nameP->setText(QString::fromStdString(
                       gameGUI_->getPlayer(gameGUI_->getCurrentPlayer()).getName()));
    nameP->setAlignment(Qt::AlignHCenter);
    nbWall = new QLabel();
    nbWall->setText(QString::number(
                        gameGUI_->getPlayer(gameGUI_->getCurrentPlayer()).getWallstock()));
    nbWall->setAlignment(Qt::AlignHCenter);
    sideObj = new QLabel();
    sideObj->setText(QString::fromStdString
                     (toString(gameGUI_->getPlayer(gameGUI_->getCurrentPlayer()).getObjective())));
    sideObj->setAlignment(Qt::AlignHCenter);
    listInfo_->addWidget(nameP);
    listInfo_->addWidget(nbWall);
    listInfo_->addWidget(sideObj);

    root_->setSizeConstraint(QLayout::SetFixedSize);
    root_->setSpacing(0);
    root_->addLayout(boardGUI_);
    root_->addSpacing(10);
    root_->addLayout(listInfo_);

}


