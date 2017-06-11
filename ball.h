#ifndef BALL_H
#define BALL_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QMouseEvent>

class Ball : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
public:
    friend class Block;
    Ball(QGraphicsItem* parent = 0);
    //void respond_by_moving(QPoint click_loc);
public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void move();
private:
    double x_velocity;
    double y_velocity;

    void hit_wall();
    void hit_block();
};


#endif // BALL_H
