#ifndef VOLUMECONTROL_H
#define VOLUMECONTROL_H

#include <QObject>
#include <QSpinBox>
#include <QSlider>
#include <QWidget>
#include <QLabel>
#include <QMediaPlayer>
#include "mute_button.h"

using namespace std;

class VolumeControl: public QWidget
{
    Q_OBJECT
public:
    VolumeControl(QWidget* parent = 0) : QWidget(parent)
    {
        createWidgets();
        createSound();
        arrangeWidgets();
        makeConnections();
        isMuted = false;
        value = 50;
        isHidden = true;
        this->hide();
    }

private:
    int value;
    bool isMuted;
    bool isHidden;
    QWidget* controlContainer;
    QLabel* widgetLabel;
    QSpinBox* inpBox;
    QSlider* volumeSlider;
    MuteButton* mute;

    //used to play sound for text to speech if required
    bool soundEnabled = false;
    QMediaPlayer *thisSound;

    void createWidgets();
    void createSound();
    void setUpLabel();
    void setUpSlider();
    void setUpInpBox();
    void setUpMute();
    void arrangeWidgets();
    void makeConnections();

signals:
    void valueChanged(int);
    void muted(bool);
    void shown(bool);

private slots:
    void updateValue(int newValue);

    void updateMuted();

public slots:
    void showVolumeControl();

    //used to set whether the widget will play sound
    void enableSound(bool enable)
    {
        soundEnabled = enable;
    }


};

#endif // VOLUMECONTROL_H
