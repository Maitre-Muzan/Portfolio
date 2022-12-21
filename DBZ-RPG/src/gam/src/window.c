/*
** EPITECH PROJECT, 2020
** window defender
** File description:
** window
*/

#include "../include/game.h"

t_rpg window_resise(t_rpg game)
{
    sfVector2u size = sfRenderWindow_getSize(game.win);
    sfRenderWindow_setSize(game.win, size);
    return (game);
}

sfRenderWindow *window_create(char *name, sfBool bol)
{
    sfVideoMode video_mode = {1366, 768, 32};
    sfRenderWindow *window;

    if (bol == sfTrue)
        window = sfRenderWindow_create(video_mode, name,
            sfFullscreen | sfResize | sfClose, NULL);
    else
        window = sfRenderWindow_create(video_mode, name,
            sfResize | sfClose, NULL);
    if (!window)
        return (NULL);
    sfRenderWindow_setFramerateLimit(window, fps);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    return (window);
}

t_rpg redefine_window(t_rpg game)
{
    if (game.full) {
        sfRenderWindow_close(game.win);
        sfRenderWindow_destroy(game.win);
        game.win = window_create("MY_DEFENDER", sfFalse);
    } else {
        sfRenderWindow_close(game.win);
        sfRenderWindow_destroy(game.win);
        game.win = window_create("MY_DEFENDER", sfTrue);
    }
    game.full = (game.full ? sfFalse : sfTrue);
    sfRenderWindow_setFramerateLimit(game.win, fps);
    sfRenderWindow_setMouseCursorVisible(game.win, sfFalse);
    return (game);
}