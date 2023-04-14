#include "undo_button.h"

void UndoButton::createWidget()
{
    setIcon(QIcon(":/Images/images/UndoIcon.png"));
    setIconSize(QSize(25, 25));
    setMinimumSize(QSize(40, 35));
    setStyleSheet("padding: 7px; background-color:white; margin-left:20px; border: 1px solid white;");
}

void UndoButton::createSound()
{
    thisSound = new QMediaPlayer();
    thisSound -> setMedia(QUrl("qrc:/Sounds/sounds/overallControl/UndoneLastAction.mp3"));
}
