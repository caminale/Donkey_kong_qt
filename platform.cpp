#include "platform.h"

platform::platform()
{
    QPixmap imagePlatform(":/image/platform.jpg");


    imagePlatform=imagePlatform.scaled(300,60,Qt::IgnoreAspectRatio);


    setPixmap(imagePlatform);
}
