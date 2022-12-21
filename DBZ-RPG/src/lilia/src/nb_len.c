/*
** EPITECH PROJECT, 2019
** nb_len
** File description:
** Return the lenght of number
*/

#include "../../../include/steph_rpg.h"

int nb_len(int nb)
{
    int i = 0;

    while (nb > 0) {
        nb = nb / 10;
        i++;
    }
    return (i);
}
