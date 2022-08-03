#include "caroffroadbody.h"

CarOffRoadBody::CarOffRoadBody(float32 initX, float32 initY, QGraphicsScene *scene, b2World *world) :
    CarBody()
{
    this->setPos(initX * SCALE, initY * SCALE);
    scene->addItem(this);

    //create body of car
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(initX, initY);
    body = world->CreateBody(&bodyDef);

    b2Vec2 vertice_1[7];
    vertice_1[0].Set(-1.77f, -1.015f);
    vertice_1[1].Set(0.1063f, -1.015f);
    vertice_1[2].Set(0.5237f, -0.9165f);
    vertice_1[3].Set(0.6173f, -0.3853f);
    vertice_1[4].Set(0.6173f, 0.5364f);
    vertice_1[5].Set(-1.67f, 0.5364f);
    vertice_1[6].Set(-1.77f, 0.3864f);

    b2Vec2 vertice_2[5];
    vertice_2[0].Set(0.6173f, -0.3853f);
    vertice_2[1].Set(1.87f, -0.1645f);
    vertice_2[2].Set(1.87f, 0.4364f);
    vertice_2[3].Set(1.72f, 0.5364f);
    vertice_2[4].Set(0.6173f, 0.5364f);

    b2PolygonShape shape1, shape2;
    shape1.Set(vertice_1, 7);
    shape2.Set(vertice_2, 5);

    b2FixtureDef fixtureDef_1;
    fixtureDef_1.shape = &shape1;
    fixtureDef_1.density = 5.0f;
    fixtureDef_1.friction = 1.0f;

    b2FixtureDef fixtureDef_2;
    fixtureDef_2.shape = &shape2;
    fixtureDef_2.density = 5.0f;
    fixtureDef_2.friction = 1.0f;

    body->CreateFixture(&fixtureDef_1);
    body->CreateFixture(&fixtureDef_2);
}

QRectF CarOffRoadBody::boundingRect() const
{
    QRectF Rect(-1.93 * SCALE, -1.055 * SCALE, 3.86 * SCALE, 2.11 * SCALE);
    return Rect;
}

void CarOffRoadBody::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygonF polygonShape;
    polygonShape << QPointF(-1.77 * SCALE, -1.015 * SCALE)
                 << QPointF(0.1063 * SCALE, -1.015 * SCALE)
                 << QPointF(0.5237 * SCALE, -0.9165 * SCALE)
                 << QPointF(0.6173 * SCALE, -0.3853 * SCALE)
                 << QPointF(1.87 * SCALE, -0.1645 * SCALE)
                 << QPointF(1.87 * SCALE, 0.4364 * SCALE)
                 << QPointF(1.72 * SCALE, 0.5364 * SCALE)
                 << QPointF(-1.67 * SCALE, 0.5364 * SCALE)
                 << QPointF(-1.77 * SCALE, 0.3864 * SCALE)
                 << QPointF(-1.77 * SCALE, -1.015 * SCALE);

    QBrush CarBrush;
    CarBrush.setColor(Qt::darkGreen);
    CarBrush.setStyle(Qt::SolidPattern);
    painter->setBrush(CarBrush);

    painter->drawPolygon(polygonShape);


    painter->drawLine(QLineF(-1.67 * SCALE, -0.915 * SCALE, -0.412 * SCALE, -0.915 * SCALE));
    painter->drawLine(QLineF(-0.412 * SCALE, -0.915 * SCALE, -0.412 * SCALE, -0.4143 * SCALE));
    painter->drawLine(QLineF(-0.412 * SCALE, -0.4143 * SCALE, -1.67 * SCALE, -0.4143 * SCALE));
    painter->drawLine(QLineF(-1.67 * SCALE, -0.4143 * SCALE, -1.67 * SCALE, -0.915 * SCALE));
    painter->drawLine(QLineF(-1.041 * SCALE, -0.915 * SCALE, -1.041 * SCALE, -0.4143 * SCALE));
    painter->drawLine(QLineF(-0.362 * SCALE, -0.915 * SCALE, -0.362 * SCALE, -0.4143 * SCALE));
    painter->drawLine(QLineF(-0.362 * SCALE, -0.4143 * SCALE, 0.5412 * SCALE, -0.4143 * SCALE));
    painter->drawLine(QLineF(0.5412 * SCALE, -0.4143 * SCALE, 0.4684 * SCALE, -0.8268 * SCALE));
    painter->drawLine(QLineF(0.4684 * SCALE, -0.8268 * SCALE, 0.0947 * SCALE, -0.915 * SCALE));
    painter->drawLine(QLineF(0.0947 * SCALE, -0.915 * SCALE, -1.67 * SCALE, -0.915 * SCALE));
    painter->drawLine(QLineF(-1.77 * SCALE, -0.3136 * SCALE, 0.63 * SCALE, -0.3136 * SCALE));
    painter->drawLine(QLineF(0.63 * SCALE, -0.3136 * SCALE, 1.87 * SCALE, -0.0934 * SCALE));
    painter->drawLine(QLineF(-0.362 * SCALE, -0.3136 * SCALE, -0.362 * SCALE, 0.5364 * SCALE));
    painter->drawLine(QLineF(-1.72 * SCALE, -0.2643 * SCALE, 0.58 * SCALE, -0.2643 * SCALE));
    painter->drawLine(QLineF(0.58 * SCALE, -0.3136 * SCALE, 0.58 * SCALE, 0.5364 * SCALE));
    painter->drawLine(QLineF(0.63 * SCALE, -0.3136 * SCALE, 0.63 * SCALE, 0.5364 * SCALE));
    painter->drawLine(QLineF(0.58 * SCALE, 0.4364 * SCALE, -1.6766 * SCALE, 0.4364 * SCALE));
    painter->drawLine(QLineF(-1.6766 * SCALE, 0.4364 * SCALE, -1.72 * SCALE, 0.3713 * SCALE));
    painter->drawLine(QLineF(-1.72 * SCALE, 0.3713 * SCALE, -1.72 * SCALE, -0.2643 * SCALE));
    painter->drawLine(QLineF(0.63 * SCALE, 0.4364 * SCALE, 1.87 * SCALE, 0.4364 * SCALE));

    painter->drawLine(QLineF(-1.6748 * SCALE, 0.3343 * SCALE, -1.6748 * SCALE, 0.2343 * SCALE));
    painter->drawLine(QLineF(-1.6748 * SCALE, 0.2343 * SCALE, -1.498 * SCALE, 0.0575 * SCALE));
    painter->drawLine(QLineF(-1.498 * SCALE, 0.0575 * SCALE, -0.862 * SCALE, 0.0575 * SCALE));
    painter->drawLine(QLineF(-0.862 * SCALE, 0.0575 * SCALE, -0.6852 * SCALE, 0.2343 * SCALE));
    painter->drawLine(QLineF(-0.6852 * SCALE, 0.2343 * SCALE, -0.6852 * SCALE, 0.3343 * SCALE));
    painter->drawLine(QLineF(-0.6852 * SCALE, 0.3343 * SCALE, -0.8620 * SCALE, 0.1575 * SCALE));
    painter->drawLine(QLineF(-0.8620 * SCALE, 0.1575 * SCALE, -1.498 * SCALE, 0.1575 * SCALE));
    painter->drawLine(QLineF(-1.498 * SCALE, 0.1575 * SCALE, -1.6748 * SCALE, 0.3343 * SCALE));

    painter->drawLine(QLineF(0.6852 * SCALE, 0.3343 * SCALE, 0.6852 * SCALE, 0.2343 * SCALE));
    painter->drawLine(QLineF(0.6852 * SCALE, 0.2343 * SCALE, 0.862 * SCALE, 0.0575 * SCALE));
    painter->drawLine(QLineF(0.862 * SCALE, 0.0575 * SCALE, 1.498 * SCALE, 0.0575 * SCALE));
    painter->drawLine(QLineF(1.498 * SCALE, 0.0575 * SCALE, 1.6748 * SCALE, 0.2343 * SCALE));
    painter->drawLine(QLineF(1.6748 * SCALE, 0.2343 * SCALE, 1.6748 * SCALE, 0.3343 * SCALE));
    painter->drawLine(QLineF(1.6748 * SCALE, 0.3343 * SCALE, 1.498 * SCALE, 0.1575 * SCALE));
    painter->drawLine(QLineF(1.498 * SCALE, 0.1575 * SCALE, 0.862 * SCALE, 0.1575 * SCALE));
    painter->drawLine(QLineF(0.862 * SCALE, 0.1575 * SCALE, 0.6852 * SCALE, 0.3343 * SCALE));

}
