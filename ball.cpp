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

            double xbuff = 90;
            double ybuff = 0;
            double ballx = pos().x();
            double bally = pos().y();
            double blockx = block->pos().x();
            double blocky = block->pos().y();

            //cases for where it hits the block
          //hits the bottom
          if (bally > blocky + ybuff && y_velocity < 0){
              y_velocity = y_velocity*-1;
              qDebug() << "hit bottom of block";
              -- block->value;
              if (block->value == 0){

                          delete block;
                      }
                }
          //hits the top
          if (blocky > bally + ybuff && y_velocity > 0){
              y_velocity*=-1;
              qDebug() << "hit top of block";

              -- block->value;
              if (block->value == 0){
                  delete block;
              }
          }
         //hits the right side
          if (ballx > blockx  && x_velocity < 0){
           qDebug() << "hit right of block";
              x_velocity*=-1;
              -- block->value;
              if (block->value == 0){
                  delete block;
                  }
              }
          //hits the left side
          if (blockx > ballx  && x_velocity > 0){
              qDebug() << "hit left of block";
              x_velocity*=-1;
              //y_velocity *= -1;
              -- block->value;
              if (block->value == 0){

                  delete block;
              }}
            //game -> scene -> removeItem(block);
           // game -> spawn_blocks();

            return;
        }
    }
}


