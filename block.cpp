#include "block.h"
#include "game.h"

extern Game* game;

//default constructor
Block::Block(QGraphicsItem *parent) : QGraphicsRectItem(parent), QObject(){
    value = 1;
    int colorselector = rand()%4;
    if(colorselector == 0)
         setBrush(Qt::blue);
    if (colorselector == 1)
          setBrush(Qt::red);
    if (colorselector == 2)
        setBrush(Qt::green);
    if(colorselector == 3)
         setBrush(Qt::yellow);
    setRect(0,0,100,100);
    //print_value* p_value = new QGraphicsTextItem;
   // game->scene->addItem(p_value);


}

//constructor taking an int
Block::Block(int new_value, QGraphicsItem *parent) : QGraphicsRectItem(parent), QObject(), value(new_value)
{
    int colorselector = rand()%4;
    if(colorselector == 0)
         setBrush(Qt::blue);
    if (colorselector == 1)
          setBrush(Qt::red);
    if (colorselector == 2)
        setBrush(Qt::green);
    if(colorselector == 3)
         setBrush(Qt::yellow);
    setRect(0,0,100,100);
}

