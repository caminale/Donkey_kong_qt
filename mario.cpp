#include "mario.h"
#include "ui_mario.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QtCore/qmath.h>
#include <QDebug>


mario::mario(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

  QPixmap marioPix=QPixmap(":/image/mario3.gif");
  setPixmap(marioPix);
  timer = new QTimer(this);
  mytimer = new QTimer(this);
  connect(timer,SIGNAL(timeout()),this,SLOT( jump()));
  connect(mytimer,SIGNAL(timeout()),this,SLOT( gestionCompteARebours()));


}


void mario::keyPressEvent(QKeyEvent *event){

    // move mario left
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0){
            //we test if mario jump
            if(inTheAir==false){
                setPos(x()-10,y());//not jump-> normal mouvement
            }

            else{
                keyLeftjump=true;//jump -> activation of a boolean read in jump function
            }
        }
    }


    // move mario left
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800){
            qDebug()<<"true or false : "<<inTheAir;
            if(inTheAir==false){
                setPos(x()+10,y());
            }

            else{
                ketRightjump=true;
            }
        }

    }

    else if (event->key() == Qt::Key_Space){
        timer->start(100);// move is called each every 1s
        mytimer->start(100);
    }
}

void mario::move(){


}

void mario::jump(){

//double ya =-4.9*compteur*compteur + 15*compteur +22;
//qDebug() << "la hauteur : "<<ya ;

    if(pos().y()>20){
        setPos(x(),y()+7.9*compteur*compteur - 19*compteur-22); //essaye pas de comprendre juju j'ai un peu modifié la constante de gravité
        inTheAir=true;

    }
    //if we pressed the right key during a jump
    if(ketRightjump==true){
        qDebug()<<"ca saute à droite";
        setPos(x()+qLn(compteur)*8*compteur,y());

    }
    if(keyLeftjump==true){

        setPos(x()-qLn(compteur)*8*compteur,y());
//        qDebug()<<"ca saute à gauche"<<-qLn(compteur+0.1)*10*compteur ;

    }

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


