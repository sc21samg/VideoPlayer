#include "mute_button.h"
#include <QPushButton>
#include <QObject>
#include <QStyle>

//setting the appearence of the mute button to allign with its state
void MuteButton::setAppearence()
{
    if (value == true)
        setIcon(QIcon(mutedIconLoc));
    else
        setIcon(QIcon(soundIconLoc));
}

void MuteButton::changeAppearence()
{
    setAppearence();
}

//connecting the pressing of the button to change the button's state and appearence
void MuteButton::makeConnections()
{
    connect(this, SIGNAL(pressed()), this, SLOT(changeValue()));
    connect(this, SIGNAL(pressed()), this, SLOT(changeAppearence()));
}
