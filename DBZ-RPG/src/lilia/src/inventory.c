/*
** EPITECH PROJECT, 2020
** inventory.c
** File description:
** Manage inventory option
*/

#include "../../../include/steph_rpg.h"

void filled_ivt(t_goku *goku)
{
    char *font = "src/lilia/asset/sixty.TTF";
    char *str[6] = {my_strcat("Level : ", my_put_nbr(goku->gstat.lev)),
    my_strcat("EXP : ", my_put_nbr(goku->gstat.exp)),
    my_strcat("HEALTH : ", my_put_nbr(goku->gstat.life)),
    my_strcat("POWER : " , my_put_nbr(goku->gstat.pow)),
    "INVENTORY :", my_strcat(my_put_nbr(goku->gstat.cnb), " Dragon balls")};

    goku->t_info[0] = create_text(str[0], font, (sfVector2f){50, 25}, 60);
    goku->t_info[1] = create_text(str[1], font, (sfVector2f){350, 70}, 40);
    goku->t_info[2] = create_text(str[2], font, (sfVector2f){350, 140}, 40);
    goku->t_info[3] = create_text(str[3], font, (sfVector2f){350, 210}, 40);
    goku->t_info[4] = create_text(str[4], font, (sfVector2f){350, 330}, 50);
    goku->t_info[5] = create_text(str[5], font, (sfVector2f){475, 400}, 40);
}

void draw_ivt(t_window *screen, t_goku *goku)
{
    for (int i = 0; i < 6; i++) {
        sfText_setColor(goku->t_info[i], sfMagenta);
        sfRenderWindow_drawText(screen->window, goku->t_info[i], NULL);
    }
}

void show_ivt(t_window *screen, t_goku *goku)
{
    filled_ivt(goku);
    while (goku->ivt == 1 && sfRenderWindow_isOpen(screen->window)) {
        sfRenderWindow_clear(screen->window, sfBlack);
        sfRenderWindow_setView(screen->window, screen->view1);
        sfView_setCenter(screen->view1, (sfVector2f){640, 360});
        close_event(screen->window, screen->event);
        sfRenderWindow_drawSprite(screen->window, goku->back[1], NULL);
        sfRenderWindow_drawSprite(screen->window, goku->profil, NULL);
        draw_ivt(screen, goku);
        sfRenderWindow_drawSprite(screen->window, goku->x_bt, NULL);
        bt_effect(screen, goku->x_bt);
        if (mouse_on_sprite(goku->x_bt, screen->window)
        && sfMouse_isButtonPressed(sfMouseLeft))
            goku->ivt = 0;
        sfRenderWindow_display(screen->window);
    }
    sfView_setCenter(screen->view1, screen->cam);
}
