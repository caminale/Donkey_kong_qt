#ifndef GAME_H
#define GAME_H
#include "game.h"
#include "mario.h"
#include "platform.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

class Game: public QGraphicsView{
    Q_OBJECT

public:
    explicit  Game(QWidget * parent=0);




    platform *getPlatform1() const;

    void setPlatform1(platform *value);

private:
    QGraphicsScene * scene;
    mario * Mario;
    platform *platform1;
    int gameHeight;
    int gameWidth;

};

#endif // GAME_H
