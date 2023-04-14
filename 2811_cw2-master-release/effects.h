#ifndef EFFECTS_H
#define EFFECTS_H

#include <QPushButton>
#include <QMediaPlayer>

class Effects : public QPushButton
{
    Q_OBJECT
public:
    Effects(QString widgetColor, QWidget *parent = 0) : QPushButton(parent)
    {
        color = widgetColor;
        selected = false;
        createWidget();
        createSound();
        makeConnections();
    }

    QString getColor()
    {
        return color;
    }

    bool getSelected()
    {
        return selected;
    }

private:
    QString color;
    int hue, brightness, contrast, saturation;
    bool selected;

    //used to play the sound if required
    bool soundEnabled = false;
    QMediaPlayer *thisSound;

    static std::map<QString, QString> colorHexVals;
    static std::map<QChar, int> hexValues;

    QString getTextColor();
    double getLuminance(int shade);

    void createWidget();
    void createSound();
    void makeConnections();

signals:
    void pressed(Effects*);

private slots:
    void emitColor()
    {
        emit pressed(this);
    }

public slots:
    void toggleSelected();

    //used to set whether the widget will play sound
    void enableSound(bool enable)
    {
        soundEnabled = enable;
    }
};

#endif // EFFECTS_H
