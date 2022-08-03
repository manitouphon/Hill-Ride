#ifndef RECT_H
#define RECT_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include "Box2D/Box2D.h"

#define PI 3.14159

class Rect : public QGraphicsRectItem
{
public:
    explicit Rect(float32 width, float32 height, float32 initX, float32 initY, b2BodyType bodyType,float32 density, float32 friction, float32 restitution, b2World *world, QGraphicsScene * scene);
    ~Rect();
    b2Body* getBody();
private:
    b2Body * body;
    const int SCALE = 60;
public:
    void advance(int phase);
};

#endif // RECT_H
