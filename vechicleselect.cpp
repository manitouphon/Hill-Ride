#include "vechicleselect.h"
#include "ui_vechicleselect.h"
#include "mainmenu.h"


vechicleSelect::vechicleSelect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::vechicleSelect)
{
    ui->setupUi(this);
    ui->StackedVehicleWidget->setCurrentIndex(0);
}

vechicleSelect::~vechicleSelect()
{
    delete ui;
}

void vechicleSelect::on_pushButton_clicked()
{
    emit backClicked();
}

void vechicleSelect::on_ChangeVRight_clicked()
{
    int index= ui->StackedVehicleWidget->currentIndex();
    ui->StackedVehicleWidget->setCurrentIndex( index + 1);
}

void vechicleSelect::on_ChangeVLeft_clicked()
{
    int index= ui->StackedVehicleWidget->currentIndex();
    ui->StackedVehicleWidget->setCurrentIndex( index - 1);
}


