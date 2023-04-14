#include "settings_button.h"
#include <QVBoxLayout>
#include <QUrl>

void SettingsButton::createWidgets()
{
    //creating the menu
    menu = new QMenu();
    menu -> setTitle("Settings");

    toggleTextToSpeech = new QPushButton("Text to Speech:   OFF");
}

void SettingsButton::createSounds()
{
    settingsSound = new QMediaPlayer();
    settingsSound -> setMedia(QUrl("qrc:/Sounds/sounds/overallControl/Settings.mp3"));

    enabledTextToSpeechSound = new QMediaPlayer();
    enabledTextToSpeechSound -> setMedia(QUrl("qrc:/Sounds/sounds/overallControl/EnableScreenReader.mp3"));

    disabledTextToSpeechSound = new QMediaPlayer();
    disabledTextToSpeechSound -> setMedia(QUrl("qrc:/Sounds/sounds/overallControl/ScreenReaderDisabled.mp3"));
}

void SettingsButton::arrangeWidgets()
{
    QVBoxLayout *layout = new QVBoxLayout();

    layout -> addWidget(toggleTextToSpeech, 0, Qt::AlignCenter);

    menu -> setLayout(layout);

    setMenu(menu);
}

void SettingsButton::makeConnections()
{
    connect(toggleTextToSpeech, SIGNAL(pressed()), this, SLOT(enabledTextToSpeech()));
    connect(menu, SIGNAL(aboutToShow()), this, SLOT(playSound()));
}

//used to alter whether the UI uses text to speech and updates the buttons text to reflect it's current state
void SettingsButton::enabledTextToSpeech()
{
    textToSpeech = !textToSpeech;

    if (textToSpeech)
    {
        toggleTextToSpeech -> setText("Text to Speech:   ON");

        enabledTextToSpeechSound -> play();
    }
    else
    {
        toggleTextToSpeech -> setText("Text to Speech:   OFF");

        disabledTextToSpeechSound -> play();
    }

    emit usingTextToSpeech(textToSpeech);
}

//plays the relevent sound when the settings menu is opened if text to speech enabled
void SettingsButton::playSound()
{
    if (textToSpeech)
        settingsSound -> play();
}
