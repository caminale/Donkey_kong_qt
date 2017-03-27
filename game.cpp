#include "game.h"
#include <QImage>

Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    //setBackgroundBrush(QBrush(QImage(":/images/mario.png")));
    setScene(scene);

    // create the player
    Mario = new mario();
    Mario->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    Mario->setFlag(QGraphicsItem::ItemIsFocusable);
    Mario->setFocus();
    // add the player to the scene
    scene->addItem(Mario);
    show();
}
