#ifndef MARIO_H
#define MARIO_H
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QElapsedTimer>
#include "platform.h"

namespace Ui {
class mario;
}

class mario : public QObject,public QGraphicsPixmapItem{

    Q_OBJECT

public:


  mario(QGraphicsItem * parent=0);
  void keyPressEvent(QKeyEvent * event);
  void keyReleaseEvent(QKeyEvent *event);




  bool inTheAir=false;
  bool ketRightjump=false;
  bool keyLeftjump=false;

  bool jumpRight=false;
  bool jumpLeft=false;
public slots:
  void moove();
  void gravity();
  bool isOnPlatform();
  void trajectory();
  void managePix();
  bool onSupport();


private:
    Ui::mario *ui;
    QElapsedTimer *timerElapse,*elapsGravity;
    QTimer * timer,*mytimer,*timerTrajectory,*timercollision,*timerPix,*timerGravity,*timerSupport;
    platform pf1;
    bool keyRight=false;
    bool keySpace=false;
    bool keyLeft=false;
    bool inJump=false;
    bool keyRspace=false;
    int numberPix;
    QPixmap marioR2,marioR1,imageMario;
    QPixmap marioL1,marioL2,marioL3;
    QPixmap marioR3,marioB,marioF;
    void move();
    int t=0;


    //void keyPressEvent(QKeyEvent *event);
};

#endif // MARIO_H
