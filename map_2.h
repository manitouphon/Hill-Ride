#ifndef MAP_2_H
#define MAP_2_H

#include <QGraphicsPolygonItem>
#include <QGraphicsScene>
#include <QPolygonF>
#include <QPointF>
#include "Box2D/Box2D.h"


class Map_2
{
public:
    Map_2(b2World * world, QGraphicsScene * scene);
private:
    QGraphicsPolygonItem * polygonShape_1;
    b2Body * body;
    const int SCALE = 60;

};

#endif // MAP_2_H
