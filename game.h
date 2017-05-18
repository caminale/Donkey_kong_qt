#ifndef GAME_H
#define GAME_H
#include "game.h"
#include "mario.h"
#include "platform.h"
#include <QGraphicsView>
#include <QWidget>
#include"goomba.h"
#include <QGraphicsScene>
#include"health.h"
#include <QDebug>
#include <QPixmap>



class mario;

class Game: public QGraphicsView{
    Q_OBJECT

public:
    explicit  Game(QWidget * parent=0);
    QList<platform*> platList;
    QList<Health*> heartList;
    platform *getPlatform1() const;
    void setPlatform1(platform *value);
    QGraphicsScene * scene;
    void decrease();
    mario *getMario();
    void gameOver();

public slots:
    void spawnGoomba();
    void endInvinsibility();



private:

    mario * Mario;
    platform *platform1;
    int gameHeight;
    int gameWidth;
    int ival;
    Goomba *goo1;
    Health *health;
    bool b_invinsible;
    QTimer *timerInvinsible;




};

#endif // GAME_H
