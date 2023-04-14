#ifndef SHARE_BUTTON_H
#define SHARE_BUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QString>
#include <QMediaPlayer>

class QPushButton;
class ThePlayer;
class QDialog;
class QDialogButtonBox;

class share_button : public QDialog
{
    Q_OBJECT

    public:
        share_button(QWidget* parent = 0);


    private slots:
        void buttonClicked();

    private:
        QLabel* share;
        QPushButton* bluetooth;
        QPushButton* message;
        QPushButton* email;
        QPushButton* Notes;
        QPushButton* more_button;
        QDialogButtonBox* dialog;
        QWidget* widget;
        QPushButton* telegram;
        QPushButton* twitter;

        //used to play sound if neccessary
        bool soundEnabled = false;
        QMediaPlayer *thisSound;

        void createWidget();
        void createSound();
        void arrangeWidget();
        void makeConnections();

public slots:
        //used to set whether the widget will play sound
        void enableSound(bool enable)
        {
            soundEnabled = enable;
        }
};

#endif // SHARE_BUTTON_H
