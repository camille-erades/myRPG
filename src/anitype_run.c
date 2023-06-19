/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** anitype_run.c
*/

#include "../include/rpg.h"

static void type_run_next(animation_t *ani, game_t *game, int type,
    screen_t *hud)
{
    if (ani->ani_index >= 10)
        ani->ani_index = 0;
    sfSprite_setTextureRect(game->player->player,
        (sfIntRect){ani->ani_index * 120, 40, 34, 38});
    sfClock_restart(ani->ani_clock);
}

void type_run(animation_t *ani, game_t *game, int type, screen_t *hud)
{
    if (type == 1){
        ani->ani_time = sfClock_getElapsedTime(ani->ani_clock);
        sfSprite_setPosition(game->player->player, ani->herotoview_posi);
        sfSprite_setOrigin(game->player->player, (sfVector2f){17, 19});
        if (sfTime_asSeconds(ani->ani_time) > 0.1){
            ani->ani_index++;
            type_run_next(ani, game, type, hud);
        }
    }
}
