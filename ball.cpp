#include "ball.h"
#include "game.h"
#include "block.h"
#include <QTimer>
#include <QDebug>

extern Game* game;

Ball::Ball(QGraphicsItem *parent) : QGraphicsEllipseItem(parent), QObject() {
    setRect(0,0,10,10);
    x_velocity = 0;
    y_velocity = 0;

    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer -> start(16);
}

//void Ball::respond_by_moving(QPoint click_loc)

void Ball::mousePressEvent(QGraphicsSceneMouseEvent * event)
{  qDebug() << "Custom item clicked.";

  // if (event->type() == QEvent::MouseButtonRelease){
   //QPointF point = event->scenePos();
   //double clickx = point.x();
   //double clicky = point.y();

   // double locx = this->pos().x();
  //  double locy = this->pos().x();

    x_velocity = -5; // clickx - locx;
    y_velocity = -5; //clicky - locy;
  //}
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
    if(mapToScene(rect().topRight()).x() <= 0)
        x_velocity*=-1;

    if(mapToScene(rect().topLeft()).x() >= 740)
            x_velocity*=-1;

    //hit the bottom
    if(mapToScene(rect().bottomRight()).y() > 910){
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
            //cases for where it hits the block
          //hits the bottom
          if (pos().y() > block->pos().y() + 0 && y_velocity < 0)
              y_velocity*=-1;
          //hits the top
          if (block->pos().y() > pos().y() + 0 && y_velocity > 0)
              y_velocity*=-1;
         //hits the right side
          if (pos().x() > block->pos().x() + 0 && x_velocity < 0)
              x_velocity*=-1;
         //hits the left side
          if (block->pos().x() > pos().x() + 0 && x_velocity > 0)
              x_velocity*=-1;
            //game -> scene -> removeItem(block);
            -- block->value;
            if (block->value == 0)
                 delete block;
            return;
        }
    }
}


