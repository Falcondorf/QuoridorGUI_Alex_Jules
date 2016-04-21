#ifndef FORMULAIREWINDOW_H
#define FORMULAIREWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QGroupBox>
#include "game.h"
#include "gameWindow.h"

/*!
 * \brief formulaireWindow La classe qui gère la fenetre de configuration du jeu.
 */
class formulaireWindow : public QWidget
{
    Q_OBJECT
public:
    /*!
     * \brief formulaireWindow constructeur de la fenetre de configuration du jeu.
     * \param parent la fenetre d'ouverture du jeu.
     */
    explicit formulaireWindow(QWidget *parent = 0);
signals:

public slots:
    /*!
     * \brief startGame Lance la fenetre de jeu et ferme le formulaire.
     */
    void startGame();
    /*!
     * \brief fourPlayerGame Affiche ou cache la possibilité d'entrer le nom
     *  des 4 joueurs au lieu de deux.
     */
    void fourPlayerGame();
private:
    /*!
     * \brief theGameWindow_ la fenetre de jeu.
     */
    gameWindow *theGameWindow_;
    /*!
     * \brief theGame_ le jeu lancé.
     */
    Game *theGame_;
    /*!
     * \brief superRoot_ VBox Possède tout les composant de la fenetre ainsi que le bouton.
     */
    QVBoxLayout *superRoot_;
    /*!
     * \brief root_  Possède tout les composant de la fenetre sauf le bouton de lancement.
     */
    QHBoxLayout *root_;
    /*!
     * \brief groupParam_ Possède les informations sur le nombre de joueur et la taille du plateau.
     */
    QVBoxLayout *groupParam_;
    /*!
     * \brief sbNbJ_ Défini le nombre de joueur.
     */
    QSpinBox *sbNbJ_;
    /*!
     * \brief lNbJ_ Label du nombre de joueur.
     */
    QLabel *lNbJ_;
    /*!
     * \brief sbSize_ Défini la taille du tableau.
     */
    QSpinBox *sbSize_;
    /*!
     * \brief lSize_ Label de la taille du tableau.
     */
    QLabel *lSize_;
    /*!
     * \brief leName1_ Le nom du premier joueur.
     */
    QLineEdit *leName1_;
    /*!
     * \brief lName1_ Le label du premier joueur.
     */
    QLabel *lName1_;
    /*!
     * \brief leName2_ Le nom du deuxième joueur.
     */
    QLineEdit *leName2_;
    /*!
     * \brief lName2_ Le label du deuxième joueur.
     */
    QLabel *lName2_;
    /*!
     * \brief leName3_ Le nom du troisième joueur.
     */
    QLineEdit *leName3_;
    /*!
     * \brief lName3_ Le label du troisième joueur.
     */
    QLabel *lName3_;
    /*!
     * \brief leName4_ Le nom du quatrième joueur.
     */
    QLineEdit *leName4_;
    /*!
     * \brief lName4_ Le label du quatrième joueur.
     */
    QLabel *lName4_;
    /*!
     * \brief fourPlayerGameBox_ Groupe reprenant toutes les elements
     * de la fenetres définissant le nom des joueurs.
     */
    QGroupBox *fourPlayerGameBox_;
    /*!
     * \brief startB_ Bouton lançant la fenetre du jeu.
     */
    QPushButton *startB_;


};

#endif // FORMULAIREWINDOW_H
