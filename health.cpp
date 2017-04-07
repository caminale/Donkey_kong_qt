#include "health.h"
#include <QFont>
#include <QLabel>
#include "game.h"
#define width 30
#define height 30

Health::Health(Game *gamu): QGraphicsPixmapItem(), myGame(gamu){
    health = 3;
    QPixmap heart1(":/images/marioPix/heart.png");
    heart1=heart1.scaled(width,height,Qt::IgnoreAspectRatio);
    heart=heart1;
    setPixmap(heart);

}

int Health::getHealth(){
    return health;
}
