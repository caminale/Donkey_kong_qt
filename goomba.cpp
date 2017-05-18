#include "goomba.h"
#include"game.h"
#include <typeinfo>

Goomba::Goomba(Game *g): QGraphicsPixmapItem(), g(g)
{
    goombaH=50;
    goombaW=35;


    marioH=60;
    marioW=30;

    QPixmap imageGoomba(":/images/Goomba.png");
    imageGoomba=imageGoomba.scaled(goombaW,goombaH,Qt::IgnoreAspectRatio);
    setPixmap(imageGoomba);

    platHeight=g->platList.at(1)->getPlatHeight();
    platWidth=g->platList.at(1)->getPlatWidth();

    QTimer *timerMove=new QTimer(this);
    timerMove->start(20);
    connect(timerMove,SIGNAL(timeout()),this,SLOT(move()));

    QTimer *timerGravity=new QTimer(this);
    timerGravity->start(20);
    connect(timerGravity,SIGNAL(timeout()),this,SLOT(gravity()));

    QTimer *timerPos=new QTimer(this);
    timerPos->start(20);
    connect(timerPos,SIGNAL(timeout()),this,SLOT(getPosition()));

    this->posPlat=1;

}


void Goomba::gravity(){
    if (isOnPlatform()==true){

    }
    else{
        if(pos().y()<700)
            setPos(x(),y()+22);
    }
}

bool Goomba::isOnPlatform(){
    for(int i=0;i<3;i++)
    {
    if(pos().x()+platHeight>g->platList.at(i)->pos().x()&& pos().x()<g->platList.at(i)->pos().x()+platWidth && pos().y()+goombaH+10>g->platList.at(i)->pos().y() && pos().y()+goombaH+10<g->platList.at(i)->pos().y()+platHeight)
    {


        return true;
    }

    }return false;

}

void Goomba::move()
{


    if(this->posPlat==1||this->posPlat==3)
    {

        QList<QGraphicsItem *> colliding_items = collidingItems();
            for (int i = 0, n = colliding_items.size(); i < n; ++i){
                if (typeid(*(colliding_items[i])) == typeid(mario)){
                    if(g->getMario()->getMarioY()+80<this->pos().y())
                    {

                    // remove goomba
                    scene()->removeItem(this);
                    // delete goomba
                    delete this;
                    return;
                    }
                    else{
                        g->decrease();
                    }
                }
            }

    setPos(x()+3,y());
    }

    if(this->posPlat==2)
    {

        QList<QGraphicsItem *> colliding_items = collidingItems();
            for (int i = 0, n = colliding_items.size(); i < n; ++i){
                if (typeid(*(colliding_items[i])) == typeid(mario)){
                    if(g->getMario()->getMarioY()+80<this->pos().y())
                    {
                    // remove goomba
                    scene()->removeItem(this);
                    // delete goomba
                    delete this;
                    return;
                }
                    else{
                        g->decrease();
                    }
            }
            }

    setPos(x()-3,y());
    }


}


void Goomba::getPosition()
{

    if(this->pos().y()<700&&this->pos().x()>1200)
    {
        posPlat=2;
    }
    if(this->pos().y()>450&&this->pos().x()<150)
    {
        posPlat=3;
    }
    if(this->pos().y()>650&&this->pos().x()>1400)
    {

        this->deleteGoomba();
    }

    else return;


}

void Goomba::deleteGoomba()
{

    scene()->removeItem(this);
    delete this;
}
