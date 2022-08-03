#include "tutorial.h"
#include "ui_tutorial.h"

tutorial::tutorial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tutorial)
{
    ui->setupUi(this);
}

tutorial::~tutorial()
{
    delete ui;
}

void tutorial::on_backButton_clicked()
{
    emit backClicked();
}
