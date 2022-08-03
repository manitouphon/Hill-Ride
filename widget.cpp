#include "widget.h"
#include "ui_widget.h"
#include <QtQml/QQmlApplicationEngine>
#include "globalvar.h"
#include <QThread>
#include <QMessageBox>



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene = new Scene(0.0f, -5.0f, 200.0f, 500.0f, b2Vec2(0.0f, 9.8f));
    ui->graphicsView->setScene(scene);

    connect(scene, SIGNAL( exitGame() ) ,
            this, SLOT( exitGameplay() ) );
    connect(scene, SIGNAL(gameSync() ),
            this, SLOT(syncUp() ));





    if(defaultSetting.getCurrentLevel() == 1){
        Widget::setWindowTitle("Mt. Rocky");
    }
    else if (defaultSetting.getCurrentLevel() == 2) {
        Widget::setWindowTitle("Icy North Pole");
    }
    else if (defaultSetting.getCurrentLevel() == 3){
        Widget::setWindowTitle("UNDERTERMINED");
    }


    Widget::setGeometry(defaultSetting.currentGeometry);



    ui->speedIndicator->setNum(defaultSetting.getCurrentCarSpeed());
    ui->RemainingDistanceIndicator->setNum(defaultSetting.getRemainingDistance());

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Make a timer for 1/2s:
    carSpeedTimer= new QTimer(this);
    connect(carSpeedTimer, SIGNAL(timeout()), this, SLOT(carSpeedSyncer()));
    carSpeedTimer->start(1000/2);       //Timeout 2 times/second

    //Load the correct Level lable on the top:
    if(defaultSetting.getCurrentLevel() == 1){
        ui->levelIndicator->setText("Easy Level");
    }
    else if (defaultSetting.getCurrentLevel() == 2) {
        ui->levelIndicator->setText("Medium Level");
    }
    else if (defaultSetting.getCurrentLevel() == 3) {
        ui->levelIndicator->setText("Hard Level");
    }
    else {
        ui->levelIndicator->setText("ERROR");
    }


}

Widget::~Widget()
{
    delete ui;
    delete scene;
    emit GameplayTerminated();

}
















void Widget::exitGameplay()
{
    //change the current widget posistion in case the player move the widget while on the gameplay process.
    defaultSetting.editGeometry(Widget::geometry().x(),Widget::geometry().y(),Widget::geometry().width(),Widget::geometry().height());

    //Call up the deconstructor.
    this->~Widget();

    emit GameplayTerminated();



}

void Widget::syncUp()
{
    ui->RemainingDistanceIndicator->setNum(defaultSetting.getRemainingDistance());
    ui->graphicsView->update();
}

void Widget::carSpeedSyncer()
{
    ui->speedIndicator->setNum( round(defaultSetting.getCurrentCarSpeed()) );
}





