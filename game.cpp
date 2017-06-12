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


    spawn_blocks();





}

QPointF Game::mousePressEvent(QGraphicsSceneMouseEvent * e)
{
   // QPointF click_loc = e->pos();
    qDebug() << "Scene clicked - it worked!";
    return QPointF(0,0);
}

void Game::spawn_blocks()
{
    int num_blocks = rand() % 7 + 1;
    std::vector<int> locs;
    bool dup = false;

    // first block
    int loc = rand() % 7;
    locs.push_back(loc);
    Block * block = new Block(1);
    block->setPos(10+loc*110, 10);
    scene -> addItem(block);
    qDebug() << "Block added at" << loc;

    for (int i = 0; i < num_blocks - 1; ++i){
        loc = rand() % 7;
        for (int i = 0; i < locs.size(); ++i){
           if (locs[i] == loc)
               dup = true;
         }

         if (!dup){
             Block * block = new Block(1);
             block->setPos(10+loc*110, 10);
             scene -> addItem(block);
             locs.push_back(loc);
             qDebug() << "Block added at" << loc;
          }

    }
}
