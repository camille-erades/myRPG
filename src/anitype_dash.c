/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** anitype_dash.c
*/

#include "../include/rpg.h"

static void type_dash_next(animation_t *ani, game_t *game, int type,
    screen_t *hud)
{
    if (ani->ani_index >= 12)
        ani->ani_index = 0;
    sfSprite_setTextureRect(game->player->player,
        (sfIntRect){ani->roll_ani_index * 120, 120, 34, 38});
    sfClock_restart(ani->ani_clock);
}

void type_dash(animation_t *ani, game_t *game, int type, screen_t *hud)
{
    if (type == 3){
        ani->ani_time = sfClock_getElapsedTime(ani->ani_clock);
        sfSprite_setPosition(game->player->player, ani->herotoview_posi);
        sfSprite_setOrigin(game->player->player, (sfVector2f){17, 19});
        if (sfTime_asSeconds(ani->ani_time) > 0.1){
            ani->ani_index++;
            ani->roll_ani_index++;
            type_dash_next(ani, game, type, hud);
        }
    }
}
