/*
** EPITECH PROJECT, 2020
** game
** File description:
** game
*/

#include "../include/game.h"

static t_rpg game_click(t_rpg game)
{
    int i = 0;

    if (game.tower_pose) {
        i = is_tower(game);
            if (i != -1)
                game = put_tower(game, i);
        game.mark_id = 0;
        game.tower_pose = sfFalse;
    } else {
        i = is_marker(game);
            if (i != -1) {
                game.tower_pose = sfTrue;
                game.mark_id = i;
            }
    }
    game.sound ? sfSound_play(game.click.sound) : 0;
    return (game);
}

static t_rpg game_event(t_rpg game, tex_font f_t)
{
    while (sfRenderWindow_pollEvent(game.win, &game.event)) {
        switch (game.event.type) {
            case sfEvtClosed: sfRenderWindow_close(game.win);
            break;
            case sfEvtKeyPressed:
            if (sfKeyboard_isKeyPressed(sfKeySpace) && game.full)
                game = redefine_window(game);
            if (sfKeyboard_isKeyPressed(sfKeyEscape))
                game.id = 2;
            break;
            case sfEvtMouseButtonPressed: game = game_click(game);
            break;
            case sfEvtResized:
            if (!game.full)
                game = window_resise(game);
            break;
        }
    }
    game = effect_enemy(game, f_t);
    return (game);
}

t_rpg new_game(t_rpg game, tex_font f_t)
{
    game = game_set(game, f_t);
    game = draw_enemy(game, f_t);
    for (int i = 0; i < type_enemy; i++) {
        for (int j = 0; j < nb_enemy; j++)
            game.enemy[i][j] = move_enemy(game.enemy[i][j]);
    }
    game.coin = animate(game.coin, 9, 60, 0.1);
    sfText_setPosition(game.b_score.text, game.b_score.pos);
    sfRenderWindow_drawText(game.win, game.b_score.text, NULL);
    sfRenderWindow_drawSprite(game.win, game.coin.sprite, NULL);
    game = display_int(game, (t_numb){game.score, 50, sfBlue},
            (sfVector2f){1100, 0}, f_t);
    game = display_int(game, (t_numb){game.money, 50, sfBlue},
            (sfVector2f){80, 10}, f_t);
    game = game_anime(game, f_t);
    game = dead_end(game, f_t);
    game = game_event(game, f_t);
    return (game);
}
