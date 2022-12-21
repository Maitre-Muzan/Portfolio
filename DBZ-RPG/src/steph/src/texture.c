/*
** EPITECH PROJECT, 2020
** My_defender
** File description:
** texture
*/

#include "../../../include/steph_rpg.h"

void texture_open(t_texture *texture)
{
    texture->t_background = sfTexture_createFromFile(
    "src/steph/pict/Dbpic.png", NULL);
    texture->background = sfSprite_create();
    sfSprite_setTexture(texture->background, texture->t_background, sfTrue);
}
