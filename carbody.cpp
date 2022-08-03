#include "carbody.h"

b2Body *CarBody::getBody() const
{
    return body;
}

void CarBody::advance(int phase)
{
    if (phase)
    {
        this->setPos(body->GetPosition().x * SCALE, body->GetPosition().y * SCALE);
        this->setRotation(body->GetAngle() * 180/PI);
    }
}
