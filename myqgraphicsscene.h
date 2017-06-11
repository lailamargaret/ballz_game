#ifndef MYQGRAPHICSSCENE_H
#define MYQGRAPHICSSCENE_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include<QMouseEvent>
#include <QPoint>

class MyQGraphicsScene : public QGraphicsView {
    Q_OBJECT
public:
    MyQGraphicsScene(QWidget * parent = 0);
     QGraphicsScene * scene;
signals:
public slots:
    //QPointF mousePressEvent(QGraphicsSceneMouseEvent * e);
private:

};

#endif // MYQGRAPHICSSCENE_H
