/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** acceuil
*/

#include "../../../include/steph_rpg.h"

void people(t_texture *texture)
{
    texture->t_people1 = sfTexture_createFromFile(
    "src/steph/pict/people.png", NULL);
    texture->t_people2 = sfTexture_createFromFile(
    "src/steph/pict/people1.png", NULL);
    texture->t_people3 = sfTexture_createFromFile(
    "src/steph/pict/people2.png", NULL);
    texture->t_people4 = sfTexture_createFromFile(
    "src/steph/pict/people3.png", NULL);
    texture->t_people5 = sfTexture_createFromFile(
    "src/steph/pict/people4.png", NULL);
    texture->t_people6 = sfTexture_createFromFile(
    "src/steph/pict/people5.png", NULL);
    texture->t_people7 = sfTexture_createFromFile(
    "src/steph/pict/people6.png", NULL);
    texture->t_people8 = sfTexture_createFromFile(
    "src/steph/pict/people7.png", NULL);
    texture->t_people9 = sfTexture_createFromFile(
    "src/steph/pict/people8.png", NULL);
    texture->t_people10 = sfTexture_createFromFile(
    "src/steph/pict/people9.png", NULL);
}

void people_sprite(t_texture *texture)
{
    texture->people1 = sfSprite_create();
    texture->people2 = sfSprite_create();
    texture->people3 = sfSprite_create();
    texture->people4 = sfSprite_create();
    texture->people5 = sfSprite_create();
    texture->people6 = sfSprite_create();
    texture->people7 = sfSprite_create();
    texture->people8 = sfSprite_create();
    texture->people9 = sfSprite_create();
    texture->people10 = sfSprite_create();
}

void set_people(t_texture *texture)
{
    people_sprite(texture);
    sfSprite_setTexture(texture->people1, texture->t_people1, sfTrue);
    sfSprite_setTexture(texture->people2, texture->t_people2, sfTrue);
    sfSprite_setTexture(texture->people3, texture->t_people3, sfTrue);
    sfSprite_setTexture(texture->people4, texture->t_people4, sfTrue);
    sfSprite_setTexture(texture->people5, texture->t_people5, sfTrue);
    sfSprite_setTexture(texture->people6, texture->t_people6, sfTrue);
    sfSprite_setTexture(texture->people7, texture->t_people7, sfTrue);
    sfSprite_setTexture(texture->people8, texture->t_people8, sfTrue);
    sfSprite_setTexture(texture->people9, texture->t_people9, sfTrue);
    sfSprite_setTexture(texture->people10, texture->t_people10, sfTrue);
}

void people_position(t_texture *texture)
{
    sfSprite_setPosition(texture->people1, (sfVector2f){230, 300});
    sfSprite_setPosition(texture->people2, (sfVector2f){275, 700});
    sfSprite_setPosition(texture->people3, (sfVector2f){1850, 270});
    sfSprite_setPosition(texture->people4, (sfVector2f){1555, 2020});
    sfSprite_setPosition(texture->people5, (sfVector2f){900, 2070});
    sfSprite_setPosition(texture->people6, (sfVector2f){300, 1160});
    sfSprite_setPosition(texture->people7, (sfVector2f){375, 2020});
    sfSprite_setPosition(texture->people8, (sfVector2f){1000, 1600});
    sfSprite_setPosition(texture->people9, (sfVector2f){1500, 1240});
    sfSprite_setPosition(texture->people10, (sfVector2f){1540, 1550});
}

void display_people(t_window *screen, t_texture *texture)
{
    sfRenderWindow_drawSprite(screen->window, texture->people1, NULL);
    sfRenderWindow_drawSprite(screen->window, texture->people2, NULL);
    sfRenderWindow_drawSprite(screen->window, texture->people3, NULL);
    sfRenderWindow_drawSprite(screen->window, texture->people4, NULL);
    sfRenderWindow_drawSprite(screen->window, texture->people5, NULL);
    sfRenderWindow_drawSprite(screen->window, texture->people6, NULL);
    sfRenderWindow_drawSprite(screen->window, texture->people7, NULL);
    sfRenderWindow_drawSprite(screen->window, texture->people8, NULL);
    sfRenderWindow_drawSprite(screen->window, texture->people9, NULL);
    sfRenderWindow_drawSprite(screen->window, texture->people10, NULL);
}
