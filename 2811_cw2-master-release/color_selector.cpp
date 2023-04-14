#include "color_selector.h"
#include "QHBoxLayout"
#include <QMediaPlayer>
#include <QUrl>

//creating the color boxes
void ColorSelector::createWidgets()
{
    colors.push_back(new Color("Yellow"));

    colors.push_back(new Color("Orange"));

    colors.push_back(new Color("OrangeRed"));

    colors.push_back(new Color("Red"));

    colors.push_back(new Color("Violet"));

    colors.push_back(new Color("BlueViolet"));

    colors.push_back(new Color("Blue"));

    colors.push_back(new Color("Green"));

    colors.push_back(new Color("GreenYellow"));
}

void ColorSelector::arrangeWidgets()
{
    QHBoxLayout *layout = new QHBoxLayout;
    for(Color* color : colors)
        layout -> addWidget(color);

    layout -> setSpacing(30);

    setLayout(layout);

    setFixedSize(sizeHint());
}

void ColorSelector::makeConnections()
{
    for (Color *color : colors)
    {
        connect(color, SIGNAL(pressed(Color*)), this, SLOT(clickAction(Color*)));
        //ensures colors sounds will play
        connect(this, SIGNAL(usingSound(bool)), color, SLOT(enableSound(bool)));
    }
}

void ColorSelector::toggleHidden()
{
    if (isHidden())
    {
        this->show();
        setHidden(false);
    }
    else
    {
        this->hide();
        setHidden(true);
    }

    emit nowHidden(isHidden());
}

void ColorSelector::clickAction(Color *color)
{
    if (color -> getSelected())
    {
        //deselecting all other colors
        for (Color *c : colors)
        {
            if ((c != color) && (c -> getSelected()))
                c -> toggleSelected();
        }

        msgBox = new QMessageBox();
        msgBox -> setText("You can now draw on: " + currentVideo + "\nin " + color->getColor());
        msgBox -> addButton("OK", QMessageBox::AcceptRole);

        msgBox -> exec();
    }
}

void ColorSelector::changeCurrentVideo(QString newVideo)
{
    currentVideo = newVideo;
}

