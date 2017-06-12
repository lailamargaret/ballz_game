#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPoint>

class Game: public QGraphicsView{
public:
    Game(QWidget* parent = nullptr);

    void play();

    QGraphicsScene* scene;

    QPointF mouseReleaseEvent(QGraphicsSceneMouseEvent * e);
};

#endif // GAME_H
