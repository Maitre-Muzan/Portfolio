/*
** EPITECH PROJECT, 2020
** My_defender
** File description:
** display
*/

#include "../../../include/steph_rpg.h"

static int goku_active(t_window *screen, t_goku *goku)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
        goku->move.y = -1;
        goku_back(goku);
    } if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
        goku->move.y = 1;
        goku_on(goku);
    } if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        goku->move.x = -1;
        goku_left(goku);
    } if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        goku->move.x = 1;
        goku_right(goku);
    } return (0);
}

static void update_horview(t_window *screen, t_goku *goku)
{
    if (goku->position.x - screen->cam.x == 520 && goku->move.x == 1) {
        if (screen->cam.x == 640)
            screen->cam.x += 672;
        else if (screen->cam.x == 1312)
            screen->cam.x = screen->cam.x;
        return;
    } else if (goku->position.x - screen->cam.x == -527
    && goku->move.x == -1) {
        if (screen->cam.x == 1312)
            screen->cam.x -= 672;
        else if (screen->cam.x == 640)
            screen->cam.x = screen->cam.x;
        return;
    }
}

static void update_verview(t_window *screen, t_goku *goku)
{
    if (goku->position.y - screen->cam.y == 310 && goku->move.y == 1) {
        if (screen->cam.y == 1500)
            screen->cam.y += 460;
        else if (screen->cam.y == 1960)
            screen->cam.y = screen->cam.y;
        else
            screen->cam.y += screen->video_mode.height - 150;
    } else if (goku->position.y - screen->cam.y == -310
    && goku->move.y == -1) {
        if (screen->cam.y == 1960)
            screen->cam.y -= 460;
        else if (screen->cam.y == 360)
            screen->cam.y = screen->cam.y;
        else
            screen->cam.y = screen->cam.y - screen->video_mode.height + 150;
    }
}

static void update_bts(t_window *screen, t_goku *goku)
{
    sfSprite_setPosition(goku->bts[0], (sfVector2f){screen->cam.x + 560,
    screen->cam.y - 340});
    sfSprite_setPosition(goku->bts[1], (sfVector2f){screen->cam.x - 620,
    screen->cam.y - 340});
    for (int i = 0; i < 2; i++)
        sfRenderWindow_drawSprite(screen->window, goku->bts[i], NULL);
    bts_effect(screen, goku);
}

void display(t_window *screen, t_texture *texture, t_goku *goku)
{
    sfVector2f pose;
    sfRenderWindow_drawSprite(screen->window, texture->background, NULL);
    people_display(screen, texture);
    goku_active(screen, goku);
    display_goku(goku, screen);
    pose = sfSprite_getPosition(goku->spritego);
    update_verview(screen, goku);
    update_horview(screen, goku);
    update_bts(screen, goku);
    sfRenderWindow_setView(screen->window, screen->view1);
    sfView_setCenter(screen->view1, screen->cam);
    if (pose.x <= 250 && pose.x >= 220)
        display_conv_picco(screen, goku, texture);
    if (pose.y >= 720 && pose.y <= 750)
        display_conv_krilin(screen, goku, texture);
    else if (pose.x >= 1000 && pose.x <= 1030)
        display_conv_vege(screen, goku, texture);
    sfRenderWindow_display(screen->window);
    sfRenderWindow_clear(screen->window, sfBlack);
}
