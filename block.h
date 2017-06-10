#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>

class Block : public QObject, public QGraphicsRectItem {
public:
    Block(QGraphicsItem* parent = 0);
    Block(int new_value, QGraphicsItem* = 0);
    friend class Ball;
private:
   int value;
   QGraphicsTextItem print_value;
};

#endif // BLOCK_H
