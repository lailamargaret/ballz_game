#include "game.h"
#include "ball.h"
#include "block.h"
#include "myqgraphicsscene.h"
#include <QGraphicsView>
#include <ctime>
#include <QDebug>
#include <QMouseEvent>


Game::Game(QWidget *parent) : QGraphicsView (parent)
{
    scene = new QGraphicsScene(0,0,780,920);
    setFixedSize(780,920);
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


   /*for (int i = 0; i < 7; ++i){
       for (int j = 0; j < 6; ++j ){
         Block* block = new Block(2);
         block -> setPos(10+i*110,10 + j* 110);
         scene -> addItem(block);
     }
   }*/

  // int num_blocks = rand() % 7;
   int num_blocks =2;
   for (int i = 0; i < num_blocks; ++i){
       int loc = rand() % 7;
       Block * block = new Block(1);
       block->setPos(10+loc*100, 10);
       scene -> addItem(block);
   }

}

QPointF Game::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    QPointF click_loc = e->pos();
    qDebug() << "Scene clicked - it worked!";
}
