#include "platform.h"

platform::platform()
{
    QPixmap imagePlatform(":/images/platform.jpg");


    //imagePlatform=imagePlatform.scaled(300,60,Qt::IgnoreAspectRatio);


    setPixmap(imagePlatform);
}
