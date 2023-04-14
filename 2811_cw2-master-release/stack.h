#ifndef STACK_H
#define STACK_H

#include <QStackedWidget>
#include <QDebug>

class stack: public QStackedWidget
{
Q_OBJECT
public:
    stack(){};

public slots:
    //change widget to other widget
    void changeWidget(){

       int index = indexOf(currentWidget());
       if (index == 0){
        setCurrentIndex(1);
       }
       else
         setCurrentIndex(0);
    };
};

#endif // STACK_H
