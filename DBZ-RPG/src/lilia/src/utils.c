/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** Check mouse and element position
*/

#include "../../../include/steph_rpg.h"

sfText *create_text(char *string, char *police, sfVector2f pos,
unsigned int size)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(police);

    sfText_setString(text, string);
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setPosition(text, pos);
    sfText_setCharacterSize(text, size);
    return (text);
}

sfSprite *create_sprite(char *path, sfVector2f size, sfVector2f pos)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, size);
    return (sprite);
}

int mouse_on_text(sfText *text, sfRenderWindow *window)
{
    sfFloatRect rect = sfText_getGlobalBounds(text);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x > rect.left && mouse.x < rect.left + rect.width
    && mouse.y > rect.top && mouse.y < rect.top + rect.height)
        return (1);
    return (0);
}

int mouse_on_sprite(sfSprite *sprite, sfRenderWindow *window)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(sprite);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x > rect.left && mouse.x < rect.left + rect.width
    && mouse.y > rect.top && mouse.y < rect.top + rect.height)
        return (1);
    return (0);
}
