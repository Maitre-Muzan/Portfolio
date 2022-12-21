/*
** EPITECH PROJECT, 2020
** grahical project
** File description:
** window
*/

#include "../../../include/steph_rpg.h"

void window(t_window *screen)
{
    screen->video_mode.width = 1280;
    screen->video_mode.height = 720;
    screen->video_mode.bitsPerPixel = 32;
    screen->window = sfRenderWindow_create(screen->video_mode,
    "My_Rpg", sfDefaultStyle, NULL);
    screen->soundbuff = sfSoundBuffer_createFromFile("src/steph/music/db4.ogg");
    screen->sound = sfSound_create();
    sfSound_setBuffer(screen->sound, screen->soundbuff);
    sfSound_play(screen->sound);
    sfSound_setLoop(screen->sound, sfTrue);
}
