/*
** EPITECH PROJECT, 2020
** init button
** File description:
** init button
*/

#include "../include/game.h"

static t_button init_button(t_button but, p_button par, sfFont *ft, char *s)
{
    but.text = sfText_create();
    sfText_setString(but.text, s);
    sfText_setColor(but.text, par.color);
    sfText_setFont(but.text, ft);
    sfText_setCharacterSize(but.text, par.size);
    sfText_setPosition(but.text, (sfVector2f){0, 0});
    but.param = par;
    return (but);
}

t_rpg init_button1(t_rpg game, tex_font f_t)
{
    p_button p1 = {sfWhite, 100};
    p_button p2 = {sfWhite, 50};

    game.b_title = init_button(game.b_title, p1, f_t.font[0], TITLE);
    game.b_high = init_button(game.b_high, p1, f_t.font[0], HIGH);
    game.b_menu = init_button(game.b_menu, p2, f_t.font[0], MAIN_MENU);
    game.b_play = init_button(game.b_play, p2, f_t.font[0], PLAY);
    game.b_quit = init_button(game.b_quit, p2, f_t.font[0], QUIT);
    game.b_avatar = init_button(game.b_avatar, p2, f_t.font[0], AVATAR);
    game.b_opt = init_button(game.b_opt, p2, f_t.font[0], OPT);
    game.b_help = init_button(game.b_help, p2, f_t.font[0], HELP);
    game.b_back = init_button(game.b_back, p2, f_t.font[0], BACK);
    game.b_frame = init_button(game.b_frame, p1, f_t.font[0], FRAME);
    game.b_fullscreen = init_button(game.b_fullscreen, p2, f_t.font[0], FULL);
    game.b_again = init_button(game.b_again, p2, f_t.font[0], AGAIN);
    return (game);
}

t_rpg init_button2(t_rpg game, tex_font f_t)
{
    sfColor color = sfColor_fromRGB(176, 173, 172);
    p_button p1 = {sfWhite, 100}, p2 = {sfWhite, 50};
    p_button p3 = {color, 50}, p4 = {sfMagenta, 100};
    p_button p5 = {sfRed, 100}, p6 = {sfWhite, 35};

    game.b_score = init_button(game.b_score, p2, f_t.font[0], SCORE);
    game.b_continue = init_button(game.b_continue, p3, f_t.font[0], CONTINU);
    game.b_h = init_button(game.b_h, p6, f_t.font[0], H);
    game.b_new = init_button(game.b_new, p2, f_t.font[0], NEW_GAME);
    game.b_no = init_button(game.b_no, p2, f_t.font[0], NO);
    game.b_off = init_button(game.b_off, p2, f_t.font[0], OFF_ON);
    game.b_on = init_button(game.b_on, p2, f_t.font[0], ON_OFF);
    game.b_over = init_button(game.b_over, p4, f_t.font[0], GAME_OVER);
    game.b_resume = init_button(game.b_resume, p2, f_t.font[0], RESUME);
    game.b_sound = init_button(game.b_sound, p2, f_t.font[0], SOUND);
    game.b_win = init_button(game.b_win, p5, f_t.font[0], WIN);
    game.b_yes = init_button(game.b_yes, p2, f_t.font[0], YES);
    return (game);
}
