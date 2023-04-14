#ifndef SAVE_BUTTON_H
#define SAVE_BUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QDialogButtonBox>

#include "the_player.h"

class QPushButton;
class ThePlayer;
class QDialog;
class QDialogButtonBox;

class save_button : public QDialog
{
    Q_OBJECT

    public:
        save_button(ThePlayer* player);



    private slots:
        void buttonClicked(bool);


    private:
        ThePlayer* p;
        QPushButton* Yes;
        QPushButton* No;
        QLabel* label;
        QDialogButtonBox* dialog;

        void createWidget();
        void arrangeWidget();
        void makeConnections();
};



#endif // SAVE_BUTTON_H
