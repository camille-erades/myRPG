/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** attack
*/

#include "../include/rpg.h"

void hit_enemy(hitbox_t *hitbox)
{
    mob_t *mob;
    player_t * player;

    if (hitbox->type == MOB) {
        mob = (mob_t *)hitbox->source;
        mob->life--;
    }
    if (hitbox->type == PLAYER) {
        player = (player_t *)hitbox->source;
        player->pv--;
    }
}

void attack_enemy(player_t *player, hitbox_t *list)
{
    sfIntRect attack;
    sfVector2f player_pos = sfSprite_getPosition(player->player);
    int i = player->animation->ani_index;

    attack.top = player_pos.y - 20;
    attack.left = player_pos.x;
    attack.left += (sfSprite_getScale(player->player).x < 0) ? -60 : 20;
    attack.height = 40;
    attack.width = 40;
    if (i != 2 && i != 3 && i != 7)
        return;
    for (hitbox_t *p = list; p; p = p->next) {
        if (p->type == PLAYER || p->type == ELSE)
            continue;
        if (sfIntRect_intersects(&p->size_rect, &attack, NULL))
            hit_enemy(p);
    }
}

void attack(mob_t *melee, player_t *player)
{
    sfIntRect attack = {0, 0, 36, 24};
    sfVector2f pos = sfSprite_getPosition(melee->sprite);
    sfVector2f scale = sfSprite_getScale(melee->sprite);

    attack.top += pos.y - 10;
    attack.left += pos.x;
    attack.left += (scale.x < 0) ? -86 : 30;
    if (melee->atk_index == 6)
        if (sfIntRect_intersects(&player->hitbox->size_rect, &attack, NULL))
            player->pv--;
}

void attack_range(mob_t *mob, hitbox_t *list)
{
    sfIntRect hit = {0, 0, 70 , 45};
    sfVector2f pos = sfSprite_getPosition(mob->kaboom->kaboom);

    hit.top = pos.y -20;
    hit.left = pos.x - 36;
    if (mob->kaboom->kb_index < 4 || mob->kaboom->kb_index > 6)
        return;
    for (hitbox_t *p = list; p; p = p->next) {
        if (p->type == ELSE)
            continue;
        if (sfIntRect_intersects(&p->size_rect, &hit, NULL))
            hit_enemy(p);
    }
}

void attack_buff(hitbox_t *list, player_t *player)
{
    sfIntRect attack = {0, 0, 177, 30};
    sfVector2f player_pos = sfSprite_getPosition(player->player);
    int i = player->animation->items->buf_ani_index;

    attack.top = player_pos.y;
    attack.left = player_pos.x;
    attack.left += (player->dashdir.x < 0) ? -177 : 0;
    if (i < 7 || i > 9)
        return;
    for (hitbox_t *p = list; p; p = p->next) {
        if (p->type == PLAYER || p->type == ELSE)
            continue;
        if (sfIntRect_intersects(&p->size_rect, &attack, NULL))
            hit_enemy(p);
    }
}
