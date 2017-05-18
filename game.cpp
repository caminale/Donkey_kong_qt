#include "game.h"
#include <QImage>
#include <QSound>
#include <QSoundEffect>
#include <QMediaPlayer>
Game::Game(QWidget *parent)
{



    scene = new QGraphicsScene();
    setBackgroundBrush(QBrush(QImage(":/images/marioPix/bild.jpg")));
    ival=2;
    b_invinsible=false;
    int gameHeight=600;
    int gameWidth=1000;
    scene->setSceneRect(0,0,gameWidth,gameHeight); // make the scene 800x600 instead of infinity by infinity (default)

    setScene(scene);






    score=new Score();
    score->setPos(1000,-200);



    platform *platform1= new platform;
    platform1->setPos(-450,0);
    platform *platform2= new platform;
    platform2->setPos(0,400);
    platform *platform3= new platform;
    platform3->setPos(600,150);
    platform *platform4= new platform;
    platform4->setPos(700,700);
    platList.append(platform1);
    platList.append(platform2);
    platList.append(platform3);
    platList.append(platform4);


    Health *heart1= new Health(this);
    heart1->setPos(1200,-200);
    Health *heart2= new Health(this);
    heart2->setPos(1250,-200);
    Health *heart3= new Health(this);
    heart3->setPos(1300,-200);

    heartList.append(heart1);
    heartList.append(heart2);
    heartList.append(heart3);


    flag *f= new flag();
    f->setPos(-350,-150);

    QTimer *timerSpawn=new QTimer(this);
    timerSpawn->start(2500);
    connect(timerSpawn,SIGNAL(timeout()),this,SLOT(spawnGoomba()));


    timerInvinsible=new QTimer(this);
    connect(timerInvinsible,SIGNAL(timeout()),this,SLOT(endInvinsibility()));


    // create the player
    Mario = new mario(this);
    Mario->setPos(230,-150); // TODO generalize to always be in the middle bottom of screen

    // make the player focusable and set it to be the current focus
    Mario->setFlag(QGraphicsItem::ItemIsFocusable);
    Mario->setFocus();
    // add the player to the scene
    scene->addItem(Mario);

    scene->addItem(platform1);
    scene->addItem(platform2);
    scene->addItem(platform3);
    scene->addItem(platform4);

    scene->addItem(heart1);
    scene->addItem(heart2);
    scene->addItem(heart3);

    scene->addItem(f);

    scene->addItem(score);
    show();
}
void Game::decrease(){
    if(ival>=0){
        if(b_invinsible == false)
        {
        scene->removeItem(heartList.at(ival));
        ival--;
        b_invinsible=true;
        timerInvinsible->start(3000);
        }



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

mario *Game::getMario()
{
    return this->Mario;
}


void Game::spawnGoomba()
{

    Goomba *goomba = new Goomba(this);
    goomba->setPos(690,50);
    scene->addItem(goomba);

}
void Game::endInvinsibility()
{
    b_invinsible=false;
}


void Game::win()
{
    qDebug() << "winner";

}

void Game::increaseScore()
{
    score->increase();
}
