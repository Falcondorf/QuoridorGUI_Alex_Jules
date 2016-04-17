#include "formulaireWindow.h"


formulaireWindow::formulaireWindow(QWidget *parent) :QWidget(parent){
    superRoot_ = new QVBoxLayout(this);
    root_ = new QHBoxLayout(this);
    groupParam_ = new QVBoxLayout(this);
    sbNbJ_ = new QSpinBox(this);
    lNbJ_ = new QLabel(this);
    sbSize_ = new QSpinBox(this);
    lSize_ = new QLabel(this);
    leName1_ = new QLineEdit(this);
    leName2_ = new QLineEdit(this);
    leName3_ = new QLineEdit(this);
    leName4_ = new QLineEdit(this);
    fourPlayerGameBox_ = new QGroupBox(tr("Jeux à 4"));
    lNbJ_->setText("Nb joueurs");
    sbNbJ_->setRange(2,4);
    sbNbJ_->setSingleStep(2);


    lSize_->setText("Taille de plateau");
    sbSize_->setRange(5,19);
    sbSize_->setSingleStep(2);

    leName1_->setPlaceholderText("Nom Joueur 1");
    leName2_->setPlaceholderText("Nom Joueur 2");
    leName3_->setPlaceholderText("Nom Joueur 3");
    leName4_->setPlaceholderText("Nom Joueur 4");

    QVBoxLayout *vb2J = new QVBoxLayout(this);
    vb2J->addWidget(leName1_);
    vb2J->addWidget(leName2_);
    QVBoxLayout *vb4J = new QVBoxLayout(this);
    vb4J->addWidget(leName3_);
    vb4J->addWidget(leName4_);

    fourPlayerGameBox_->setLayout(vb4J);

    groupParam_->addWidget(lNbJ_);
    groupParam_->addWidget(sbNbJ_);
    groupParam_->addWidget(lSize_);
    groupParam_->addWidget(sbSize_);

    root_->addLayout(groupParam_);
    root_->addLayout(vb2J);
    root_->addWidget(fourPlayerGameBox_);
    startB_ = new QPushButton(tr("START"));
    startB_->setMaximumSize(100, 50);
    superRoot_->addLayout(root_);
    superRoot_->addWidget(startB_);

    QObject::connect(startB_, SIGNAL(clicked()),this, SLOT(startGame()));
}

void formulaireWindow::startGame(){
    if(sbNbJ_->value()==2){
        theGame_ = new Game(leName1_->text().toStdString(),leName2_->text().toStdString(),sbSize_->value());
    }else{
         theGame_ = new Game(leName1_->text().toStdString(),leName2_->text().toStdString(),
                            leName3_->text().toStdString(),leName4_->text().toStdString(),
                            sbSize_->value());
    }
    theGameWindow_ = new gameWindow(theGame_,this);
    theGameWindow_->show();
    //this->close();

}



