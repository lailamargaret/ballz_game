#include "ball.h"
#include "game.h"
#include <QTimer>


Ball::Ball(QGraphicsItem *parent) : QGraphicsRectItem(parent), QObject() {
    setRect(0,0,10,10);
    x_velocity = 0;
    y_velocity = -5;

    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer -> start(15);
}
