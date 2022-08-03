#include "scene.h"
#include "widget.h"
#include "globalvar.h"
#include "caroffroadbody.h"
#include <QtDebug>
#include <QMessageBox>


// To be honest, i only understand 80% of this scene process.
// So, if my comments are not explicitly explained enough, ask me IRL

Scene::Scene(float32 x, float32 y, float32 width, float32 height, b2Vec2 b2Gravity) :
    QGraphicsScene (x * SCALE, y * SCALE, width * SCALE, height * SCALE)
{
    // This is a 2 states switcher.
    // I remebered that this is use for calculating the speed
    // when it's true , it will take for example:
        // I have 2 distance record variable named X1 and X2
            //When it's true it will record the X1 and inverts the distanceToggler:boolean
            //So that way we always get the speed in positive number.

    distanceToggler = true;

    // Creates a new world
    world = new b2World(b2Gravity);

    frameTime = new QTimer(this);
    connect(frameTime, SIGNAL(timeout()), this, SLOT(syncUp()));
    frameTime->start(1000/60);



    //Fetch the current level that players need to play.

    if(defaultSetting.getCurrentLevel() ==1 )
    {
        map_1 = new Map_1(world, this);
    }
    else if(defaultSetting.getCurrentLevel() ==2 )
    {
        map_2 = new Map_2(world,this);
    }



    //Create the car. (at X=4, Y=0)
    car = new Car(4.0f, 0.0f, this, world);


    //Signals and slots connectors:
    connect(this,SIGNAL(showWonMsg() )
            ,this,SLOT(showingWonMsg() ));

}




Scene::~Scene()
{

}





//  Functions:






void Scene::syncUp()
{


    if(distanceToggler == true ){        //if Ture assign to vDistance[0] else assign to vDistance[1]
        vDistance[0] = car->getCarPos().x();
    }
    else {
        vDistance[1] = car->getCarPos().x();
    }
    distanceToggler = !distanceToggler;     //There's one reason why i named it as a "toggler".


    //When to emmit the winning message signal:
        //If the X coordination of the car matches the finish line position, it means the player reaches the end of the map.
    if(car->getCarPos().x() >= defaultSetting.getFinishLinePos()  ) {

        emit showWonMsg();

    }
    else {

    world->Step(1.0f/60.0f, 6, 2);

    QGraphicsScene::advance();


    //position the viewport to get the car in the center (Following camera):
    this->views()[0]->centerOn(car->getCarPos());
    this->views()[0]->centerOn(car->getCarBody());


//    this->view->centerOn(car->getCarPos());   //Difference not Found


    qDebug() << "current Car X:" << car->getCarPos().x() <<
                "current car Y:" << car->getCarPos().y() ;


    //Calculate the remain distance between the finish line and the car.
    defaultSetting.editRemainingDistance(car->getCarPos().x(),defaultSetting.getFinishLinePos());

    //Calculate the speed:
    if ( (vDistance[1] - vDistance[0]) >= 0 ){
        defaultSetting.editCurrentCarSpeed( (vDistance[1]-vDistance[0]) / (0.6f) );
    }
    else {
        defaultSetting.editCurrentCarSpeed( (vDistance[0]-vDistance[1]) / (0.6f) );
    }

    emit gameSync();
    }

}


//Will be emit when the player reaches the last posistion.
void Scene::showingWonMsg()
{
    //Reset the finish line posistion to zero
    defaultSetting.editFinishLinePos(0);

    QMessageBox * wonMsg = new QMessageBox;
    wonMsg->setWindowTitle("Congratulation");
    wonMsg->setText("You won! The game. Please click 'OK' to continue");
    wonMsg->show();
    emit exitGame();



}




void Scene::keyPressEvent(QKeyEvent *event)
{


    if (event->key() == Qt::Key_D)
    {
        emit moveCarForward();
    }
    else if (event->key() == Qt::Key_S)
    {
        emit stopMoveCar();
    }
    else if (event->key() == Qt::Key_A)
    {
        emit moveCarBackward();
    }
    else if (event->key() == Qt::Key_Escape){
        emit exitGame();

    }
    else if (event->key() == Qt::Key_Shift ){
        emit moveCarNitro();
    }
}

void Scene::keyReleaseEvent(QKeyEvent *event)
{
    emit releaseAcceleration();
}
