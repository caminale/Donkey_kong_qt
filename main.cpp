#include <QApplication>
#include "game.h"
#include <mainwindow.h>




int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    MainWindow* m = new MainWindow();
    m->show();


    return a.exec();
}
