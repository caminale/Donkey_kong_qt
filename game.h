#ifndef GAME_H
#define GAME_H
#include "game.h"
#include "mario.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

class Game: public QGraphicsView{
    Q_OBJECT

public:
    explicit  Game(QWidget * parent=0);
    QGraphicsScene * scene;
    mario * Mario;




private:
};

#endif // GAME_H
