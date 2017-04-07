
#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
class Game;

class Health: public QObject,public QGraphicsPixmapItem{
public:
    Health(Game* );
    void decrease();
    int getHealth();
private:
    int health;
    QPixmap heart;
    Game *myGame;
};

#endif // HEALTH_H
