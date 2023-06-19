/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** anitype_atk.c
*/

#include "../include/rpg.h"

static void type_atk_next(animation_t *ani, game_t *game, int type,
    screen_t *hud)
{
    if (ani->ani_index >= 10)
        ani->ani_index = 0;
    sfSprite_setTextureRect(game->player->player,
        (sfIntRect){ani->ani_index * 120, 78, 116, 44});
    sfClock_restart(ani->ani_clock);
}

void type_atk(animation_t *ani, game_t *game, int type, screen_t *hud)
{
    if (type == 2){
        ani->ani_time = sfClock_getElapsedTime(ani->ani_clock);
        sfSprite_setPosition(game->player->player, ani->herotoview_posi);
        sfSprite_setOrigin(game->player->player, (sfVector2f){58, 22});
        if (sfTime_asSeconds(ani->ani_time) > 0.1){
            attack_enemy(game->player, game->level->hitbox);
            ani->ani_index++;
            type_atk_next(ani, game, type, hud);
        }
    }
}

static void type_buff_atk_next(animation_t *ani, game_t *game, int type,
    screen_t *hud)
{
    if (ani->items->buf_ani_index >= 11)
        ani->items->buf_ani_index = 0;
    sfSprite_setTextureRect(game->player->animation->items->buf_atk_player,
        (sfIntRect){ani->items->buf_ani_index * 274, 0, 273, 155});
    sfClock_restart(ani->ani_clock);
}

void type_buff_atk(animation_t *ani, game_t *game, int type, screen_t *hud)
{
    if (type == 4){
        ani->ani_time = sfClock_getElapsedTime(ani->ani_clock);
        sfSprite_setPosition(game->player->animation->items->buf_atk_player,
            ani->herotoview_posi);
        sfSprite_setOrigin(game->player->animation->items->buf_atk_player,
            (sfVector2f){190, 130});
        if (sfTime_asSeconds(ani->ani_time) > 0.1){
            attack_buff(game->level->hitbox, game->player);
            ani->ani_index++;
            ani->items->buf_ani_index++;
            type_buff_atk_next(ani, game, type, hud);
            type_idle_next(ani, game, type, hud);
        }
    }
}
