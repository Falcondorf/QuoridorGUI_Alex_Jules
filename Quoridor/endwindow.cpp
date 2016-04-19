#include "endwindow.h"

endwindow::endwindow(QWidget *parent) :QWidget(parent){
     message = new QLabel(this);
     message->setText("le joueur x a gagné");
}
