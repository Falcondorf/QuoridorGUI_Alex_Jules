#include "gameWindow.h"
#include <iostream>
#include <QFont>
using namespace nvs;
void gameWindow::declareVars(){
    double sizeCase= 1400/(3*gameGUI_->getSizeGame()-1);

    /*-------------Pixmap----------------------*/



    QPixmap framePlayer("pic/woodenFrame_Player[1].png");
    framePlayer = framePlayer.scaled(sizeCase,sizeCase,Qt::KeepAspectRatio);
    QPixmap framePlayer2("pic/woodenFrame_Player[2].png");
    framePlayer2 = framePlayer2.scaled(sizeCase,sizeCase,Qt::KeepAspectRatio);
    QPixmap framePlayer3("pic/woodenFrame_Player[3].png");
    framePlayer3 = framePlayer3.scaled(sizeCase,sizeCase,Qt::KeepAspectRatio);
    QPixmap framePlayer4("pic/woodenFrame_Player[4].png");
    framePlayer4 = framePlayer4.scaled(sizeCase,sizeCase,Qt::KeepAspectRatio);


    /*-------------label rempli----------------*/

     labelP1  = new QLabel();
     labelP1->setPixmap(framePlayer);
     labelP1->setMaximumSize(QSize(sizeCase,sizeCase));
     labelP1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

     labelP2  = new QLabel();
     labelP2->setPixmap(framePlayer2);
     labelP2->setMaximumSize(QSize(sizeCase,sizeCase));
     labelP2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

     labelP3  = new QLabel();
     labelP3->setPixmap(framePlayer3);
     labelP3->setMaximumSize(QSize(sizeCase,sizeCase));
     labelP3->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

     labelP4  = new QLabel();
     labelP4->setPixmap(framePlayer4);
     labelP4->setMaximumSize(QSize(sizeCase,sizeCase));
     labelP4->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);



}


void gameWindow::declareWall(){
    double sizeCase= 1400/(3*gameGUI_->getSizeGame()-1);
    QPixmap wall("pic/wallFrame.jpg");
    wall = wall.scaled(270,270,Qt::KeepAspectRatio);

    label2  = new QLabel();
    label2->setPixmap(wall);
    label2->setMaximumSize(QSize(sizeCase/3,sizeCase/3));
    if (cbVertical->isChecked()){

        for (int i = 1; i <=2; i++){
            label4  = new QLabel();
            label4->setPixmap(wall);
            label4->setMaximumSize(QSize(sizeCase/3,sizeCase));
        }
    }else{

        for (int i=1; i<=2;i++){
            label3  = new QLabel();
            label3->setPixmap(wall);
            label3->setMaximumSize(QSize(sizeCase,sizeCase/3));
        }
    }

}


void gameWindow::declareVide()
{
    double sizeCase= 1400/(3*gameGUI_->getSizeGame()-1);

    QPixmap woodenFrame("pic/woodenFrame.jpg");
    woodenFrame = woodenFrame.scaled(sizeCase,sizeCase,Qt::KeepAspectRatio);

    labelP = new QLabel();
    labelP->setPixmap(woodenFrame);
    labelP->setMaximumSize(sizeCase, sizeCase);
    labelP->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);


    QPixmap wallE("pic/woodBackground.jpg");
    wallE = wallE.scaled(270,270,Qt::KeepAspectRatio);
    label5  = new QLabel();
    label5->setPixmap(wallE);
    label5->setMaximumSize(QSize(sizeCase/3,sizeCase/3));

    label6  = new QLabel();
    label6->setPixmap(wallE);
    label6->setMaximumSize(QSize(sizeCase,sizeCase/3));

    label7  = new QLabel();
    label7->setPixmap(wallE);
    label7->setMaximumSize(QSize(sizeCase/3,sizeCase));
}

void gameWindow::displayGrid()
{
    double sizeCase= 1400/(3*gameGUI_->getSizeGame()-1);
    declareVars();
    int width = (gameGUI_->getSizeGame()*2)-1;
    for(int i=0;i<width+1;i++){
        for(int j=0;j<width+1;j++){

            /*-------------label vide----------------*/

            declareVide();


                if(i%2==0 && j%2==0&& (i!= width && j!= width)){
                    boardGUI_->addWidget(labelP,i,j);
                }
                if(i%2!=0 && j%2!=0 && (i!= width && j!= width) ){
                    boardGUI_->addWidget(label5,i,j);
                }
                if(i%2==0 && j%2!=0 && (i!= width && j!= width)){
                    boardGUI_->addWidget(label7,i,j);
                }
                if(i%2!=0 && j%2==0 && (i!= width && j!= width)){
                    boardGUI_->addWidget(label6,i,j);
                }

                if(i==width && j%2!=0){
                    QLabel *indicej = new QLabel();
                    QString s = QString::number(j);
                    indicej->setText(s);
                    QFont font = indicej->font();
                    font.setPointSize(sizeCase/5);
                    indicej->setFont(font);
                    boardGUI_->addWidget(indicej,i,j);
                }
                if(j==width && i%2!=0){
                    QLabel *indicei = new QLabel();
                    QString s = QString::number(i);
                    indicei->setText(s);
                    QFont font = indicei->font();
                    font.setPointSize(sizeCase/5);
                    indicei->setFont(font);
                    boardGUI_->addWidget(indicei,i,j);



//                    font.setPointSize(72);
//                    font.setBold(true);
//                    label1->setFont(font);

                }
        }
    }
    /*---------Disposition des pièces------------------*/

    for(int i=0;i<width;i++){
        for(int j=0;j<width;j++){
                if(i%2==0 && j%2==0){
                    if (gameGUI_->filledPos(i,j)){
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
                    /*if(i%2!=0 && j%2!=0){
                        boardGUI_->addWidget(label2,i,j);
                    }
                    if(i%2==0 && j%2!=0){
                        boardGUI_->addWidget(label4,i,j);
                    }
                    if(i%2!=0 && j%2==0){
                        boardGUI_->addWidget(label3,i,j);
                    }*/
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
    boardGUI_ = new QGridLayout(this);
    listInfo_ = new QVBoxLayout;
    gblistInfo_ = new QGroupBox;
    sbRow = new QSpinBox;
    //lRow = new QLabel("Row");
    sbCol = new QSpinBox;
    //lCol = new QLabel("Column");
    cbVertical = new QCheckBox("Vertical ?");
    pbPlace = new QPushButton("Place the wall");
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

    //declareVars();

    /*-------------Affichage de la grille--------------------------*/

    displayGrid();

    /*-------------Infos du joueurs(liste infos)-------------------*/

    displayInfos();

    /*-------------Mouvement de joueur-----------------------------*/

    displayMoves();

    /*-------------Placement de mur--------------------------------*/
    //wallPannel->setHorizontalSpacing(0);
    sbRow->setRange(1, gameGUI_->getSizeGame()*2-3);
    sbRow->setSingleStep(2);
    sbRow->setPrefix("Row: ");
    sbCol->setRange(1, gameGUI_->getSizeGame()*2-3);
    sbCol->setSingleStep(2);
    sbCol->setPrefix("Column: ");

    //wallPannel->addWidget(lRow, 0, 0);
    //wallPannel->addWidget(lCol, 0, 1);
    wallPannel->addWidget(sbRow, 1, 0);
    wallPannel->addWidget(sbCol, 1, 1);
    wallPannel->addWidget(cbVertical,2,0);
    wallPannel->addWidget(pbPlace,2,1);
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
    QObject::connect(btW, SIGNAL(clicked()), this, SLOT(movementW()));
    QObject::connect(btE, SIGNAL(clicked()), this, SLOT(movementE()));
    QObject::connect(btNW, SIGNAL(clicked()), this, SLOT(movementNW()));
    QObject::connect(btSW, SIGNAL(clicked()), this, SLOT(movementSW()));
    QObject::connect(btSE, SIGNAL(clicked()), this, SLOT(movementSE()));
    QObject::connect(btNE, SIGNAL(clicked()), this, SLOT(movementNE()));
    QObject::connect(pbPlace, SIGNAL(clicked()), this, SLOT(placeWall()));

    gameGUI_->registerObserver(this);

}
//gameWindow::~gameWindow(){
//    gameGUI_->unregisterObserver(this);
//}

void gameWindow::update(const Subject *subject){
    end = new QLabel();
    if (subject!=gameGUI_) return;
    if (gameGUI_->getPlayer(gameGUI_->getCurrentPlayer()).getWallstock()==0
            && gameGUI_->possiblePositions().empty()){
        end->setText("Match Nul !");
        end->setAlignment(Qt::AlignCenter);
        end->setMaximumSize(100, 50);
        end->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        end->show();

        this->close();
    }
    else if (gameGUI_->isOver()){
        QString str= QString::fromUtf8(gameGUI_->getPlayer(gameGUI_->getCurrentPlayer()).getName().c_str());
        end->setText(str+" a gagné !");
        end->setAlignment(Qt::AlignCenter);
        end->resize(250, 70);
        end->setMinimumSize(250, 70);
        end->setMaximumSize(500, 250);
        end->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        end->show();

        this->close();
    }
    displaceLabel();
    displayInfos();
    displayMoves();
    if(wallPlaceble){
        if (cbVertical->isChecked() ){
                declareWall();
                boardGUI_->addWidget(label4,sbRow->value()-1, sbCol->value());
                boardGUI_->addWidget(label2,sbRow->value(), sbCol->value());
                declareWall();
                boardGUI_->addWidget(label4,sbRow->value()+1, sbCol->value());
        }else {
                declareWall();
                boardGUI_->addWidget(label3,sbRow->value(), sbCol->value()+1);
                boardGUI_->addWidget(label2,sbRow->value(), sbCol->value());
                declareWall();
                boardGUI_->addWidget(label3,sbRow->value(), sbCol->value()-1);
        }
    }
}


void gameWindow::displaceLabel()
{
    unsigned previousP = (gameGUI_->getCurrentPlayer()-1)%gameGUI_->getNbP();
    if (previousP==0){
        previousP = gameGUI_->getNbP();
    }
    unsigned iP = gameGUI_->getPlayer(previousP).getPos().first;
    unsigned jP = gameGUI_->getPlayer(previousP).getPos().second;

    switch (previousP){
    case 1:
           boardGUI_->addWidget(labelP1,iP, jP);
        break;
    case 2:
           boardGUI_->addWidget(labelP2,iP,jP);
        break;
    case 3:

           boardGUI_->addWidget(labelP3,iP,jP);
        break;
    case 4:

           boardGUI_->addWidget(labelP4,iP,jP);
        break;
    }
}

//void gameWindow::movement(Side side){
//    gameGUI_->move(side);
//}

void gameWindow::movementN(){

    gameGUI_->move(Side::North);

}

void gameWindow::movementS(){

    gameGUI_->move(Side::South);

}
void gameWindow::movementW(){

    gameGUI_->move(Side::West);


}
void gameWindow::movementE(){

    gameGUI_->move(Side::East);

}
void gameWindow::movementNW(){

    gameGUI_->move(Side::NorthWest);

}
void gameWindow::movementSE(){

    gameGUI_->move(Side::SouthEast);



}
void gameWindow::movementNE(){

    gameGUI_->move(Side::NorthEast);

}
void gameWindow::movementSW(){

    gameGUI_->move(Side::SouthWest);

}
void gameWindow::placeWall(){
    try{


        wallPlaceble = gameGUI_->wallPlacable(sbRow->value(), sbCol->value(), cbVertical->isChecked());
        gameGUI_->playWall(sbRow->value(), sbCol->value(), cbVertical->isChecked());


    }catch(std::exception & e){
        std::cout << e.what() << std::endl;
    }

}
