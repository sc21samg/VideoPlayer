#ifndef REDOBUTTON_H
#define REDOBUTTON_H

#include <QPushButton>
#include <QMediaPlayer>

class RedoButton : public QPushButton
{
    Q_OBJECT
public:
    RedoButton(QWidget *parent = 0) : QPushButton(parent)
    {
        createWidget();
        createSound();
        makeConnections();
    }

private:
    //used to manage the playing of the screen reader sounds
    bool soundEnabled = false;
    QMediaPlayer *thisSound;

    void createWidget();
    void createSound();
    void makeConnections()
    {
        connect(this, SIGNAL(pressed()), this, SLOT(playSound()));
    }

public slots:
    //used to set whether the widget will play sound
    void enableSound(bool enable)
    {
        soundEnabled = enable;
    }

    //playing the sound when the button is clicked
    void playSound()
    {
        if (soundEnabled)
            thisSound -> play();
    }
};

#endif // REDOBUTTON_H
