/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "../../../include/steph_rpg.h"

void filled_pause(t_goku *goku)
{
    char *font = "src/lilia/asset/sixty.TTF";
    char str[4][20] = {"MISSION PAUSED", "Resume", "Menu", "Quit"};

    goku->name = create_text(str[0], font, (sfVector2f){450, 100}, 60);
    goku->pause[0] = create_text(str[1], font, (sfVector2f){500, 200}, 60);
    goku->pause[1] = create_text(str[2], font, (sfVector2f){500, 300}, 60);
    goku->pause[2] = create_text(str[3], font, (sfVector2f){500, 400}, 60);
}

void draw_pause(t_window *screen, t_goku *goku)
{
    sfRenderWindow_drawText(screen->window, goku->name, NULL);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawText(screen->window, goku->pause[i], NULL);
}

void show_pause(t_window *screen, t_goku *goku)
{
    while (goku->y == 1 && sfRenderWindow_isOpen(screen->window)) {
        sfRenderWindow_clear(screen->window, sfBlack);
        sfRenderWindow_setView(screen->window, screen->view1);
        sfView_setCenter(screen->view1, (sfVector2f){640, 360});
        if (is_close(screen->window, screen->event) == 1
        || (mouse_on_text(goku->pause[2], screen->window)
        && sfMouse_isButtonPressed(sfMouseLeft))) {
            sfRenderWindow_close(screen->window);
            return;
        } sfRenderWindow_drawSprite(screen->window, goku->back[0], NULL);
        draw_pause(screen, goku);
        pause_effect(screen, goku);
        if (mouse_on_text(goku->pause[0], screen->window)
        && sfMouse_isButtonPressed(sfMouseLeft))
            goku->y = 0;
        if (mouse_on_text(goku->pause[1], screen->window)
        && sfMouse_isButtonPressed(sfMouseLeft))
            goku->j = 0;
        sfRenderWindow_display(screen->window);
    }
    sfView_setCenter(screen->view1, screen->cam);
}
