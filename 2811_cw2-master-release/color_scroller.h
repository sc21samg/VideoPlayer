#ifndef COLORSCROLLER_H
#define COLORSCROLLER_H

#include <QScrollArea>
#include "color_selector.h"

class ColorScroller : public QScrollArea
{
    Q_OBJECT
public:
    ColorScroller(QWidget *parent = 0) : QScrollArea(parent)
    {
        createWidgets();
        createSound();
        arrangeWidgets();
        makeConnections();
        this -> hide();
        setHidden(true);
    }

    ColorSelector* widget() {return content;}

private:
    ColorSelector *content;

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

#endif // COLORSCROLLER_H
