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
   // QList<platform *> colliding_items = collidingItems();

}

void mario::keyPressEvent(QKeyEvent *event){



    if (event->key() == Qt::Key_Left){
        setPixmap(this->imageG);
        if (pos().x() >0)
            {
            if(pos().x()<game->platform1->pos().x()+300 && pos().x()>game->platform1->pos().x()+280&&pos().y()<game->platform1->pos().y()+60 && pos().y()+100>game->platform1->pos().y())
            {    qDebug()<<"bloc gauche"; }
        else setPos(x()-10,y());
        }
            }
    else if (event->key() == Qt::Key_Right){
        setPixmap(this->imageD);

        if (pos().x() + 60 < 1000){
            if(pos().x()+60>game->platform1->pos().x()&& pos().x()+60<game->platform1->pos().x()+20&& pos().y()<game->platform1->pos().y()+60 && pos().y()+100>game->platform1->pos().y())
            {
                qDebug()<<"bloc droite";


            }
        else setPos(x()+10,y());
        }
    }
    else if (event->key() == Qt::Key_Up){
        setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down){

            if(pos().x()+60>game->platform1->pos().x()&& pos().x()<game->platform1->pos().x()+300 && pos().y()+110>game->platform1->pos().y() && pos().y()+110<game->platform1->pos().y()+60)
            {
            }
            else setPos(x(),y()+10);

    }

}
