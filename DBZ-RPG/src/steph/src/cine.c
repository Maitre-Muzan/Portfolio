/*
** EPITECH PROJECT, 2020
** cine.c
** File description:
** Displays cinematics
*/

#include "../../../include/steph_rpg.h"

void filled_cine(t_texture *texture)
{
    char *font = "src/lilia/asset/sixty.TTF";

    texture->land = create_sprite("src/gam/ressources/Landscape_dbz.png",
    (sfVector2f){1, 1}, (sfVector2f){0, 0});
    texture->lrect = (sfIntRect){0, 0, 1280, 720};
    texture->swip[0] = create_text("<Prev", font, (sfVector2f){20, 10},
    40);
    texture->swip[1] = create_text("Next>", font, (sfVector2f){1200, 10},
    40);
    texture->swip[2] = create_text("Skip>>", font, (sfVector2f){1200, 650},
    40);
    sfSprite_setTextureRect(texture->land, texture->lrect);
}

void draw_cine(t_window *screen, t_texture *texture)
{
    sfRenderWindow_drawSprite(screen->wind_menu, texture->land, NULL);
    for (int i = 0; i < 3; i++) {
        if (i == 1)
            i++;
        sfRenderWindow_drawText(screen->wind_menu, texture->swip[i], NULL);
    }
}

void cine_bt_effect(t_window *screen, t_texture *texture)
{
    for (int i = 0; i < 3; i++) {
        if (mouse_on_text(texture->swip[i], screen->wind_menu)
        && sfMouse_isButtonPressed(sfMouseLeft)) {
            sfText_setCharacterSize(texture->swip[i], 50);
            sfText_setColor(texture->swip[i], sfBlue);
            sfText_setCharacterSize(texture->swip[i], 40);
        }
        if (mouse_on_text(texture->swip[i], screen->wind_menu)) {
            sfText_setColor(texture->swip[i], sfBlack);
            sfText_setOutlineColor(texture->swip[i], sfWhite);
            sfText_setOutlineThickness(texture->swip[i], 15);
        } else {
            sfText_setColor(texture->swip[i], sfWhite);
            sfText_setOutlineThickness(texture->swip[i], 0);
        }
    }
}

void show_cine(t_window *screen, t_texture *texture, t_goku *goku)
{
    while (sfRenderWindow_isOpen(screen->wind_menu)) {
        close_event(screen->wind_menu, screen->event_menu);
        sfRenderWindow_clear(screen->wind_menu, sfBlack);
        if (sfTime_asSeconds(sfClock_getElapsedTime(screen->clock_menu)) > 9) {
            if (texture->lrect.left < 2560)
                texture->lrect.left += 1280;
            else
                return;
            sfSprite_setTextureRect(texture->land, texture->lrect);
            sfClock_restart(screen->clock_menu);
        } draw_cine(screen, texture);
        cine_bt_effect(screen, texture);
        if (mouse_on_text(texture->swip[0], screen->wind_menu)
        && sfMouse_isButtonPressed(sfMouseLeft)
        && texture->lrect.left > 0)
            texture->lrect.left -= 1280;
        if (mouse_on_text(texture->swip[2], screen->wind_menu)
        && sfMouse_isButtonPressed(sfMouseLeft))
            return;
        sfRenderWindow_display(screen->wind_menu);
    }
}