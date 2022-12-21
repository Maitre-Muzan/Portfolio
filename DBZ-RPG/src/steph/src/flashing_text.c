/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** flashing
*/

#include "../../../include/steph_rpg.h"

void flashing_text(t_window *screen)
{
    screen->time_menu = sfClock_getElapsedTime(screen->clock_menu);
    if (sfTime_asSeconds(screen->time_menu) > 0.3f) {
        sfRenderWindow_drawText(screen->wind_menu, screen->text, NULL);
        sfClock_restart(screen->clock_menu);
    }
}
