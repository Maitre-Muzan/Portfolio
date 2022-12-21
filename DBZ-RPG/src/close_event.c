/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** Close window with an event
*/

#include "../include/steph_rpg.h"

int close_event(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    return (0);
}

int is_close(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            return (1);
    }
    return (0);
}
