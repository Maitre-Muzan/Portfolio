/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** all_people
*/

#include "../../../include/steph_rpg.h"

void all_people(t_texture *texture)
{
    people(texture);
    set_people(texture);
    people_2(texture);
    set_people2(texture);
}

void scale_people(t_texture *texture)
{
    sfSprite_setScale(texture->people2, (sfVector2f){1.5, 1.3});
    sfSprite_setScale(texture->people3, (sfVector2f){1.5, 1.3});
    sfSprite_setScale(texture->people4, (sfVector2f){1.5, 1.3});
    sfSprite_setScale(texture->people5, (sfVector2f){1.5, 1.3});
    sfSprite_setScale(texture->people6, (sfVector2f){1.5, 1.3});
    sfSprite_setScale(texture->people7, (sfVector2f){1.5, 1.3});
    sfSprite_setScale(texture->people8, (sfVector2f){1.5, 1.3});
    sfSprite_setScale(texture->people9, (sfVector2f){1.5, 1.5});
    sfSprite_setScale(texture->people12, (sfVector2f){1.3, 1.3});
}

void people_display(t_window *screen, t_texture *texture)
{
    display_people(screen, texture);
    display_people2(screen, texture);
    scale_people(texture);
    people_position(texture);
    people_position2(texture);
}

void game_fonction(t_window *screen, t_texture *texture, t_goku *goku)
{
    initialization_position(goku, screen);
    window(screen);
    initialization_text_sp(goku, screen, texture);
    texture_open(texture);
    all_people(texture);
    create_event(screen, goku);
}
