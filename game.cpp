#include "game.h"
#include <QImage>

Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();

    int gameHeight=600;
    int gameWidth=1000;
    scene->setSceneRect(0,0,gameWidth,gameHeight); // make the scene 800x600 instead of infinity by infinity (default)

    //setBackgroundBrush(QBrush(QImage(":/images/mario.png")));
    setScene(scene);
    //create platform
    platform1 = new platform();
    platform1->setPos(500,500);

    // create the player
    Mario = new mario();
    Mario->setPos(400,400); // TODO generalize to always be in the middle bottom of screen

    // make the player focusable and set it to be the current focus
    Mario->setFlag(QGraphicsItem::ItemIsFocusable);
    Mario->setFocus();
    // add the player to the scene
    scene->addItem(Mario);
    scene->addItem(platform1);

    show();
}
