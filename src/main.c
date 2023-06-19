/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** main.c
*/

#include "../include/rpg.h"
//#include "../include/game.h"
#include "stdio.h"

int main(void)
{
    game_t *game;
    game = prepare_all();
    screen(game);
    return 0;
}
