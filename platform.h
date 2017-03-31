#ifndef PLATFORM_H
#define PLATFORM_H
#include<QGraphicsPixmapItem>
#include<QPixmap>


class platform:public QObject,public QGraphicsPixmapItem
{
     Q_OBJECT
public:
    platform();
    int getPlatHeight();
    int getPlatWidth();

protected:
    int platW;
    int platH;
};

#endif // PLATFORM_H
