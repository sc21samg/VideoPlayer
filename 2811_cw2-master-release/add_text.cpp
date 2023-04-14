#include "add_text.h"
#include <QVBoxLayout>
#include <QFont>

void AddText::createLabel()
{
    widgetLabel = new QLabel("Add Text");

    //setting the font of the text box
    QFont font;
    font.setPointSize(12);

    widgetLabel -> setFont(font);
}

void AddText::createTextBox()
{
    textBox = new QLineEdit();

    //setting content of text box
    textBox -> setAlignment(Qt::AlignHCenter);
    textBox -> setPlaceholderText("Enter text here!!");

    //setting the font of the text box
    QFont font;
    font.setPointSize(16);

    textBox -> setFont(font);

}

void AddText::createSubmit()
{
    submit = new QPushButton();

    submit -> setText("Submit");
    submit -> setFixedSize(submit -> sizeHint());

    QFont font;
    font.setPointSize(14);

    submit -> setFont(font);
}

void AddText::createSound()
{
    addTextSound = new QMediaPlayer();
    addTextSound -> setMedia(QUrl("qrc:/Sounds/sounds/addText/AddText.mp3"));

    submitTextSound = new QMediaPlayer();
    submitTextSound -> setMedia(QUrl("qrc:/Sounds/sounds/addText/SubmitText.mp3"));
}

void AddText::arrangeWidgets()
{
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(widgetLabel);
    layout->addWidget(textBox);
    layout->addWidget(submit);

    layout -> setAlignment(submit, Qt::AlignRight);

    setLayout(layout);
}


void AddText::makeConnections()
{
    submit -> connect(submit, SIGNAL(pressed()), this, SLOT(submitText()));
    submit -> connect(submit, SIGNAL(pressed()), this, SLOT(playSubmitSound()));
}

void AddText::setAppearence()
{
    setFixedHeight(sizeHint().height());
}

void AddText::toggleHidden()
{
    if (isHidden())
    {
        this->show();
        setHidden(false);

        //playing a sound to indicate that this option has been opened if sound enabled
        if (soundEnabled)
            addTextSound -> play();

    }
    else
    {
        this->hide();
        setHidden(true);
    }
}

//emmits the txt in the text field and clears it
void AddText::submitText()
{
    QString text = textBox -> text();
    emit addText(text);

    textBox -> clear();
    toggleHidden();

    showDialog(text);
}


//shows a dialogue of the most recent action
void AddText::showDialog(QString text)
{
    msgBox = new QMessageBox();
    msgBox -> setText("You added the text: " + text + " to " + currentVideo);
    msgBox -> addButton("OK", QMessageBox::AcceptRole);

    msgBox -> exec();
}

void AddText::changeCurrentVideo(QString newVideo)
{
    currentVideo = newVideo;
}
