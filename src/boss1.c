/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** boss1.c
*/

#include "../include/rpg.h"

void animate_b1(mob_t *b1, game_t *game, int type, screen_t *hud)
{
    type_idle_b1(b1, game, type, hud);
    type_run_b1(b1, game, type, hud);
    type_atk_b1(b1, game, type, hud);
}
