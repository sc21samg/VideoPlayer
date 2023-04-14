QT += core gui widgets multimedia multimediawidgets

CONFIG += c++11


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        add_text.cpp \
        color.cpp \
        color_scroller.cpp \
        color_selector.cpp \
        effects.cpp \
        effects_scroller.cpp \
        effects_selector.cpp \
        play_pause.cpp \
        redo_button.cpp \
        settings_button.cpp \
        the_button.cpp \
        the_player.cpp \
        tomeo.cpp \
        slider.cpp \
        mute_button.cpp \
        undo_button.cpp \
        volume_control.cpp \
        save_button.cpp \
        share_button.cpp

HEADERS += \
    add_text.h \
    color.h \
    color_scroller.h \
    color_selector.h \
    effects.h \
    effects_scroller.h \
    effects_selector.h \
    play_pause.h \
    mute_button.h \
    redo_button.h \
    settings_button.h \
    stack.h \
    the_button.h \
    the_player.h \
    slider.h \
    mute_button.h \
    undo_button.h \
    volume_button.h \
    volume_control.h \
    save_button.h \
    share_button.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

