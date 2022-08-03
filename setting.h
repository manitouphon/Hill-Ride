#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
#include "globalvar.h"
#include <QString>

namespace Ui {
class Setting;
}

class Setting : public QWidget
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = nullptr);
    ~Setting();



private slots:
    void on_BGM_Slider_valueChanged(int value);

    void on_Cancel_button_clicked();
    void on_SFX_Slider_valueChanged(int value);

    void on_Res_spinner_currentTextChanged(const QString &arg1);

    void on_Save_button_clicked();

    void on_fullScreen_toggled(bool checked);

signals:

    void backClicked();
    QString settingApplied();
    void screenFullscreen();
    void screenNormal();

private:
    Ui::Setting *ui;


};








#endif // SETTING_H
