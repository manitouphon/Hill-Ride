#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "setting.h"
#include "vechicleselect.h"
#include "globalvar.h"
#include "levelselect.h"
#include "tutorial.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

signals :
    void clearMsg();
    void syncToGameWidget();


private slots:
        //custom slots:

    void backToMainMenu();
    void applySettings();
    void enteringGame();
    void applyFullscreen();
    void applyNormalScreen();


        //Generated from UI form editor Slots:

    void on_SettingButton_clicked();

    void on_changeVehicleButton_clicked();

    void on_PlayButton_clicked();

    void on_HelpButton_clicked();

    void on_QuitButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainMenu *ui;
    Setting _setting;
    levelSelect _levelSelect;
    vechicleSelect _vehicleSelect;
    tutorial _help;
    Widget * Gameplay;
};

#endif // MAINMENU_H
