#include "share_button.h"

share_button::share_button(QWidget* parent) : QDialog(parent)
{
    createWidget();
    arrangeWidget();
    makeConnections();
}

//when share button clicked then dialog appears
void share_button::buttonClicked()
{
  QDialog::show();

  //playing relevent sound if enabled
  if (soundEnabled)
      thisSound -> play();
}

//widget creation
void share_button::createWidget()
{
   dialog = new QDialogButtonBox(Qt::Vertical);
   share = new QLabel("Share");
   bluetooth = new QPushButton("Bluetooth");
   bluetooth->setIcon(QIcon(":/Images/images/295680.png"));
   message = new QPushButton("Messages");
   message->setIcon(QIcon(":/Images/images/3158179.png"));
   email = new QPushButton("Email");
   email->setIcon(QIcon(":/Images/images/Apple_Mail-512.webp"));

   more_button = new QPushButton("More");
   more_button->setCheckable(true);


   Notes = new QPushButton("Notes");
   Notes->setIcon(QIcon(":/Images/images/apple-notes-493153.webp"));
   telegram = new QPushButton("Telegram");
   telegram->setIcon(QIcon(":/Images/images/tele.jpg"));
   twitter = new QPushButton("Twitter");
   twitter->setIcon(QIcon(":/Images/images//Twitter-logo.svg.png"));

   createSound();
}

void share_button::createSound()
{
    thisSound = new QMediaPlayer();
    thisSound -> setMedia(QUrl("qrc:/Sounds/sounds/overallControl/ShareVideo.mp3"));
}

//arrange widget vertically in a dialog box
void share_button::arrangeWidget()
{
    widget = new QWidget();
    QVBoxLayout* v = new QVBoxLayout();
    QVBoxLayout* v1 = new QVBoxLayout();
    v->addWidget(share);
    dialog->addButton(bluetooth, QDialogButtonBox::ActionRole);
    dialog->addButton(message, QDialogButtonBox::ActionRole);
    dialog->addButton(email, QDialogButtonBox::ActionRole);
    dialog->addButton(more_button, QDialogButtonBox::ActionRole);


    v1->addWidget(Notes);
    v1->addWidget(telegram);
    v1->addWidget(twitter);
    v1->setAlignment(Qt::AlignLeft);
    v1->setContentsMargins(0,0,0,0);
    widget->setLayout(v1);
    widget->setVisible(false);

    v->addWidget(dialog);
    v->addWidget(widget);
    v->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(v);
}

void share_button::makeConnections()
{
    //connecting more button when clicked see more options for sharing
    connect(more_button, &QAbstractButton::toggled, widget, &QWidget::setVisible);
}
