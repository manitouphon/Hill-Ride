#include "globalvar.h"
#include <QSize>
#include <QThread>

//Welcome to the backend and setting storage, the most crucial class that we use to do something cool. (not joking)
//This is the body of the class GlobalVar:class.
//There's only 1 instantiation of this class (declared as an extern variable in the globalVar.h)
//Please take note that some part that I didn't write any comments.
//  Mostly because they don't functions in the runtime or some are left due to not using them ...... (kinda sad)

//Let's start:

//Constructor
GlobalVar::GlobalVar(QObject *parent)
{
    //This one will store the current software screen resolution (not implanted yet but it's still here just in case
    // one day someone wants to continue this by adding some cool features, this will abstracts some complexity (even tho not much)
    currentGeometry.setWidth(1024);
    currentGeometry.setHeight(576);
    isFullScreen = 0;




}


//Below are the definition of each public methods.

//Get functions definitions:




bool GlobalVar::fullScreenStatus(){
    return  isFullScreen;
}

float GlobalVar::getCurrentCarSpeed()
{
    return currentCarSpeed;
}

int GlobalVar::getRemainingDistance()
{
    return remainingDistance;
}

int GlobalVar::getFinishLinePos()
{
    return  finishLinePos;
}

int GlobalVar::getCurrentLevel()
{
    return currentLevel;
}






//edit funtions definitions:




void GlobalVar::editFullScreenStatus(bool status)
{
    isFullScreen=status;
}
void GlobalVar::editGeometry(int x, int y, int w, int h){
    currentGeometry.setX(x);
    currentGeometry.setY(y);
    currentGeometry.setWidth(w);
    currentGeometry.setHeight(h);

}

void GlobalVar::editCurrentCarSpeed(float newCarSpeed)
{
    currentCarSpeed = newCarSpeed;
}


//This is what you see on the gameplay (the remaining distance)
void GlobalVar::editRemainingDistance(int currentCarX, int finishLineX)
{
    remainingDistance = (finishLineX - currentCarX) / 60 ;

}



void GlobalVar::editFinishLinePos(int newFinishLinePos)
{
    finishLinePos = newFinishLinePos;
}

void GlobalVar::editCurrentLevel(int newLevel)
{
    currentLevel = newLevel;
}






//Here's a slot that sets the current background music and SFX to match with both c++ and QML

void GlobalVar::onBmgVolumeChanged(double newBmg)
{
    _bmgVol = newBmg;
    qDebug() << "BmgVolume in C++: " << newBmg;
}

void GlobalVar::onSfxVolumeChanged(double newSfx)
{
    _sfxVol = newSfx;
    qDebug() << "SfxVolume in C++: " << newSfx;
}







//-------------------------------------------------------------------------

//Backends works





void GlobalVar::enteringGame(int gamemode)
{
    //We set the current level to game mode to know which button (easy, meduim or hard) is pressed
    currentLevel = gamemode;

    //Check if the Gameplay:pointer is not empty
    if (Gameplay != nullptr)
        {
            //If it's NOT empty, make it empty
           Gameplay = nullptr;

        }
        //Then we can make a new widget from the Gamplay:pointer
            Gameplay= new Widget;
            //Connect the signal here (because when Gameplay ==nullptr , we can't connect them since it's empty)
            connect(Gameplay, SIGNAL(GameplayTerminated()),
                    this, SLOT(whenGameplayTerminated())
                    );

            //I don't quite remember why i put this line but
            // as the legend says, if it works, don't fix it.
            //JK (I think this was added due to the probability of the game is not showing anything at all at the start
            //  and crashes. So, I add a 2s wait time ... and it works.
            QThread::msleep(2000);

            //Since all the previous process are just background, we need to show it.
            Gameplay->showNormal();
}


//This is a slot when the gameplay is terminated (
   //   (SINGAL SOURCE: Gameplay:pointerToObject, SIGNAL( GameplayTerminated() )
void GlobalVar::whenGameplayTerminated()
{
    //First thing first, show the mainmenu back.
    emit showMainmenu();
    // Connect statement: main.cpp


    //Disconnect to avoid some errors and reduce the listen operation.
    disconnect(Gameplay, SIGNAL(GameplayTerminated()),
            this, SLOT(whenGameplayTerminated())
            );
    //Make the gameplay:pointer as a null pointer.
    Gameplay = nullptr;

}


//Something that will be useful when exit
    // (but it was never called) ... (kinda sad again.)
void GlobalVar::execTheExitSeq()
{
    Gameplay = nullptr;
    delete this;

}








