#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>

class Block : public QObject, public QGraphicsRectItem {
public:
    Block(QGraphicsItem* parent = 0, int new_value = 1);

private:
   int value;
};


#endif // BLOCK_H
