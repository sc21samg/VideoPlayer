#ifndef ADDTEXT_H
#define ADDTEXT_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QMediaPlayer>

class AddText : public QWidget
{
    Q_OBJECT
public:
    explicit AddText(QWidget *parent = nullptr) : QWidget(parent)
    {
        createWidgets();
        createSound();
        arrangeWidgets();
        makeConnections();
        setAppearence();
        this->hide();
        setHidden(true);
    }

    void setInitialVideo(QString video) {currentVideo = video;}

private:
    QLineEdit* textBox;
    QLabel* widgetLabel;
    QPushButton* submit;

    //used to manage sound playing
    bool soundEnabled = false;
    QMediaPlayer *addTextSound;
    QMediaPlayer *submitTextSound;

    //used to add the name of the video to the text box
    QString currentVideo;

    //the dialog box displayed when the user submits the text
    QMessageBox *msgBox;

    void createWidgets()
    {
        createLabel();
        createTextBox();
        createSubmit();
    }

    void createLabel();
    void createTextBox();
    void createSubmit();
    void createSound();
    void arrangeWidgets();
    void makeConnections();
    void setAppearence();
    void showDialog(QString text);

signals:
    void addText(QString);

public slots:
    void toggleHidden();

    void changeCurrentVideo(QString);

    //used to set whether the widget will play sound
    void enableSound(bool enable)
    {
        soundEnabled = enable;
    }

private slots:
    void submitText();

    void playSubmitSound()
    {
        if (soundEnabled)
            submitTextSound -> play();
    }

};

#endif // ADDTEXT_H
