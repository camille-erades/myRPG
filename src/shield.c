/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** shield
*/

/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** anitype_dash.c
*/

#include "../include/rpg.h"

static void the_world_next(animation_t *ani, game_t *game, int type,
    screen_t *hud)
{
    if (ani->items->world_ani_index >= 15)
        ani->items->world_ani_index = 16;
    sfSprite_setTextureRect(game->player->animation->items->the_world,
        (sfIntRect){ani->items->world_ani_index * 480, 0, 480, 480});
    sfClock_restart(ani->ani_clock);
}

void the_world(animation_t *ani, game_t *game, int type, screen_t *hud)
{
    if (type == 5){
        ani->ani_time = sfClock_getElapsedTime(ani->ani_clock);
        sfSprite_setPosition(game->player->animation->items->the_world,
            ani->herotoview_posi);
        sfSprite_setOrigin(game->player->animation->items->the_world,
            (sfVector2f){240, 300});
        if (sfTime_asSeconds(ani->ani_time) > 0.1){
            ani->ani_index++;
            ani->items->world_ani_index++;
            the_world_next(ani, game, type, hud);
        }
    }
}
