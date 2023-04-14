#ifndef SLIDER_H
#define SLIDER_H

#include <QWidget>
#include <QSlider>
#include <QObject>
#include <QTimer>

class slider : public QSlider{
Q_OBJECT

public:
    slider(Qt::Orientation orientation, QWidget *parent=0) :  QSlider(parent){
        setOrientation(orientation);
        setTickPosition(QSlider::TicksBothSides);
    }

    ~slider() {};

public slots:
    void changeMax(qint64 max);
    void updateSlider(qint64 pos);

};

#endif // SLIDER_H
