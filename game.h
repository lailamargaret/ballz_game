#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPoint>
#include "block.h"
#include "ball.h"
#include "score.h"

class Game: public QGraphicsView{
    friend class Ball;
    friend class Score;
public:
    Game(QWidget* parent = nullptr);
    Game(const Game & g);
    Game(Game&& g);
    Game& operator =(Game g);
    void some_function_that_swaps(Game & g);

    void play();

    void mousePressEvent(QMouseEvent * e);

    void spawn_blocks();

    void move_blocks_down();

    QGraphicsScene* scene;

private:
    std::vector<Block> blocks;
    bool clicked;
    Ball * ball;
    Score * score;
};

#endif // GAME_H
