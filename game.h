#ifndef GAME_H
#define GAME_H
#include "game.h"
#include "mario.h"
#include "platform.h"
#include <QGraphicsView>
#include <QWidget>
#include"goomba.h"
#include <QGraphicsScene>


class mario;

class Game: public QGraphicsView{
    Q_OBJECT

public:
    explicit  Game(QWidget * parent=0);
    QList<platform*> platList;
    platform *getPlatform1() const;
    void setPlatform1(platform *value);


public slots:
    void spawnGoomba();



private:
    QGraphicsScene * scene;
    mario * Mario;
    platform *platform1;
    int gameHeight;
    int gameWidth;
    Goomba *goo1;


};

#endif // GAME_H
