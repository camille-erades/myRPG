/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** anitype_run.c
*/

#include "../include/rpg.h"

static void type_run_next_b1(mob_t *b1, game_t *game, int type, screen_t *hud)
{
    if (b1->ani_index >= 8)
        b1->ani_index = 0;
    sfSprite_setTextureRect(b1->sprite,
    (sfIntRect){b1->ani_index * 145, 146.25, 145, 146.25});
    sfClock_restart(b1->ani_clock);
}

void type_run_b1(mob_t *b1, game_t *game, int type, screen_t *hud)
{
    if (type == 1){
        b1->ani_time = sfClock_getElapsedTime(b1->ani_clock);
        if (sfTime_asSeconds(b1->ani_time) > 0.1){
            b1->ani_index++;
            type_run_next_b1(b1, game, type, hud);
        }
    }
}

static void type_run_next_m(mob_t *m, game_t *game, int type, screen_t *hud)
{
    if (m->ani_index >= 8)
        m->ani_index = 0;
    sfSprite_setTextureRect(m->sprite,
    (sfIntRect){m->ani_index * 250, 344, 250, 151});
    sfClock_restart(m->ani_clock);
}

void type_run_m(mob_t *m, game_t *game, int type, screen_t *hud)
{
    if (type == 1){
        m->ani_time = sfClock_getElapsedTime(m->ani_clock);
        if (sfTime_asSeconds(m->ani_time) > 0.1){
            m->ani_index++;
            type_run_next_m(m, game, type, hud);
        }
    }
}
