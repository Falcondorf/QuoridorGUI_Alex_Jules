#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "game.h"
#include <QGridLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>

class gameWindow : public QWidget
{
    Q_OBJECT
public:
    explicit gameWindow(Game *myGame, QWidget *parent = 0);

signals:

public slots:

private:
    Game *gameGUI_;
    QGridLayout *boardGUI_;
    QVBoxLayout *listInfo_;
    QHBoxLayout *root_;
    QLabel *nameP;
    QLabel *nbWall;
    QLabel *sideObj;
    QGroupBox *gblistInfo_;
};

#endif // GAMEWINDOW_H
