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
#include <QElapsedTimer>
#include "game.h"
#define origin 0
#define width 60
#define height 100
#define g      9.81
#define jumpSize 52
#define floor   700
#define alpha   45
#define jumpX   20




mario::mario(Game *gamu): QGraphicsPixmapItem(), myGame(gamu)
{
    QPixmap marioRight1(":/images/marioPix/marioR1.png");
    QPixmap marioLeft1(":/images/marioPix/marioL1.png");
    QPixmap marioLeft2(":/images/marioPix/marioL2.png");
    QPixmap marioLeft3(":/images/marioPix/marioL3.png");
    QPixmap marioRight2(":/images/marioPix/marioR2.png");
    QPixmap marioRight3(":/images/marioPix/marioR3.png");
    QPixmap marioBack(":/images/marioPix/marioF.png");

    marioRight1=marioRight1.scaled(width,height,Qt::IgnoreAspectRatio);
    marioRight2=marioRight2.scaled(width,height,Qt::IgnoreAspectRatio);
    marioLeft1=marioLeft1.scaled(width,height,Qt::IgnoreAspectRatio);
    marioLeft2=marioLeft2.scaled(width,height,Qt::IgnoreAspectRatio);
    marioLeft3=marioLeft3.scaled(width,height,Qt::IgnoreAspectRatio);
    marioRight3=marioRight3.scaled(width,height,Qt::IgnoreAspectRatio);
    marioBack=marioBack.scaled(width,height,Qt::IgnoreAspectRatio);

    marioR1=marioRight1;
    marioR2=marioRight2;
    marioR3=marioRight3;
    marioL1=marioLeft1;
    marioL2=marioLeft2;
    marioL3=marioLeft3;
    marioB=marioBack;
    setPixmap(imageMario);

    platHeight=myGame->platList.at(1)->getPlatHeight();
    platWidth=myGame->platList.at(1)->getPlatWidth();



    timerElapse=new QElapsedTimer();
    elapsGravity=new QElapsedTimer();
    timer = new QTimer(this);
    timerGravity = new QTimer(this);
    timerTrajectory=new QTimer(this);
    timerPix=new QTimer(this);
    timerSupport=new QTimer(this);
    connect(timerTrajectory,SIGNAL(timeout()),this,SLOT( trajectory()));
    connect(timerGravity,SIGNAL(timeout()),this,SLOT(gravity()));
    connect(timer,SIGNAL(timeout()),this,SLOT( moove()));
    connect(timerPix,SIGNAL(timeout()),this,SLOT(managePix()));
    connect(timerSupport,SIGNAL(timeout()),this,SLOT(onSupport()));

    timer->start(20);
    timerPix->start(40);
    timerSupport->start(50);

}


void mario::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Left){
        keyLeft =true;
    }
    if(event->key() == Qt::Key_Right){
        keyRight =true;
    }
    if(event->key() == Qt::Key_Space){
        keySpace =true;
    }
}

void mario::keyReleaseEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Space){
        keySpace =false;
    }
    if(event->key() == Qt::Key_Right){
        keyRight=false;
    }
    if(event->key() == Qt::Key_Left){
        keyLeft=false;
    }
}


void mario::moove(){

    if(keyLeft==true){

        if(pos().x()>0){
            if(inJump==true){
                jumpLeft=true;
            }
            else if(keySpace==true){
                inJump=true;
                timerElapse->start();
                timerTrajectory->start(50);
            }
            else{
            setPos(x()-10,y());
            }
        }
        else setPos(x(),y());
    }
    else if(keyRight==true){

       if(pos().x()+width<1000){
           if(inJump==true){
               jumpRight=true;
           }
           else if(keySpace==true){
               inJump=true;
               timerElapse->start();
               timerTrajectory->start(50);
           }
           else{
           setPos(x()+10,y());
           }
       }
       else setPos(x(),y());
    }
    else if(keySpace==true){
        inJump=true;
        if(timerTrajectory->isActive()){
        }
        else{
        timerElapse->start();
        timerTrajectory->start(50);
        }

    }
    else setPos(x(),y());

}
void mario::onSupport(){
    if (pos().y()>=floor){
        collision=true;
        qDebug()<<"t'es sur le sol";
        timerGravity->stop();
        setPos(x(),floor);
    }
    else{
    qDebug()<<"tu touches rien";
    elapsGravity->start();
    timerGravity->start(20);
    collision=false;

    }
    for(int i=0;i<3;i++){
     if(this->collidesWithItem(myGame->platList.at(i))){
        if(pos().y()>=myGame->platList.at(i)->pos().y()-height){
            collision=true;
            qDebug()<<"tu touches la brique";
            timerGravity->stop();
            setPos(x(),myGame->platList.at(i)->pos().y()-height+20);
        }
    }
    }


}

void mario::gravity(){

        qreal t=elapsGravity->elapsed()/100;
        if(keySpace==false && collision==false && inJump==false){
        qDebug()<<"yoloooooooooooooooooooooooooooooooooooooooooooooo          "<<t;
            qreal marioY=-g*pow(t,2);
            setPos(x(),y()+22);
        }


}

void mario::trajectory(){
    qreal t=timerElapse->elapsed()/100;
    qreal marioY=-g*pow(t,2)+jumpSize*sin(alpha)*t;
    qreal marioX=jumpX*cos(alpha)*t;
    setPos(x(),y()-marioY);
    inJump=true;

    if(jumpRight==true){
        setPos(x()+marioX,y());
        jumpRight=false;
    }
    else if(jumpLeft==true){
        setPos(x()-marioX,y());
        jumpLeft=false;
    }

    if(pos().y()>floor){
        timerTrajectory->stop();
        setPos(x(),floor);
        inJump=false;
    }
    for(int i=0;i<3;i++){
        if(this->collidesWithItem(myGame->platList.at(i))){
            timerTrajectory->stop();
            setPos(x(),myGame->platList.at(i)->pos().y()-height);
            timerTrajectory->stop();
            inJump=false;
        }
        else if(pos().y()<myGame->platList.at(i)->pos().y()+10&& this->collidesWithItem(myGame->platList.at(i))){
            setPos(x(),y()-marioY);
            qDebug()<<"yoloooooooooooooooooooooooooooooooooooooooooooooo          ";
           //timerGravity->start();
            inJump=false;
        }
//       else if(this->collidesWithItem(myGame->platList.at(i) &&  pos().y()<myGame->platList.at(i)->pos().y()-70))
//            setPos(x(),y()-marioY);
//  }

//    qDebug() << "position des y" << pos().y() ;
//    qDebug() << "The slow operation took" << timerElapse->elapsed() << "milliseconds";
    qDebug() << "t vaut " << t << "milliseconds";
}
}
void mario::managePix(){

    switch(this->numberPix){
        case 0 :
            setPixmap(marioR2);
        case 1 :
            if (keyRight==true){
                setPixmap(marioR1);
            }
            else if (keyLeft==true){
                setPixmap( marioL1);
            }
            else setPixmap(marioB);
            break;
        case 2 :
            if (keyRight==true){
                setPixmap( marioR2);
            }
            else if (keyLeft==true){
                setPixmap( marioL2);
            }
            else setPixmap(marioB);
            break;
        case 3 :
            if (keyRight==true){
                setPixmap( marioR3);
            }
            else if (keyLeft==true){
                setPixmap( marioL2);
            }
            else setPixmap(marioB);
            break;
        case 4 :
            if (keyRight==true){
                setPixmap( marioR3);
            }
            else if (keyLeft==true){

                setPixmap(  marioL3);
            }
            else setPixmap(marioB);
            break;
        case 5 :
            if (keyRight==true){
                setPixmap( marioR1);
            }
            else if (keyLeft==true){
               setPixmap( marioL1);
            }
            else setPixmap(marioB);
            break;
        case 6 :
            if (keyRight==true){
                this->setPixmap( marioR2);
            }
            else if (keyLeft==true){
                setPixmap( marioL1);
            }
            else setPixmap(marioB);
            break;
    }
    if(numberPix<6)numberPix++;
    else numberPix = 1;
}
bool mario::isOnPlatform(){

   return this->collidesWithItem(myGame->getPlatform1());

}


