#include "game.h"
#include "ball.h"
#include <QGraphicsView>

Game::Game(QWidget *parent) : QGraphicsView (parent)
{
    scene = new QGraphicsScene(0,0,740,920);
    setFixedSize(740,920);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene);
}

void Game::play()
{
    Ball* ball = new Ball();
    ball -> setFlag(QGraphicsItem::ItemIsFocusable);
    ball->setFocus();
    ball->setPos(320,880);
    scene -> addItem(ball);
}
