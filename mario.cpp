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
#define g     1000
#define jumpSize 750
#define floor   700
#define alpha   (M_PI/2)
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

    timerTrajectory=new QTimer(this);
    timerPix=new QTimer(this);
    timerSupport=new QTimer(this);
    connect(timerTrajectory,SIGNAL(timeout()),this,SLOT( trajectory()));

    connect(timer,SIGNAL(timeout()),this,SLOT( moove()));
    connect(timerPix,SIGNAL(timeout()),this,SLOT(managePix()));
    connect(timerSupport,SIGNAL(timeout()),this,SLOT(onSupport()));

    timer->start(20);
    timerPix->start(40);
    timerSupport->start(20);

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
    if(event->key() == Qt::Key_E){
        keyE =true;
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
    if(event->key() == Qt::Key_E){
        keyE =false;
    }
}


void mario::moove(){

    if(keyLeft==true){
        if(this->Support != nullptr && (!keySpace)){
            setPos(x()-10,this->Support->pos().y() - height + 15);
        }

        else moveBy(-10,0);

    }


     if(keyRight==true){

        if(pos().x()+width<1000 && (!keySpace)){
            if(this->Support != nullptr){
                qDebug() << "support";
                setPos(x()+10,this->Support->pos().y() - height + 15);

            }
        }

        else moveBy(10,0);


    }
     if(keySpace){
        if(!timerTrajectory->isActive()){
            puissanceSaut = jumpSize;
            timerElapse->start();
            timerTrajectory->start(20);
            PosotionInitiale = this->pos();
        }
    }
    if(keyE){

    }
}
void mario::onSupport(){
    bool isSupport = false;
    for(int i=0;i<3;i++){
        if(this->collidesWithItem(myGame->platList.at(i))){
            if (pos().y() < myGame->platList.at(i)->pos().y()){
                this->setSupport(myGame->platList.at(i));
                isSupport = true;
                qDebug()<<pos().y();
            }
            else if (pos().y()+height > myGame->platList.at(i)->pos().y() + this->platHeight){
                if(this->Support == nullptr){
                    this->PosotionInitiale = this->pos();
                    puissanceSaut=-60;
                    myGame->decrease();
                }
            }

        }
    }

    if (pos().y()>=floor){
        isSupport = true;
    }
    if(!isSupport){
        gravity();
        this->setSupport(nullptr);
        qDebug()<<pos().y();
    }
}

void mario::setSupport(platform *value)
{
    Support = value;
}

platform *mario::getSupport() const
{
    return Support;
}

 void mario::backflip(){

 }

 QTimer *mario::getTimerSupport() const
 {
     return timerSupport;
 }

 void mario::setTimerSupport(QTimer *value)
 {
     timerSupport = value;
 }

 QTimer *mario::getTimerGravity() const
 {
     return timerGravity;
 }

 void mario::setTimerGravity(QTimer *value)
 {
     timerGravity = value;
 }

 QTimer *mario::getTimerPix() const
 {
     return timerPix;
 }

 void mario::setTimerPix(QTimer *value)
 {
     timerPix = value;
 }

 QTimer *mario::getTimerTrajectory() const
 {
     return timerTrajectory;
 }

 void mario::setTimerTrajectory(QTimer *value)
 {
     timerTrajectory = value;
 }

 QTimer *mario::getTimer() const
 {
     return timer;
 }

 void mario::setTimer(QTimer *value)
 {
     timer = value;
 }

 void mario::gravity(){
     if(!this->timerTrajectory->isActive()){
         this->PosotionInitiale = this->pos();
        puissanceSaut = 0;
        timerTrajectory->start(20);
        timerElapse->start();
    }
}

void mario::trajectory(){


    qreal t=(qreal)timerElapse->elapsed()/1000;
    qreal teta=(qreal)timerElapse->elapsed()/100;
    qreal marioY = 0.5*g*pow(t,2) - puissanceSaut*qSin(alpha)*t + this->PosotionInitiale.y();
    qreal marioX = puissanceSaut*qCos(alpha)*t + this->PosotionInitiale.x() ;
    qreal marioxB=this->PosotionInitiale.x() +10*cos(teta);
    qreal marioyB=this->PosotionInitiale.y() +10*sin(teta);
    qreal degre=(qreal)timerElapse->elapsed();
    qDebug()<<"degre "<<degre;
    if(degre==360){
        degre=0;
    }
    if(keyRight==true){
        this->PosotionInitiale.setX(this->PosotionInitiale.x() + 10);
        jumpRight=false;
    }
    else if(keyLeft==true){
        this->PosotionInitiale.setX(this->PosotionInitiale.x() - 10);
        jumpLeft=false;
    }

    if(pos().y()>floor){
        timerTrajectory->stop();
        setPos(x(),floor);
    }

    if(this->Support!=nullptr){
        if(marioY >= this->Support->pos().y() - height){
            this->timerTrajectory->stop();
            marioY = this->Support->pos().y() - height + 10;

        }
    }
    if(keyE==true){
//        this->PosotionInitiale.setX(marioxB);
//        this->PosotionInitiale.setY(marioyB);
//        qDebug()<<"backflip";
        if(keyLeft==true){
        setTransformOriginPoint ( width/2,height/2);
        setRotation(degre);
        }
        if(keyRight==true){
            setTransformOriginPoint ( width/2,height/2);
            setRotation(-degre);
        }
        if(this->Support!=nullptr){
            setRotation(360);
        }
    }
    setPos(marioX,marioY);



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
void mario::gameOver(){
    timer->stop();
    timerPix->stop();
    timerSupport->stop();
    timerTrajectory->stop();

}



