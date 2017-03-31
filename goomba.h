#ifndef GOOMBA_H
#define GOOMBA_H
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include<QTimer>
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
  bool getPosition();


private:
    int posPlat;
    int goombaW;
    int goombaH;
    int marioH;
    int marioW;
    Game *g;
    int platHeight;
    int platWidth;

};

#endif // GOOMBA_H
