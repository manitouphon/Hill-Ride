#ifndef VECHICLESELECT_H
#define VECHICLESELECT_H

#include <QWidget>

namespace Ui {
class vechicleSelect;
}

class vechicleSelect : public QWidget
{
    Q_OBJECT

public:
    explicit vechicleSelect(QWidget *parent = nullptr);
    ~vechicleSelect();

private slots:
    void on_pushButton_clicked();


    void on_ChangeVRight_clicked();

    void on_ChangeVLeft_clicked();



signals:

    void backClicked();

private:
    Ui::vechicleSelect *ui;

};

#endif // VECHICLESELECT_H
