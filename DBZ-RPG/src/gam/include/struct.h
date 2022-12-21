/*
** EPITECH PROJECT, 2020
** struct .h
** File description:
** struct
*/

#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "../../../include/steph_rpg.h"

typedef struct ij
{
    int i;
    int j;
}t_ij;

typedef struct numb
{
    int n;
    int size;
    sfColor color;
}t_numb;

typedef struct damage_data
{
    int i;
    int j;
    int a;
    int b;
    int c;
    int e;
    int width;
    int height;
}t_damage;

typedef struct font_texture
{
    sfTexture **texture;
    sfFont **font;
    int tile1;
    int tile2;
}tex_font;

typedef struct button_param
{
    sfColor color;
    int size;
}p_button;

typedef struct button
{
    sfText *text;
    sfVector2f pos;
    p_button param;
}t_button;

typedef struct spr_tex
{
    sfSprite *sprite;
    sfVector2f pos;
    sfClock *clock;
    sfClock *clock2;
    sfVector2f scale;
    sfIntRect rect;
}spr_tex;

typedef struct sound
{
    sfSound *sound;
    sfSoundBuffer *buffer;
}t_sound;

typedef struct enemy
{
    int section;
    int inc;
    int walk_front[2];
    int walk_right[2];
    int walk_left[2];
    int life;
    sfBool alive;
    sfIntRect rect;
    sfSprite *sprite;
    sfVector2f pos;
    sfClock *clock;
    sfClock *clock2;
    sfVector2f scale;
}t_enemy;

typedef struct tower
{
    int life;
    int power;
    int price_id;
    int pric;
    sfBool bool;
    sfSprite *sprite;
    sfVector2f pos;
    sfClock *clock;
    sfClock *clock2;
    sfVector2f scale;
}t_tower;

typedef struct marker
{
    sfRectangleShape *rect;
    sfVector2f pos;
}t_mark;

typedef struct defender
{
    spr_tex coin;
    int money;
    int score;
    t_button b_score;
    sfBool tower_pose;
    sfRenderWindow *win;
    sfView *view;
    sfBool full;
    sfBool sound;
    int mark_id;
    int id;
    spr_tex cursor;
    spr_tex map;
    sfEvent event;
    t_mark *marker;
    sfMusic *menu_music;
    sfMusic *game_music;
    sfMusic *game_over;
    sfMusic *game_win;
    spr_tex menu_bg;
    spr_tex logo;
    t_sound click;
    sfClock *clock2;
    sfClock *clock;
    t_tower **towers;
    sfVector2i mouse;
    t_button b_title;
    t_button b_menu;
    t_button b_play;
    t_button b_opt;
    t_button b_continue;
    t_button b_new;
    t_button b_resume;
    t_button b_quit;
    t_button b_avatar;
    t_button b_back;
    t_button b_help;
    t_button b_over;
    t_button b_win;
    t_button b_yes;
    t_button b_no;
    t_button b_again;
    t_button b_on;
    t_button b_off;
    t_button b_h;
    t_button b_fullscreen;
    t_button b_frame;
    t_button b_high;
    t_button b_sound;
    t_enemy **enemy;
    t_window screen;
    t_goku goku;
    t_texture texture;
}t_rpg;

#endif
