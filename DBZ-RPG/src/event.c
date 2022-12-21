/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** event
*/

#include "../include/steph_rpg.h"

void create_event(t_window *screen, t_goku *goku)
{
    t_texture *texture;
    goku->y = 0;
    while (sfRenderWindow_isOpen(screen->window)) {
        sfRenderWindow_setFramerateLimit(screen->window, 14);
        close_event(screen->window, screen->event);
        goku->ball = rand() % 3;
        if (goku->y == 0) {
            gaming(screen, texture, goku);
            gaming_end(screen, texture, goku);
        }
    }
    sfSoundBuffer_destroy(screen->soundbuff);
    sfSound_destroy(screen->sound);
    sfRenderWindow_close(screen->window);
}
