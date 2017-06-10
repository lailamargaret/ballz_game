#ifndef BLOCK_VALUE_H
#define BLOCK_VALUE_H

#include "block.h"

class Block_value : public QObject, public QGraphicsTextItem, public Block{
public:
    Block_value(QGraphicsItem* parent = 0);
private:
    int score;
};


#endif // BLOCK_VALUE_H
