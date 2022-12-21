/*
** EPITECH PROJECT, 2020
** My_defender
** File description:
** event
*/

#include "../../../include/steph_rpg.h"

void destroy_goku(t_goku *goku, t_texture *texture)
{
    sfSprite_destroy(goku->spritego);
    sfTexture_destroy(goku->textgo);
    sfSprite_destroy(goku->spritepo);
    sfTexture_destroy(goku->textpo);
    sfSprite_destroy(texture->sprite_end);
    sfTexture_destroy(texture->end);
    sfSprite_destroy(goku->bts[0]);
    sfSprite_destroy(goku->bts[1]);
    sfSprite_destroy(goku->back[0]);
    sfSprite_destroy(goku->back[1]);
    sfClock_destroy(goku->clock1);
    sfClock_destroy(goku->clock2);
    sfClock_destroy(goku->clock3);
    sfClock_destroy(goku->clock4);
}
