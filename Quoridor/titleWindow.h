#ifndef TITLEWINDOW_H
#define TITLEWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include "formulaireWindow.h"

class titleWindow : public QWidget
{

    Q_OBJECT
private:
    QVBoxLayout *root_;
    QPushButton *start_;
    QLabel *img_;
    formulaireWindow *formW;
public:
    explicit titleWindow(QWidget *parent = 0);
signals:


public slots:

    void startForm();




};

#endif // TITLEWINDOW_H
