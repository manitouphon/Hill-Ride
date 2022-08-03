#include "messagesvar.h"
#include <QMessageBox>

MessagesVar::MessagesVar()
{


}

void MessagesVar::showWinningMessageBox()
{
    wonMsgBox.show();
}

void MessagesVar::setWinningMessageBox(QString newMsg)
{
    wonMsgBox.setWindowTitle("congratulation You Won!");
    wonMsgBox.setcButtonText(0,"Gotcha!");
    wonMsgBox.setText(newMsg);
}
