#ifndef FLAG_H
#define FLAG_H
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include <QObject>

class flag:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    flag();
};

#endif // FLAG_H
