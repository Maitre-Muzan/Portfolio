/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "../../../include/steph_rpg.h"

void show_chat(t_texture *texture, t_window *screen, char *str1, char *str2)
{
    int k = 0;

    if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue)
        k = 1;
    if (k == 0) {
        sfText_setPosition(texture->text, texture->postext1);
        sfText_setString(texture->text, str1);
        sfText_setFont(texture->text, texture->font);
        sfText_setCharacterSize(texture->text, 20);
        sfRenderWindow_drawText(screen->window, texture->text, NULL);
    } else {
        sfText_setPosition(texture->text, texture->postext2);
        sfText_setString(texture->text, str2);
        sfText_setFont(texture->text, texture->font);
        sfText_setCharacterSize(texture->text, 20);
        sfRenderWindow_drawText(screen->window, texture->text, NULL);
    }
}

void display_conv_picco(t_window *screen, t_goku *goku, t_texture *texture)
{
    sfSprite_setPosition(goku->spritecon[0], goku->poscon1);
    sfSprite_setTexture(goku->spritecon[0], goku->textcon[0], sfTrue);
    sfRenderWindow_drawSprite(screen->window, goku->spritecon[0], NULL);
    sfText_setPosition(texture->text, goku->poscon1);
    sfText_setString(texture->text, "\n freezer est la\n Fais attention Goku!");
    sfText_setFont(texture->text, goku->convfont);
    sfText_setCharacterSize(texture->text, 15);
    sfRenderWindow_drawText(screen->window, texture->text, NULL);
}

void display_conv_krilin(t_window *screen, t_goku *goku, t_texture *texture)
{
    sfSprite_setPosition(goku->spritecon[1], goku->poscon2);
    sfSprite_setTexture(goku->spritecon[1], goku->textcon[1], sfTrue);
    sfRenderWindow_drawSprite(screen->window, goku->spritecon[1], NULL);
    sfText_setPosition(texture->text, goku->poscon2);
    sfText_setString(texture->text, "\n il a  deux boules\n tu dois le battre");
    sfText_setFont(texture->text, goku->convfont);
    sfText_setCharacterSize(texture->text, 15);
    sfRenderWindow_drawText(screen->window, texture->text, NULL);
}

void display_conv_vege(t_window *screen, t_goku *goku, t_texture *texture)
{
    sfSprite_setPosition(goku->spritecon[2], goku->poscon3);
    sfSprite_setTexture(goku->spritecon[2], goku->textcon[2], sfTrue);
    sfRenderWindow_drawSprite(screen->window, goku->spritecon[2], NULL);
    sfText_setPosition(texture->text, goku->poscon3);
    sfText_setString(texture->text, "\n  kakarot \n  On doit sauver la terre");
    sfText_setFont(texture->text, goku->convfont);
    sfText_setCharacterSize(texture->text, 15);
    sfRenderWindow_drawText(screen->window, texture->text, NULL);
}
