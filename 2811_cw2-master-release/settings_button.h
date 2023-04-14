#ifndef SETTINGSBUTTON_H
#define SETTINGSBUTTON_H

#include <QPushButton>
#include <QMenu>
#include <QMediaPlayer>

class SettingsButton : public QPushButton
{
    Q_OBJECT
public:
    SettingsButton(QWidget *parent = 0) : QPushButton(parent)
    {
        createWidgets();
        createSounds();
        arrangeWidgets();
        makeConnections();
    }

    ~SettingsButton()
    {
        delete menu;
    }

private:
    QMenu *menu;
    QPushButton *toggleTextToSpeech;
    bool textToSpeech = false;

    //used to play sounds when and if required
    QMediaPlayer *settingsSound;
    QMediaPlayer *enabledTextToSpeechSound;
    QMediaPlayer *disabledTextToSpeechSound;

    void createWidgets();
    void createSounds();
    void arrangeWidgets();
    void makeConnections();

signals:
    void usingTextToSpeech(bool);

private slots:
    void enabledTextToSpeech();

    void playSound();
};

#endif // SETTINGSBUTTON_H
