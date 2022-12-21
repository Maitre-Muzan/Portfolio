/*
** EPITECH PROJECT, 2020
** init
** File description:
** init
*/

#include "../include/game.h"

t_rpg re_init(t_rpg game, tex_font f_t)
{
    destroy_tower(game);
    game.money = 900;
    game.score = 0;
    game = init_tower(game, f_t);
    destroy_enemy(game);
    game = init_enemy(game, f_t);
    return (game);
}

tex_font init_font_tex(tex_font f_t)
{
    f_t.font = malloc(sizeof(sfFont *) * nb_font);
    f_t.font[0] = sfFont_createFromFile(FONT1);
    f_t.texture = malloc(sizeof(sfTexture *) * nb_tex);
    f_t.texture[0] = sfTexture_createFromFile(TEXTURE1, NULL);
    f_t.texture[1] = sfTexture_createFromFile(TEXTURE2, NULL);
    f_t.texture[2] = sfTexture_createFromFile(TEXTURE3, NULL);
    f_t.texture[3] = sfTexture_createFromFile(TEXTURE4, NULL);
    f_t.texture[4] = sfTexture_createFromFile(TOW1, NULL);
    f_t.texture[5] = sfTexture_createFromFile(TOW2, NULL);
    f_t.texture[6] = sfTexture_createFromFile(TOW3, NULL);
    f_t.texture[7] = sfTexture_createFromFile(TOW4, NULL);
    f_t.texture[8] = sfTexture_createFromFile(COIN, NULL);
    f_t.texture[9] = sfTexture_createFromFile(ENNEMY, NULL);
    return (f_t);
}

t_rpg init_game(t_rpg game, tex_font f_t)
{
    game.score = 0;
    game.money = 900;
    game.mark_id = 0;
    game.id = 0;
    game.full = sfTrue;
    game.sound = sfTrue;
    game.tower_pose = sfFalse;
    game = init_button1(game, f_t);
    game = init_button2(game, f_t);
    game = init_sounds(game);
    game = init_music(game);
    game = init_sprite(game, f_t);
    game = init_tower(game, f_t);
    game = init_marker(game, f_t);
    game = init_enemy(game, f_t);
    game.clock = sfClock_create();
    game.clock2 = sfClock_create();
    return (game);
}