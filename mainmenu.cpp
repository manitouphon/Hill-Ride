#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "globalvar.h"


#include <QPalette>
#include <QPixmap>
#include <QSoundEffect>
#include <QtDebug>
#include "widget.h"
#include <QThread>
#include <QFontDatabase>

#include <QStyle>
#include <QDesktopWidget>


GlobalVar defaultSetting ;


MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
        //Centered the window with the aspect to the desktop
    this->setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    this->size(),
                    qApp->desktop()->availableGeometry()));


    Gameplay = nullptr;

    ui->setupUi(this);
    QWidget::setWindowTitle("Hill Climb");

    defaultSetting.currentGeometry = this->geometry() ;


        //Applying the background to the MainMenu and it's other stacked widgets.
    QPixmap background(":/images/resource/Background.jpg");
    background.scaled(1024,
                      576,
                      Qt::KeepAspectRatio);
    QPalette BgImage;
    BgImage.setBrush(QPalette::Background,background);
    this->setPalette(BgImage);

        /*Dynamically add another stacked widget to inherite the ui from the other stacked widget
         (beside from MainMenu UI) to dynamically added into the MainMenu Stacked Widget
        */

    ui->stackedWidget->insertWidget(1,& _levelSelect);
    ui->stackedWidget->insertWidget(2,&_vehicleSelect);
    ui->stackedWidget->insertWidget(3,&_setting);
    ui->stackedWidget->insertWidget(4,&_help);


    ui->stackedWidget->setCurrentIndex(0);

        //Connect the custom signals and slots:

    connect(&_setting, SIGNAL( backClicked() ),
            this,SLOT( backToMainMenu() ));

    connect(&_vehicleSelect, SIGNAL( backClicked() ),
            this,SLOT( backToMainMenu() ));

    connect(&_levelSelect, SIGNAL(backClicked() ),
            this, SLOT( backToMainMenu() ));

    connect(&_help, SIGNAL(backClicked() ),
            this, SLOT( backToMainMenu()));

    connect(&_setting, SIGNAL( settingApplied() ),
            this, SLOT(applySettings()));

    connect(&_levelSelect, SIGNAL( enterGame() ),
            this, SLOT(enteringGame() ));

    connect(this,SIGNAL(clearMsg() ),
            &_levelSelect, SLOT(clearingMsg() ));

    connect(&_setting, SIGNAL( screenFullscreen() ),
            this, SLOT( applyFullscreen() ));

    connect(&_setting, SIGNAL( screenNormal() ),
            this, SLOT(applyNormalScreen() ));





        //setup the background music:

    defaultSetting.MainMenuBGM.setSource(QUrl::fromLocalFile(":/music/resource/bgm.wav"));
    defaultSetting.MainMenuBGM.setLoopCount(QSoundEffect::Infinite);
    defaultSetting.MainMenuBGM.setVolume(defaultSetting.getBgmVol());
    defaultSetting.MainMenuBGM.play();

        //initialize custom fonts:
    QFontDatabase::addApplicationFont(":/fonts/fonts(Must install)/AKbalthom Freehand [Version 1.50] 082014.ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts(Must install)/AKbalthom HighSchool-Frame [Version 1.10] 082014.ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts(Must install)/AKbalthom HighSchool-Fun.ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts(Must install)/AKbalthom HighSchool.ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts(Must install)/AKbalthom Kbach [Version 1.50] 082014.ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts(Must install)/AKbalthom KhmerBasic.ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts(Must install)/AKbalthom KhmerHand.ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts(Must install)/AKbalthom KhmerLer [Version 2.00].ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts(Must install)/AKbalthom Seoul.ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts(Must install)/AKbalthom Superhero.ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts(Must install)/AKbalthom SuperheroKH.ttf");



}

MainMenu::~MainMenu()
{
    delete ui;
}




    // ***Custom Signal:

void MainMenu::backToMainMenu()
{
    this->setVisible(true);
    ui->stackedWidget->setCurrentIndex(0);
}

void MainMenu::enteringGame()
{
    defaultSetting.currentGeometry = this->geometry();
    if (Gameplay != nullptr)
    {
       Gameplay = nullptr;

    }

        Gameplay= new Widget;
        connect(Gameplay, SIGNAL(GameplayTerminated()),
                this, SLOT(backToMainMenu() ));

        QThread::msleep(2000);

        if(defaultSetting.isFullScreen)
        {
            Gameplay->showFullScreen();
        }
        else {
            Gameplay->showNormal();
        }

        ui->stackedWidget->setCurrentIndex(0);
        emit clearMsg();
    this->setVisible(false);
}

void MainMenu::applyFullscreen()
{
    this->showFullScreen();
}

void MainMenu::applyNormalScreen()
{
    this->showNormal();
}



void MainMenu::applySettings()
{
    defaultSetting.currentGeometry = this->geometry() ;
    if(defaultSetting.fullScreenStatus()==false){

        defaultSetting.currentGeometry.setX(  defaultSetting.currentGeometry.x() +
                                              ((defaultSetting.currentGeometry.width()/2) - (defaultSetting.nextGeometry.width()/2))
                                            );
        defaultSetting.currentGeometry.setY(  defaultSetting.currentGeometry.y() +
                                              ((defaultSetting.currentGeometry.height()/2) - (defaultSetting.nextGeometry.height()/2))
                                            );





        defaultSetting.currentGeometry.setWidth(defaultSetting.nextGeometry.width());
        defaultSetting.currentGeometry.setHeight(defaultSetting.nextGeometry.height());
        MainMenu::setGeometry(defaultSetting.currentGeometry);

    }




}




    //***Generated From UI form class:
void MainMenu::on_SettingButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainMenu::on_changeVehicleButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainMenu::on_PlayButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainMenu::on_HelpButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainMenu::on_QuitButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void MainMenu::on_pushButton_clicked()
{
    this->close();
}

void MainMenu::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
