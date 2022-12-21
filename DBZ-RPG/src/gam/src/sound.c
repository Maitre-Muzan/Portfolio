/*
** EPITECH PROJECT, 2020
** sound
** File description:
** sound
*/

#include "../include/game.h"

void destroy_sounds(t_rpg game)
{
    sfSound_destroy(game.click.sound);
    sfSoundBuffer_destroy(game.click.buffer);
}

t_rpg init_sounds(t_rpg game)
{
    game.click.sound = sfSound_create();
    game.click.buffer = sfSoundBuffer_createFromFile(CLICK_SOUND);
    sfSound_setBuffer(game.click.sound, game.click.buffer);
    return (game);
}
