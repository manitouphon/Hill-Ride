#ifndef LEVELSELECT_H
#define LEVELSELECT_H

#include <QWidget>



namespace Ui {
class levelSelect;
}

class levelSelect : public QWidget
{
    Q_OBJECT

public:
    explicit levelSelect(QWidget *parent = nullptr);
    ~levelSelect();

private slots:
    void on_BackButton_clicked();

    void on_MediumButton_clicked();

    void on_HardButton_clicked();

    void on_EasyButton_clicked();

    void clearingMsg();

signals:

    void backClicked();
    void enterGame();

private:
    Ui::levelSelect *ui;
};

#endif // LEVELSELECT_H
