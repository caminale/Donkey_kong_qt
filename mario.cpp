#include "mario.h"
#include "ui_mario.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QImage>
#include <QList>
#include <typeinfo>
#include "game.h"
#include <QDebug>

extern Game * game;

mario::mario( QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    QPixmap imageMario(":/image/mario.png");
    QPixmap imageMarioD(":/image/marioDroite.png");
    QPixmap imageMarioG(":/image/marioGauche.png");


    imageMario=imageMario.scaled(60,100,Qt::IgnoreAspectRatio);
    imageMarioD=imageMarioD.scaled(60,100,Qt::IgnoreAspectRatio);
    imageMarioG=imageMarioG.scaled(60,100,Qt::IgnoreAspectRatio);


    setPixmap(imageMario);
    imageD=imageMarioD;
    imageG=imageMarioG;


}

mario::~mario()
{
    delete ui;
}

void mario::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i){

    if (typeid(*(colliding_items[i])) == typeid(game->platform1)){

       if(pos().y()>colliding_items[i]->pos().y())
       {

       }
        return;
    }
    }
}

void mario::keyPressEvent(QKeyEvent *event){



    if (event->key() == Qt::Key_Left){
        if (pos().x() >0){
        setPixmap(this->imageG);

        setPos(x()-10,y());
        }
    }
    else if (event->key() == Qt::Key_Right){
        setPixmap(this->imageD);
        if (pos().x() + 60 < 800){

        setPos(x()+10,y());
        }
    }
    else if (event->key() == Qt::Key_Up){
        setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down){


            if(pos().x()+60>100&& pos().x()<100+300 && pos().y()+110> 100 && pos().y()+110< 100+60)
            {

            }
            else setPos(x(),y()+10);



    }

}
