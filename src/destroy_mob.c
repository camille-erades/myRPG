/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** destroy_mob
*/

#include "../include/rpg.h"

void destroy_attack(kb_t *attack)
{
    if (attack) {
        sfClock_destroy(attack->cooldown_clock);
        sfClock_destroy(attack->kb_clock);
        sfSprite_destroy(attack->kaboom);
        sfTexture_destroy(attack->kaboom_t);
        free(attack);
    }
}

void destroy_mob(mob_t *mob)
{
    if (mob) {
        sfSprite_destroy(mob->sprite);
        sfTexture_destroy(mob->texture);
        sfClock_destroy(mob->ani_clock);
        free(mob);
        destroy_attack(mob->kaboom);
    }
}

void destroy_list(mob_t *mob)
{
    mob_t *next = NULL;

    while (mob) {
        next = mob->next;
        destroy_mob(mob);
        mob = next;
    }
}

void destroy_hitbox_list(hitbox_t *hitbox)
{
    hitbox_t *next = NULL;

    while (hitbox) {
        next = hitbox->next;
        free(hitbox);
        hitbox = next;
    }
}
