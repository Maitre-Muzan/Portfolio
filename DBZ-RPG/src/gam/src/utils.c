/*
** EPITECH PROJECT, 2020
** utils
** File description:
** utils
*/

#include "../include/game.h"

static int int_len(int n)
{
    int i = 0;

    for (i = 0; n > 0; i++)
        n = n / 10;
    if (i == 0)
        return (1);
    return (i);
}

char *int_to_string(int n)
{
    int len = int_len(n);
    char *str = malloc(len + 1);

    for (int i = len - 1; i >= 0; i--) {
        str[i] = (n % 10) + '0';
        n = n / 10;
        if (n == 0)
            break;
    }
    str[len] = '\0';
    return (str);
}

t_rpg display_int(t_rpg game, t_numb n, sfVector2f vector, tex_font f_t)
{
    char *str = int_to_string(n.n);
    sfText *text =  sfText_create();

    sfText_setString(text, str);
    sfText_setFont(text, f_t.font[0]);
    sfText_setCharacterSize(text, n.size);
    sfText_setColor(text, n.color);
    sfText_setPosition(text, vector);
    sfRenderWindow_drawText(game.win, text, NULL);
    free(str);
    sfText_destroy(text);
    return (game);
}

t_rpg display_bar(t_rpg game, t_numb n, sfVector2f vector, tex_font f_t)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setFillColor(shape, n.color);
    sfRectangleShape_setPosition(shape, vector);
    sfRectangleShape_setSize(shape, (sfVector2f){n.n / 5, 5});
    sfRenderWindow_drawRectangleShape(game.win, shape, NULL);
    sfRectangleShape_destroy(shape);
    return (game);
}
