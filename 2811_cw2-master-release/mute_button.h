#ifndef MUTE_BUTTON_H
#define MUTE_BUTTON_H

#include <QPushButton>
#include <QObject>
#include <QCommonStyle>

class MuteButton : public QPushButton
{
    Q_OBJECT

public:
    MuteButton(QString soundIcon, QString mutedIcon, QWidget* parent = 0) : QPushButton(parent), soundIconLoc(soundIcon), mutedIconLoc(mutedIcon)
    {
        value = false;
        setAppearence();
        makeConnections();
    }

private slots:
    void changeValue() {value = !value;}
    void changeAppearence();

private:
    bool value;
    QString soundIconLoc;
    QString mutedIconLoc;
    //used to access the default volume widget
    QCommonStyle style;

    void setAppearence();

    void makeConnections();
};

#endif // MUTE_BUTTON_H
