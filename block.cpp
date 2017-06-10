#include "block.h"
#include "game.h"

extern Game* game;

//default constructor
Block::Block(QGraphicsItem *parent) : QGraphicsRectItem(parent), QObject(){
    value = 1;
   // print_value.setPlainText(QString::number(value));
    setRect(0,0,730,100);
    //print_value* p_value = new QGraphicsTextItem;
   // game->scene->addItem(p_value);

}

//constructor taking an int
Block::Block(int new_value, QGraphicsItem *parent) : QGraphicsRectItem(parent), QObject(), value(new_value)
{
    setRect(0,0,500,100);
}

