#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPoint>
#include "block.h"

class Game: public QGraphicsView{
public:
    Game(QWidget* parent = nullptr);

    void play();

    QGraphicsScene* scene;

    QPointF mousePressEvent(QGraphicsSceneMouseEvent * e);

    void spawn_blocks();

private:
    std::vector<Block> blocks;
};

#endif // GAME_H
