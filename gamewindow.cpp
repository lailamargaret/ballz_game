#include "gamewindow.h"
#include <QDebug>
#include <QGraphicsScene>

GameWindow::GameWindow(int a, int b, int x, int y)
{
    QGraphicsScene(a,b,x,y);
}

void GameWindow::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug << "Scene clicked";
}
