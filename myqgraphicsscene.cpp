#include "myqgraphicsscene.h"

#include<QPointF>

MyQGraphicsScene::MyQGraphicsScene(QWidget *parent) : QGraphicsView(parent){
    scene = new QGraphicsScene(0,0,740,920);
    this -> setFixedSize(740,920);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this -> setScene(scene);
}

/*QPointF MyQGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *e){
    QPointF pt = e->pos();
    return pt;
}*/
