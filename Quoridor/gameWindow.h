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

/*!
 * \brief gameWindow La classe définissant la fenetre du jeu.
 */
class gameWindow : public QWidget, nvs::Observer
{
    Q_OBJECT
public:
    /*!
      * \brief Constructeur de la fenêtre de jeu
      * \param myGame La partie créé qui sera gérée par la fenêtre de jeu
      * \param parent formulaireWindow, la fenêtre de formulaire
      */
     explicit gameWindow(Game *myGame, QWidget *parent = 0);
    /*!
      * \brief Méthode de mise à jour de l'affichage suite à l'observation du jeu.
      * \param subject Le jeu observé
      */
     virtual void update(const nvs::Subject *subject) override;
//    /*!
//      * \brief Le destructeur de
//      */
//     virtual ~gameWindow();

private slots:
    /*!
     * \brief Slot de connection sur le bouton de déplacement Nord
     */
    void movementN();
    /*!
     * \brief Slot de connection sur le bouton de déplacement Sud
     */
    void movementS();
    /*!
     * \brief Slot de connection sur le bouton de déplacement Ouest
     */
    void movementW();
    /*!
     * \brief Slot de connection sur le bouton de déplacement Est
     */
    void movementE();
    /*!
     * \brief Slot de connection sur le bouton de déplacement Nord est
     */
    void movementNE();
    /*!
     * \brief Slot de connection sur le bouton de déplacement Sud est
     */
    void movementSE();
    /*!
     * \brief Slot de connection sur le bouton de déplacement Nord ouest
     */
    void movementNW();
    /*!
     * \brief Slot de connection sur le bouton de déplacement Sud ouest
     */
    void movementSW();
    /*!
     * \brief Slot de connection entre les composante de placement de mur sur le bouton placer
     */
    void placeWall();


private:

    /*!
     * \brief Label affiché lorsue le jeu est terminé
     */
    QLabel *end;
    /*!
     * \brief Permet de déterminer si le mur doit ou non être affiché
     */
    bool isDisplayed =false;
    /*!
     * \brief Le moteur de jeu
     */
    Game *gameGUI_;
    /*!
     * \brief Layout en forme de grille représentant le plateau de jeu
     */
    QGridLayout *boardGUI_;
    /*!
     * \brief Layout permettant l'affichage des informations du joueurs courant
     */
    QVBoxLayout *listInfo_;
    /*!
     * \brief Le layout contenant l'affichage global
     */
    QHBoxLayout *root_;
    /*!
     * \brief Dans le layout infos, il s'agit du nom du joueur courant
     */
    QLabel *nameP;
    /*!
     * \brief Dans le layout infos, il s'agit du nombre de mur restant
     */
    QLabel *nbWall;
    /*!
     * \brief Dans le layout infos, il s'agit du côté que le joueur doit atteindre
     */
    QLabel *sideObj;
    /*!
     * \brief Groupbox disposant les infos du joueur courant
     */
    QGroupBox *gblistInfo_;
    //QLabel *lRow;
    /*!
     * \brief SpinBox permettant la séléction de la ligne où placer un mur
     */
    QSpinBox *sbRow;
    //QLabel *lCol;
    /*!
     * \brief SpinBox perettant la sélection de la colonne où placer un mur
     */
    QSpinBox *sbCol;
    /*!
     * \brief CheckBox permettant de définir si on place un mur verticalement ou non.
     */
    QCheckBox *cbVertical;
    QGridLayout *wallPannel;
    QPushButton *pbPlace;
    QGroupBox *wallOpt;
    bool simplebool;
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
