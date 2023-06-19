/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** actualise_mob
*/

#include "../include/rpg.h"

void remove_elem_form_list(mob_t *mob, level_t *level)
{
    if (mob == level->range) {
        level->range = mob->next;
        if (level->range)
            level->range->prev = NULL;
        return;
    }
    if (mob == level->melee) {
        level->melee = mob->next;
        if (level->melee)
            level->melee->prev = NULL;
        return;
    }
    if (mob->prev)
        mob->prev->next = mob->next;
    if (mob->next)
        mob->next->prev = mob->prev;
}

void remove_hitbox(hitbox_t *mob, level_t *level)
{
    if (!mob)
        return;
    if (mob == level->hitbox) {
        level->hitbox = mob->next;
        level->hitbox->previous = NULL;
    } else {
        if (mob->previous)
            mob->previous->next = mob->next;
        if (mob->next)
            mob->next->previous = mob->previous;
    }
    free(mob);
}

void actualise_mob(mob_t *mob, level_t *level)
{
    if (mob->life <= 0) {
        if (mob == level->b1) {
            level->b1 = NULL;
        } else {
            remove_elem_form_list(mob, level);
        }
        remove_hitbox(mob->hitbox, level);
        destroy_mob(mob);
    }
}

void kill_mob(mob_t *mob, level_t *level)
{
    for (mob_t *p = mob; p; p = p->next) {
        remove_elem_form_list(p, level);
        remove_hitbox(p->hitbox, level);
        destroy_mob(p);
    }
}
