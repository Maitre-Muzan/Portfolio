/*
** EPITECH PROJECT, 2020
** rand seed
** File description:
** rand seed
*/

#include "../include/game.h"

unsigned int rand_seed(void)
{
    int fd = open("/dev/urandom", O_RDONLY);
    unsigned int seed = 0;
    int rd = 0;

    if (fd == -1)
        return (0);
    rd = read(fd, &seed, sizeof(seed));
    if (rd < 0)
        return (0);
    close(fd);
    return (seed);
}