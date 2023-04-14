#ifndef PLAY_PAUSE_H
#define PLAY_PAUSE_H

#include <QWidget>
#include <QPushButton>
#include <QVideoWidget>
#include <QMediaPlayer>


#include "the_player.h"

class QPushButton;
class ThePlayer;
class QVideoWidget;

class Play_Pause: public QWidget
{
    Q_OBJECT

    public:
        Play_Pause(ThePlayer* l, QWidget* parent = 0) : QWidget(parent)
        {
            t = l;
            //create the widget play/pause
            createWidget();
            //arranges the widgets as layout
            arrangeWidget();
            //creates the sound to be played for screen reading
            createSounds();
            //make signal and slot to change behaviour while clicked
            makeConnections();
        }

    private slots:

        void buttonClicked(bool);

    private:
        QPushButton* play;
        ThePlayer* t;
        bool checked = false;

        //used to manage playing of sounds for text to speech
        bool soundEnabled = false;
        QMediaPlayer *pauseSound;
        QMediaPlayer *playSound;

        void createWidget();
        void createSounds();
        void arrangeWidget();
        void makeConnections();

public slots:
        //used to set whether the widget will play sound
        void enableSound(bool enable)
        {
            soundEnabled = enable;
        }

};

#endif // PLAY_PAUSE_H
