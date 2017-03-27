#include "mario.h"
#include "ui_mario.h"
#include <QGraphicsScene>
#include <QKeyEvent>

mario::mario(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/mario.png"));

}

mario::~mario()
{
    delete ui;
}
