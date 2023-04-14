#ifndef COLORSELECTOR_H
#define COLORSELECTOR_H

#include <QScrollArea>
#include <vector>
#include <QMessageBox>
#include <QMediaPlayer>
#include "color.h"

//the widget used by the user to select a color to add drawings to video

class ColorSelector : public QWidget
{
    Q_OBJECT
public:
    ColorSelector(QWidget* parent = 0) : QWidget(parent)
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
    std::vector<Color*> colors;

    //used to add the name of the video to the text box
    QString currentVideo;

    //the dialog box displayed when the user selects a color
    QMessageBox *msgBox;

    //used to manage sound playing
    bool soundEnabled = false;

    void createWidgets();
    void arrangeWidgets();
    void makeConnections();

signals:
    void nowHidden(bool);

    void usingSound(bool);

private slots:
    void clickAction(Color*);

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

#endif // COLORSELECTOR_H
