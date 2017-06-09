#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>

class Game: public QGraphicsView{
public:
    Game(QWidget* parent = nullptr);

    void play();

    QGraphicsScene* scene;
};

#endif // GAME_H
