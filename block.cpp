#include "block.h"
#include "game.h"

extern Game* game;

//default constructor
Block::Block(QGraphicsItem *parent) : QGraphicsRectItem(parent), QObject(){
    int colorselector = rand()%4 + 1;
    value = colorselector;
    if(colorselector == 1)
         setBrush(Qt::red);
    if (colorselector == 2)
          setBrush(Qt::yellow);
    if (colorselector == 3)
        setBrush(Qt::green);
    if(colorselector == 4)
         setBrush(Qt::blue);
    setRect(0,0,100,100);
    //print_value* p_value = new QGraphicsTextItem;
   // game->scene->addItem(p_value);


}

//constructor taking an int
Block::Block(int new_value, QGraphicsItem *parent) : QGraphicsRectItem(parent), QObject(), value(new_value)
{
    int colorselector = rand()%4 + 1;
    value = colorselector;
    if(colorselector == 1)
         setBrush(Qt::red);
    if (colorselector == 2)
          setBrush(Qt::yellow);
    if (colorselector == 3)
        setBrush(Qt::green);
    if(colorselector == 4)
         setBrush(Qt::blue);
    setRect(0,0,100,100);
}

