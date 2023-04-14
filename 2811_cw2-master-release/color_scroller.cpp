#include "color_scroller.h"
#include "color.h"
#include <QLayout>

void ColorScroller::createWidgets()
{
    content = new ColorSelector();

    setFixedHeight(content -> height() + 23);
}

void ColorScroller::arrangeWidgets()
{
    setWidget(content);
}

void ColorScroller::createSound()
{
    thisSound = new QMediaPlayer();
    thisSound -> setMedia(QUrl("qrc:/Sounds/sounds/colors/SelectColor.mp3"));
}

void ColorScroller::toggleHidden()
{
    if (isHidden())
    {
        this->show();
        setHidden(false);

        if (soundEnabled)
            thisSound -> play();
     }
     else
     {
        this->hide();
        setHidden(true);
     }
}
