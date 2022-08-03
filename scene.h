#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <Box2D/Box2D.h>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include "car.h"
#include "map_1.h"
#include "map_2.h"




class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Scene(float32 x, float32 y, float32 width, float32 height, b2Vec2 b2Gravity); //Create world of Box2D and also QGraphicsScene
                                                                                  //Accept argument in meter unit of Box2D
    ~Scene();
public: signals:
    void moveCarForward();
    void moveCarBackward();
    void stopMoveCar();
    void moveCarNitro();
    void releaseAcceleration();
    void exitGame();
    void showWonMsg();
    void gameSync();


private slots:
    void syncUp();
    void showingWonMsg();
private:
    QGraphicsView * view;
    b2World * world; //world for Box2D simulation
    QTimer * frameTime; //timer for syncing Box2D simulation world to QGraphicsScene
                        //This will emit timeout() signal 60 times per second

    Car * car;
    Map_1 * map_1;
    Map_2 * map_2;


    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private:
    const int SCALE = 60;

    bool distanceToggler;       //Made for toggleing the assignment betwwen vDistance[0] or vDistance[1]
    float vDistance[2];         //Made for assign the current car posistion every 60ms and
};

#endif // SCENE_H
