//
// Created by twak on 11/11/2019.
//

#include "the_player.h"
#include <QFile>

//creates the sounds for the various actions performed on the video
void ThePlayer::createSounds()
{
    muteSound = new QMediaPlayer();
    muteSound -> setMedia(QUrl("qrc:/Sounds/sounds/volumeControl/VideoMuted.mp3"));

    unmuteSound = new QMediaPlayer();
    unmuteSound -> setMedia(QUrl("qrc:/Sounds/sounds/volumeControl/VideoUnmuted.mp3"));

    changeVolumeSound = new QMediaPlayer();
    changeVolumeSound -> setMedia(QUrl("qrc:/Sounds/sounds/volumeControl/VolumeChanged.mp3"));

    skipForwardSound = new QMediaPlayer();
    skipForwardSound -> setMedia(QUrl("qrc:/Sounds/sounds/videoControl/Skipped5SecondsForward.mp3"));

    rewindSound = new QMediaPlayer();
    rewindSound -> setMedia(QUrl("qrc:/Sounds/sounds/videoControl/GoneBack5Seconds.mp3"));

    saveSound = new QMediaPlayer();
    saveSound -> setMedia(QUrl("qrc:/Sounds/sounds/overallControl/VideoSaved.mp3"));
}

// all buttons have been setup, store pointers here
void ThePlayer::setContent(std::vector<TheButton*>* b, std::vector<TheButtonInfo>* i) {
    buttons = b;
    infos = i;
    jumpTo(buttons -> at(0) -> info);
}

void ThePlayer::playStateChanged (QMediaPlayer::State ms) {
    switch (ms) {
        case QMediaPlayer::State::StoppedState:
            play(); // starting playing again...
            break;
        break;
    default:
        break;
    }
}

void ThePlayer::jumpTo (TheButtonInfo* button) {
    setMedia( * button -> url);
    play();
}

void ThePlayer::mute (bool mute)
{
    muted = mute;

    if (muted == false)
    {
        setVolume(volume);

        //playing sound if required
        if (soundEnabled)
            unmuteSound -> play();
    }
    else
    {
        setVolume(0);

        //playing sound if required
        if (soundEnabled)
            muteSound -> play();
    }
}

void ThePlayer::changeVolume (int newVolume)
{
    volume = newVolume;

    if (muted == false)
        setVolume(volume);

    //playing sound if required
    if (soundEnabled)
        changeVolumeSound -> play();
}

void ThePlayer::changePos(int pos){
    setPosition(pos*1000);
}

void ThePlayer::forward5sec(){
    setPosition(position()+5000);
    play();

    //playing sound if required
    if (soundEnabled)
        skipForwardSound -> play();
}

void ThePlayer::back5sec(){
    setPosition(position()-5000);
    play();

    //playing sound if required
    if (soundEnabled)
        rewindSound -> play();
}

void ThePlayer::save_current_video()
{
  QString desPath = "";
  QString l = currentMedia().canonicalUrl().toString();
  QString m =  currentMedia().canonicalUrl().toString();
  QString n = m.right(m.length()-7);
  QString te = "";
  std::reverse(n.begin(), n.end());
  int i = 0;
  int count = 0;
  while(count != 2)
  {
    if(n[i] == '/')
    {
      count++;
    }
    i++;
  }
  while(i < n.length())
  {
    te += n[i];
    i++;
  }
  std::reverse(te.begin(), te.end());
  QString d = currentMedia().canonicalUrl().toString();
  std::reverse(d.begin(), d.end());
  QString f = "";
  int j = 0;
  while(d[j] != '/')
  {
    f += d[j];
    j++;
  }
  std::reverse(f.begin(), f.end());
  desPath = te + "/Our Playlist/" + f;
  QFile::copy(l.right(l.length()-7), desPath);

  //playing relevent sound if enabled
  if (soundEnabled)
      saveSound -> play();
}
