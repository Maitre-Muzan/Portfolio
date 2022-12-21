/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** people2
*/

#include "../../../include/steph_rpg.h"

void people_2(t_texture *texture)
{
    texture->t_people11 = sfTexture_createFromFile(
    "src/steph/pict/people10.png", NULL);
    texture->t_people12 = sfTexture_createFromFile(
    "src/steph/pict/people11.png", NULL);
    texture->t_people13 = sfTexture_createFromFile(
    "src/steph/pict/people12.png", NULL);
    texture->t_people14 = sfTexture_createFromFile(
    "src/steph/pict/people13.png", NULL);
}

void people_sprite2(t_texture *texture)
{
    texture->people11 = sfSprite_create();
    texture->people12 = sfSprite_create();
    texture->people13 = sfSprite_create();
    texture->people14 = sfSprite_create();
}

void set_people2(t_texture *texture)
{
    people_sprite2(texture);
    sfSprite_setTexture(texture->people11, texture->t_people11, sfTrue);
    sfSprite_setTexture(texture->people12, texture->t_people12, sfTrue);
    sfSprite_setTexture(texture->people13, texture->t_people13, sfTrue);
    sfSprite_setTexture(texture->people14, texture->t_people14, sfTrue);
}

void people_position2(t_texture *texture)
{
    sfSprite_setPosition(texture->people11, (sfVector2f) {1555, 700});
    sfSprite_setPosition(texture->people12, (sfVector2f) {970, 650});
    sfSprite_setPosition(texture->people13, (sfVector2f) {1900, 1720});
    sfSprite_setPosition(texture->people14, (sfVector2f) {1030, 220});
}

void display_people2(t_window *screen, t_texture *texture)
{
    sfRenderWindow_drawSprite(screen->window, texture->people11, NULL);
    sfRenderWindow_drawSprite(screen->window, texture->people12, NULL);
    sfRenderWindow_drawSprite(screen->window, texture->people13, NULL);
    sfRenderWindow_drawSprite(screen->window, texture->people14, NULL);
}
