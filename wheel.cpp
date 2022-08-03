#include "wheel.h"

Wheel::Wheel(float32 radius, float32 initX, float32 initY, float32 density, float32 friction, float32 restitution, b2World *world, QGraphicsScene *scene) :
    QGraphicsItem(),
    radius(radius)
{
    //set position in QGraphicsScene
    this->setPos(QPointF(initX * SCALE, initY * SCALE));

    //add item to QGraphicsScene
    scene->addItem(this);

    // Create Circle of Box2D simulation
    // Define and create body
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(initX, initY);
        body = world->CreateBody(&bodyDef);


    // Define and create circle shape and fixture
        b2CircleShape shape;
        shape.m_radius = radius;
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
        fixtureDef.density = density;
        fixtureDef.friction = friction;
        fixtureDef.restitution = restitution;
        body->CreateFixture(&fixtureDef);

}

Wheel::~Wheel()
{
    body->GetWorld()->DestroyBody(body);
}

b2Body *Wheel::getBody() const
{
    return body;
}


void Wheel::advance(int phase)
{
    if (phase)
    {
        this->setPos(body->GetPosition().x * SCALE, body->GetPosition().y * SCALE);
        this->setRotation(qreal(body->GetAngle() * 180/PI));
    }

}

void Wheel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QBrush WheelBrush;
    WheelBrush.setColor(Qt::darkGray);
    WheelBrush.setStyle(Qt::SolidPattern);
    painter->setBrush(WheelBrush);
    painter->drawEllipse(QPointF(this->boundingRect().center()), radius * SCALE, radius * SCALE);
    painter->drawEllipse(QPointF(this->boundingRect().center()), radius * 0.55f * SCALE, radius * 0.55f * SCALE);

}

QRectF Wheel::boundingRect() const
{
    return QRectF(-radius * SCALE, -radius * SCALE, radius * 2 * SCALE, radius * 2 * SCALE);
}

