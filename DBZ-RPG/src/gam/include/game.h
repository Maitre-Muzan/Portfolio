/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef _MY_H

#define _MY_H

#include "struct.h"

#ifndef NB_FONT_TEX
#define NB_FONT_TEX
static int nb_font = 1;
static int nb_tex = 10;
static int tow_nb = 9;
static int tow_type = 4;
static int nb_mark = 8;
static int type_enemy = 2;
static int nb_enemy = 3;
#endif

#ifndef FPS
#define FPS
static int fps = 60;
#endif

#ifndef PRICES
static char *prices[5] = {"100", "125", "150", "175", NULL};
#endif

#ifndef RESSOURCES
#define RESSOURCES

#define DEAD(x, y) ((x <= -300 && y <= -300) ? 1 : 0)
#define IN(x, y) ((x >= 0 && x <= 1400 && y >= 0 && y <= 830) ? 1 : 0)
#define OUT(x, y) ((x > 1400 && y > 840) ? 1 : 0)

#define MUSIC1 "src/gam/ressources/audio/db4.ogg"
#define MUSIC2 "src/gam/ressources/audio/db4.ogg"
#define M_OVER "src/gam/ressources/audio/game_over.ogg"
#define M_WIN "src/gam/ressources/audio/game_win.ogg"
#define CLICK_SOUND "src/gam/ressources/audio/click.ogg"
#define FONT1 "src/gam/ressources/fonts/name.ttf"
#define TEXTURE1 "src/gam/ressources/Landscape.png"
#define TEXTURE2 "src/gam/ressources/cursor_dbz.png"
#define TEXTURE3 "src/gam/ressources/Logo.png"
#define TEXTURE4 "src/gam/ressources/neww.png"
#define TOW1 "src/gam/ressources/png/tower1.png"
#define TOW2 "src/gam/ressources/png/tower2.png"
#define TOW3 "src/gam/ressources/png/tower3.png"
#define TOW4 "src/gam/ressources/png/tower4.png"
#define COIN "src/gam/ressources/coinss.png"
#define ENNEMY "src/gam/ressources/roboo.png"

#define TITLE "DBZ_RPG"
#define MAIN_MENU "MAIN MENU"
#define PLAY "PLAY"
#define OPT "OPTIONS"
#define AVATAR "AVATAR"
#define HELP "HOW TO PLAY"
#define NEW_GAME "NEW GAME"
#define GAME_OVER "GAME  OVER !!"
#define WIN "CONGRATULATIONS !!"
#define AGAIN "Return to main menu ??"
#define YES "yes"
#define NO "no"
#define QUIT "QUIT"
#define BACK "BACK"
#define CONTINU "CONTINUE"
#define RESUME "RESUME"
#define ON_OFF "ON"
#define OFF_ON "OFF"
#define H "HOW TO PLAY\n\n\
    + Moves\n\n\
- Use arrows keys to move\n\
- Come closer to enter the rooms\n\n\
    +Shortcuts\n\n\
- [Echap] for Pause\n\
- [Space] to leave the fullscreen"
#define FULL "FULLSCREEN"
#define SOUND "SOUND"
#define HIGH "HIGH SCORE"
#define FRAME "FRAMERATE LIMIT"
#define SCORE "Score: "

#endif

#ifndef M_
#define M_
static int menu_id = 0;
static int play_id = 1;
static int pause_id = 2;
static int opt_id = 3;
static int help_id = 4;
static int new_id = 5;
static int game_over_id = 6;
static int game_win_id = 7;
static int quit_id = 9;
static int avatar_id = 8;
#endif

    t_rpg menu(t_rpg, tex_font);
    t_rpg play_game(t_rpg, tex_font);
    t_rpg pause_game(t_rpg, tex_font);
    t_rpg opt_game(t_rpg, tex_font);
    t_rpg help(t_rpg, tex_font);
    t_rpg new_game(t_rpg, tex_font);
    t_rpg game_over(t_rpg, tex_font);
    t_rpg game_win(t_rpg, tex_font);

t_rpg game_set(t_rpg, tex_font);
t_rpg game_anime(t_rpg, tex_font);
t_rpg dead_end(t_rpg, tex_font);

unsigned int rand_seed(void);
int my_rpg(t_rpg, tex_font);

t_rpg init_game(t_rpg, tex_font);
tex_font init_font_tex(tex_font);
t_rpg init_button1(t_rpg, tex_font);
t_rpg init_button2(t_rpg, tex_font);
t_rpg init_sounds(t_rpg);
t_rpg init_music(t_rpg);
t_rpg init_sprite(t_rpg, tex_font);
t_rpg init_tower(t_rpg, tex_font);
t_rpg init_marker(t_rpg, tex_font);
t_rpg init_coin(t_rpg, tex_font);
t_rpg init_enemy(t_rpg, tex_font);
t_rpg re_init(t_rpg, tex_font);
t_rpg rpg_test(t_rpg , tex_font);

void destroy_game(t_rpg, tex_font);
void destroy_marker(t_rpg);
t_rpg destroy_button(t_rpg);
void destroy_music(t_rpg);
void destroy_sounds(t_rpg);
void destroy_sprite(t_rpg);
void destroy_tower(t_rpg);
void destroy_clock(t_rpg);
void destroy_enemy(t_rpg);

t_button button_effect(sfVector2i, t_button);
sfBool button_click(sfVector2i, t_button);

int switch_music(t_rpg, sfBool);
t_rpg cursor(t_rpg);
void print_tower_price(t_rpg, t_tower, tex_font);
t_rpg towers_attack(t_rpg, tex_font);
t_rpg life_tower(t_rpg);
t_rpg tower_redef(t_rpg);

t_rpg redefine_window(t_rpg);
t_rpg window_resise(t_rpg);
sfRenderWindow *window_create(char *, sfBool);

char *int_to_string(int);
t_rpg display_int(t_rpg, t_numb, sfVector2f, tex_font);
t_rpg display_bar(t_rpg, t_numb, sfVector2f, tex_font);

t_rpg set_marker_position(t_rpg);
int is_marker(t_rpg);

int my_getnbr(const char *);
int is_tower(t_rpg);
t_rpg put_tower(t_rpg, int);

spr_tex animate(spr_tex, int, int, float);

t_rpg put_enemies(t_rpg);
t_rpg draw_enemy(t_rpg, tex_font);
t_enemy move_enemy(t_enemy);
t_enemy anime_enemy(t_enemy);
t_rpg effect_enemy(t_rpg, tex_font);
t_rpg enemy_dead(t_rpg);
t_rpg all_dead(t_rpg);

#endif
