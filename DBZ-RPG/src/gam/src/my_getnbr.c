/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** get the number
*/

int my_getnbr(char const *str)
{
    int r = 0;
    int i = 0;
    int neg = 1;

    for (i; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-')
            neg *= -1;
    }
    for (i; str[i] >= '0' && str[i] <= '9'; i++) {
        if (r < 214748364 || (r == 214748364 && str[i] <= '7')) {
            r *= 10;
            r += str[i] - 48;
        } else
            return (0);
    }
    return ((r * neg));
}
