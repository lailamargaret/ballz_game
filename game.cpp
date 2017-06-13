#include "game.h"
#include "ball.h"
#include "block.h"
#include "myqgraphicsscene.h"
#include <QGraphicsView>
#include <ctime>
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsItem>
//#include <QTimer>
#include "score.h"

Game::Game(QWidget *parent) : QGraphicsView (parent), ball(nullptr), score(nullptr)
{
   try{
    scene = new QGraphicsScene(0,0,780,920);
    setFixedSize(780,920);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene);

    clicked = false;

    ball = new Ball();
    ball -> setFlag(QGraphicsItem::ItemIsFocusable);
    ball->setFocus();
    ball->setPos(320,880);
    scene -> addItem(ball);

    // score = new Score();
     //score->setPos(10,890);
     //scene->addItem(score);
    }
    catch(const std::exception& e){
        delete scene;
        delete ball;
        delete score;
        throw;
    }


}

Game::Game(const Game& g): ball(nullptr), score(nullptr)
{
   try { ball = new Ball (*(g.ball));
        //scene = new QGraphicsScene(*(g.scene));
        score = new Score (*(g.score));}
    catch(const std::exception& e){
        delete ball;
        delete score;
        throw;
    }
}

Game::Game(Game &&g) : ball(nullptr), score(nullptr)
{
    std::swap(ball, g.ball);
    std::swap(score, g.score);
}

Game& Game::operator = (Game g)
{
    std::swap(ball, g.ball);
    std::swap(score, g.score);
    return *this;
}

void Game::play()
{

    spawn_blocks();

}

void Game::mousePressEvent(QMouseEvent * e)
{
   if (ball->x_velocity != 0 && ball->y_velocity != 0){
       return;
   }

    QPointF click_loc = e->pos();
    clicked = true;

    ball->x_velocity = (click_loc.x()-ball->pos().x())/40;
    ball->y_velocity = (click_loc.y()-ball->pos().y())/40;

   // qDebug() << "Scene clicked - it worked!";

   // if (ball->x_velocity == 0 && ball->y_velocity == 0){
    spawn_blocks();
    move_blocks_down();
    //}

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
    //qDebug() << "Block added at" << loc;

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
             //qDebug() << "Block added at" << loc;
          }

    }
}

void Game::move_blocks_down()
{
    QList <QGraphicsItem* > all_it = items();
    for (int i = 0, n = all_it.size(); i < n; ++i){
        Block * block = dynamic_cast<Block*>(all_it[i]);
        if(block){
           block->setPos(block->pos().x(), block->pos().y()+110);
           if (block->pos().y() >= 890){
               scene->removeItem(block);
               delete block;}
        }
    }
    clicked = false;
}

