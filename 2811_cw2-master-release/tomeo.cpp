//    ______
//   /_  __/___  ____ ___  ___  ____
//    / / / __ \/ __ `__ \/ _ \/ __ \
//   / / / /_/ / / / / / /  __/ /_/ /
//  /_/  \____/_/ /_/ /_/\___/\____/
//              video for sports enthusiasts...
//
//
#include <algorithm>
#include <iostream>
#include <QApplication>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QMediaPlaylist>
#include <string>
#include <vector>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtCore/QFileInfo>
#include <QtWidgets/QFileIconProvider>
#include <QDesktopServices>
#include <QImageReader>
#include <QMessageBox>
#include <QtCore/QDir>
#include <QtCore/QDirIterator>
#include <QScrollArea>
#include "redo_button.h"
#include "settings_button.h"
#include "the_player.h"
#include "the_button.h"
#include "slider.h"
#include "undo_button.h"
#include "volume_control.h"
//libraries for play and pause button
#include "play_pause.h"
//libraries for volume and mute button
#include "add_text.h"
//stack widget library
#include "color_selector.h"
#include "color_scroller.h"
#include "effects_selector.h"
#include "effects_scroller.h"
#include "stack.h"
#include "save_button.h"
#include "share_button.h"

// read in videos and thumbnails to this directory
std::vector<TheButtonInfo> getInfoIn (std::string loc) {

    std::vector<TheButtonInfo> out =  std::vector<TheButtonInfo>();
    QDir dir(QString::fromStdString(loc) );
    QDirIterator it(dir);

    while (it.hasNext()) { // for all files

        QString f = it.next();

            if (f.contains("."))

#if defined(_WIN32)
            if (f.contains(".wmv"))  { // windows
#else
            if (f.contains(".mp4") || f.contains("MOV"))  { // mac/linux
#endif

            QString thumb = f.left( f .length() - 4) +".png";

            if (QFile(thumb).exists()) { // if a png thumbnail exists
                QImageReader *imageReader = new QImageReader(thumb);
                    QImage sprite = imageReader->read(); // read the thumbnail
                    if (!sprite.isNull()) {
                        QIcon* ico = new QIcon(QPixmap::fromImage(sprite)); // voodoo to create an icon for the button
                        QUrl* url = new QUrl(QUrl::fromLocalFile( f )); // convert the file location to a generic url
                        out . push_back(TheButtonInfo( url , ico  ) ); // add to the output list
                    }
                    else
                        qDebug() << "warning: skipping video because I couldn't process thumbnail " << thumb << endl;
            }
            else
                qDebug() << "warning: skipping video because I couldn't find thumbnail " << thumb << endl;
        }
    }

    return out;
}



int main(int argc, char *argv[]) {

    // let's just check that Qt is operational first
    qDebug() << "Qt version: " << QT_VERSION_STR << endl;

    // create the Qt Application
    QApplication app(argc, argv);

    // collect all the videos in the folder
    std::vector<TheButtonInfo> videos;

    if (argc == 2)
        videos = getInfoIn( std::string(argv[1]) );

    if (videos.size() == 0) {

        const int result = QMessageBox::information(
                    NULL,
                    QString("Tomeo"),
                    QString("no videos found! Add command line argument to \"quoted\" file location."));
        exit(-1);
    }


    // the QMediaPlayer which controls the playback
    ThePlayer *player = new ThePlayer();

    // create the main window and layout
    QWidget *window = new QWidget();
    QVBoxLayout *top = new QVBoxLayout();
    window->setLayout(top);
    window->setWindowTitle("tomeo");
    window->setMinimumSize(800, 680);

    //creation of undo,redo and share button at the top of page
    QWidget* re_un_sh = new QWidget();
    QHBoxLayout* h = new QHBoxLayout();
    UndoButton* undo = new UndoButton();
    RedoButton* redo = new RedoButton();
    QPushButton* share = new QPushButton();
    QPushButton* save = new QPushButton();
    SettingsButton* settings = new SettingsButton();
    undo->setIcon(QIcon(":/Images/images/UndoIcon.png"));
    redo->setIcon(QIcon(":/Images/images/RedoIcon.png"));
    share->setIcon(QIcon(":/Images/images/ShareIcon.png"));
    save->setIcon(QIcon(":/Images/images/SaveIcon.png"));
    //undo->setIconSize(QSize(25, 25));
    //redo->setIconSize(QSize(25, 25));
    //share->setIconSize(QSize(25, 25));
    //save->setIconSize(QSize(25,25));
    undo->setMinimumSize(QSize(40, 35));
    redo->setMinimumSize(QSize(40, 35));
    share->setMinimumSize(QSize(40, 35));
    save->setMinimumSize(QSize(40,35));
    undo->setStyleSheet("padding: 7px; background-color:white; margin-left:20px; border: 1px solid white;");
    redo->setStyleSheet("padding: 7px; margin-left: 2px; background-color:white; border: 1px solid white;");
    share->setStyleSheet("padding: 7px; margin-left: 499px; background-color:white; border: 1px solid white;");
    save->setStyleSheet("padding: 7px; margin-left: 20px; background-color:white; border: 1px solid white;");

    //creating share_button when clicked then shows options for sharing
    share_button* qw = new share_button();
    share->connect(share, SIGNAL(clicked(bool)), qw, SLOT(buttonClicked()));
    //creating save_button when clicked then shows options for saving video or not
    save_button* c = new save_button(player);
    save->connect(save, SIGNAL(clicked(bool)), c, SLOT(buttonClicked(bool)));

    h->addWidget(undo);
    h->addWidget(redo);
    h->addWidget(share);
    h->addWidget(save);
    h->addWidget(settings);

    re_un_sh->setLayout(h);
    re_un_sh->setMinimumHeight(45);
    re_un_sh->setMaximumHeight(45);

    //creation of video, forward, backward widget
    QWidget* wid = new QWidget();
    QHBoxLayout* lay = new QHBoxLayout();
    // the widget that will show the video
    QVideoWidget *videoWidget = new QVideoWidget;
    //the widget that will show the forward video in the list
    QPushButton* forward = new QPushButton();
    //the widget that will show the backward video in the list
    QPushButton* backward = new QPushButton();
    forward->setIcon(QIcon(":/Images/images/NextVideoIcon.png"));
    backward->setIcon(QIcon(":/Images/images/PreviousVideoIcon.png"));
    forward->setStyleSheet("background-color:white; border: 1px solid white;");
    backward->setStyleSheet("background-color:white; border: 1px solid white;");
    forward->setIconSize(QSize(20, 20));
    backward->setIconSize(QSize(20, 20));
    forward->setMaximumSize(22,22);
    backward->setMaximumSize(22,22);
    //adding all widgets in the layout
    lay->addWidget(backward);
    lay->addWidget(videoWidget);
    lay->addWidget(forward);
    wid->setMinimumHeight(550);
    wid->setLayout(lay);

    // creation of play/pause buttons and to move or reback the video for 5 second
    QWidget* we = new QWidget();
    QHBoxLayout* ho = new QHBoxLayout();
    QPushButton* forward_15second = new QPushButton();
    Play_Pause* windo = new Play_Pause(player);
    windo->setStyleSheet("padding: 1px; background-color:white;border: 1px solid white;");
    QPushButton* backward_15second = new QPushButton();
    forward_15second->setIcon(QIcon(":/Images/images/SkipForwardIcon.png"));
    backward_15second->setIcon(QIcon(":/Images/images/SkipBackwardIcon.png"));
    forward_15second->setIconSize(QSize(50,50));
    backward_15second->setIconSize(QSize(50,50));
    forward_15second->setStyleSheet("padding: 1px; background-color:white;border: 1px solid white;");
    backward_15second->setStyleSheet("padding: 1px; background-color:white; border: 1px solid white;");
    ho->addWidget(backward_15second);
    ho->addWidget(windo);
    ho->addWidget(forward_15second);
    //ho->setSizeConstraint(QLayout::SetFixedSize);
    we->setLayout(ho);

    //sandra adding functionality to buttons
    forward_15second->connect(forward_15second, SIGNAL(clicked()),player, SLOT (forward5sec()));

    backward_15second->connect(backward_15second, SIGNAL(clicked()),player, SLOT (back5sec()));


    //creation of features at the bottom of mobile
    QWidget* hori = new QWidget();
    QHBoxLayout* box = new QHBoxLayout();

    QPushButton* addDrawingButton = new QPushButton();
    addDrawingButton->setIcon(QIcon(":/Images/images/DrawIcon.png"));
    addDrawingButton->setIconSize(QSize(70,70));
    addDrawingButton->setStyleSheet("padding:7px; background-color:white; border: 1px solid white;");
    ColorScroller *colorSelectionBox = new ColorScroller();
    colorSelectionBox -> connect(addDrawingButton, SIGNAL(pressed()), colorSelectionBox, SLOT(toggleHidden()));
    colorSelectionBox -> widget() -> setInitialVideo(videos.at(0).url -> fileName());

    QPushButton* addEffectsButton = new QPushButton();
    addEffectsButton->setIcon(QIcon(":/Images/images/EffectsIcon.png"));
    addEffectsButton->setIconSize(QSize(70,70));
    addEffectsButton->setStyleSheet("padding: 7px; background-color:white; width: 70; height:70; border: 1px solid white;");
    EffectsScroller *effectsSelectionBox = new EffectsScroller();
    effectsSelectionBox -> connect(addEffectsButton, SIGNAL(pressed()), effectsSelectionBox, SLOT(toggleHidden()));
    effectsSelectionBox -> widget() -> setInitialVideo(videos.at(0).url -> fileName());

    QPushButton* volume = new QPushButton();
    volume->setIcon(QIcon(":/Images/images/VolumeIcon.png"));
    volume->setIconSize(QSize(70,70));
    volume->setStyleSheet("padding:7px; background-color:white;border: 1px solid white;");
    //creating and configuring the volume controler so it appears when pressed
    VolumeControl* volumeControler = new VolumeControl();
    volume -> connect(volume, SIGNAL(pressed()), volumeControler, SLOT(showVolumeControl()));
    volumeControler -> connect(volumeControler, SIGNAL(valueChanged(int)), player, SLOT(changeVolume(int)));
    volumeControler -> connect(volumeControler, SIGNAL(muted(bool)), player, SLOT(mute(bool)));
    volumeControler -> setMaximumHeight(window->height() / 10);

    QPushButton* addTextButton = new QPushButton();
    addTextButton->setIcon(QIcon(":/Images/images/TextIcon.png"));
    addTextButton->setIconSize(QSize(70,70));
    addTextButton->setStyleSheet("padding:7px; background-color:white; border: 1px solid white;");
    AddText* addTextBox = new AddText();
    addTextBox -> connect(addTextButton, SIGNAL(pressed()), addTextBox, SLOT(toggleHidden()));
    addTextBox -> setInitialVideo(videos.at(0).url -> fileName());

    player->setVideoOutput(videoWidget);

    // a row of buttons
    QWidget *buttonWidget = new QWidget();
    // a list of the buttons
    std::vector<TheButton*> buttons;
    // the buttons are arranged vetically
    QVBoxLayout *layout = new QVBoxLayout();
    buttonWidget->setLayout(layout);

    //create a stacked widget with select screen
    stack *stacked = new stack();
    stacked->addWidget(window);

    //collect amount of videos
    int size = videos.size();
    // create the buttons to display all videos
    for ( int i = 0; i < size; i++ ) {
        TheButton *button = new TheButton(buttonWidget);
        button->connect(button, SIGNAL(jumpTo(TheButtonInfo* )), player, SLOT (jumpTo(TheButtonInfo*))); // when clicked, tell the player to play.
        //changes widget back to player
        button->connect(button, SIGNAL(pressed()), stacked,
                        SLOT(changeWidget()));
        button->connect(button, SIGNAL(currentVideo(QString)), addTextBox, SLOT(changeCurrentVideo(QString))); //ensures dialogue gives correct video
        button->connect(button, SIGNAL(currentVideo(QString)), colorSelectionBox -> widget(), SLOT(changeCurrentVideo(QString))); //ensures dialogue gives correct video
        buttons.push_back(button);
        layout->addWidget(button);
        button->init(&videos.at(i));
    }

    // tell the player what buttons and videos are available
    player->setContent(&buttons, &videos);

    QPushButton* selectVideoButton = new QPushButton();
    selectVideoButton->setIcon(QIcon(":/Images/images/SelectVideoIcon.png"));
    selectVideoButton->setIconSize(QSize(70,70));
    selectVideoButton->setStyleSheet("padding:7px; background-color:white;border: 1px solid white;");
    //giving some functionality to selectVideoButton such that on click, video selector appears
    selectVideoButton -> setCheckable(true);
    selectVideoButton -> setChecked(false);
    buttonWidget -> hide();
    selectVideoButton->connect(selectVideoButton, SIGNAL(pressed()), stacked,
                               SLOT(changeWidget()));
    buttonWidget->setHidden(true);

    box->addWidget(selectVideoButton);
    box->addWidget(addDrawingButton);
    box->addWidget(addEffectsButton);
    box->addWidget(addTextButton);
    box->addWidget(volume);
    //box->setSizeConstraint(QLayout::SetFixedSize);
    hori->setLayout(box);

    slider *slide = new slider(Qt::Horizontal);
        slide->setTickInterval(1);
        slide->setMinimum(0);


        player->connect(player, SIGNAL(durationChanged(qint64)),
                        slide, SLOT(changeMax(qint64)));
        player->connect(player, SIGNAL(positionChanged(qint64)),
                        slide, SLOT(updateSlider(qint64)));
        slide->connect(slide, SIGNAL(sliderMoved(int)),
                       player, SLOT(changePos(int)));

        //slider stops/starts video when held.
        slide->connect(slide, SIGNAL(sliderPressed()),
                       player, SLOT(pause()));
        slide->connect(slide, SIGNAL(sliderReleased()),
                       player, SLOT(play()));

    //connecting all widgets to settings to use textToSpeech
    settings -> connect(settings, SIGNAL(usingTextToSpeech(bool)), undo, SLOT(enableSound(bool)));
    settings -> connect(settings, SIGNAL(usingTextToSpeech(bool)), redo, SLOT(enableSound(bool)));
    settings -> connect(settings, SIGNAL(usingTextToSpeech(bool)), qw, SLOT(enableSound(bool)));
    settings -> connect(settings, SIGNAL(usingTextToSpeech(bool)), player, SLOT(enableSound(bool)));
    settings -> connect(settings, SIGNAL(usingTextToSpeech(bool)), colorSelectionBox, SLOT(enableSound(bool)));
    settings -> connect(settings, SIGNAL(usingTextToSpeech(bool)), effectsSelectionBox, SLOT(enableSound(bool)));
    settings -> connect(settings, SIGNAL(usingTextToSpeech(bool)), volumeControler, SLOT(enableSound(bool)));
    settings -> connect(settings, SIGNAL(usingTextToSpeech(bool)), addTextBox, SLOT(enableSound(bool)));

    //icon from https://icons8.com
    settings->setIcon(QIcon(":/Images/images/Settings.png"));
    settings->setMinimumSize(QSize(20,30));

    // tell the player what buttons and videos are available
    player->setContent(&buttons, &videos);

    
    // add the undo, redo, bookmark and share button at top of mobile
    top->addWidget(re_un_sh);
    //add the forward, backward and video widget at middle of mobile
    top->addWidget(wid);
    top->addWidget(slide);
    top->addWidget(addTextBox);
    //add the forward_15second, backward_15second, play/pause button at bottom of video widget
    top->addWidget(we);
    //top->addWidget(buttonWidget);
    top->addWidget(volumeControler);
    top->addWidget(colorSelectionBox);
    top->addWidget(effectsSelectionBox);
    top->addWidget(hori);


    //pausing the player by default
    player->pause();

    // showtime!
    stacked->addWidget(buttonWidget);
    //stacked->setCurrentWidget(buttonWidget);
    stacked->show();

    // wait for the app to terminate
    return app.exec();
}
