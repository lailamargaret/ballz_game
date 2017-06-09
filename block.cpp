#include "block.h"

Block::Block(QGraphicsItem *parent, int new_value) : QGraphicsRectItem(parent), QObject(), value(new_value){
    setRect(0,0,1000,100);

}
