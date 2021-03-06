#include "score.h"
#include <QFont>


Score::Score (QGraphicsItem *parent) : QGraphicsTextItem(parent){
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 11));

}

Score::Score(const Score & s)
{
    score = s.score;
}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::get_score() const
{
    return score;
}
