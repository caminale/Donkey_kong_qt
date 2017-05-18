#include "flag.h"

flag::flag()
{

    QPixmap imageFlag(":/images/marioPix/flag.png");

    int flagH=150;
    int flagW=90;

    imageFlag=imageFlag.scaled(flagW,flagH,Qt::IgnoreAspectRatio);


    setPixmap(imageFlag);

}
