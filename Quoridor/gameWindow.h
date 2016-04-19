#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "game.h"
#include <QGridLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QSpinBox>
#include <QPushButton>
#include <qcheckbox>
#include "observer.h"
#include "subject.h"


class gameWindow : public QWidget, nvs::Observer
{
    Q_OBJECT
public:
     explicit gameWindow(Game *myGame, QWidget *parent = 0);
     virtual void update(const nvs::Subject *subject) override;
     virtual ~gameWindow();

private slots:
    void movementN();
    void movementS();
    void movementW();
    void movementE();
    void movementNE();
    void movementSE();
    void movementNW();
    void movementSW();
    void placeWall();


private:


    QLabel *end;
    bool isDisplayed =false;
    Game *gameGUI_;
    QGridLayout *boardGUI_;
    QVBoxLayout *listInfo_;
    QHBoxLayout *root_;
    QLabel *nameP;
    QLabel *nbWall;
    QLabel *sideObj;
    QGroupBox *gblistInfo_;
    QLabel *lRow;
    QSpinBox *sbRow;
    QLabel *lCol;
    QSpinBox *sbCol;
    QCheckBox *cbVertical;
    QGridLayout *wallPannel;
    QPushButton *pbPlace;
    QGroupBox *wallOpt;

    QPushButton *btN;
    QPushButton *btS;
    QPushButton *btW;
    QPushButton *btE;
    QPushButton *btNW;
    QPushButton *btNE;
    QPushButton *btSW;
    QPushButton *btSE;
    QGridLayout *glRose;
    QGroupBox *moveOpt;
    QVBoxLayout *rightPannel;


    QLabel *labelP;
    QLabel *labelPCopy;
    QLabel *labelP1;
    QLabel *labelP2;
    QLabel *labelP3;
    QLabel *labelP4;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *label5;
    QLabel *label6;
    QLabel *label7;

    void declareVars();
    void declareWall();
    void displayGrid();
    void displayInfos();
    void displayMoves();
    void displaceLabel();
    void declareVide();
};

#endif // GAMEWINDOW_H
