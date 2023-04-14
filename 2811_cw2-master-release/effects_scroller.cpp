#include "effects_scroller.h"
#include "effects.h"
#include <QLayout>

void EffectsScroller::createWidgets()
{
    content = new EffectsSelector();

    setFixedHeight(content -> height() + 23);
}

void EffectsScroller::createSound()
{
    thisSound = new QMediaPlayer();
    thisSound -> setMedia(QUrl("qrc:/Sounds/sounds/effects/ApplyEffects.mp3"));
}

void EffectsScroller::arrangeWidgets()
{
    setWidget(content);
}

void EffectsScroller::toggleHidden()
{
    if (isHidden())
    {
        this->show();
        setHidden(false);

        //playing sound if it is enabled
        if (soundEnabled)
            thisSound -> play();
     }
     else
     {
        this->hide();
        setHidden(true);
     }
}
