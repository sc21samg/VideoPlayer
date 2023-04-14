#include "video_player.h"

void VideoPlayer::createWidgets()
{
}

void VideoPlayer::arrangeWidgets()
{
    if (player != nullptr)
    {
        textDisplay = new QWidget(player);
    }
}
