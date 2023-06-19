/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** anitype_run.c
*/

#include "../include/rpg.h"

static void type_run_next_r(mob_t *r, game_t *game, int type, screen_t *hud)
{
    if (r->ani_index >= 8)
        r->ani_index = 0;
    sfSprite_setTextureRect(r->sprite,
    (sfIntRect){r->ani_index * 160, 131, 160, 131});
    sfClock_restart(r->ani_clock);
}

void type_run_r(mob_t *r, game_t *game, int type, screen_t *hud)
{
    if (type == 1){
        r->ani_time = sfClock_getElapsedTime(r->ani_clock);
        sfSprite_setOrigin(r->sprite, r->origin);
        if (sfTime_asSeconds(r->ani_time) > 0.1){
            r->ani_index++;
            type_run_next_r(r, game, type, hud);
        }
    }
}
