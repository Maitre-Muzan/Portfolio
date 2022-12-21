/*
** EPITECH PROJECT, 2019
** description
** File description:
** usage
*/

#include "../../../include/steph_rpg.h"

int describe_game(char *str)
{
    if (str[0] == '-' && str[1] == 'h' && str[2] == '\0') {
        write(1, "\nUSAGE", 6);
        my_putchar('\n');
        write(1, "    ", 4);
        write(1, "Our RPG is an interesting game that you can play to ", 52);
        write(1, "relax.\n    Your objectif is to look for cristal ball", 54);
        write(1, "\n    and fight freezer to save the health.\n", 45);
        write(1, "    Enjoy playing.\n", 19);
    }
    if (str[1] != 'h')
        return (84);
    return (0);
}
