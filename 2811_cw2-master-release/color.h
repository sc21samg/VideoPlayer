#ifndef COLOR_H
#define COLOR_H

#include <QPushButton>
#include <QMediaPlayer>

class Color : public QPushButton
{
    Q_OBJECT
public:
    Color(QString widgetColor, QWidget *parent = 0) : QPushButton(parent)
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
    bool selected;

    bool soundEnabled = false;
    QMediaPlayer *colorSound;

    static std::map<QString, QString> colorHexVals;
    static std::map<QChar, int> hexValues;

    QString getTextColor();
    double getLuminance(int shade);

    void createWidget();
    void createSound();
    void makeConnections();

signals:
    void pressed(Color*);

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

#endif // COLOR_H
