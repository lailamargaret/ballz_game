#include "ball.h"
#include "game.h"
#include "block.h"
#include <QTimer>
#include <QDebug>

extern Game* game;

Ball::Ball(QGraphicsItem *parent) : QGraphicsEllipseItem(parent), QObject() {
    setRect(0,0,20,20);
    setBrush(Qt::white);

    x_velocity = 0;
    y_velocity = 0;

    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer -> start(18);
}

//copy constructor
Ball::Ball(const Ball &b)
{
    x_velocity = b.x_velocity;
    y_velocity = b.y_velocity;
}

void Ball::move()
{
    moveBy(x_velocity, y_velocity);
    hit_wall();
    hit_block();
}

void Ball::hit_wall()
{
    //hit the ceiling
    if(mapToScene(rect().topLeft()).y() <= 0)
        y_velocity*=-1;

    //hit the left
    if(mapToScene(rect().topLeft()).x() <= 0)
        x_velocity*=-1;

    if(mapToScene(rect().topLeft()).x() >= 740)
            x_velocity*=-1;

    //hit the bottom
    if(mapToScene(rect().bottomRight()).y() > 890){
        x_velocity = 0;
        y_velocity = 0;
    }
}

void Ball::hit_block()
{
    QList <QGraphicsItem* > col_it = collidingItems();
    for (int i = 0, n = col_it.size(); i < n; ++i){
        Block * block = dynamic_cast<Block*>(col_it[i]);
        if(block){

            double xbuff = 80;
            double ybuff = 0;
            double ballx = pos().x();
            double bally = pos().y();
            double blockx = block->pos().x();
            double blocky = block->pos().y();

          //cases for where it hits the block
            //hits the right side
             if (ballx > blockx + xbuff && x_velocity < 0){
             // qDebug() << "hit right of block";
              x_velocity*=-1;
                 }

          //hits the left side
          else if (blockx > ballx  && x_velocity > 0){
          // qDebug() << "hit left of block";
          x_velocity*=-1;
          }

          //hits the bottom
          else if (bally > blocky + ybuff && y_velocity < 0){
              y_velocity = y_velocity*-1;
             // qDebug() << "hit bottom of block";
          }

          //hits the top
          else if (blocky > bally + ybuff && y_velocity > 0){
              y_velocity*=-1;
             // qDebug() << "hit top of block";
           }

          -- block->value;
          if (block->value == 0){
             delete block;
          }

          if(block->value == 1)
               block->setBrush(Qt::red);
          if (block->value == 2)
                block->setBrush(Qt::yellow);
          if (block->value == 3)
              block->setBrush(Qt::green);
          if(block->value == 4)
               block->setBrush(Qt::blue);
            //game -> scene -> removeItem(block);
           // game -> spawn_blocks();

            return;
        }
    }
}


