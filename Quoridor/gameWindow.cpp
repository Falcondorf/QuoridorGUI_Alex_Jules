#include "gameWindow.h"
#include <iostream>
using namespace std;
gameWindow::gameWindow(Game *myGame, QWidget *parent) :QWidget(parent),gameGUI_(myGame){


    root_ = new QHBoxLayout(this);
    boardGUI_ = new QGridLayout();
    listInfo_ = new QVBoxLayout();
    gblistInfo_ = new QGroupBox();

    double sizeCase= 1000/(3*gameGUI_->getSizeGame()-1);
    int width = (gameGUI_->getSizeGame()*2)-1;

    QPixmap woodenFrame("pic/woodenFrame.jpg");
    woodenFrame = woodenFrame.scaled(sizeCase,sizeCase,Qt::KeepAspectRatio);
    QPixmap wall("pic/wallFrame.jpg");
    wall = wall.scaled(200,200,Qt::KeepAspectRatio);
    QPixmap framePlayer("pic/woodenFrame_Player[1].jpg");
    framePlayer = framePlayer.scaled(sizeCase,sizeCase,Qt::KeepAspectRatio);
    QPixmap framePlayer2("pic/woodenFrame_Player[2].jpg");
    framePlayer2 = framePlayer2.scaled(sizeCase,sizeCase,Qt::KeepAspectRatio);
    QPixmap framePlayer3("pic/woodenFrame_Player[3].jpg");
    framePlayer3 = framePlayer3.scaled(sizeCase,sizeCase,Qt::KeepAspectRatio);
    QPixmap framePlayer4("pic/woodenFrame_Player[4].jpg");
    framePlayer4 = framePlayer4.scaled(sizeCase,sizeCase,Qt::KeepAspectRatio);
    QPixmap wallE("pic/woodBackground.jpg");
    wallE = wallE.scaled(200,200,Qt::KeepAspectRatio);

    for (int i=0;i<width;i++){
        for(int j=0;j<width;j++){

            /*-------------label rempli ---------------*/

             QLabel *labelP1  = new QLabel();
             labelP1->setPixmap(framePlayer);
             labelP1->setMaximumSize(QSize(sizeCase,sizeCase));
             labelP1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

             QLabel *labelP2  = new QLabel();
             labelP2->setPixmap(framePlayer2);
             labelP2->setMaximumSize(QSize(sizeCase,sizeCase));
             labelP2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

             QLabel *labelP3  = new QLabel();
             labelP3->setPixmap(framePlayer3);
             labelP3->setMaximumSize(QSize(sizeCase,sizeCase));
             labelP3->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

             QLabel *labelP4  = new QLabel();
             labelP4->setPixmap(framePlayer4);
             labelP4->setMaximumSize(QSize(sizeCase,sizeCase));
             labelP4->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

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
             labelP->setPixmap(woodenFrame);
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
                     switch (gameGUI_->getNum(i,j)){
                     case 1:
                            boardGUI_->addWidget(labelP1,i,j);
                         break;
                     case 2:
                            boardGUI_->addWidget(labelP2,i,j);
                         break;
                     case 3:
                            boardGUI_->addWidget(labelP3,i,j);
                         break;
                     case 4:
                            boardGUI_->addWidget(labelP4,i,j);
                         break;
                     }
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
                    boardGUI_->addWidget(labelP,i,j);
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
    nameP->setText("name of the player : "+QString::fromStdString(
                       gameGUI_->getPlayer(gameGUI_->getCurrentPlayer()).getName()));
    nameP->setAlignment(Qt::AlignHCenter);
    nbWall = new QLabel();
    nbWall->setText("number of walls : "+QString::number(
                        gameGUI_->getPlayer(gameGUI_->getCurrentPlayer()).getWallstock()));
    nbWall->setAlignment(Qt::AlignHCenter);
    sideObj = new QLabel();
    sideObj->setText("Goal to reach : "+QString::fromStdString
                     (toString(gameGUI_->getPlayer(gameGUI_->getCurrentPlayer()).getObjective())));
    sideObj->setAlignment(Qt::AlignHCenter);
    listInfo_->addWidget(nameP);
    listInfo_->addWidget(nbWall);
    listInfo_->addWidget(sideObj);

    gblistInfo_->setTitle("Current player infos");
    gblistInfo_->setLayout(listInfo_);
    gblistInfo_->setMaximumHeight(200);

    root_->setSizeConstraint(QLayout::SetFixedSize);
    root_->setSpacing(0);
    root_->addLayout(boardGUI_);
    root_->addSpacing(10);
    root_->addWidget(gblistInfo_);

}


