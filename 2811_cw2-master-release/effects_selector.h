#ifndef EFFECTSSELECTOR_H
#define EFFECTSSELECTOR_H

#include <QScrollArea>
#include <vector>
#include <QMessageBox>
#include <QMediaPlayer>
#include "effects.h"

//the widget used by the user to select a color to add drawings to video

class EffectsSelector : public QWidget
{
    Q_OBJECT
public:
    EffectsSelector(QWidget* parent = 0) : QWidget(parent)
    {
        createWidgets();
        arrangeWidgets();
        makeConnections();
        this -> hide();
        setHidden(true);
    }

    //must be called befor app.exec()
    void setInitialVideo(QString video)
    {
        currentVideo = video;
    }

private:
    std::vector<Effects*> colors;

    //used to add the name of the video to the text box
    QString currentVideo;

    //the dialog box displayed when the user selects a color
    QMessageBox *msgBox;

    //used to manage sound playing
    bool soundEnabled = false;

    void createWidgets();
    void createSound();
    void arrangeWidgets();
    void makeConnections();

signals:
    void nowHidden(bool);

    void usingSound(bool);

private slots:
   // void clickAction(QString);
    void clickAction(Effects*);

public slots:
    void toggleHidden();

    void changeCurrentVideo(QString);

    //used to set whether the widget will play sound emit to childeren what the setting is
    void enableSound(bool enable)
    {
        soundEnabled = enable;
        emit usingSound(soundEnabled);
    }
};

#endif // EffectsSELECTOR_H
