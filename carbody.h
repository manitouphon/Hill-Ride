#ifndef CARBODY_H
#define CARBODY_H

#include <QGraphicsItem>
#include <QPolygonF>
#include <QGraphicsScene>
#include <QPainter>
#include <QPainterPath>
#include "Box2D/Box2D.h"

class CarBody : public QGraphicsItem
{
    // QGraphicsItem interface
protected:
    b2Body * body;
public:
    void advance(int phase);
    b2Body *getBody() const;
private:
    const int SCALE = 60;
    const int PI = 3.14159f;
};

#endif // CARBODY_H
