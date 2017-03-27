#ifndef PLATFORM_H
#define PLATFORM_H
#include<QGraphicsPixmapItem>
#include<QPixmap>


class platform:public QObject,public QGraphicsPixmapItem
{
     Q_OBJECT
public:
    platform();
};

#endif // PLATFORM_H
