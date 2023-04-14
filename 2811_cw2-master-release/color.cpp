#include "color.h"
#include <cmath>
#include <QFont>

//setting up the color hex map to ensure text is accessible
std::map<QString, QString> Color::colorHexVals = {
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

std::map<QChar, int> Color::hexValues = {
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
QString Color::getTextColor()
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
double Color::getLuminance(int shade)
{
    int luminance = (double) shade / 255.0;

    if (luminance <= 0.03928)
        return luminance / 12.92;
    else
        return pow((luminance + 0.055) / 1.055, 2.4);
}

void Color::createWidget()
{
    QFont font;
    font.setPointSize(14);
    font.setBold(true);

    setFont(font);
    setText(color);
    setStyleSheet("background-color: " + color + ";"
                  "color:" + getTextColor() + ";");

    setFixedSize(QSize(150, 80));
}

void Color::createSound()
{
    colorSound = new QMediaPlayer();
    colorSound -> setMedia(QUrl("qrc:/Sounds/sounds/colors/" + color + ".mp3"));
}

void Color::makeConnections()
{
    connect(this, SIGNAL(pressed()), this, SLOT(toggleSelected()));
    connect(this, SIGNAL(pressed()), this, SLOT(emitColor()));
}

void Color::toggleSelected()
{
    selected = !selected;

    if (selected)
    {
        setStyleSheet("border: 5px solid Gold;"
                      "background-color: " + color + ";");

        if (soundEnabled)
            colorSound->play();
    }
    else
    {
        setStyleSheet("border: 0px solid;"
                      "background-color: " + color + ";");
    }
}
