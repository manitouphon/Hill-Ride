#include "car.h"

Car::Car(float32 initX, float32 initY, QGraphicsScene * scene, b2World * world)
{

    carBody = new CarOffRoadBody(initX, initY, scene, world);


    frontWheel = new Wheel(0.37f, initX + 1.18, initY + 0.7604, 40.0f, 0.8f, 0.5f, world, scene);
    rearWheel = new Wheel(0.37f, initX - 1.18, initY + 0.7604, 40.0f, 0.8f, 0.5f, world, scene);


    //joining the two wheels to car's body
        //front wheel
        {
            b2WheelJointDef frontWheelDef;
            frontWheelDef.Initialize(carBody->getBody(), frontWheel->getBody(), frontWheel->getBody()->GetWorldCenter(), b2Vec2(0, 1.5));
            frontWheelDef.enableMotor = true;
            frontWheelDef.collideConnected = false;
            frontWheelDef.maxMotorTorque = 100.0f;
            frontWheelDef.motorSpeed = 0.0f;
            frontWheelDef.dampingRatio = 0.1f;
            frontWheelDef.frequencyHz = 5;


            frontWheelJoint = (b2WheelJoint *) world->CreateJoint(&frontWheelDef);
        }
        //rear wheel
        {
            b2WheelJointDef rearWheelDef;
            rearWheelDef.Initialize(carBody->getBody(), rearWheel->getBody(), rearWheel->getBody()->GetWorldCenter(), b2Vec2(0, 1.5));
            rearWheelDef.enableMotor = true;
            rearWheelDef.collideConnected = false;
            rearWheelDef.maxMotorTorque = 100.0f;
            rearWheelDef.motorSpeed = 0.0f;
            rearWheelDef.dampingRatio = 0.1f;
            rearWheelDef.frequencyHz = 5 ;

            rearWheelJoint = (b2WheelJoint *) world->CreateJoint(&rearWheelDef);
        }

    //connect signal and slot for user to be able to control the car itself
    connect(scene, SIGNAL(moveCarForward()), this, SLOT(moveForward()));
    connect(scene, SIGNAL(moveCarBackward()), this, SLOT(moveBackward()));
    connect(scene, SIGNAL(stopMoveCar()), this, SLOT(stopMove()));
    connect(scene, SIGNAL(releaseAcceleration()), this, SLOT(releasePedal()));
    connect(scene, SIGNAL(moveCarNitro()), this, SLOT(moveNitro()));

}

Car::~Car()
{
    //destroy both QGraphicsItem and also body in box2D world
    carBody->~CarBody();
    frontWheel->~Wheel();
    rearWheel->~Wheel();
}

CarBody *Car::getCarBody() const
{
    return carBody;
}

QPoint Car::getCarPos()
{
    QPoint currentCarPos;
    currentCarPos.setX(frontWheel->x());
    currentCarPos.setY(frontWheel->y());
    return currentCarPos;
}

void Car::moveForward()
{
    rearWheelJoint->SetMaxMotorTorque(1800.0f);
    rearWheelJoint->SetMotorSpeed(25.0f);
}

void Car::moveBackward()
{
    rearWheelJoint->SetMaxMotorTorque(1300.0f);
    rearWheelJoint->SetMotorSpeed(-20.0f);
}

void Car::stopMove()
{
    rearWheelJoint->SetMaxMotorTorque(500.0f);
    rearWheelJoint->SetMotorSpeed(0.0f);

    frontWheelJoint->SetMaxMotorTorque(500.0f);
    frontWheelJoint->SetMotorSpeed(0.0f);
}

void Car::moveNitro()
{
    rearWheelJoint->SetMaxMotorTorque(320000.0f);
    rearWheelJoint->SetMotorSpeed(75.0f);
}

//will be called when user released the key
void Car::releasePedal()
{
    rearWheelJoint->SetMaxMotorTorque(10.0f);
    rearWheelJoint->SetMotorSpeed(0.0f);

    frontWheelJoint->SetMaxMotorTorque(10.0f);
    frontWheelJoint->SetMotorSpeed(0.0f);
}
