#include "platform.h"

platform::platform()
{
    QPixmap imagePlatform(":/images/platform.jpg");

    platH=60;
    platW=700;

    imagePlatform=imagePlatform.scaled(platW,platH,Qt::IgnoreAspectRatio);


    setPixmap(imagePlatform);
}


int platform::getPlatHeight()
{
    return platH;
}

int platform::getPlatWidth()
{
    return platW;
}

