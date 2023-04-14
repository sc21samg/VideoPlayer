//
// Created by twak on 11/11/2019.
//

#ifndef CW2_THE_PLAYER_H
#define CW2_THE_PLAYER_H


#include <QApplication>
#include <QMediaPlayer>
#include "the_button.h"
#include <vector>
#include <QTimer>



class ThePlayer : public QMediaPlayer {

Q_OBJECT

private:
    std::vector<TheButtonInfo>* infos;
    std::vector<TheButton*>* buttons;
    QTimer* mTimer;
    long updateCount = 0;
    int volume;
    bool muted;

    //used to play sound for text to speech if required
    bool soundEnabled = false;
    QMediaPlayer *muteSound;
    QMediaPlayer *unmuteSound;
    QMediaPlayer *changeVolumeSound;
    QMediaPlayer *skipForwardSound;
    QMediaPlayer *rewindSound;
    QMediaPlayer *saveSound;

    void createSounds();

public:
    ThePlayer() : QMediaPlayer(NULL) {
        volume = 50;
        muted = false;
        setVolume(volume); // be slightly less annoying
        connect (this, SIGNAL (stateChanged(QMediaPlayer::State)), this, SLOT (playStateChanged(QMediaPlayer::State)));
        createSounds();

    }

    // all buttons have been setup, store pointers here
    void setContent(std::vector<TheButton*>* b, std::vector<TheButtonInfo>* i);


private slots:

    // change the image and video for one button every one second
    void playStateChanged (QMediaPlayer::State ms);

public slots:

    // start playing this ButtonInfo
    void jumpTo (TheButtonInfo* button);

    //mute/unmute the video
    void mute (bool mute);

    //change the volume
    void changeVolume(int newVolume);
 
    void changePos(int pos);

    //skip in the video 5 seconds forward/backwards
    void forward5sec();
    void back5sec();

    //Kunal's creation
    void save_current_video();

    //used to set whether the widget will play sound
    void enableSound(bool enable)
    {
        soundEnabled = enable;
    }

};

#endif //CW2_THE_PLAYER_H
