/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** anitype_atk.c
*/

#include "../include/rpg.h"

void boom_next(mob_t *r, game_t *game, int type, screen_t *hud)
{
    if (r->kaboom->kb_index >= 13){
        r->kaboom->kb_index = -1;
        r->is_attacking = sfFalse;
    }
    sfSprite_setTextureRect(r->kaboom->kaboom, (sfIntRect){r->kaboom->kb_index
        * 128, 0, 128, 128});
    sfClock_restart(r->kaboom->kb_clock);
}

void boom(mob_t *r, game_t *game, int type, screen_t *hud)
{
    float i = 0.0;

    i += (r->kaboom->kb_index < 1) ? 0.3 : 0.1;
    r->kaboom->kb_cd = sfClock_getElapsedTime(r->kaboom->kb_clock);
    if (sfTime_asSeconds(r->kaboom->kb_cd) > i) {
        if (r->kaboom->kb_index == -1)
            sfSprite_setPosition(r->kaboom->kaboom,
            game->player->animation->herotoview_posi);
        r->kaboom->kb_index++;
        boom_next(r, game, type, hud);
        attack_range(r, game->level->hitbox);
    }
}

void type_atk_next_r(mob_t *r, game_t *game, int type, screen_t *hud)
{
    if (r->ani_index >= 13) {
        sfClock_restart(r->kaboom->cooldown_clock);
        r->ani_index = 0;
    }
    sfSprite_setTextureRect(r->sprite,
    (sfIntRect){r->ani_index * 160, 262, 160, 131});
    sfClock_restart(r->ani_clock);
}

void type_atk_r(mob_t *r, game_t *game, int type, screen_t *hud)
{
    r->ani_time = sfClock_getElapsedTime(r->ani_clock);
    if (sfTime_asSeconds(r->ani_time) > 0.1){
        r->ani_index++;
        type_atk_next_r(r, game, type, hud);
    }
    if (r->ani_index == 9)
        r->is_attacking = sfTrue;
}
