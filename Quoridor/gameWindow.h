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

class gameWindow : public QWidget
{
    Q_OBJECT
public:
    explicit gameWindow(Game *myGame, QWidget *parent = 0);

signals:

public slots:
    void movementN();
    void movementS();
private:
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
    QGridLayout *wallPannel;
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

    void displayGrid();
    void displayInfos();
    void displayMoves();
};

#endif // GAMEWINDOW_H
