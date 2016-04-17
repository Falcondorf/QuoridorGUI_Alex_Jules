#include "gameWindow.h"

void gameWindow::displayGrid()
{
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
}

void gameWindow::displayInfos()
{

    nameP->setText("name of the player : "+QString::fromStdString(
                       gameGUI_->getPlayer(gameGUI_->getCurrentPlayer()).getName()));
    nameP->setAlignment(Qt::AlignHCenter);

    nbWall->setText("number of walls : "+QString::number(
                        gameGUI_->getPlayer(gameGUI_->getCurrentPlayer()).getWallstock()));
    nbWall->setAlignment(Qt::AlignHCenter);

    sideObj->setText("Goal to reach : "+QString::fromStdString
                     (toString(gameGUI_->getPlayer(gameGUI_->getCurrentPlayer()).getObjective())));
    sideObj->setAlignment(Qt::AlignHCenter);
    listInfo_->addWidget(nameP);
    listInfo_->addWidget(nbWall);
    listInfo_->addWidget(sideObj);

    gblistInfo_->setTitle("Current player infos");
    gblistInfo_->setLayout(listInfo_);
    //gblistInfo_->setMaximumHeight(200);

}

void gameWindow::displayMoves()
{
    btN->setDisabled(true);
    btS->setDisabled(true);
    btW->setDisabled(true);
    btE->setDisabled(true);
    btNW->setDisabled(true);
    btNE->setDisabled(true);
    btSW->setDisabled(true);
    btSE->setDisabled(true);

    glRose->addWidget(btN,0,1);
    glRose->addWidget(btS,2,1);
    glRose->addWidget(btW,1,0);
    glRose->addWidget(btE,1,2);
    glRose->addWidget(btNE,0,2);
    glRose->addWidget(btNW,0,0);
    glRose->addWidget(btSW,2,0);
    glRose->addWidget(btSE,2,2);
    moveOpt->setTitle("Move");
    moveOpt->setLayout(glRose);
    //moveOpt->setMaximumHeight(200);

    for(Side s : gameGUI_->possiblePositions()){
        switch(s){
        case Side::North:
            btN->setEnabled(true);
            break;
        case Side::South:
            btS->setEnabled(true);
            break;
        case Side::West:
            btW->setEnabled(true);
            break;
        case Side::East:
            btE->setEnabled(true);
            break;
        case Side::NorthWest:
            btNW->setEnabled(true);
            break;
        case Side::NorthEast:
            btNE->setEnabled(true);
            break;
        case Side::SouthWest:
            btSW->setEnabled(true);
            break;
        case Side::SouthEast:
            btSE->setEnabled(true);
            break;
        }
    }
}

gameWindow::gameWindow(Game *myGame, QWidget *parent) :QWidget(parent),gameGUI_(myGame){
    root_ = new QHBoxLayout(this);
    nameP = new QLabel();
    nbWall = new QLabel();
    sideObj = new QLabel();
    boardGUI_ = new QGridLayout;
    listInfo_ = new QVBoxLayout;
    gblistInfo_ = new QGroupBox;
    sbRow = new QSpinBox;
    lRow = new QLabel("Row");
    sbCol = new QSpinBox;
    lCol = new QLabel("Column");
    wallPannel = new QGridLayout;
    wallOpt = new QGroupBox;
    btN = new QPushButton("North");

    btS = new QPushButton("South");

    btW = new QPushButton("West");

    btE = new QPushButton("East");

    btNW= new QPushButton("NorthWest");

    btNE= new QPushButton("NorthEast");

    btSW= new QPushButton("SouthWest");

    btSE= new QPushButton("SouthEast");

    glRose = new QGridLayout;
    moveOpt= new QGroupBox;
    rightPannel = new QVBoxLayout;

    /*-------------Affichage de la grille--------------------------*/

    displayGrid();

    /*-------------Infos du joueurs(liste infos)-------------------*/

    displayInfos();

    /*-------------Mouvement de joueur-----------------------------*/

    displayMoves();

    /*-------------Placement de mur--------------------------------*/
    //wallPannel->setHorizontalSpacing(0);
    sbRow->setMaximum(gameGUI_->getSizeGame());
    sbRow->setMinimum(0);
    sbCol->setMaximum(gameGUI_->getSizeGame());
    sbCol->setMinimum(0);
    wallPannel->addWidget(lRow, 0, 0);
    wallPannel->addWidget(lCol, 0, 1);
    wallPannel->addWidget(sbRow, 1, 0);
    wallPannel->addWidget(sbCol, 1, 1);
    wallOpt->setTitle("Place Wall");
    wallOpt->setLayout(wallPannel);

    rightPannel->addWidget(gblistInfo_);
    rightPannel->addWidget(moveOpt);
    rightPannel->addWidget(wallOpt);
    root_->setSizeConstraint(QLayout::SetFixedSize);
    root_->setSpacing(0);
    root_->addLayout(boardGUI_);
    root_->addSpacing(10);
    root_->addLayout(rightPannel);

    QObject::connect(btN, SIGNAL(clicked()), this, SLOT(movementN()));
    QObject::connect(btS, SIGNAL(clicked()), this, SLOT(movementS()));
}

void gameWindow::movementN(){

    gameGUI_->move(Side::North);

    displayGrid();

    displayInfos();

    displayMoves();

    this->show();
}

void gameWindow::movementS(){

    gameGUI_->move(Side::South);

    displayGrid();

    displayInfos();

    displayMoves();

    this->show();
}
