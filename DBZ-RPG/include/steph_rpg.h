/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg project
*/

#ifndef WINDOW_H
#define WINDOW_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Window.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/VideoMode.h>

typedef struct window
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
    sfRenderWindow *wind_menu;
    sfVideoMode video_menu;
    sfEvent event_menu;
    sfSoundBuffer *soundbuff;
    sfSound *sound;
    sfSoundBuffer *soundbuff_menu;
    sfSound *sound_menu;
    sfSoundBuffer *ss_menu;
    sfSound *s_menu;
    sfView *view1;
    sfFloatRect rect;
    sfVector2f offset;
    sfVector2f cam;
    sfClock *clock_menu;
    sfTime time_menu;
    sfText *text;
    sfFont *font;
    sfColor colrfnt;
    sfColor colorbrd;
}t_window;

typedef struct texture
{
    sfTexture *t_background;
    sfSprite *background;
    sfTexture *t_goku;
    sfSprite *goku;
    sfTexture *t_menu;
    sfSprite *menu;
    sfSprite *inter;
    sfSprite *land;
    sfIntRect lrect;
    sfText *swip[3];
    sfTexture *t_people1;
    sfSprite *people1;
    sfTexture *t_people2;
    sfSprite *people2;
    sfTexture *t_people3;
    sfSprite *people3;
    sfTexture *t_people4;
    sfSprite *people4;
    sfTexture *t_people5;
    sfSprite *people5;
    sfTexture *t_people6;
    sfSprite *people6;
    sfTexture *t_people7;
    sfSprite *people7;
    sfTexture *t_people8;
    sfSprite *people8;
    sfTexture *t_people9;
    sfSprite *people9;
    sfTexture *t_people10;
    sfSprite *people10;
    sfTexture *t_people11;
    sfSprite *people11;
    sfTexture *t_people12;
    sfSprite *people12;
    sfTexture *t_people13;
    sfSprite *people13;
    sfTexture *t_people14;
    sfSprite *people14;
    sfTexture *end;
    sfSprite *sprite_end;
    sfText *text;
    sfText *quit;
    sfFont *font;
    sfVector2f pos_over;
    sfVector2f end_quit;
    sfVector2f postext1;
    sfVector2f postext2;
    char *win;
    char *lose;
}t_texture;

typedef struct go_stat
{
    int lev;
    int exp;
    int life;
    int pow;
    int cnb;
}stat_t;

typedef struct t_goku t_goku;
struct t_goku
{
    int y;
    int j;
    int ivt;
    sfFont *convfont;
    sfSprite *profil;
    sfSprite *x_bt;
    sfText *t_info[6];
    sfTexture *textgo;
    sfSprite *spritego;
    sfTexture *textpo;
    sfSprite *spritepo;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f rpos;
    sfVector2f move;
    sfImage *black;
    sfIntRect rec;
    sfTime time;
    sfClock *clock1;
    sfClock *clock2;
    sfClock *clock3;
    sfClock *clock4;
    sfFont *font;
    sfText *name;
    sfText *pause[3];
    sfSprite *bts[2];
    sfVector2f oname;
    sfKeyCode key;
    stat_t gstat;
    sfSprite *arena;
    sfSprite *chest[3];
    sfIntRect chest_rec[3];
    int ball;
    sfSprite *back[2];
    sfSprite *spritecon[3];
    sfTexture *textcon[3];
    sfVector2f poscon1;
    sfVector2f poscon2;
    sfVector2f poscon3;

};

void people(t_texture *texture);
void people_sprite(t_texture *texture);
void set_people(t_texture *texture);
void people_position(t_texture *texture);
void scale_people(t_texture *texture);
void display_people(t_window *screen, t_texture *texture);
void people_2(t_texture *texture);
void people_sprite2(t_texture *texture);
void set_people2(t_texture *texture);
void people_position2(t_texture *texture);
void display_people2(t_window *screen, t_texture *texture);
void all_people(t_texture *texture);
void people_display(t_window *screen, t_texture *texture);

void all_destroy(t_window *screen);
void menu_window(t_window *screen, t_texture *texture);
void display_menu(t_window *screen, t_texture *texture);
void destroy_menu(t_window *screen);
void event_menu(t_window *screen, t_texture *texture, t_goku *goku);
void text_menu(t_window *screen);
void flashing_text(t_window *screen);

void display(t_window *screen, t_texture *texture, t_goku *goku);
void window(t_window *screen);
void create_event(t_window *screen, t_goku *goku);
int close_event(sfRenderWindow *window, sfEvent event);
void destroy(t_window *screen);
void texture_open(t_texture *texture);
void game_fonction(t_window *screen, t_texture *texture, t_goku *goku);
void show_chat(t_texture *texture, t_window *screen, char *str1, char *str2);

void display_conv_picco(t_window *screen, t_goku *goku, t_texture *texture);
void display_conv_krilin(t_window *screen, t_goku *goku, t_texture *texture);
void display_conv_vege(t_window *screen, t_goku *goku, t_texture *texture);
void re_initialization(t_texture *texture, t_goku *goku);
void gaming_end(t_window *screen, t_texture *texture, t_goku *goku);
void display_end(t_texture *texture, t_window *screen, int i);
void gaming(t_window *screen, t_texture *texture, t_goku *goku);
void display_goku(t_goku *goku, t_window *screen);
void display_rgoku(t_goku *goku, t_window *screen);
int goku_in_room(t_window *screen, t_goku *goku);
void initialization_text_sp(t_goku *goku, t_window *screen,
t_texture *texture);
void initialization_position(t_goku *goku, t_window *screen);
int describe_game(char *str);
void goku_on(t_goku *goku);
void goku_back(t_goku *goku);
void goku_left(t_goku *goku);
void goku_right(t_goku *goku);
void destroy_goku(t_goku *goku, t_texture *texture);
int mouse_on_sprite(sfSprite *sprite, sfRenderWindow *window);
int mouse_on_text(sfText *text, sfRenderWindow *window);
int mouse_on_usp(t_window *screen, sfSprite *sprite);
sfText *create_text(char *string, char *police, sfVector2f pos,
unsigned int size);
sfSprite *create_sprite(char *path, sfVector2f size, sfVector2f pos);
int button_light(t_window *screen, sfText *txt);
void bt_effect(t_window *screen, sfSprite *sprite);
void bts_effect(t_window *screen, t_goku *goku);
void filled_pause(t_goku *goku);
void draw_pause(t_window *screen, t_goku *goku);
void show_pause(t_window *screen, t_goku *goku);
void filled_ivt(t_goku *goku);
void draw_ivt(t_window *screen, t_goku *goku);
void show_ivt(t_window *screen, t_goku *goku);
void pause_effect(t_window *screen, t_goku *goku);
int check_room(t_window *screen, t_goku *goku);
void show_room(t_window *screen, t_texture *texture, t_goku *goku);
void filled_chest(t_goku *goku);
int is_close(sfRenderWindow *window, sfEvent event);
void filled_cine(t_texture *texture);
void draw_cine(t_window *screen, t_texture *texture);
void cine_bt_effect(t_window *screen, t_texture *texture);
void show_cine(t_window *screen, t_texture *texture, t_goku *goku);
void my_putchar(char c);
int my_putstr(char const *str);
int nb_len(int nb);
int my_strlen(char *str);
char *my_put_nbr(long int nb);
char *my_strcat(char *dest, char *src);

#endif
