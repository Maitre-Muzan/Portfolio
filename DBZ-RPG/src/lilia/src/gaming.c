/*
** EPITECH PROJECT, 2020
** gaming
** File description:
** Struct of game
*/

#include "../../../include/steph_rpg.h"

static void gaming_status(t_window *screen, t_texture *texture, t_goku *goku)
{
    if (mouse_on_usp(screen, goku->bts[0])
    && sfMouse_isButtonPressed(sfMouseLeft))
        goku->y = 1;
    if (mouse_on_usp(screen, goku->bts[1])
    && sfMouse_isButtonPressed(sfMouseLeft))
        goku->ivt = 1;
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
        goku->y = 1;
}

void gaming(t_window *screen, t_texture *texture, t_goku *goku)
{
    int i = 0;

    gaming_status(screen, texture, goku);
    i = check_room(screen, goku);
    if (goku->y == 1) {
        show_pause(screen, goku);
        return;
    } if (i == 1) {
        show_room(screen, texture, goku);
    } if (goku->ivt == 1)
        show_ivt(screen, goku);
    else {
        goku->key = sfKeyEscape;
        display(screen, texture, goku);
    }
}

void gaming_end(t_window *screen, t_texture *texture, t_goku *goku)
{
    if (sfKeyboard_isKeyPressed(sfKeyRShift) == sfTrue)
        goku->y = 2;
    if (goku->y == 2)
        display_end(texture, screen, 1);
}
