/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** menu
*/

#include "../../../include/steph_rpg.h"

void menu_window(t_window *screen, t_texture *texture)
{
    screen->video_menu.width = 1280;
    screen->video_menu.height = 720;
    screen->video_menu.bitsPerPixel = 32;
    screen->wind_menu = sfRenderWindow_create(screen->video_menu,
    "My_rpg", sfDefaultStyle, NULL);
    texture->inter = create_sprite("src/hans/assets/interaction4.jpg",
    (sfVector2f){0.125, 0.125}, (sfVector2f){0, 0});
    texture->t_menu = sfTexture_createFromFile("src/steph/pict/db_menu.png",
    NULL);
    texture->menu = sfSprite_create();
    sfSprite_setTexture(texture->menu, texture->t_menu, sfTrue);
    screen->soundbuff_menu = sfSoundBuffer_createFromFile(
    "src/steph/music/DBS.ogg");
    screen->sound_menu = sfSound_create();
    sfSound_setBuffer(screen->sound_menu, screen->soundbuff_menu);
    sfSound_play(screen->sound_menu);
    sfSound_setLoop(screen->sound_menu, sfTrue);
    screen->clock_menu = sfClock_create();
}

void text_menu(t_window *screen)
{
    screen->font = sfFont_createFromFile("src/steph/pict/name.ttf");
    screen->text = sfText_create();
    sfText_setString(screen->text, "Press Enter to start");
    sfText_setFont(screen->text, screen->font);
    sfText_setStyle(screen->text, 1);
    sfText_setColor(screen->text, sfBlack);
    sfText_setCharacterSize(screen->text, 45);
    sfText_setPosition(screen->text, (sfVector2f) {80, 500});
}

void display_menu(t_window *screen, t_texture *texture)
{
    int x = 0, y = 0;

    x = (rand() % 1180) + 1;
    y = (rand() % 650) + 1;
    sfSprite_setScale(texture->menu, (sfVector2f) {1, 1});
    sfRenderWindow_drawSprite(screen->wind_menu, texture->menu, NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSprite_setPosition(texture->inter,
        (sfVector2f){(float)x, (float)y});
        sfRenderWindow_drawSprite(screen->wind_menu, texture->inter, NULL);
    }
    flashing_text(screen);
    sfRenderWindow_display(screen->wind_menu);
}

void destroy_menu(t_window *screen)
{
    sfClock_destroy(screen->clock_menu);
    sfText_destroy(screen->text);
    sfRenderWindow_destroy(screen->wind_menu);
}

void event_menu(t_window *screen, t_texture *texture, t_goku *goku)
{
    int seed = 0;

    srand(seed);
    show_cine(screen, texture, goku);
    while (sfRenderWindow_isOpen(screen->wind_menu)) {
        sfRenderWindow_setFramerateLimit(screen->wind_menu, 14);
        while (sfRenderWindow_pollEvent(screen->wind_menu,
        &screen->event_menu)) {
            if (screen->event_menu.type == sfEvtClosed)
                sfRenderWindow_close(screen->wind_menu);
            if (screen->event_menu.type == sfEvtKeyPressed
            && screen->event_menu.key.code == sfKeyReturn) {
                sfSound_stop(screen->sound_menu);
                sfRenderWindow_close(screen->wind_menu);
                game_fonction(screen, texture, goku);
            }
        }
        display_menu(screen, texture);
    }
    sfSoundBuffer_destroy(screen->soundbuff_menu);
    sfSound_destroy(screen->sound_menu);
}
