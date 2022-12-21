/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** Displays a number
*/

#include "../../../include/steph_rpg.h"

char *my_put_nbr(long int nb)
{
    int i = nb_len(nb);
    char *str = malloc(sizeof(char) * (i + 1));

    str[i] = '\0';
    if (nb >= 0 && nb <= 9) {
        str[i - 1] = nb + '0';
        return (str);
    } else {
        for (int a = nb, pos = i - 1; a > 0; pos--) {
            str[pos] = (a % 10) + 48;
            a /= 10;
        }
        return (str);
    }
}
