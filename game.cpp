#include "game.h"
#include <QImage>

Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    ival=2;
    int gameHeight=600;
    int gameWidth=1000;
    scene->setSceneRect(0,0,gameWidth,gameHeight); // make the scene 800x600 instead of infinity by infinity (default)

    //setBackgroundBrush(QBrush(QImage(":/images/mario.png")));
    setScene(scene);

    platform *platform1= new platform;
    platform1->setPos(100,700);
    platform *platform2= new platform;
    platform2->setPos(600,450);
    platform *platform3= new platform;
    platform3->setPos(0,200);
    platList.append(platform1);
    platList.append(platform2);
    platList.append(platform3);;

    Health *heart1= new Health(this);
    heart1->setPos(0,0);
    Health *heart2= new Health(this);
    heart2->setPos(50,0);
    Health *heart3= new Health(this);
    heart3->setPos(100,0);

    heartList.append(heart1);
    heartList.append(heart2);
    heartList.append(heart3);

    QTimer *timerSpawn=new QTimer(this);
    timerSpawn->start(2500);
    connect(timerSpawn,SIGNAL(timeout()),this,SLOT(spawnGoomba()));





    // create the player
    Mario = new mario(this);
    Mario->setPos(530,150); // TODO generalize to always be in the middle bottom of screen

    // make the player focusable and set it to be the current focus
    Mario->setFlag(QGraphicsItem::ItemIsFocusable);
    Mario->setFocus();
    // add the player to the scene
    scene->addItem(Mario);
    scene->addItem(platform1);
    scene->addItem(platform2);
    scene->addItem(platform3);
    scene->addItem(heart1);
    scene->addItem(heart2);
    scene->addItem(heart3);
    show();
}
void Game::decrease(){
    if(ival>=0){
        scene->removeItem(heartList.at(ival));
        ival--;
    }
    else Mario->gameOver();
}

platform *Game::getPlatform1() const
{
    return platform1;
}

void Game::setPlatform1(platform *value)
{
    platform1 = value;
}


void Game::spawnGoomba()
{
    //myDoor->doorValue=1;

    this->goo1 = new Goomba(this);
    this->goo1->setPos(190,150);
    scene->addItem(goo1);





}

