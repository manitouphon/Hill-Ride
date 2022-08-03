#include "levelselect.h"
#include "ui_levelselect.h"
#include "widget.h"
#include "mainmenu.h"
#include <QThread>
#include "globalvar.h"

GlobalVar defaultSetting;

levelSelect::levelSelect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::levelSelect)
{
    ui->setupUi(this);


}

levelSelect::~levelSelect()
{
    delete ui;
}

void levelSelect::on_BackButton_clicked()
{
    emit backClicked();
    ui->msgLabel->clear();
}




void levelSelect::on_EasyButton_clicked()
{
    ui->msgLabel->setText("Loading . . . ");
    defaultSetting.editCurrentLevel(1);

    emit enterGame();
}

void levelSelect::on_MediumButton_clicked()
{
    ui->msgLabel->setText("Loading . . . ");
    defaultSetting.editCurrentLevel(2);

    emit enterGame();
}

void levelSelect::on_HardButton_clicked()
{
    ui->msgLabel->setText("Coming Soon!");
}


void levelSelect::clearingMsg()
{
    ui->msgLabel->setText("");

}


