#ifndef GOOMBA_H
#define GOOMBA_H
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include<QTimer>
#include "score.h"
class Game;


class Goomba:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Goomba(Game *g);
    void deleteGoomba();

public slots:
  void gravity();
  bool isOnPlatform();
  void move();
  void getPosition();


private:
    int posPlat;
    int goombaW;
    int goombaH;
    int marioH;
    int marioW;
    Game *g;
    int platHeight;
    int platWidth;
    QPixmap imageGoombaR;
    QPixmap imageGoombaL;


};

#endif // GOOMBA_H
