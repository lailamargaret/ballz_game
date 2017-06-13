#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
    friend class Game;
public:
    Score(QGraphicsItem * parent = 0);
    Score(const Score& s);
    void increase();
    int get_score()const;
private:
    int score;

};

#endif // SCORE_H
