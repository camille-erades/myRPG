/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** hitbox.c
*/

#include "../include/rpg.h"

void update(hitbox_t *hitbox)
{
    sfVector2f pos;
    mob_t *mob = NULL;
    player_t *player = NULL;

    switch (hitbox->type) {
    case MOB : mob = (mob_t *)hitbox->source;
        pos = sfSprite_getPosition(mob->sprite);
        pos.x -= mob->hitbox_posi.x;
        pos.y -= mob->hitbox_posi.y;
        break;
    case PLAYER : player = (player_t *)hitbox->source;
        pos = sfSprite_getPosition(player->player);
        pos.x -= 10;
        pos.y += 3  ;
        break;
    default: return;
    }
    hitbox->size_rect.left = pos.x;
    hitbox->size_rect.top = pos.y;
}

sfVector2f can_move(sfVector2f direction, hitbox_t *hitbox, hitbox_t *current,
    sfBool dash)
{
    sfIntRect rect_x;
    sfIntRect rect_y;

    update(current);
    rect_x = current->size_rect;
    rect_y = current->size_rect;
    rect_x.left += direction.x;
    rect_y.top += direction.y;
    for (hitbox_t *p = hitbox; p; p = p->next) {
        if (p == current)
            continue;
        update(p);
        if (dash == sfTrue && p->type != ELSE)
            continue;
        if (sfIntRect_intersects(&p->size_rect, &rect_x, NULL))
            direction.x = 0;
        if (sfIntRect_intersects(&p->size_rect, &rect_y, NULL))
            direction.y = 0;
    }
    return direction;
}

hitbox_t *get_last_hitbox(hitbox_t *hitbox)
{
    hitbox_t *p = hitbox;
    if (p) {
        while (p->next)
            p = p->next;
        return p;
    }
    return NULL;
}
