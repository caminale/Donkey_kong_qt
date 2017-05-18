#include "mainwindow.h"
#include "ui_mainwindow.h"

Game * game;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette p;
    p = palette();
    p.setBrush(QPalette::Window, QBrush(QPixmap(":/images/marioPix/overworld_bg.png")));
    setPalette(p);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

        game = new Game();
        game->setWindowState(Qt::WindowMaximized);

        game->show();
}
