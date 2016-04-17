#include "titleWindow.h"



titleWindow::titleWindow(QWidget *parent) :QWidget(parent){

    root_ = new QVBoxLayout(this);
    start_ = new QPushButton("START",this);


    QPixmap imgQuoridor("pic/imageQuoridor.jpg");
    img_ = new QLabel();
    img_->setPixmap(imgQuoridor);

    root_->addWidget(img_);
    root_->addWidget(start_);
    QObject::connect(start_, SIGNAL(clicked()),this, SLOT(startForm()));
}
void titleWindow::startForm(){
    formW= new formulaireWindow();
    formW->show();
    this->close();

}
