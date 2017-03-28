#include "mario.h"
#include "ui_mario.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QtCore/qmath.h>
#include <QDebug>
#include <QImage>
#include <QList>
#include <typeinfo>
#include "game.h"



extern Game * game;

mario::mario( QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

//  QPixmap marioPix=QPixmap(":/image/marioJ1.jpg");
//  setPixmap(marioPix);
    QPixmap imageMario(":/images/marioJ1.jpg");
    QPixmap imageMarioD(":/images/marioDroite.png");
    QPixmap imageMarioG(":/images/marioGauche.png");
    QPixmap imageMarioL1(":/images/marioL1.jpg");
    QPixmap imageMarioJ1(":/images/marioJ1.jpg");
    QPixmap imageMarioR1(":/images/marioR1.jpg");
    QPixmap imageMarioR2(":/images/marioR2.jpg");


    imageMario=imageMario.scaled(60,100,Qt::IgnoreAspectRatio);
    imageMarioL1=imageMarioL1.scaled(60,100,Qt::IgnoreAspectRatio);
    imageMarioJ1=imageMarioJ1.scaled(60,100,Qt::IgnoreAspectRatio);
    imageMarioR1=imageMarioR1.scaled(60,100,Qt::IgnoreAspectRatio);
    imageMarioR2=imageMarioR2.scaled(60,100,Qt::IgnoreAspectRatio);
    imageMarioD=imageMarioD.scaled(60,100,Qt::IgnoreAspectRatio);
    imageMarioG=imageMarioG.scaled(60,100,Qt::IgnoreAspectRatio);


    setPixmap(imageMario);

    imageD=imageMarioD;
    imageG=imageMarioG;
    imageJ=imageMarioJ1;
    timer = new QTimer(this);
    mytimer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT( jump()));
    connect(mytimer,SIGNAL(timeout()),this,SLOT( gestionCompteARebours()));
}


void mario::keyPressEvent(QKeyEvent *event){

    // move mario left
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0){
            if(pos().x()<game->platform1->pos().x()+300 && pos().x()>game->platform1->pos().x()+280&&pos().y()<game->platform1->pos().y()+60 && pos().y()+100>game->platform1->pos().y())
            {    qDebug()<<"bloc gauche"; }
        else
            //we test if mario jump
            if(inTheAir==false){
                setPos(x()-10,y());//not jump-> normal mouvement
                 setPixmap(this->imageG);
            }

            else{
                keyLeftjump=true;//jump -> activation of a boolean read in jump function
                 setPixmap(this->imageG);
            }
        }
    }


    // move mario right
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800){
            qDebug()<<"true or false : "<<inTheAir;
            if(pos().x()+60>game->platform1->pos().x()&& pos().x()+60<game->platform1->pos().x()+20&& pos().y()<game->platform1->pos().y()+60 && pos().y()+100>game->platform1->pos().y())
            {
                qDebug()<<"bloc droite";
            }
        else if(inTheAir==false){
                setPos(x()+10,y());
                setPixmap(this->imageD);
            }

            else{
                ketRightjump=true;
                setPixmap(this->imageD);

            }
        }

    }

    else if (event->key() == Qt::Key_Space){
        setPixmap(this->imageJ);
        timer->start(100);// move is called each every 1s
        mytimer->start(100);

    }
}
bool mario::isOnPlatform(){
    if(pos().x()+60>game->platform1->pos().x()&& pos().x()<game->platform1->pos().x()+300 && pos().y()+110>game->platform1->pos().y() && pos().y()+110<game->platform1->pos().y()+60)
    {


        return true;
    }

}


void mario::jump(){

//double ya =-4.9*compteur*compteur + 15*compteur +22;
//qDebug() << "la hauteur : "<<ya ;




    if(pos().y()>20){


        else {
            setPos(x(),y()+7.9*compteur*compteur - 19*compteur-22); //essaye pas de comprendre juju j'ai un peu modifié la constante de gravité
            inTheAir=true;
        }

    }
    //if we pressed the right key during a jump
    if(ketRightjump==true){
        qDebug()<<"ca saute à droite";
        setPos(x()+qLn(compteur)*8*compteur,y());


    }
    if(keyLeftjump==true){}
        if(pos().y()>700){
            setPos(x(),700);
            inTheAir=false;
            timer->stop();
            compteur=0;
            ketRightjump=false;
            keyLeftjump=false;

    }
}


//permit to create a time variable for our equations of positions
int mario::gestionCompteARebours()
{

    compteur+=1;
    qDebug() << "le compteur est de  : "<<compteur ;
    if(compteur==5){
        mytimer->stop();
        qDebug()<<"le timer est de :"<<mytimer;
    }
    return compteur;

}


// if(pos().x()+60>game->platform1->pos().x()&& pos().x()<game->platform1->pos().x()+300 && pos().y()+110>game->platform1->pos().y() && pos().y()+110<game->platform1->pos().y()+60)




