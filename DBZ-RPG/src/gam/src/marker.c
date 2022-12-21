/*
** EPITECH PROJECT, 2020
** marker
** File description:
** marker
*/

#include "../include/game.h"

static sfBool is_empty_marker(t_mark marker, t_rpg game)
{
    for (int i = 0; i < tow_type; i++) {
        for (int j = 1; j < tow_nb; j++) {
            if (marker.pos.x > game.towers[i][j].pos.x - 31
            && marker.pos.x < game.towers[i][j].pos.x + 31 &&
            marker.pos.y < game.towers[i][j].pos.y  + 31 &&
            marker.pos.y > game.towers[i][j].pos.y - 31) {
                return (sfFalse);
            }
        }
    }
    return (sfTrue);
}

int is_marker(t_rpg game)
{
    float a = (float)game.mouse.x;
    float b = (float)game.mouse.y;
    sfVector2f rect;

    for (int i = 0; i < nb_mark; i++) {
        rect = sfRectangleShape_getSize(game.marker[i].rect);
        if (a > game.marker[i].pos.x && a < (game.marker[i].pos.x + rect.x) &&
        b > game.marker[i].pos.y  && b < (game.marker[i].pos.y + rect.y)
        && is_empty_marker(game.marker[i], game))
            return (i);
    }
    return (-1);
}

t_rpg set_marker_position(t_rpg game)
{
    game.marker[0].pos = (sfVector2f){280, 500};
    game.marker[1].pos = (sfVector2f){355, 650};
    game.marker[2].pos = (sfVector2f){580, 650};
    game.marker[3].pos = (sfVector2f){510, 360};
    game.marker[4].pos = (sfVector2f){805, 500};
    game.marker[5].pos = (sfVector2f){970, 500};
    game.marker[6].pos = (sfVector2f){1200, 360};
    game.marker[7].pos = (sfVector2f){960, 210};
    for (int i = 0; i < nb_mark; i++)
        sfRectangleShape_setPosition(game.marker[i].rect, game.marker[i].pos);
    return (game);
}

void destroy_marker(t_rpg game)
{
    for (int i = 0; i < nb_mark; i++)
        sfRectangleShape_destroy(game.marker[i].rect);
    free(game.marker);
}

t_rpg init_marker(t_rpg game, tex_font f_t)
{
    game.marker = malloc(sizeof(t_mark) * nb_mark);
    for (int i = 0; i < nb_mark; i++) {
        game.marker[i].rect = sfRectangleShape_create();
        sfRectangleShape_setFillColor(game.marker[i].rect, sfRed);
        sfRectangleShape_setSize(game.marker[i].rect, (sfVector2f){75, 75});
    }
    return (game);
}
