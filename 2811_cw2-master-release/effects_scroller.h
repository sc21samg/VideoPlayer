#ifndef EFFECTSCROLLER_H
#define EFFECTSCROLLER_H

#include <QScrollArea>
#include "effects_selector.h"

class EffectsScroller : public QScrollArea
{
    Q_OBJECT
public:
    EffectsScroller(QWidget *parent = 0) : QScrollArea(parent)
    {
        createWidgets();
        createSound();
        arrangeWidgets();
        makeConnections();
        this -> hide();
        setHidden(true);
    }

    EffectsSelector* widget() {return content;}

private:
    EffectsSelector *content;

    //used to manage sound playing
    bool soundEnabled = false;
    QMediaPlayer *thisSound;

    void createWidgets();
    void createSound();
    void arrangeWidgets();
    void makeConnections()
    {
        connect(this, SIGNAL(usingSound(bool)), content, SLOT(enableSound(bool)));
    }

signals:
    void usingSound(bool);

public slots:
    void toggleHidden();

    //used to set whether the widget will play sound emit to childeren what the setting is
    void enableSound(bool enable)
    {
        soundEnabled = enable;
        emit usingSound(soundEnabled);
    }
};

#endif // EFFECTSSCROLLER_H
