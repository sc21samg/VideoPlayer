#include <QWidget>
#include "play_pause.h"
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QStyle>


void Play_Pause::buttonClicked(bool checked)
{
    checked = Play_Pause::checked;
    //if true then changed symbol to pause else play
    if (checked)
    {
        play->setIcon(QIcon(":/Images/images/PauseIcon.png"));
        t->play();
        Play_Pause::checked = false;

        //playing sound if enabled
        if (soundEnabled)
            playSound -> play();
    }
    else
    {
        play->setIcon(QIcon(":/Images/images/PlayIcon.png"));
        t->pause();
        Play_Pause::checked = true;

        //playing sound if enabled
        if (soundEnabled)
            pauseSound -> play();
    }
}

void Play_Pause::createWidget()
{
    //initially creating play button
    play = new QPushButton();
    play->setCheckable(true);
    //setting initial icon to play
    play->setIcon(QIcon(":/Images/images/PlayIcon.png"));
    play->setIconSize(QSize(50,50));
}

void Play_Pause::createSounds()
{
    playSound = new QMediaPlayer();
    playSound -> setMedia(QUrl("qrc:/Sounds/sounds/videoControl/VideoNowPlaying.mp3"));

    pauseSound = new QMediaPlayer();
    pauseSound -> setMedia(QUrl("qrc:/Sounds/sounds/videoControl/VideoPaused.mp3"));
}

void Play_Pause::arrangeWidget()
{
    //adding widget into layout
    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(play);
    setLayout(layout);
}


void Play_Pause::makeConnections()
{
   connect(play, SIGNAL(clicked(bool)), this, SLOT(buttonClicked(bool)));
}

