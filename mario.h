#ifndef MARIO_H
#define MARIO_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>
//#include <QMediaPlayer>

namespace Ui {
class mario;
}

class mario : public QObject,public QGraphicsPixmapItem{

    Q_OBJECT

public:
  mario(QGraphicsItem * parent=0);
    ~mario();


private:
    Ui::mario *ui;
    QPixmap imageD;
    QPixmap imageG;


    void keyPressEvent(QKeyEvent *event);
};

#endif // MARIO_H
