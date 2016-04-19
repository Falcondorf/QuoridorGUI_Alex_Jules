#ifndef ENDWINDOW
#define ENDWINDOW
#include "endwindow.h"
#include <QWidget>
#include <QLabel>
#include "game.h"
#include "gameWindow.h"

class endwindow : public QWidget
{
    Q_OBJECT
   public:
       explicit endwindow(QWidget *parent = 0);

   private:
      // gameWindow *theGameWindow_;
       QLabel *message;

};
#endif // ENDWINDOW

