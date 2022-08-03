#ifndef CAR_H
#define CAR_H

#include "wheel.h"
#include "caroffroadbody.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QDebug>

class Car : public QObject
{
    Q_OBJECT
public:
    explicit Car(float32 initX, float32 initY, QGraphicsScene * scene, b2World * world);
    ~Car();
    CarBody *getCarBody() const;
    QPoint getCarPos();

public slots:
    void moveForward();
    void moveBackward();
    void stopMove();
    void moveNitro();
    void releasePedal();

private:
    CarBody * carBody;
    Wheel * frontWheel;
    Wheel * rearWheel;
    b2WheelJoint * frontWheelJoint;
    b2WheelJoint * rearWheelJoint;


};

#endif // CAR_H
