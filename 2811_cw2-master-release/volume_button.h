#ifndef VOLUMEBUTTON_H
#define VOLUMEBUTTON_H

#include <QObject>
#include <QPushButton>

class VolumeButton : public QPushButton
{
Q_OBJECT
public:
    VolumeButton(QWidget* parent = 0) : QPushButton(parent)
    {
        makeConnections();
    }

private:
    void makeConnections()
    {
        connect(this, SIGNAL(pressed()), this, SLOT(emmitLocation()));
    }


signals:
   void pressedThisLocation(QRect);

private slots:
    void emmitLocation()
    {
        emit pressedThisLocation(geometry());
    }
};

#endif // VOLUMEBUTTON_H
