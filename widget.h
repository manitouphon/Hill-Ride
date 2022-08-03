#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <QList>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QKeyEvent>
#include "car.h"
#include "scene.h"
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
signals:
    void GameplayTerminated();

public slots:
    void exitGameplay();
    void syncUp();
    void carSpeedSyncer();



private:
    Ui::Widget *ui;
    Scene * scene;
    QTimer * carSpeedTimer;
};

#endif // WIDGET_H
