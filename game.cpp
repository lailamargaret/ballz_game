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

  int num_blocks = rand() % 7 + 1;
  std::vector<Block> blocks;

  //draw first block
  int loc = rand() % 7;
  Block * block = new Block(1);
  block->setPos(10+loc*110, 10);
  scene -> addItem(block);
  blocks.push_back(block);
  qDebug() << "Block added at" << loc;


  for (int i = 0; i < num_blocks - 1; ++i){
       int loc = rand() % 7;
       for (int i = 0; i < blocks.size(); ++i){
           if (blocks[i].pos().x() != 10+loc*110){
               Block * block = new Block(1);
               block->setPos(10+loc*110, 10);
               scene -> addItem(block);
               blocks.push_back(block);
               qDebug() << "Block added at" << loc;
           }
       }

   }

}

QPointF Game::mousePressEvent(QGraphicsSceneMouseEvent * e)
{
   // QPointF click_loc = e->pos();
    qDebug() << "Scene clicked - it worked!";
    return QPointF(0,0);
}
