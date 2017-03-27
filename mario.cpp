#include "mario.h"
#include "ui_mario.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QImage>

mario::mario(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
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
        setPos(x(),y()+10);
    }
}
