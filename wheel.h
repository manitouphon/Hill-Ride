#ifndef WHEEL_H
#define WHEEL_H

#include "Box2D/Box2D.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QBrush>

class Wheel : public QGraphicsItem
{
public:
    explicit Wheel(float32 radius, float32 initX, float32 initY, float32 density, float32 friction, float32 restitution, b2World *world, QGraphicsScene * scene);
    ~Wheel();
    b2Body *getBody() const;
private:
    b2Body * body;
    float32 radius;
    const int SCALE = 60;
    const float PI = 3.14159f;

public:
    void advance(int phase); //invoked by QGraphicsScene 60 times per second
    QPoint frontWheelPos();
    QPoint rearWheelPos();      //Both rear and front are Use for fetching the wheel posistion (AKA coordinates)
    // QGraphicsItem interface
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // CIRCLE_H
