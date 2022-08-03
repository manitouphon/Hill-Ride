#ifndef GLOBALVAR_H
#define GLOBALVAR_H

/*
    The reasons why I make this seems to be like all the private variables are Readable and write-able
    because these variables are needed to change in setting screen.
    I group them in private access modifier because we might have some that can be READ only variable.
    So Let's just make this global class's structure looks professional. xD
*/

#include <QRect>
#include <QSoundEffect>
#include <QPixmap>
#include <QPalette>
#include <QPoint>
#include <QRegion>

#include "widget.h"

class GlobalVar : public QObject
{
    Q_OBJECT



public:

    //Constructor:

    explicit GlobalVar(QObject *parent = 0);

    //Get Private Var:


    QRect currentGeometry;
    QRect nextGeometry;
    bool fullScreenStatus();
    QPixmap *background;
    float getCurrentCarSpeed();
    int getRemainingDistance();
    int getFinishLinePos();
    int getCurrentLevel();
    double bmgVolume() { return _bmgVol; }
    double sfxVolume() { return _sfxVol; }


    //Edit Private Var:


    void editFullScreenStatus(bool status);
    void editGeometry(int x, int y, int w, int h);
    void editCurrentCarSpeed(float newCarSpeed);
    void editRemainingDistance(int currentCarX, int finishLineX);
    void editFinishLinePos(int newFinishLinePos);
    void editCurrentLevel(int newLevel);

    void setBmgVolume(double bmgVol);
    void setSfxVolume(double sfxVol);


    // variables:
    bool isFullScreen;

signals:
    void showMainmenu();





private:



    Widget * Gameplay;

    double _bmgVol;
    double _sfxVol;

    int finishLinePos;
    float currentCarSpeed;
    int remainingDistance;
    int currentLevel;

private slots:

    void onBmgVolumeChanged(double newBmg);
    void onSfxVolumeChanged(double newSfx);
    void enteringGame(int gamemode);
    void whenGameplayTerminated();

    void execTheExitSeq();  //Execute the exit sequences


};

extern GlobalVar defaultSetting;    //Extern variable that will be use for storing the backend operations and
                                    //You guess it, the default settings.

#endif // GOBALVAR_H
