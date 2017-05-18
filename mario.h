#ifndef MARIO_H
#define MARIO_H
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QElapsedTimer>
#include <QPointF>
#include "platform.h"
#include "health.h"


class Game;

namespace Ui {
class mario;
}

class mario : public QObject,public QGraphicsPixmapItem{

    Q_OBJECT

public:


  mario(Game* );
  void keyPressEvent(QKeyEvent * event);
  void keyReleaseEvent(QKeyEvent *event);
  void gameOver();
  int getMarioX();
  int getMarioY();





  platform *getSupport() const;

  void setSupport(platform *value);

  QTimer *getTimer() const;
  void setTimer(QTimer *value);

  QTimer *getTimerTrajectory() const;
  void setTimerTrajectory(QTimer *value);

  QTimer *getTimerPix() const;
  void setTimerPix(QTimer *value);

  QTimer *getTimerGravity() const;
  void setTimerGravity(QTimer *value);

  QTimer *getTimerSupport() const;
  void setTimerSupport(QTimer *value);

public slots:
  void moove();
  void gravity();
  void trajectory();
  void managePix();
  void onSupport();
  void backflip();
  void animationGameOver();


private:
    Ui::mario *ui;
    QElapsedTimer *timerElapse,*elapsGravity;
    QTimer * timer,*timerTrajectory,*timerPix,*timerGravity,*timerSupport, *timerGameOver;
    platform pf1;
    bool keyRight=false;
    bool keySpace=false;
    bool keyLeft=false;
    bool keyE=false;
    bool inJump=false;
    bool jumpRight=false;
    bool jumpLeft=false;
    bool collision=false;
    bool collisionU=false;

    QPointF PosotionInitiale;
    int numberPix;
    QPixmap marioR2,marioR1,imageMario;
    QPixmap marioL1,marioL2,marioL3;
    QPixmap marioR3,marioB,marioF;
    QPixmap marioDab1,marioDab2,marioDab3;
    QPixmap q_gameOver;
    void move();
    int t=0;
    Game *myGame;
    Health *health;
    int platHeight;
    int platWidth;
    platform *Support;
    qreal puissanceSaut;
};

#endif // MARIO_H
