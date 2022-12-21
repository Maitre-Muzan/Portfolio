/*
** EPITECH PROJECT, 2020
** graphical_project
** File description:
** main
*/

#include "../../../include/steph_rpg.h"

int goku_in_room(t_window *screen, t_goku *goku)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
        if (goku->rpos.y > 150)
            goku->rpos.y -= 5;
        goku->move.y = -1;
        goku_back(goku);
    } if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
        if (goku->rpos.y < 2250)
            goku->rpos.y += 5;
        goku->move.y = 1;
        goku_on(goku);
    } if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        if (goku->rpos.x > 400)
            goku->rpos.x -= 5;
        goku->move.x = -1;
        goku_left(goku);
    } if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        if (goku->rpos.x < 860)
            goku->rpos.x += 5;
        goku->move.x = 1;
        goku_right(goku);
    } return (0);
}

void display_rgoku(t_goku *goku, t_window *screen)
{
    sfSprite_setPosition(goku->spritego, goku->rpos);
    sfSprite_setTexture(goku->spritego, goku->textgo, sfTrue);
    sfSprite_setTextureRect(goku->spritego, goku->rec);
    sfRenderWindow_drawSprite(screen->window, goku->spritego, NULL);
}

void display_goku(t_goku *goku, t_window *screen)
{
    sfSprite_setPosition(goku->spritego, goku->position);
    sfSprite_setTexture(goku->spritego, goku->textgo, sfTrue);
    sfSprite_setTextureRect(goku->spritego, goku->rec);
    sfRenderWindow_drawSprite(screen->window, goku->spritego, NULL);
}
