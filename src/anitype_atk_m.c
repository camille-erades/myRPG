/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** anitype_atk.c
*/

#include "../include/rpg.h"

static void type_atk_next_b1(mob_t *b1, game_t *game, int type, screen_t *hud)
{
    static int line = 0;
    if (b1->ani_index >= 10){
        b1->ani_index = 0;
        line++;
        if (line == 4)
            line = 0;
    }
    sfSprite_setTextureRect(b1->sprite,
    (sfIntRect){b1->ani_index * 145, (line * 146.25) + 292.5, 145, 146.25});
    sfClock_restart(b1->ani_clock);
}

void type_atk_b1(mob_t *b1, game_t *game, int type, screen_t *hud)
{
    if (type == 2){
        b1->ani_time = sfClock_getElapsedTime(b1->ani_clock);
        if (sfTime_asSeconds(b1->ani_time) > 0.1){
            b1->ani_index++;
            type_atk_next_b1(b1, game, type, hud);
        }
    }
}

static void type_atk_next_m(mob_t *m, game_t *game, int type, screen_t *hud)
{
    if (m->atk_index >= 8)
        m->atk_index = 0;
    sfSprite_setTextureRect(m->sprite,
    (sfIntRect){m->atk_index * 250, 177, 250, 151});
    sfClock_restart(m->ani_clock);
}

void type_atk_m(mob_t *m, game_t *game, int type, screen_t *hud)
{
    if (type == 2)
        m->is_attacking = sfTrue;
    if (m->is_attacking){
        m->ani_time = sfClock_getElapsedTime(m->ani_clock);
        if (sfTime_asSeconds(m->ani_time) > 0.1){
            attack(m, game->player);
            m->atk_index++;
            type_atk_next_m(m, game, type, hud);
        }
    }
    if (m->atk_index == 0)
        m->is_attacking = sfFalse;
}
