#include "game.h"
#include <QApplication>
#include <QGraphicsScene>
#include <ctime>

Game* game;

int main(int argc, char *argv[])
{
    srand(int(time(0)));

    QApplication a(argc, argv);
    Game* game = new Game();
    game->show();
    game->play();

    return a.exec();
}
