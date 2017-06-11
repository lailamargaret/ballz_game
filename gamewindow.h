#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QGraphicsScene>

class GameWindow : public QGraphicsScene{
public:
    GameWindow(int a, int b, int x, int y);

public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};


#endif // GAMEWINDOW_H
