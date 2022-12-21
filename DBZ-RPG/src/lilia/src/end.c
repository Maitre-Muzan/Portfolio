/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "../../../include/steph_rpg.h"

void filled_end(t_texture *texture, t_window *screen, int i)
{
    sfSprite_setTexture(texture->sprite_end, texture->end, sfTrue);
    sfText_setPosition(texture->text, texture->pos_over);
    if (i == 0)
        sfText_setString(texture->text, texture->lose);
    else if (i == 1)
        sfText_setString(texture->text, texture->win);
    sfText_setFont(texture->text, texture->font);
    sfText_setCharacterSize(texture->text, 50);
    sfText_setPosition(texture->quit, texture->end_quit);
    sfText_setString(texture->quit, "QUIT");
    sfText_setFont(texture->quit, texture->font);
    sfText_setCharacterSize(texture->text, 50);
}

void draw_end(t_texture *texture, t_window *screen)
{
    sfRenderWindow_drawSprite(screen->window, texture->sprite_end, NULL);
    sfRenderWindow_drawText(screen->window, texture->text, NULL);
    sfRenderWindow_drawText(screen->window, texture->quit, NULL);
}

void display_end(t_texture *texture, t_window *screen, int i)
{
    filled_end(texture, screen, i);
    while (42){
        sfRenderWindow_clear(screen->window, sfBlack);
        sfRenderWindow_setView(screen->window, screen->view1);
        sfView_setCenter(screen->view1, (sfVector2f){640, 360});
        close_event(screen->window, screen->event);
        draw_end(texture, screen);
        button_light(screen, texture->quit);
        if (mouse_on_text(texture->quit, screen->window)
        && sfMouse_isButtonPressed(sfMouseLeft))
            sfRenderWindow_close(screen->window);
        sfRenderWindow_display(screen->window);
    }
}
