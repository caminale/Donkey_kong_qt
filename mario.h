#ifndef MARIO_H
#define MARIO_H
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>
#include "platform.h"

namespace Ui {
class mario;
}

class mario : public QObject,public QGraphicsPixmapItem{

    Q_OBJECT

public:


  mario(QGraphicsItem * parent=0);
  void keyPressEvent(QKeyEvent * event);
  bool isOnPlatform();
  int compteur=0;
  QTimer * timer,*mytimer;
  bool inTheAir=false;
  bool ketRightjump=false;
  bool keyLeftjump=false;


public slots:
  int gestionCompteARebours();
  void jump();


private:
    Ui::mario *ui;
    QPixmap imageD;
    QPixmap imageG;
    QPixmap imageJ;
    platform pf1;
    void move();


    //void keyPressEvent(QKeyEvent *event);
};

#endif // MARIO_H
