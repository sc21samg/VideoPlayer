#include "effects_selector.h"
#include "QHBoxLayout"
#include <QSlider>
#include <QVBoxLayout>

//creating the color boxes
void EffectsSelector::createWidgets()
{
    colors.push_back(new Effects("Yellow"));

    colors.push_back(new Effects("Orange"));

    colors.push_back(new Effects("OrangeRed"));

    colors.push_back(new Effects("Red"));
}

void EffectsSelector::arrangeWidgets()
{
    QHBoxLayout *layout = new QHBoxLayout;

    layout -> addSpacing(200);
    for(Effects* color : colors)     
        layout -> addWidget(color);

    layout -> setSpacing(30);

    setLayout(layout);

    setFixedSize(sizeHint());
}

void EffectsSelector::makeConnections()
{
    for (Effects *color : colors)
    {
        connect(color, SIGNAL(pressed(Effects*)), this, SLOT(clickAction(Effects*)));
        connect(this, SIGNAL(usingSound(bool)), color, SLOT(enableSound(bool)));
    }
}

void EffectsSelector::toggleHidden()
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

void EffectsSelector::clickAction(Effects *color)
{
    if (color -> getSelected())
    {
        //deselecting all other colors
        for (Effects *c : colors)
        {
            if ((c != color) && (c -> getSelected()))
                c -> toggleSelected();
        }

        msgBox = new QMessageBox();
        if(color->getColor() == "Yellow")
            msgBox -> setText("You can now change the Hue of " + currentVideo);
        if(color->getColor() == "Orange")
            msgBox -> setText("You can now change the Saturation of " + currentVideo);
        if(color->getColor() == "OrangeRed")
            msgBox -> setText("You can now change the Brightness of " + currentVideo);
        if(color->getColor() == "Red")
            msgBox -> setText("You can now change the Contrast of " + currentVideo);

        msgBox -> addButton("OK", QMessageBox::AcceptRole);

        msgBox -> exec();
    }
}

void EffectsSelector::changeCurrentVideo(QString newVideo)
{
    currentVideo = newVideo;
}

