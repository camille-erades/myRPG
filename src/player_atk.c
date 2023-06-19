/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** player_atk.c
*/

#include "../include/rpg.h"

sfBool atk(screen_t *hud, animation_t *ani, game_t *game)
{
    int i = 0;
    static sfBool attack = sfFalse;

    if (sfKeyboard_isKeyPressed(sfKeyG)) {
        if (attack == sfFalse)
            ani->ani_index = 0;
        attack = sfTrue;
    }
    i = ani->ani_index;
    if (attack){
        animate_hero(ani, game, 2, hud);
    }
    if (attack)
        if ((!sfKeyboard_isKeyPressed(sfKeyG) && i == 5) || i == 10) {
            attack = sfFalse;
            ani->ani_index = 0;
        }
    return attack;
}
