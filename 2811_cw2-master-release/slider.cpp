#include "slider.h"
#include "qdebug.h"

void slider::changeMax(qint64 max){
    //changes the maximum range of the slider
    setMaximum(max/1000.0);
}

void slider::updateSlider(qint64 pos){
    //updates the postition of the slider
    setValue(pos/1000.0);
}
