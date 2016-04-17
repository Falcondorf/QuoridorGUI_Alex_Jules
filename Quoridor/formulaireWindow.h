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

class formulaireWindow : public QWidget
{
    Q_OBJECT
public:
    explicit formulaireWindow(QWidget *parent = 0);
signals:

public slots:

private:
     QVBoxLayout *superRoot_;
    QHBoxLayout *root_;
    QVBoxLayout *groupParam_;
    QSpinBox *sbNbJ_;
    QLabel *lNbJ_;
    QSpinBox *sbSize_;
    QLabel *lSize_;
    QLineEdit *leName1_;
    QLabel *lName1_;
    QLineEdit *leName2_;
    QLabel *lName2_;
    QLineEdit *leName3_;
    QLabel *lName3_;
    QLineEdit *leName4_;
    QLabel *lName4_;
    QGroupBox *fourPlayerGameBox_;
    QPushButton *startB_;


};

#endif // FORMULAIREWINDOW_H
