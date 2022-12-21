/*
** EPITECH PROJECT, 2020
** button manage
** File description:
** Make effect on button
*/

#include "../../../include/steph_rpg.h"

int mouse_on_usp(t_window *screen, sfSprite *sprite)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(sprite);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(screen->window);

    if (mouse.x > rect.left - screen->cam.x + 640
    && mouse.x < rect.left + rect.width - screen->cam.x + 640
    && mouse.y > rect.top - screen->cam.y + 360
    && mouse.y < rect.top + rect.height - screen->cam.y + 360)
        return (1);
    return (0);
}

void bt_effect(t_window *screen, sfSprite *sprite)
{
    if (mouse_on_usp(screen, sprite))
        sfSprite_setColor(sprite, sfColor_fromRGB(240, 185, 100));
    else
        sfSprite_setColor(sprite, sfColor_fromInteger(-1));
}

void bts_effect(t_window *screen, t_goku *goku)
{
    for (int i = 0; i < 2; i++)
        bt_effect(screen, goku->bts[i]);
}

int button_light(t_window *screen, sfText *txt)
{
    if (mouse_on_text(txt, screen->window)
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        sfText_setCharacterSize(txt, 70);
        sfText_setColor(txt, sfBlue);
        sfText_setCharacterSize(txt, 60);
        return (1);
    }
    if (mouse_on_text(txt, screen->window)) {
        sfText_setColor(txt, sfBlack);
        sfText_setOutlineColor(txt, sfWhite);
        sfText_setOutlineThickness(txt, 15);
    } else {
        sfText_setColor(txt, sfWhite);
        sfText_setOutlineThickness(txt, 0);
    }
    return (0);
}

void pause_effect(t_window *screen, t_goku *goku)
{
    for (int i = 0; i < 3; i++) {
        button_light(screen, goku->pause[i]);
    }
}
