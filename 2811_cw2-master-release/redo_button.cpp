#include "redo_button.h"

void RedoButton::createWidget()
{
    setIcon(QIcon(":/Images/images/RedoIcon.png"));
    setIconSize(QSize(25, 25));
    setMinimumSize(QSize(40, 35));
    setStyleSheet("padding: 7px; margin-left: 2px; background-color:white; border: 1px solid white;");
}

void RedoButton::createSound()
{
    thisSound = new QMediaPlayer();
    thisSound -> setMedia(QUrl("qrc:/Sounds/sounds/overallControl/Redo.mp3"));
}
