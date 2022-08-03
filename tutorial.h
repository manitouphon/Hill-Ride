#ifndef TUTORIAL_H
#define TUTORIAL_H

#include <QWidget>

namespace Ui {
class tutorial;
}

class tutorial : public QWidget
{
    Q_OBJECT

public:
    explicit tutorial(QWidget *parent = nullptr);
    ~tutorial();

private slots:


    void on_backButton_clicked();

signals:
    void backClicked();

private:
    Ui::tutorial *ui;
};

#endif // TUTORIAL_H









