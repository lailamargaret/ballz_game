#include "game.h"
#include "ball.h"
#include "block.h"
#include "myqgraphicsscene.h"
#include <QGraphicsView>


Game::Game(QWidget *parent) : QGraphicsView (parent)
{
    /*scene = new QGraphicsScene(0,0,740,920);
    setFixedSize(740,920);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene);*/
   MyQGraphicsScene* my_scene = new MyQGraphicsScene();
}

void Game::play()
{
    Ball* ball = new Ball();
    ball -> setFlag(QGraphicsItem::ItemIsFocusable);
    ball->setFocus();
    ball->setPos(320,880);
   scene -> addItem(ball);

    //mousePressEvent(QGraphicsSceneMouseEvent * event);

    Block* block = new Block(1);
    block -> setPos(10,10);
    scene -> addItem(block);
}
