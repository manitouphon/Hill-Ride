#include "rect.h"


Rect::Rect(float32 width, float32 height, float32 initX, float32 initY, b2BodyType bodyType, float32 density, float32 friction, float32 restitution, b2World *world, QGraphicsScene *scene)
{
    // Create rect of QGraphicsItem
    this->setRect(-width / 2 * SCALE, -height / 2 * SCALE, width * SCALE, height * SCALE);
    this->setPos(initX * SCALE, initY * SCALE);

    //add item to QGraphicsScene
    scene->addItem(this);

    // Create rect of Box2D simulation
    // Define body and create it

        b2BodyDef bodyDef;
        bodyDef.type = bodyType;
        bodyDef.position.Set(initX, initY);
        body = world->CreateBody(&bodyDef);


    // Create shape and fixture

        b2PolygonShape shape;
        shape.SetAsBox(width/2, height/2);
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
        fixtureDef.density = density;
        fixtureDef.friction = friction;
        fixtureDef.restitution = restitution;
        body->CreateFixture(&fixtureDef);

        this->setPen(QPen(Qt::blue, 2, Qt::SolidLine, Qt::RoundCap));
}

Rect::~Rect()
{
    body->GetWorld()->DestroyBody(body);
}

b2Body *Rect::getBody()
{
    return body;
}

void Rect::advance(int phase)
{
    if (phase)
    {
        this->setPos(body->GetPosition().x * SCALE, body->GetPosition().y * SCALE);
        this->setRotation(qreal(body->GetAngle() * 180/PI));
    }
}
