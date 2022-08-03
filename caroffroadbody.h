#ifndef CAROFFROADBODY_H
#define CAROFFROADBODY_H

#include "carbody.h"

class CarOffRoadBody : public CarBody
{
public:
    CarOffRoadBody(float32 initX, float32 initY, QGraphicsScene * scene, b2World * world);
    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    const int SCALE = 60;
};

#endif // CAROFFROAD_H
