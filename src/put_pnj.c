/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** put_pnj.c
*/

#include "../include/rpg.h"

void put_pnj_next(animation_t *ani, game_t *game)
{
    if (game->level->pnj->ani_index >= 4)
        game->level->pnj->ani_index = 0;
    sfSprite_setTextureRect(game->level->pnj->pnj_sprite,
        (sfIntRect){game->level->pnj->ani_index * 64, 0, 64, 64});
    sfClock_restart(game->level->pnj->ani_clock);
}

void put_pnj(animation_t *ani, game_t *game, sfVector2f posi)
{
    game->level->pnj->ani_time =
        sfClock_getElapsedTime(game->level->pnj->ani_clock);
    sfSprite_setPosition(game->level->pnj->pnj_sprite, posi);
    if (sfTime_asSeconds(game->level->pnj->ani_time) > 0.2){
        game->level->pnj->ani_index++;
        put_pnj_next(ani, game);
    }
}
