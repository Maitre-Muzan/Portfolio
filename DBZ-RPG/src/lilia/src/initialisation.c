/*
** EPITECH PROJECT, 2020
** graphical_project
** File description:
** main
*/

#include "../../../include/steph_rpg.h"

void initialization_position(t_goku *goku, t_window *screen)
{
    goku->rec = (sfIntRect){0, 0, 33, 35};
    goku->position = (sfVector2f){95, 220};
    goku->clock1 = sfClock_create();
    goku->clock2 = sfClock_create();
    goku->clock3 = sfClock_create();
    goku->clock4 = sfClock_create();
    screen->rect = (sfFloatRect){0, 0, 1280, 720};
    screen->view1 = sfView_createFromRect(screen->rect);
    screen->cam = (sfVector2f){640, 360};
    goku->move = (sfVector2f){1, 1};
    goku->y = 0, goku->ivt = 0;
    goku->profil = create_sprite("src/hans/assets/goku_stat.png",
    (sfVector2f){0.3, 0.3}, (sfVector2f){50, 150});
    goku->x_bt = create_sprite("src/hans/assets/x.png", (sfVector2f){2, 2},
    (sfVector2f){1120, 20});
    goku->gstat = (stat_t){1, 100, 1000, 1200, 4};
    goku->arena = create_sprite("src/hans/assets/arena.png",
    (sfVector2f){1.5, 1.5}, (sfVector2f){390, 52});
    goku->black = sfImage_createFromFile("src/Dbpic_black.png");
}

void re_initialization(t_texture *texture, t_goku *goku)
{
    goku->poscon1.x = 270, goku->poscon1.y = 230;
    goku->poscon2.x = 320, goku->poscon2.y = 650;
    goku->poscon3.x = 1020, goku->poscon3.y = 1550;
    texture->text = sfText_create();
    texture->quit = sfText_create();
    texture->font = sfFont_createFromFile("src/lilia/asset/sixty.TTF");
    goku->convfont = sfFont_createFromFile("src/lilia/asset/arial.ttf");
    texture->postext1 = (sfVector2f){500, 200};
    texture->postext2 = (sfVector2f){600, 400};
    texture->pos_over = (sfVector2f){500, 200};
    texture->end_quit = (sfVector2f){600, 400};
    texture->win = "CONGRATULATIONS!!!";
    texture->lose = "GAME OVER!!";
    goku->textcon[0] = sfTexture_createFromFile("src/lilia/asset/bl.png", NULL);
    goku->spritecon[0] = sfSprite_create();
    goku->textcon[1] = sfTexture_createFromFile("src/lilia/asset/rd.png", NULL);
    goku->spritecon[1] = sfSprite_create();
    goku->textcon[2] = sfTexture_createFromFile("src/lilia/asset/gr.png", NULL);
    goku->spritecon[2] = sfSprite_create();
}

void initialization_text_sp(t_goku *goku, t_window *screen,
t_texture *texture)
{
    goku->back[0] = create_sprite("src/hans/assets/pause.jpg",
    (sfVector2f){1, 1}, (sfVector2f){0, 0});
    goku->back[1] = create_sprite("src/hans/assets/invent.jpg",
    (sfVector2f){1, 1}, (sfVector2f){0, 0});
    goku->textgo = sfTexture_createFromFile("src/lilia/asset/goku.png", NULL);
    goku->spritego = sfSprite_create();
    texture->end = sfTexture_createFromFile("src/lilia/asset/po.png", NULL);
    texture->sprite_end = sfSprite_create();
    goku->textpo = sfTexture_createFromFile("src/lilia/asset/po.png", NULL);
    goku->spritepo = sfSprite_create();
    goku->bts[0] = create_sprite("src/hans/assets/pause_bt.png",
    (sfVector2f){0.25, 0.25}, (sfVector2f){1200, 20});
    goku->bts[1] = create_sprite("src/hans/assets/backpack.png",
    (sfVector2f){1, 1}, (sfVector2f){20, 20});
    filled_pause(goku);
    sfSprite_setTexture(goku->spritepo, goku->textpo, sfTrue);
}
