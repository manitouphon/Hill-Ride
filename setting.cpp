#include "setting.h"
#include "ui_setting.h"
#include "mainmenu.h"


#include <QSoundEffect>
#include <QPixmap>
#include <QPalette>
#include <QVariant>
#include <QSize>
//#include <QtDebug>






Setting::Setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);

            //Apply the current right setting to show in the Resolution Spinner:
    //Resolutions:
    if (defaultSetting.currentGeometry.width() == 1920 &&
        defaultSetting.currentGeometry.height() == 1080)
    {

        ui->Res_spinner->setCurrentIndex(0);
    }

    if (defaultSetting.currentGeometry.width() == 1280 &&
        defaultSetting.currentGeometry.height() == 720)
    {
        ui->Res_spinner->setCurrentIndex(1);
    }

    if ( defaultSetting.currentGeometry.width() == 1024 &&
         defaultSetting.currentGeometry.height() == 576)
    {
        ui->Res_spinner->setCurrentIndex(2);
    }

    if ( defaultSetting.currentGeometry.width() ==  896 &&
         defaultSetting.currentGeometry.height() == 504 )
    {
        ui->Res_spinner->setCurrentIndex(3);
    }

    //Volumes:


    //FullscreenStatus:
    if( defaultSetting.fullScreenStatus() == true )
    {
        ui->fullScreen->clicked( 1 );
    }
    else {
        ui->fullScreen->clicked( 0 );
    }


}

Setting::~Setting()
{
    delete ui;
}






    //Auxilary Functions:

            //Converts an integer into a Qstring:

    QString intToStr(int value)
    {
        QVariant x(value);
                 //Qvariant allows to convert into string and others. The x variant the value variable that is ready to convert to any basic c++ data types.

        QString convertedValue = x.toString();
                  //x.toString: converts the x variant to a Qstring.
        return convertedValue;
                 //return as a Qstring , ofc.... xD
    }



            //Converts the Qslider return value(int) to a suitable qreal(double) volume for changing the volume:

    double intToDouble(double value)
    {
        double convertedValue=0.0;
        convertedValue = value / 100;
//        qDebug() <<  convertedValue ; //Works Like a charm xD
        return  convertedValue;
    }




//Slots :
    //Custom signals are the signals that is made from scratch and we need to emit and connect them.


    //Purely custom:
    void Setting::on_Cancel_button_clicked()
    {
        emit backClicked();

    }

    //Native with custom:

void Setting::on_BGM_Slider_valueChanged(int value)
{

    ui->current_BGM_vol->setText( intToStr(value) );
    ui->Save_button->setEnabled(1);


    defaultSetting.editBgmVol( intToDouble(value) );
    qDebug() << defaultSetting.getBgmVol();
    defaultSetting.MainMenuBGM.setVolume( intToDouble(value) );
}

void Setting::on_SFX_Slider_valueChanged(int value)
{
    ui->current_SFX_vol->setText( intToStr(value) );
    ui->Save_button->setEnabled(1);

}

void Setting::on_Res_spinner_currentTextChanged(const QString &arg1)
{

    ui->Save_button->setEnabled(1);
            //Set the save button to be clickable.


            //Make a new temporary variable that store the new changes which will apply to the global settings variable.

            //Set the new ScreenSize according to the new Setting that is applied:
    if ( arg1 == "1920 x 1080")
    {
        defaultSetting.nextGeometry.setWidth(1920);
        defaultSetting.nextGeometry.setHeight(1080);

    }
    
    if ( arg1 == "1280 x 720")
    {
        defaultSetting.nextGeometry.setWidth(1280);
        defaultSetting.nextGeometry.setHeight(720);
    }    
    if ( arg1 == "1024 x 576")
    {
        defaultSetting.nextGeometry.setWidth(1024);
        defaultSetting.nextGeometry.setHeight(576);
    }

//    qDebug() <<"Width:" <<defaultSetting.currentGeometry.width()<<"\n"
//             <<"Height:"<<defaultSetting.currentGeometry.height();


}

void Setting::on_Save_button_clicked()
{
        //Apply the new screen fullscreen status:
    emit settingApplied();


}

void Setting::on_fullScreen_toggled(bool checked)
{
    defaultSetting.editFullScreenStatus( checked );
    if(checked == 1 ){
        emit screenFullscreen();
    }
    else {
        emit screenNormal();
    }
}
