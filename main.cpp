#include "mainmenu.h"
#include <QtQml/QQmlApplicationEngine>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplication>
#include <QQuickWindow>
#include <QQmlContext>


GlobalVar defaultSetting;   //This is a declaration that use the extern variable (Orignally declared in the globalVar.h)

int main(int argc, char *argv[])
{

    //First to note:
    //  defaultSetting (an Object): acts here as a backend and a storage to store some settings.
    //  *window (pointer): points to where the main.qml is running and located. (peek the process by going to line 33)
    // I sometimes wrote comments like this "NAME:Type" to make a better reference of what they are.
    //      For example: defaultSetting:object, windows:pointer, enterGameplay:function




    QGuiApplication app(argc, argv);
    QApplication gameplay(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/resource/main.qml")));

    //(To be honest this 2 lines of codes are copied from the internet but i works so well that I keep it xD)
    //DONT FORGET TO DELETE THE LAST LINE OF COMMENT WHEN SUBMIT.... IT WILL BE A LITTLE BIT sketchy ... xD

    QObject *topLevel = engine.rootObjects().value(0);
    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);
    //Explanation above.








    // connect our QML signal to our C++ slot
    QObject::connect(window, SIGNAL(sfxChanged(double)),
                         &defaultSetting, SLOT(onSfxVolumeChanged(double))
                     );





    //The window is a pointer for refering to the main.qml file.
    //The above line is a connector that listen to the signal emit from the main.qml
    //When there's the exact "sfxChanged(double)" signal is emited from the *windows(main.qml),
    //it then do the function "onSfxVolumeChanged(double), which is an object that acts as a backend and stores some settings
    //Like SFx volume, BGM volume, fullscreen status (apply and discuss later). defaultSetting is an object created using
    //globalVar class (globalVar.h && globalVar.cpp)






    QObject::connect(window, SIGNAL(bmgChanged(double)),
                         &defaultSetting, SLOT(onBmgVolumeChanged(double))
    //This one acts the same. It takes a parameter from the *window:QMLObject (QML) and give it to defaultSetting:Object


                     );
    QObject::connect(window, SIGNAL(enterGame(int)),
                     &defaultSetting, SLOT(enteringGame(int))
                     );
    //This triggers when there's a signal from *windows telling the backend (defaultSetting) to starts the game.
    //Which is the process of showing the gameplay (an private property of defaultSetting)


    QObject::connect(&defaultSetting, SIGNAL(showMainmenu()) ,
                     window, SLOT( gameplayOver() )
                     );
    //This one is inverted from the top:
    /*  Noted that the top twos is that The signals are from the *window (main.qml)
     *  and have slots connected in defaultSetting:object.
     *
     * But this one is different since we want the backend to tell the *window (main.qml) to know that the gameplay is over
     * and somehow need to show itself back.
     * In this case we connect the signal from the defaultSetting:object to the slot of *window (main.qml)
     *  What it means is that, when the gameplay is over, the backend (defaultSetting:object) will emit a signal
     *  that will triggers the slot in the *window (main.qml)
     *
     */




 return app.exec();
}


