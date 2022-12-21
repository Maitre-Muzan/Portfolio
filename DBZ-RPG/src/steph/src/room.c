/*
** EPITECH PROJECT, 2020
** room
** File description:
** Manage room
*/

#include "../../../include/steph_rpg.h"

void filled_chest(t_goku *goku)
{
    goku->chest[0] = create_sprite("src/hans/assets/chest.png",
    (sfVector2f){1, 1}, (sfVector2f){590, 250});
    goku->chest[1] = create_sprite("src/hans/assets/chest.png",
    (sfVector2f){1, 1}, (sfVector2f){650, 250});
    goku->chest[2] = create_sprite("src/hans/assets/chest.png",
    (sfVector2f){1, 1}, (sfVector2f){710, 250});
    for (int i = 0; i < 3; i++) {
        goku->chest_rec[i] = (sfIntRect){0, 0, 32, 32};
        sfSprite_setTextureRect(goku->chest[i], goku->chest_rec[i]);
    }
}

void draw_chest(t_window *screen, t_goku *goku)
{
    for (int i = 0; i < 3; i++) {
        sfRenderWindow_drawSprite(screen->window, goku->chest[i], NULL);
    }
}

void change_chest(t_window *screen, t_texture *texture, t_goku *goku)
{
    for (int i = 0; i < 3; i++) {
        if (mouse_on_sprite(goku->chest[i], screen->window)
        && sfMouse_isButtonPressed(sfMouseLeft)) {
            goku->chest_rec[i].left += 32;
            sfSprite_setTextureRect(goku->chest[i], goku->chest_rec[i]);
            sfRenderWindow_drawSprite(screen->window, goku->chest[i], NULL);
            if (i == goku->ball)
                display_end(texture, screen, 1);
            else
                display_end(texture, screen, 0);
        }
    }
    for (int i = 0; i < 3; i++)
        bt_effect(screen, goku->chest[i]);
}

void show_room(t_window *screen, t_texture *texture, t_goku *goku)
{
    int i = 0;

    filled_chest(goku);
    goku->rpos = (sfVector2f){675, 675};
    while (i != -1 && sfRenderWindow_isOpen(screen->window)) {
        sfRenderWindow_clear(screen->window, sfBlack);
        sfRenderWindow_setView(screen->window, screen->view1);
        sfView_setCenter(screen->view1, (sfVector2f){640, 360});
        close_event(screen->window, screen->event);
        sfRenderWindow_drawSprite(screen->window, goku->arena, NULL);
        draw_chest(screen, goku);
        goku_in_room(screen, goku);
        display_rgoku(goku, screen);
        change_chest(screen, texture, goku);
        i = check_room(screen, goku);
        sfRenderWindow_display(screen->window);
    }
    sfView_setCenter(screen->view1, screen->cam);
}
