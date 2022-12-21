/*
** EPITECH PROJECT, 2020
** check_room
** File description:
** Check room door
*/

#include "../../../include/steph_rpg.h"

int check_room(t_window *screen, t_goku *goku)
{
    if (goku->position.x >= 945 && goku->position.x <= 965
    && goku->position.y == 625 && goku->move.y == -1)
        return (1);
    if (goku->rpos.x >= 650 && goku->rpos.x <= 690
    && goku->rpos.y == 675 && goku->move.y == 1)
        return (-1);
    return (0);
}
