#include "volume_control.h"
#include <QHBoxLayout>

using namespace std;

void VolumeControl::createWidgets()
{
    setUpLabel();
    setUpSlider();
    setUpInpBox();
    setUpMute();
}

//adds a label to the widget
void VolumeControl::setUpLabel()
{
    widgetLabel = new QLabel("Volume");
}

//adds a horizontal slider to the menu, used to set the volume
void VolumeControl::setUpSlider()
{
    volumeSlider = new QSlider();
    volumeSlider -> setMinimum(0);
    volumeSlider -> setMaximum(100);
    volumeSlider -> setOrientation(Qt::Horizontal);
    volumeSlider -> setSliderPosition(50);
}

//adds an input box where the user can choose the volume by typing an exact number
void VolumeControl::setUpInpBox()
{
    inpBox = new QSpinBox();
    inpBox -> setSingleStep(5);
    inpBox -> setRange(0, 100);
    inpBox -> setValue(50);

    //setting size of box
    inpBox -> setMaximumSize(40, 40);
}

void VolumeControl::setUpMute()
{
    mute = new MuteButton(":/Images/images/VolumeIcon.png", ":/Images/images/VolumeMuted.png");
    mute -> setIconSize(QSize(35, 35));
    mute -> setMaximumSize(60, 60);
}

void VolumeControl::createSound()
{
    thisSound = new QMediaPlayer();
    thisSound -> setMedia(QUrl("qrc:/Sounds/sounds/volumeControl/VolumeControl.mp3"));
}

//adds the widgets to the menu in a vertical layout
void VolumeControl::arrangeWidgets()
{
    QVBoxLayout *layout = new QVBoxLayout();
    QHBoxLayout *controlLayout = new QHBoxLayout();
    controlContainer = new QWidget();

    controlLayout -> addWidget(mute);
    controlLayout -> addWidget(inpBox);
    controlLayout -> addWidget(volumeSlider);
    controlContainer -> setLayout(controlLayout);

    layout -> addWidget(widgetLabel);
    layout -> addWidget(controlContainer);

    setLayout(controlLayout);
}

//a slot to update the value of the volume an emit a signal indicating as such
void VolumeControl::updateValue(int newValue)
{
    value = newValue;
    emit valueChanged(newValue);
}

//a slot to update the vale of 'muted' and emit a signal containing the new value
void VolumeControl::updateMuted()
{
    isMuted = !isMuted;
    emit muted(isMuted);
}


void VolumeControl::makeConnections()
{
    //connecting the slider and spinner so their values align
    connect(volumeSlider, SIGNAL(sliderMoved(int)), inpBox, SLOT(setValue(int)));
    connect(inpBox, SIGNAL(valueChanged(int)), volumeSlider, SLOT(setValue(int)));
    //connecting the spinner and slider to the volume of the container
    connect(volumeSlider, SIGNAL(sliderMoved(int)), this, SLOT(updateValue(int)));
    connect(inpBox, SIGNAL(valueChanged(int)), this, SLOT(updateValue(int)));
    //connecting the mute button to the mute bool in the container
    connect(mute, SIGNAL(pressed()), this, SLOT(updateMuted()));
}

void VolumeControl::showVolumeControl()
{
    if (isHidden)
    {
        show();
        isHidden = false;

        //playing sound if enabled
        if (soundEnabled)
            thisSound -> play();
    }
    else
    {
        hide();
        isHidden = true;
    }

    emit shown(isHidden);
}
