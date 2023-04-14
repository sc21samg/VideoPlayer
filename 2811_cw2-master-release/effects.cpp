#include "effects.h"
#include <cmath>
#include <QFont>

//setting up the color hex map to ensure text is accessible
std::map<QString, QString> Effects::colorHexVals = {
    {"Red", "#FF0000"},
    {"Yellow", "#FFFF00"},
    {"Orange", "#FFA500"},
    {"OrangeRed", "#FF4500"},
    {"Violet", "#EE82EE"},
    {"BlueViolet", "#8A2BE2"},
    {"Blue", "#0000FF"},
    {"Green", "#008000"},
    {"GreenYellow", "#ADFF2F"}
};

std::map<QChar, int> Effects::hexValues = {
    {'0', 0},
    {'1', 1},
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
    {'A', 10},
    {'B', 11},
    {'C', 12},
    {'D', 13},
    {'E', 14},
    {'F', 15},
};

//returns the color the text should be to ensure accessability based on W3C guidelines
QString Effects::getTextColor()
{

    QString colorHex = colorHexVals[color];

    //getting the distinct rgb values
    int r = (hexValues[colorHex.at(1)] * 16) + hexValues[colorHex.at(2)];
    int g = (hexValues[colorHex.at(3)] * 16) + hexValues[colorHex.at(4)];
    int b = (hexValues[colorHex.at(5)] * 16) + hexValues[colorHex.at(6)];

    double lumR = getLuminance(r);
    double lumG = getLuminance(g);
    double lumB = getLuminance(b);

    double relativeLum = (0.2126 * lumR) + (0.7152 * lumG) + (0.0722 * lumB);

    if (relativeLum > 0.179)
        return "Black";
    else
        return "White";
}

//returns the luminescence for each rgb value
double Effects::getLuminance(int shade)
{
    int luminance = (double) shade / 255.0;

    if (luminance <= 0.03928)
        return luminance / 12.92;
    else
        return pow((luminance + 0.055) / 1.055, 2.4);
}

void Effects::createWidget()
{
    QFont font;
    font.setPointSize(14);
    font.setBold(true);

    setFont(font);
    if(color == "Yellow")
    {
             setText("Hue");
    }
    if(color == "Orange")
    {
             setText("Saturation");
    }
    if(color == "OrangeRed")
    {
             setText("Brightness");
    }
    if(color == "Red")
    {
             setText("Contrast");
    }

    setStyleSheet("background-color: " + color + ";"
                  "color:" + getTextColor() + ";");

    setFixedSize(QSize(170, 80));
}

void Effects::makeConnections()
{
    connect(this, SIGNAL(pressed()), this, SLOT(toggleSelected()));
    connect(this, SIGNAL(pressed()), this, SLOT(emitColor()));
}

void Effects::createSound()
{
    thisSound = new QMediaPlayer();
    thisSound -> setMedia(QUrl("qrc:/Sounds/sounds/effects/" + text() + ".mp3"));
    thisSound -> setVolume(50);
}

void Effects::toggleSelected()
{
    selected = !selected;

    if (selected)
    {
        setStyleSheet("border: 5px solid Gold;"
                      "background-color: " + color + ";");

        //playing the sound if it is enabled
        if (soundEnabled)
            thisSound -> play();
    }
    else
    {
        setStyleSheet("border: 0px solid;"
                      "background-color: " + color + ";");
    }
}
