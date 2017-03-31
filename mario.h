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




public slots:
  void moove();
  void gravity();
  bool isOnPlatform();
  void trajectory();
  void managePix();
  void onSupport();


private:
    Ui::mario *ui;
    QElapsedTimer *timerElapse,*elapsGravity;
    QTimer * timer,*timerTrajectory,*timerPix,*timerGravity,*timerSupport;
    platform pf1;
    bool keyRight=false;
    bool keySpace=false;
    bool keyLeft=false;
    bool inJump=false; 
    bool jumpRight=false;
    bool jumpLeft=false;
    bool collision=true;
    int numberPix;
    QPixmap marioR2,marioR1,imageMario;
    QPixmap marioL1,marioL2,marioL3;
    QPixmap marioR3,marioB,marioF;
    void move();
    int t=0;
};

#endif // MARIO_H
