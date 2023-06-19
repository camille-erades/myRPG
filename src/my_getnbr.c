/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-pushswap-clement.monnoire
** File description:
** my_getnbr
*/

int get_nbr(char const *str)
{
    int i = 0;
    int nbr = 0;
    int sign = 1;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57){
        nbr *= 10;
        nbr = nbr + str[i] - 48;
        i++;
    }
    return (nbr * sign);
}
