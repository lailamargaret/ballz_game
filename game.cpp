#include "game.h"
#include "ball.h"
#include "block.h"
#include "myqgraphicsscene.h"
#include <QGraphicsView>


Game::Game(QWidget *parent) : QGraphicsView (parent)
{
    scene = new QGraphicsScene(0,0,780,920);
    setFixedSize(780,920);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene);
 //  MyQGraphicsScene* my_scene = new MyQGraphicsScene();
}

void Game::play()
{
    Ball* ball = new Ball();
    ball -> setFlag(QGraphicsItem::ItemIsFocusable);
    ball->setFocus();
    ball->setPos(320,880);
   scene -> addItem(ball);

    //mousePressEvent(QGraphicsSceneMouseEvent * event);

   for (int i = 0; i < 7; ++i){
       for (int j = 0; j < 6; ++j ){
         Block* block = new Block(2);
         block -> setPos(10+i*110,10 + j* 110);
         scene -> addItem(block);
     }
   }
}
