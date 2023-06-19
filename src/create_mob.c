/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** create_mob
*/

#include "../include/rpg.h"

sfVector2f get_random_postion(void)
{
    sfVector2f pos;
    int i = rand() % 4;

    if (i == 0)
        pos = (sfVector2f){570 + rand() % 450, 50 + rand() % 250};
    if (i == 1)
        pos = (sfVector2f){570 + rand() % 450, 1550 - rand() % 250};
    if (i == 2)
        pos = (sfVector2f){30 + rand() % 270, 625 + rand() % 375};
    if (i == 3)
        pos = (sfVector2f){1570 - rand() % 270, 625 + rand() % 375};
    return pos;
}
