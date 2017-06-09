#include "game.h"
#include <QApplication>
#include <QGraphicsScene>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game* game = new Game();
    game->show();
    game->play();

    return a.exec();
}
