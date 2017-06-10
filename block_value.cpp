#include "block_value.h"

Block_value::Block_value(QGraphicsItem *parent) : QGraphicsTextItem(parent), QObject()
{
    score = Block.value;

    setPlainText(QString::number(score));
    setFont(QFont("times", 16));
}
