/*
** EPITECH PROJECT, 2020
** My_defender
** File description:
** destroy
*/

#include "../../../include/steph_rpg.h"

void destroy(t_window *screen)
{
    sfSoundBuffer_destroy(screen->soundbuff);
    sfSound_destroy(screen->sound);
    sfView_destroy(screen->view1);
    sfRenderWindow_close(screen->window);
}
